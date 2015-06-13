#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

void permutations(string prefix, string str) 
{
	if(str.size() == 0) {
		cout << prefix << " ";
		return;
	} else {
		for(int i=0; i < str.size(); ++i) {
			// cout << str.substr(0, i) << "|" << str.substr(i+1, str.size()) << endl;
			permutations(prefix + str[i], str.substr(0, i) + str.substr(i+1, str.size()));
		}
	}
}

int main() {
	
	string start = "abcd";
	
	permutations("", start);


	return 0;
}