#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ifstream fin("cowqueue.in");
	ofstream fout("cowqueue.out");

	int n;

	vector <pair<int, int>> log;

	fin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		fin >> a >> b;
		log.push_back(make_pair(a, b));
	}

	sort(log.begin(), log.end());

	int time = 0;

	for (int i = 0; i < log.size(); i++) {
		if (log[i].first > time) {
			time = log[i].first;
			time += log[i].second;
		}
		else {
			time += log[i].second;
		}
	}

	fout << time << endl;

	return 0;
}