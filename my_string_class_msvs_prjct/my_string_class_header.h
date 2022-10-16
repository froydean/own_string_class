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
	bool check_for_max_neg_input(const int count);
	void holy_trinity_init(const char* str, const size_t len);
	void clear_inner();
	bool same_string(const char* str) const;

public:

	MyString();
	MyString(const char* user_string);
	MyString(const initializer_list <char> str_as_list);
	MyString(string user_string);
	MyString(const char* user_string, const int count);
	MyString(const int count, const char one_char);
	MyString(const MyString & other);

	~MyString();

	MyString operator+(const MyString & other) const;
	MyString operator+(const char* user_string) const;
	MyString operator+(string user_string) const;
	void operator+=(const char* user_string);
	void operator+=(string user_string);
	void operator=(const char* user_string);
	void operator=(string user_string);
	void operator=(const char sym);
	void operator=(const MyString & other);
	char operator[](const int index) const;
	bool operator>(const MyString & other)const;
	bool operator<(const MyString & other) const;
	bool operator>=(const MyString & other) const;
	bool operator<=(const MyString & other) const;
	bool operator!=(const MyString & other) const;
	bool operator==(const MyString & other) const;
	
	char* c_str() const;
	char* data() const;
	size_t length() const;
	size_t size() const;
	bool empty() const;
	size_t capacity() const;
	
	void shrink_to_fit();
	void clear();

	friend ostream& operator<<(ostream& out, MyString & current_obj);
	friend istream& operator>>(istream& in, MyString & current_obj);

	void insert(const int index, const int count, const char sym);
	void insert(const int index, const char* user_string);
	void insert(const int index, const char* user_string, const int count);
	void insert(const int index, string user_string);
	void insert(const int index, string user_string, const int count);

	void erase(const int index, const int count);

	void append(const int count, const char sym);
	void append(const char* user_string);
	void append(const char* user_string, const int index, const int count);
	void append(string user_string);
	void append(string user_string, const int index, const int count);

	void replace(const int index, const int count, const char* user_string);
	void replace(const int index, const int count, string user_string);

	MyString substr(const int index) const;
	MyString substr(const int index, const int count) const;

	int find(const char* user_string) const;
	int find(const char* user_string, const int index) const;
	int find(string user_string) const;
	int find(string user_string, const int index) const;
	
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