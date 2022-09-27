//This file has all methods of MyString class defined
//Rules as so: if there is \0 in input then first its appearance equals end of the string
//				if 0 is input size of string, empty "" string anyway creates
#include "my_string_class_header.h"

MyString::MyString() {
	this->head_string = NULL;
	this->string_length = 0;
}

MyString::MyString(const char* user_string) {
	if (user_string) {
		this->string_length = strlen(user_string);
		this->head_string = new char[(this->string_length) + 1];
		strcpy(this->head_string, user_string);
	}
	else {
		this->head_string = NULL;
		this->string_length = 0;
	}
	
}

MyString::MyString(initializer_list <char> str_as_list) {
	
	//protection against \0 sym in the middle of the list
	char* tmp = new char[str_as_list.size() + 1];
	copy(str_as_list.begin(), str_as_list.end(), tmp);
	tmp[str_as_list.size()] = '\0';

	this->string_length = strlen(tmp);
	this->head_string = new char[(this->string_length) + 1];
	strcpy(this->head_string, tmp);
	delete[] tmp;
}

MyString::MyString(string user_string) {
	this->string_length = user_string.length();
	this->head_string = new char[(this->string_length) + 1];
	user_string.copy(this->head_string, this->string_length, 0);
	this->head_string[this->string_length] = '\0';
}

MyString::MyString(const char* user_string, int count) {
	//protection against neagtive string size
	if (count < 0) {
		cout << "String with negative size can't be created" << endl;
		this->head_string = NULL;
		this->string_length = 0;
		return;
	}
	//int_max is limit
	if (count == INT_MAX) {
		cout << "String with such big size can't be created" << endl;
		this->head_string = NULL;
		this->string_length = 0;
		return;
	}
	//protection against \0 sym in the middle of the string
	char* tmp = new char[count+1];
	strncpy(tmp, user_string, count);
	tmp[count] = '\0';
	this->string_length = strlen(tmp);
	this->head_string = new char[(this->string_length) + 1];
	strcpy(this->head_string, tmp);
	delete[] tmp;
	
}

MyString::MyString(int count, char one_char) {
	//protection against neagtive string size
	if (count < 0) {
		cout << "String with negative size can't be created" << endl;
		this->head_string = NULL;
		this->string_length = 0;
		return;
	}
	//int_max is limit
	if (count == INT_MAX) {
		cout << "String with such big size can't be created" << endl;
		this->head_string = NULL;
		this->string_length = 0;
		return;
	}
	//protection against \0 sym
	if (one_char) {
		this->string_length = count;
		this->head_string = new char[count + 1];
		for (int i = 0; i < count; i++) {
			this->head_string[i] = one_char;
		}
		this->head_string[count] = '\0';
	}
	else {
		this->string_length = 0;
		this->head_string = new char[(this->string_length) + 1];
		this->head_string[0] = '\0';
	}
	
}

MyString::MyString(const MyString& other) {
	//protection against nullptr other string
	if (other.head_string) {
		this->string_length = other.string_length;
		this->head_string = new char[(this->string_length) + 1];
		strcpy(this->head_string, other.head_string);
	}
	else {
		this->head_string = NULL;
		this->string_length = 0;
	}
}

MyString::~MyString() {
	delete[] this->head_string;
	this->string_length = 0;
}

void MyString::printDebugInfo() {
	if (this->head_string) {
		cout << "String goes: " << this->head_string << endl;
		cout << "Length is: " << this->string_length << endl;
	}
	else {
		cout << "String has null pointer." << endl;
	}
}