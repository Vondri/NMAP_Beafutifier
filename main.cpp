#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

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
	class Mod {
	public:
		Code code;
		Mod(Code _code) : code(_code) {}
		friend std::ostream& operator<<(std::ostream& os, const Mod& mod){
			return os << "\33[38;5;" << mod.code << "m";
		}
		
	};
}

std::vector<size_t> get_pos(std::string& str, std::string str_to_find){
	std::vector<size_t> pos_vec;
	size_t pos = str.find(str_to_find, 0);
	while(pos != std::string::npos){
		pos_vec.push_back(pos);
		pos = str.find(str_to_find, pos+1);
	}
	return pos_vec;
}



int main(int argc, char* argv[]) {
	Color::Mod open(Color::FG_LIME);
	Color::Mod filtered(Color::FG_YELLOW);
	Color::Mod closed(Color::FG_RED);
	Color::Mod pink(Color::FG_PURPLE);
	std::string def = "\33[0m";

	int c;
	std::string x = "";
	while((c = getc(stdin)) != EOF) {
	//	std::cout << open << char(c) << "\33[0m";
		x += char(c);
	}

	
	std::string line;
	std::stringstream X(x);
	bool firstChar = true;
	while(getline(X, line, '\n')){
		//std::cout << line << std::endl;
		//std::cout << "--------------------------------------" << std::endl;
		if(line.find("open") != std::string::npos){
			std::cout << open << line << def << std::endl; 
			continue;
		}  

		if(line.find("filtered") != std::string::npos){
			std::cout << filtered << line << def << std::endl;
			continue;
		}  
		size_t pos1 = line.find("|");
		size_t pos2 = line.find(":");
		std::vector<char> v = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
						  '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
						  '-', '_', '=', '+', '[', ']', '{', '}', '\\', '|',
						  ';', ':', '\'', '"', ',', '<', '.', '>', '/', '?',
						  '`', '~'};
		if((line.find("|") != std::string::npos) && (line.find(":") != std::string::npos)){
			//std::cout << line << std::endl;
			firstChar = true;
			for(int i = 0; i < line.size(); i++){

				
				
				if(i >= pos1 && i <= pos2 && firstChar == false && line.find("(RSA)") == std::string::npos && line.find("(ECDSA)") == std::string::npos && line.find("(ED25519)") == std::string::npos){
					std::cout << pink << line[i] << def;
				} else {
					std::cout << def << line[i];
				}
				firstChar = false;
			}
			std::cout << std::endl;
			continue;
		} else {
			std::cout << def << line << std::endl;
		}
		//std::cout << pos1 << " " << pos2 << std::endl;
		//std::cout << def << line << std::endl; 
		
	}
	
	return 0;
}
