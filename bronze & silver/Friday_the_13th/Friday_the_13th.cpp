/*
ID: song.ne1
TASK: friday
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <fstream>
using namespace std;

bool isly(int i) {
	if (i % 100 == 0) {
		if (i % 400 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (i % 4 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

deque <int> sunday(deque <int> days, int start) {
	days[6]++;
	return days;
}

deque <int> normal(deque <int> days, int start) {
	for (int i = 0; i < 7; i++) {
		if (i == start - 1) {
			days[i]++;
			break;
		}
	}
	return days;
}

deque <int> mon(deque <int> days, int start, int m) {
	for (int d = 1; d <= m; d++) {
		if (d == 13) {
			if (start == 7) {
				days = sunday(days, start);
				start = 1;
			}
			else {
				days = normal(days, start);
				start++;
			}
		}
		else {
			if (start == 7) {
				start = 1;
			}
			else {
				start++;
			}
		}
	}
	days[7] = start;
	return days;
}



int main(void)
{

	ofstream fout("friday.out");
	ifstream fin("friday.in");

	int years;
	fin >> years;
	deque <int> days;
	for (int i = 0; i < 7; i++) {
		days.push_back(0);
	}
	days.push_back(1);
	for (int i = 1900; i < 1900 + years; i++) {
		for (int m = 1; m <= 12; m++) {
			if (isly(i)) {
				if (m == 2) {
					days = mon(days, days[7], 29);
				}
				else if (m == 9 || m == 4 || m == 6 || m == 6 || m == 11) {
					days = mon(days, days[7], 30);
				}
				else {
					days = mon(days, days[7], 31);
				}
				
			}
			else {
				if (m == 2) {
					days = mon(days, days[7], 28);
				}
				else if (m == 9 || m == 4 || m == 6 || m == 6 || m == 11) {
					days = mon(days, days[7], 30);
				}
				else {
					days = mon(days, days[7], 31);
				}
			}
		}
	}
	days.push_front(days[6]);
	fout << days[6] << " ";
	for (int i = 0; i < 6; i++) {
		if (i == 5) {
			fout << days[i];
		}
		else {
			fout << days[i] << " ";
		}

	}
	fout << endl;

	return 0;
}