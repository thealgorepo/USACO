#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;


bool iseven(int a) {
	return a % 2 == 0;
}

int main(void)
{
	ifstream fin("geteven.in");
	ofstream fout("geteven.out");

	int var[300][300];

	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		char tvar;
		int val;
		fin >> tvar >> val;
		if (iseven(val)) {
			var[tvar][0]++;
		}
		else {
			var[tvar][1]++;
		}
	}

	int r;

	for (int B = 0; B < 2; B++) {
		for (int E = 0; E < 2; E++) {
			for (int S = 0; S < 2; S++) {
				for (int I = 0; I < 2; I++) {
					for (int G = 0; G < 2; G++) {
						for (int O = 0; O < 2; O++) {
							for (int M = 0; M < 2; M++) {
								if (iseven((B + E + S + S + I + E)*(G + O + E + S) * (M + O + O))) {
									r += var['B'][B] * var['E'][E] * var['S'][S] * var['I'][I] * var['G'][G] * var['O'][O] * var['M'][M];
								}
							}
						}
					}
				}
			}
		}
	}

	fout << r << endl;

	return 0;
}