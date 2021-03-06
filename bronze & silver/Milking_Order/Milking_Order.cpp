#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool test(vector <int> cows, int p, vector <int> sh) {

	vector <int> ps;

	for (int i = 0; i < sh.size(); i++) {
		bool isthere = 0;
		for (int h = 0; h < cows.size(); h++) {
			if (cows[h] == sh[i]) {
				ps.push_back(h);
				isthere = 1;
				break;
			}
		}
		if (!isthere) {
			bool firstj = 0;
			int firstji;
			for (int j = 0; j < cows.size(); j++) {
				if (cows[j] == 0 && !isthere) {
					if (!firstj) {
						firstj = 1;
						firstji = j;
					}
					cows[j] = sh[i];
					ps.push_back(j);
					vector <int> sps;
					sps = ps;
					sort(sps.begin(), sps.end());
					if (sps == ps) {
						break;
					}
					else {
						ps.pop_back();
					}
				}
			}
			if (!firstj) {
				ps.push_back(firstji);
			}
		}
	}

	vector <int> sps;
	sps = ps;

	sort(sps.begin(), sps.end());

	if (sps != ps) {
		return 0;
	}
	else {
		return 1;
	}

}

int main(void)
{
	ifstream fin("milkorder.in");
	ofstream fout("milkorder.out");

	int n, m, k;
	fin >> n >> m >> k;

	vector <int> ms;
	vector <int> C(n);

	fill(C.begin(), C.end(), 0);
	
	for (int i = 0; i < m; i++) {
		int b;
		fin >> b;
		ms.push_back(b);
	}

	for (int i = 0; i < k; i++) {
		int c, p;
		fin >> c >> p;
		C[p-1] = c;
	}

	int p = 0;

	for (int i = 0; i < n; i++) {
		if (C[i] == 0) {
			vector <int> cows;
			cows = C;
			cows[i] = 1;
			bool t = 0;
			t = test(cows, i, ms);
			if (t) {
				if (p == 0) {
					p = i + 1;
				}
				else {
					p = min(p, i + 1);
				}
			}
		}
	}

	fout << p;

	return 0;
}