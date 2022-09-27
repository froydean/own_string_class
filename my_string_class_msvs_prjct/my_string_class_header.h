//This file has MyString class and all funcs declaration

#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include <initializer_list>
#include <climits>
using namespace std;

class MyString {

private:

	//ME: do i need do this const char?
	char* head_string;
	size_t string_length;

public:

	MyString();
	MyString(const char* user_string);
	MyString(initializer_list <char> str_as_list);
	MyString(string user_string);
	MyString(const char* user_string, int count);
	MyString(int count, char one_char);
	MyString(const MyString& other);

	~MyString();

	void printDebugInfo();
};

void run_tests_for_constructors();
void char_array_test();
void init_list_test();
void std_string_test();
void char_n_array_test();
void n_chars_test();
void copy_constr_test();