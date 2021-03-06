#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector < vector <pair<char, bool>>> vec;
int n, CurrentArea = 0, CurrentPerimeter = 0, MaxArea = 0, MaxPerimeter = 0;

void Recurring(int c, int d);


int main(void)
{
	ifstream fin("perimeter.in");
	ofstream fout("perimeter.out");

	fin >> n;
	string str;
	getline(cin, str);
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		string ST;
		getline(fin, ST);
		for (auto j : ST) {
			vec[i].push_back(make_pair(j, 0));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CurrentArea = 0;
			CurrentPerimeter = 0;
			if (!vec[i][j].second && vec[i][j].first == '#') {
				Recurring(i, j);
			}
			MaxArea = max(CurrentArea, MaxArea);
			MaxPerimeter = max(CurrentPerimeter, MaxPerimeter);
		}
	}

	fout << MaxArea << " " << MaxPerimeter << endl;

	return 0;
}

void Recurring(int c, int d)
{
	if (c < 0 || c >= n || d < 0 || d >= n || vec[c][d].second) return;
	if (vec[c][d].first == '.') return;

	if (c == 0 || vec[c - 1][d].first == '.') CurrentPerimeter++;
	if (d == 0 || vec[c][d - 1].first == '.') CurrentPerimeter++;
	if (c == n - 1 || vec[c + 1][d].first == '.') CurrentPerimeter++;
	if (d == n - 1 || vec[c][d + 1].first == '.') CurrentPerimeter++;
	CurrentArea++;
	vec[c][d].second = 1;

	Recurring(c, d - 1);
	Recurring(c, d + 1);
	Recurring(c - 1, d);
	Recurring(c + 1, d);
}