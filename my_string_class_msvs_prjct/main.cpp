//This program implements my own class MyString for working with string avoiding STL library
//This file run all tests
//stan bangtan sonyeondan
#include "my_string_class_header.h"

int main() {
	setlocale(LC_ALL, "");

	MyString a1 = "hello amazing world", a2;

	a2 = a1.substr(6);

	return 0;
}