#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v{ 1,2,3,4,5,6,7,8,9,10 };

void printstack();

void printvector();

void printqueue() {
	cout <<endl<< "Queue mode" << endl << "Back -> ";


	for (int i = v.size() - 1; i > -1; i--) {
		cout << v[i] << " ";
	}
	cout << "<- Front" << endl;
	cout << "1 for Vector Mode" << endl << "2 for Stack Mode" << endl << "3 to Enqueue Element" << endl << "4 to Dequeue" << endl << "5 to exit" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		printvector();
	}
	else if (x == 2) {
		printstack();
	}
	else if (x == 3) {
		cout << "What element: ";
		int b;
		cin >> b;
		v.push_back(b);
		printqueue();
	}
	else if (x == 4) {
		v.erase(v.begin());
		printqueue();
	}
	else if (x == 5) {
		return;
	}
	else {
		cout << "Please enter a valid command." << endl;
		printqueue();
	}
	return;
}
void printstack() {
	cout << endl << "Stack mode" << endl << "Top -> ";


	for (int i = v.size() - 1; i > -1; i--) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "1 for Queue Mode" << endl << "2 for Vector Mode" << endl << "3 to Push Element" << endl << "4 to Pop" << endl << "5 to exit" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		printqueue();
	}
	else if (x == 2) {
		printvector();
	}
	else if (x == 3) {
		cout << "What element: ";
		int b;
		cin >> b;
		v.push_back(b);
		printstack();
	}
	else if (x == 4) {
		v.pop_back();
		printstack();
	}
	else if (x == 5) {
		return;
	}
	else {
		cout << "Please enter a valid command." << endl;
		printstack();
	}
	return;
}
void printvector() {
	cout << endl << "Vector mode" << endl << "Beginning -> ";

	for (auto i : v) {
		cout << i << " ";
	}
	
	cout << "<- End" << endl;
	cout << "1 for Stack Mode" << endl << "2 for Queue Mode" << endl << "3 to Push_Back Element" << endl << "4 to Pop_Back" << endl << "5 to exit" << endl;

	int x;
	cin >> x;
	if (x == 1) {
		printstack();
	}
	else if (x == 2) {
		printqueue();
	}
	else if (x == 3) {
		cout << "What element: ";
		int b;
		cin >> b;
		v.push_back(b);
		printvector();
	}
	else if (x == 4) {
		v.pop_back();
		printvector();
	}
	else if (x == 5) {
		return;
	}
	else {
		cout << "Please enter a valid command." << endl;
		printvector();
	}
	return;
}

int main(void)
{
	cout << "Program Begin" << endl;
	printvector();
	
	cout << endl << "Program End" << endl;

	system("pause");

	return 0;
}