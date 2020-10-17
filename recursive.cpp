#include <iostream>
#include <vector>
#include <string>
using namespace std;



bool isSubStr(string s1, string s2, int m, int n) { 
	// Base Cases 
    if (m == 0) return true; 
	if (n == 0) return false; 

	// If last characters of two strings are matching 
	if (s1[m-1] == s2[n-1]) 
		return isSubStr(s1, s2, m-1, n-1); 

	// If last characters are not matching 
	return isSubStr(s1, s2, m, n-1); 
}


void contain(vector<string> & input) {
	int inputSize = input.size();
	cout << "----------------" << endl;
	for(int i =0; i < inputSize; i++) {
		cout << input.at(i) << ": ";
		for (int j = i+1; j < inputSize; j++) {
			if (isSubStr(input[i], input[j], input[i].size(), input[j].size())) {
				cout << input[j] << ", ";
			}
		}
		cout << endl;
	}
}


int main(int argc, char const *argv[]){
	if (argc != 2) {
		cout << "Need a input to represent the number of input strings." << endl;
	}
	vector<string> input;
	string str;
	cout << "Input your strings: " << endl;
	for (int i = 0; i < stoi(argv[1]); i++) {
		getline(cin, str);
		input.push_back(str);
	}
	contain(input);
	return 0;
}

