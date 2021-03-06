#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
using namespace std;
const int MOD = 1000000007;
int binarySearch(vector <int> arr, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}



struct BIT {
	vector <int> tree;
	vector <int> indices;

public: void update(int index, int val) {
	int actual = binarySearch(indices, 0, indices.size() - 1, index);
	while (actual < indices.size()) {
		tree[actual] += val;
		if (tree[actual] >= MOD) tree[actual] -= MOD;
		actual += actual & -actual;
	}
}
public: int query(int index) {
	int left = 0;
	int right = indices.size() - 1;
	while (left != right) {
		int mid = (left + right + 1) / 2;
		if (indices[mid] > index) {
			right = mid - 1;
		}
		else {
			left = mid;
		}
	}
	int ret = 0;
	while (left > 0) {
		ret += tree[left];
		if (ret >= MOD) ret -= MOD;
		left -= left & -left;
	}
	return ret;
}
};

BIT newBIT(vector <int> set) {
	BIT temp;
	temp.indices.resize(set.size() + 2);
	temp.tree.resize(temp.indices.size());
	temp.indices[0] = -1;
	int index = 1;
	for (int out : set) {
		temp.indices[index++] = out;
	}
	temp.indices[temp.indices.size() - 1] = INT_MAX;
	return temp;
}




int main(void)
{
	ifstream fin("hopscotch.in");
	ofstream fout("hopscotch.out");

	int r, c, colors;
	fin >> r >> c >> colors;

	vector <vector <int>> grid(r);
	for (int i = 0; i < r; i++) {
		grid[i].resize(c);
		for (int j = 0; j < c; j++) {
			fin >> grid[i][j];
		}
	}

	vector <vector <int>> columns(colors + 1);

	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			int color = grid[i][j];
			if (!columns[color].empty() && columns[color][columns[color].size() - 1] == j) continue;
			columns[color].push_back(j);
		}
	}

	vector <BIT> bits(colors + 1);

	for (int i = 1; i < bits.size(); i++) {
		if (columns[i].size() > 0) {
			bits[i] = newBIT(columns[i]);
		}
	}
	vector <int> gen;
	for (int i = 0; i < c; i++) {
		gen.push_back(i);
	}
	BIT full = newBIT(gen);
	full.update(0, 1);
	bits[grid[0][0]].update(0, 1);
	for (int i = 1; i < r - 1; i++) {
		for (int j = c - 2; j > 0; j--) {
			int val = full.query(j - 1) - bits[grid[i][j]].query(j - 1);
			if (val < 0) val += MOD;
			full.update(j, val);
			bits[grid[i][j]].update(j, val);
		}
	}
	int ret = full.query(c - 2) - bits[grid[r - 1][c - 1]].query(c - 2);
	if (ret < 0) ret += MOD;
	fout << ret;

	return 0;
}