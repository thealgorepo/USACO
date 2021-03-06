#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
using namespace std;


struct cow {
	int x, y,r;
	bool c;
};

bool sortbyx(const cow &a, const cow &b) {
	return (a.x < b.x);
}

cow newCow() {
	cow A;
	cin >> A.x >> A.y >> A.r;
	return A;
}
vector <cow> cows;
vector <cow> ccows;

void call(int og) {
	for (int i = og; i < ccows.size(); i++) {
		if (ccows[i].x > ccows[og].x + ccows[og].r) {
			break;
		}
	}
}

int main(void)
{
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cows.push_back(newCow());
	}

	sort(cows.begin(), cows.end(), sortbyx);

	for (int i = 0; i < cows.size(); i++) {
		ccows = cows;
		call(i);
	}

	return 0;
}