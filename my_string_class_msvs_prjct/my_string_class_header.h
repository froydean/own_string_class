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

	void set_fields_to_zero();
	bool check_for_max_neg_input(int count);
	void holy_trinity_init(char* str, size_t len);
	void clear_inner();
	bool same_string(const char* str);

public:

	MyString();
	MyString(const char* user_string);
	MyString(initializer_list <char> str_as_list);
	MyString(string user_string);
	MyString(const char* user_string, int count);
	MyString(int count, char one_char);
	MyString(const MyString & other);

	~MyString();

	MyString operator+(const MyString & other);
	MyString operator+(const char* user_string);
	MyString operator+(string user_string);
	void operator+=(const char* user_string);
	void operator+=(string user_string);
	void operator=(const char* user_string);
	void operator=(string user_string);
	void operator=(char sym);
	void operator=(const MyString & other);
	char operator[](int index);
	bool operator>(const MyString & other);
	bool operator<(const MyString & other);
	bool operator>=(const MyString & other);
	bool operator<=(const MyString & other);
	bool operator!=(const MyString & other);
	bool operator==(const MyString & other);
	
	char* c_str();
	char* data();
	size_t length();
	size_t size();
	bool empty();
	size_t capacity();
	
	void shrink_to_fit();
	void clear();

	friend ostream& operator<<(ostream& out, MyString & current_obj);
	friend istream& operator>>(istream& in, MyString & current_obj);

	void insert(int index, int count, char sym);
	void insert(int index, const char* user_string);
	void insert(int index, const char* user_string, int count);
	void insert(int index, string user_string);
	void insert(int index, string user_string, int count);

	void erase(int index, int count);

	void append(int count, char sym);
	void append(const char* user_string);
	void append(const char* user_string, int index, int count);
	void append(string user_string);
	void append(string user_string, int index, int count);

	void replace(int index, int count, const char* user_string);
	void replace(int index, int count, string user_string);

	MyString substr(int index);
	MyString substr(int index, int count);

	int find(const char* user_string);
	int find(const char* user_string, int index);
	int find(string user_string);
	int find(string user_string, int index);
	
	void print_debug_info();
};

void run_tests_for_constructors();
void char_array_test();
void init_list_test();
void std_string_test();
void char_n_array_test();
void n_chars_test();
void copy_constr_test();

void run_tests_for_operators();
void opertr_plus();
void opertr_plus_equal();
void opertr_equal();
void opertr_ind();
void opertr_as();

void run_single_tests();

void run_insert_tests();

void run_erase_tests();

void run_append_tests();

void run_replace_tests();

void run_substr_tests();

void run_find_tests();