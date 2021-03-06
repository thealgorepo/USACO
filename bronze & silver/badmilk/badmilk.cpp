#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



struct entry {
	int p, m, t;
};

int main(void)
{
	ifstream fin("badmilk.in");
	ofstream fout("badmilk.out");

	int count = 0;

	int n, m, d, s;
	fin >> n >> m >> d >> s;

	vector<entry> log;
	vector <int> milks;
	vector <pair<int, int>> slog;

	for (int i = 0; i < d; i++) {
		int P, M, T;
		bool j = 0;
		fin >> P >> M >> T;
		log.push_back({ P,M,T });
		if (milks.size() == 0) {
			milks.push_back(M);
			j = 1;
		}

		else {
			for (int i = 0; i < milks.size(); i++) {
				if (milks[i] == M) {
					j = 1;
					continue;
				}
			}
		}
		if (!j) {
			milks.push_back(M);
		}
	}

	for (int i = 0; i < s; i++) {
		int P, T;
		fin >> P >> T;
		slog.push_back(make_pair(P, T));
	}

	for (int i = 0; i < milks.size(); i++) {
		bool l = 0;
		int c = 0;
		int m = milks[i];
		
		vector <pair<int, bool>> npeople;
		for (int i = 0; i < n; i++) {
			npeople.push_back(make_pair(i + 1, 0));
		}
		for (int j = 0; j < log.size(); j++) {
			bool f = 0;
			if (log[j].m == m) {
				c++;
				int t = log[j].t;
				int p = log[j].p;
				for (int k = 0; k < npeople.size(); k++) {
					if (npeople[k].first == p && npeople[k].second) {
						f = 1;
					}
				}

				if (f) {
					c--;
					continue;
				}
				
				for (int h = 0; h < slog.size(); h++) {
					if (p == slog[h].first) {
						if (t >= slog[h].second) {
							l = 1;
							break;
						}
						else {
							npeople[p - 1].second = 1;
							continue;
						}
					}
				}
				if (!f) {
					npeople[p - 1].second = 1;
				}
				if (l) {
					break;
				}
			}
			if (l) {
				break;
			}
		}
		for (int x = 0; x < slog.size(); x++) {
			if (!npeople[slog[x].first - 1].second) {
				l = 1;
			}
		}
		if (l) {
			continue;
		}
		count = max(count, c);
	}

	fout << count << endl;


	return 0;
}