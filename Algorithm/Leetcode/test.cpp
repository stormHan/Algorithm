/*
	used to test the algorithms
*/

#include <iostream>
#include <vector>
#include <string>

#include "Print.h"

using namespace std;

//test zone


int main()
{
	// set the initialization
	vector<int> test_vec = { 10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8 };

	string version1 = "1";
	string version2 = "0";
	int int_ans; 
	// testing
	
	int_ans = compareVersion(version1, version2);

	// show the answer
	cout << int_ans << endl;
	
	getchar();
	return 0;
}
