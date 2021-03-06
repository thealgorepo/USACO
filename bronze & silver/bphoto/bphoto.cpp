#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
	ifstream fin ("bphoto.in");
	ofstream fout("bphoto.out");

	long long slast;
	long long count = 1;
	long long last;
	long long n;

	fin >> n >> slast >> last;

	for (long long i = 2; i < n; i++) {
		if (i == n - 1) {
			count++;
			continue;
		}
		long long c;
		fin >> c;
		if (c == 0) {
			continue;
		}
		long long b = min(slast, c);
		b *= 2;
		long long a = max(slast, c);
		if (b < a) {
			count++;
		}
		slast = last;
		last = c;
	}

	fout << count << endl;

	return 0;
}