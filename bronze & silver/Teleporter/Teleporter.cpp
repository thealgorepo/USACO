#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int absol(int x) {
	if (x < 0) {
		return (-x);
	}
	else {
		return x;
	}
}

int main(void)
{
	ofstream fout("teleport.out");
	ifstream fin("teleport.in");
	int start, end, x, y;
	fin >> start >> end >> x >> y;
	int tel1, tel2;
	tel1 = absol(start - x) + absol(end - y);
	tel2 = absol(start - y) + absol(end - x);
	if (absol(start - end) >= tel1 || absol(start - end) >= tel2) {
		if (tel1 >= tel2) {
			fout << tel2;
		}
		else {
			fout << tel1;
		}
	}
	else {
		fout << absol(start - end);
	}
	return 0;
}