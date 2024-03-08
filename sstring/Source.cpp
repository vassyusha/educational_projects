#include "sstring.h"
#include <iostream>

int main() {

	sstring s0;

	sstring s1 = "abc";
	sstring s2 = "def";
	s1 += s2;
	s1.print();
	std::cout << s1[2] << " " << s1.size() << std::endl;
	s1[2] = '0';
	s1.printl();
	std::cout << s0.empty() << " " << s1.empty() << std::endl;
	s2 += s1.clear();
	s2.printl();
	sstring s = "abcdef";

	s.substr(1, 3).print();
	s.printl();

	s.insert(2, "aa").print();
	s.insert(2, '0').printl();

	s.erase(2).print();
	s.erase(2, 2).print();

	s = "abcdaabcaaaf";
	std::cout << s.find("aa") << " " << s.find("dd");
	
}