/*
ID: song.ne1
TASK: gift1
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector <pair<string,int>> giving(vector <pair<string,int>> accts, int amnt, int people, vector <int> pos, int giverpos) {
	if (amnt == 0) {
		return accts;
	}
	for (int i = 0; i < people; i++) {
		accts[pos[i]].second += amnt / people;
	}
	if (amnt%people != 0) {
		accts[giverpos].second += amnt % people;
	}
	accts[giverpos].second -= amnt;
	return accts;
}

int main(void)
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int NP;
	fin >> NP;
	vector <string> names;
	vector <pair<string, int>> accts;
	for (int i = 0; i < NP; i++) {
		string name;
		fin >> name;
		names.push_back(name);
		accts.push_back(make_pair(name, 0));
	}
	for (int i = 0; i < NP; i++) {
		string name;
		fin >> name;
		int giver;
		for (int g = 0; g < names.size(); g++) {
			if (name == names[g]) {
				giver = g;
			}
		}
		int amount, people;
		fin >> amount >> people;
		vector <int> pos;
		for (int j = 0; j < people; j++) {
			string nm;
			fin >> nm;
			for (int h = 0; h < names.size(); h++) {
				if (names[h] == nm) {
					pos.push_back(h);
				}
			}
		}
		accts = giving(accts,amount, people, pos, giver);
	}
	for (int i = 0; i < accts.size(); i++) {
		fout << accts[i].first << " " << accts[i].second << "\n";
	}
	return 0;
}