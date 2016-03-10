// bitset.cpp
// 
// An example of using the C++ bitset class from the STL.
// (c) 2016 zubernetes

#include <iostream>
#include <string>
#include <bitset>

int main() {
	std::bitset<16> foo;
	std::bitset<16> bar (0xfa2);
	std::bitset<16> baz (string("0101111001"));	
	
	std::cout << "foo: " << foo << '\n';
	std::cout << "bar: " << bar << '\n';	
	std::cout << "baz: " << baz << '\n';
	
	return 0;	
}
