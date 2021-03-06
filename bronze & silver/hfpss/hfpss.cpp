#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ofstream fout("hps.out");
	ifstream fin("hps.in");

	vector <long long> yet;

	yet.push_back(0);
	yet.push_back(0);
	yet.push_back(0);

	long long n;

	fin >> n;

	for (long long i = 0; i < n; i++) {
		char b;
		fin >> b;
		if (b == 'P') {
			yet[0]++;
		}
		else if (b == 'H') {
			yet[1]++;
		}
		else {
			yet[2]++;
		}
	}

	sort(yet.begin(), yet.end());

	fout << yet[2] + yet[1] << endl;

	return 0;
}