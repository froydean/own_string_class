//This program implements my own class MyString for working with string avoiding STL library
//This file run all tests
//stan bangtan sonyeondan
#include "my_string_class_header.h"

int main() {
	setlocale(LC_ALL, "");

	//run_tests_for_constructors();
	//run_tests_for_operators();
	//run_single_tests();
	//run_insert_tests();
	//run_erase_tests();
	//run_append_tests();
	//run_replace_tests();
	//run_substr_tests();
	//run_find_tests();

	MyString a("sa;odkapokpeokfpeok");
	cout << a << endl;
	a = "a";
	cout << a << endl;
	
	return 0;
}