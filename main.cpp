#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#include <stdio.h>
#include <unistd.h>


using namespace std;

namespace Color {
	enum Code {
		FG_LIME = 46,
		FG_DARKGREEN = 22,
		FG_GREEN = 76,

		FG_DARKYELLOW = 172,
		FG_YELLOW = 226,
		FG_LIGHTYELLOW = 226,

		FG_DARKRED = 88,
		FG_RED = 160,
		FG_LIGHTRED = 196,

		FG_PURPLE = 129,
		FG_DARKPURPLE = 89,
		FG_LIGHTPURPLE = 171,

		FG_PINK = 219,
		FG_LIGHTPINK = 201
	};
}

int main(int argc, char* argv[]) {
	if(isatty(fileno(stdin))){
		std::cout << "You can run this only using pipe!";
		return 1;
	}
	
	string open = "\33[38;5;" + to_string(Color::FG_LIME) + "m";
	string filtered = "\33[38;5;" + to_string(Color::FG_YELLOW) + "m";
	string closed ="\33[38;5;" + to_string(Color::FG_RED) + "m";
	string pink = "\33[38;5;" + to_string(Color::FG_PURPLE) + "m";
	string def = "\33[0m";

	int c;
	string sScanOutput = "";
	while((c = getc(stdin)) != EOF) { sScanOutput += char(c); }

	
	string line;
	stringstream ssScanOutput(sScanOutput);
	bool firstChar = true;
	while(getline(ssScanOutput, line, '\n')){
		if(line.find("open") != string::npos){
			cout << open << line << def << endl; 
			continue;
		}  

		if(line.find("filtered") != string::npos){
			cout << filtered << line << def << endl;
			continue;
		}  
		size_t pos1 = line.find("|");
		size_t pos2 = line.find(":");
		vector<char> v = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
						  '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
						  '-', '_', '=', '+', '[', ']', '{', '}', '\\', '|',
						  ';', ':', '\'', '"', ',', '<', '.', '>', '/', '?',
						  '`', '~'};
		if((line.find("|") != string::npos) && (line.find(":") != string::npos)){
			firstChar = true;
			for(int i = 0; i < line.size(); i++){
				if(i >= pos1 && i <= pos2 && firstChar == false && line.find("(RSA)") == string::npos && line.find("(ECDSA)") == string::npos && line.find("(ED25519)") == string::npos){
					cout << pink << line[i] << def;
				} else {
					cout << def << line[i];
				}
				firstChar = false;
			}
			cout << endl;
			continue;
		} else {
			cout << def << line << endl;
		}
	}
	return 0;
}
