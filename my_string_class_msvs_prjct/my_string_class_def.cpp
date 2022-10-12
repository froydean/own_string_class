//This file has all methods of MyString class defined
//Rules as so: if there is \0 in input then first its appearance equals end of the string
//				if 0 is input size of string, empty "" string anyway creates
//				if NULL is a parametr for creation, strings with null pointer anyway creates
//				if NULL -> totally len = 0, but if len = DOES NOT means it is NULL
//				insert /0 works as erase
//				/n/t are not supposed to be in here
#include "my_string_class_header.h"

MyString::MyString() {
	this->head_string = NULL;
	this->string_length = 0;
}

MyString::MyString(const char* user_string) {
	if (user_string) {
		holy_trinity_init((char*)user_string, strlen(user_string));
	}
	else {
		set_fields_to_zero();
	}
}

MyString::MyString(initializer_list <char> str_as_list) {
	//protection against \0 sym in the middle of the list
	char* tmp = new char[str_as_list.size() + 1];
	copy(str_as_list.begin(), str_as_list.end(), tmp);
	tmp[str_as_list.size()] = '\0';
	holy_trinity_init(tmp, strlen(tmp));
	delete[] tmp;
}

MyString::MyString(string user_string) {
	this->string_length = user_string.length();
	this->head_string = new char[(this->string_length) + 1];
	user_string.copy(this->head_string, user_string.length(), 0);
	this->head_string[this->string_length] = '\0';
}

MyString::MyString(const char* user_string, int count) {
	if (check_for_max_neg_input(count)) return;
	if (user_string == NULL) {
		set_fields_to_zero();
		return;
	}
	//protection against \0 sym in the middle of the string
	char* tmp = new char[count+1];
	strncpy(tmp, user_string, count);
	tmp[count] = '\0';
	holy_trinity_init(tmp, strlen(tmp));
	delete[] tmp;	
}

MyString::MyString(int count, char one_char) {
	if (check_for_max_neg_input(count)) return;
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
		holy_trinity_init(other.head_string, other.string_length);
	}
	else {
		set_fields_to_zero();
	}
}

MyString::~MyString() {
	delete[] this->head_string;
	this->string_length = 0;
}

void MyString::print_debug_info() {
	if (this->head_string) {
		cout << "String goes: " << this->head_string << endl;
		cout << "Length is: " << this->string_length << endl;
	}
	else {
		cout << "String has null pointer." << endl;
	}
}
//do all help funcs private/protected
void MyString::set_fields_to_zero() {
	this->head_string = NULL;
	this->string_length = 0;
}

bool MyString::check_for_max_neg_input(int count) {
	//protection against neagtive string size
	if (count < 0) {
		cout << "String with negative size can't be created." << endl;
		set_fields_to_zero();
		return 1;
	}
	//int_max is limit
	if (count == INT_MAX) {
		cout << "String with such big size can't be created." << endl;
		set_fields_to_zero();
		return 1;
	}
	return 0; //all ok
}

void MyString::holy_trinity_init(char* str, size_t len) {
	this->string_length = len;
	this->head_string = new char[len + 1];
	strcpy(this->head_string, str);
}

MyString MyString::operator+(const MyString& other) {
	if (other.head_string == NULL)return *this;
	MyString tmp;
	if (this->head_string) {
		tmp.string_length = this->string_length + other.string_length;
		tmp.head_string = new char[tmp.string_length + 1];
		strcpy(tmp.head_string, this->head_string);
		strcat(tmp.head_string, other.head_string);
	}else{
		tmp.string_length = other.string_length;
		tmp.head_string = new char[tmp.string_length + 1];
		strcpy(tmp.head_string, other.head_string);
	}
	return tmp;
}

MyString MyString::operator+(const char* user_string) {
	if (user_string == NULL) return *this;
	MyString tmp;
	if (this->head_string) {
		tmp.string_length = this->string_length + strlen(user_string);
		tmp.head_string = new char[tmp.string_length + 1];
		strcpy(tmp.head_string, this->head_string);
		strcat(tmp.head_string, user_string);
	}
	else {
		tmp.string_length = strlen(user_string);
		tmp.head_string = new char[tmp.string_length + 1];
		strcpy(tmp.head_string, user_string);
	}
	return tmp;
}

MyString MyString::operator+(string user_string) {
	MyString tmp;
	if (this->head_string) {
		tmp.string_length = this->string_length + user_string.length();
		tmp.head_string = new char[tmp.string_length + 1];
		strncpy(tmp.head_string, this->head_string, this->string_length);
		user_string.copy(&tmp.head_string[this->string_length], user_string.length(), 0);
		tmp.head_string[tmp.string_length] = '\0';
	}
	else {
		tmp.string_length = user_string.length();
		tmp.head_string = new char[tmp.string_length + 1];
		user_string.copy(&tmp.head_string[0], user_string.length(), 0);
		tmp.head_string[tmp.string_length] = '\0';
	}
	return tmp;
}

void MyString::operator+=(const char* user_string) {
	if (user_string == NULL) return;
	if (this->head_string) {
		this->string_length += strlen(user_string);;
		if (this->head_string = (char*)realloc(this->head_string, (this->string_length + 1) * sizeof(char))) {
			strcat(this->head_string, user_string);
		}
		else {
			cout << "Memory allocation failed." << endl;
			set_fields_to_zero();
		}
	}
	else {
		if (user_string) {
			holy_trinity_init((char*)user_string, strlen(user_string));
		}
	}
}

void MyString::operator+=(string user_string) {
	this->operator+=((const char*)user_string.c_str());
}

void MyString::operator=(const char* user_string) {
	if (this->head_string) {
		//change to clear
		delete[] this->head_string;
		this->head_string = NULL;
		this->string_length = 0;
	}
	if (user_string) {
		holy_trinity_init((char*)user_string, strlen(user_string));
	}
	else {
		set_fields_to_zero();
	}
}

void MyString::operator=(string user_string) {
	this->operator=((const char*)user_string.c_str());
}

void MyString::operator=(char sym) {
	if (sym == NULL) return;
	if (this->head_string) {
		clear();
	}
	holy_trinity_init(&sym, 1);
}

void MyString::operator=(const MyString& other) {
	if (this->head_string) {
		clear();
	}
	if (other.head_string) {
		holy_trinity_init((char*)other.head_string, strlen(other.head_string));
	}
	else {
		set_fields_to_zero();
	}
}

//returns NULL if unsuccessfull
char MyString::operator[](int index) {
	if (index < 0) {
		cout << "Negative index unacceptable." << endl;
		return NULL;
	} else if (index >= this->string_length) {
		cout << "Index is out of range." << endl;
		return NULL;
	}
	else {
		return this->head_string[index];
	}
}

//thin about -1 as a result
bool MyString::operator> (const MyString & other) {
	if (this->head_string && other.head_string) {
		return !operator<=(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator< (const MyString & other) {
	if (this->head_string && other.head_string) {
		return !operator>=(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator>= (const MyString & other) {
	if (this->head_string && other.head_string) {
		for (int i = 0; i < other.string_length; i++) {
			if (this->head_string[i] < other.head_string[i]) return false;
		}
		return true;
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator<= (const MyString & other) {
	if (this->head_string && other.head_string) {
		for (int i = 0; i < this->string_length; i++) {
			if (this->head_string[i] > other.head_string[i]) return false;
		}
		return true;
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator!= (const MyString & other) {
	if (this->head_string && other.head_string) {
		return !operator==(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator== (const MyString & other) {
	if (this->head_string && other.head_string) {
		if (this->string_length != other.string_length) return false;
		for (int i = 0; i < other.string_length; i++)
			if (this->head_string[i] != other.head_string[i])
				return false;
		return true;
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

char* MyString::c_str() {
	return this->head_string;
}

char* MyString::data() {
	return this->head_string;
}

size_t MyString::length() {
	return this->string_length;
}

size_t MyString::size() {
	return this->string_length;
}

bool MyString::empty() {
	if (this->string_length) return false;
	return true;
}

size_t MyString::capacity() {
	//return this->string_length+1; //or do field capacity
	//0 means bad ptr
	if (this->head_string) {
		return _msize(this->head_string) / sizeof(char);
	}
	else {
		cout << "String has null pointer." << endl;
		return 0;
	}
}

void MyString::shrink_to_fit() {
	//check if one last byte do or do not lost while realloc
	//null ptr
	this->head_string = (char*)realloc(this->head_string, sizeof(char) * (this->string_length+1));
	this->head_string[this->string_length] = '\0';
}

void MyString::clear() {
	delete[] this->head_string;
	this->head_string = NULL;
	this->string_length = 0;
}

void MyString::clear2() {
	strcpy(this->head_string, "\0");
	this->string_length = 0;
}


ostream& operator<<(ostream & out, MyString & current_obj){
	if (current_obj.head_string) {
		out << current_obj.head_string<<" "<<current_obj.string_length<<" "<< current_obj.capacity();
	}else
		out << "String has null pointer";
	return out;
}

istream& operator>>(istream& in, MyString & current_obj){
	current_obj.head_string = new char[INT_MAX];
	in >> current_obj.head_string;
	current_obj.string_length = strlen(current_obj.head_string);
	current_obj.head_string = (char*)realloc(current_obj.head_string, (current_obj.length() + 1) * sizeof(char));
	current_obj.head_string[current_obj.length()] = '\0';
	return in;
}

void MyString::insert(int index, int count, char sym) {
	if (index>=0 && count>=0) {
		if (count == 0) return;
		if (index > this->string_length) {
			cout << "Index is out of range" << endl;
			return;
		}
		if (sym == '/0') {
			//change to erase
			char* buf = (char*)malloc((index + 1) * sizeof(char));
			strncpy(buf, this->head_string, index);
			buf[index] = '\0';
			*this = (const char*)buf;
			free(buf);
			return;
		}
		char* buf = (char*)malloc((this->string_length + count + 1) * sizeof(char));
		strncpy(buf, this->head_string, index);
		for (int i = index; i < count + index; i++) {
			buf[i] = sym;
		}
		memcpy((buf + index + count), (this->head_string + index), (this->string_length - index));
		buf[this->string_length + count] = '\0';
		*this = (const char*)buf;
		free(buf);
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}

void MyString::insert(int index, const char* user_string) {
	if (index >= 0) {
		if (user_string == NULL || user_string == "") return;
		if (index > this->string_length) {
			cout << "Index is out of range" << endl;
			return;
		}
		if (user_string == "/0") {
			//change to erase
			char* buf = (char*)malloc((index+1) * sizeof(char));
			strncpy(buf, this->head_string, index);
			buf[index] = '\0';
			*this = (const char*)buf;
			free(buf);
			return;
		}
		int count = strlen(user_string);
		char* buf = (char*)malloc((this->string_length + count + 1) * sizeof(char));
		strncpy(buf, this->head_string, index);
		for (int i = index, k = 0; i < count + index; i++, k++) {
			buf[i] = user_string[k];
		}
		memcpy((buf + index + count), (this->head_string + index), (this->string_length - index));
		buf[this->string_length + count] = '\0';
		*this = (const char*)buf;
		free(buf);
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}

void MyString::insert(int index, const char* user_string, int count) {
	if (index >= 0 && count >=0) {
		if (user_string == NULL || user_string == "" || count == 0) return;
		if (index > this->string_length) {
			cout << "Index is out of range" << endl;
			return;
		}
		if (user_string[0] == '/0') {
			//change to erase
			char* buf = (char*)malloc((index + 1) * sizeof(char));
			strncpy(buf, this->head_string, index);
			buf[index] = '\0';
			*this = (const char*)buf;
			free(buf);
			return;
		}
		char* buf = (char*)malloc((this->string_length + count + 1) * sizeof(char));
		strncpy(buf, this->head_string, index);
		for (int i = index, k = 0; i < count + index; i++, k++) {
			buf[i] = user_string[k];
		}
		memcpy((buf + index + count), (this->head_string + index), (this->string_length - index));
		buf[this->string_length + count] = '\0';
		*this = (const char*)buf;
		free(buf);
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}

void MyString::insert(int index, string user_string) {
	insert(index, user_string.c_str());
}

void MyString::insert(int index, string user_string, int count) {
	insert(index, user_string.c_str(), count);
}

void MyString::erase(int index, int count) {
	if (index >= 0 && count >= 0) {
		if (count == 0)return;
		if (index >= this->string_length) { //NOTE: >=!!!
			cout << "Index is out of range" << endl;
			return;
		}
		size_t newLen = this->string_length - count;
		char* buf = new char[newLen + 1];
		strncpy(buf, this->head_string, index);
		memcpy((buf + index), (this->head_string + index + count), (this->string_length - index-count));
		buf[newLen] = '\0';
		strcpy(this->head_string,buf);
		this->string_length = newLen;
		delete[] buf;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
	
}

void MyString::append(int count, char sym) {
	insert(this->string_length, count, sym);
}
void MyString::append(const char* user_string) {
	insert(this->string_length, user_string);

}
void MyString::append(const char* user_string, int index, int count) {
	insert(this->string_length, user_string+index, count);
}
void MyString::append(string user_string) {
	insert(this->string_length, user_string);
}
void MyString::append(string user_string, int index, int count) {
	insert(this->string_length, (user_string.c_str()+index), count);
}

void MyString::replace(int index, int count, const char* user_string) {
	erase(index, count);
	insert(index, user_string);
}
void MyString::replace(int index, int count, string user_string) {
	erase(index, count);
	insert(index, user_string);
}

MyString MyString::substr(int index) {
	if (index >= 0) {
		MyString tmp;
		tmp = *this;
		tmp.erase(0, index);
		tmp.shrink_to_fit();
		return tmp;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}

MyString MyString::substr(int index, int count) {
	if (index >= 0) {
		MyString tmp;
		tmp = *this;
		tmp.erase(0, index);
		tmp.erase(count, this->string_length - index-count);
		tmp.shrink_to_fit();
		return tmp;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}


bool MyString::same_string(const char* str){
	for (int i = 0; i < this->string_length; i++) {
		if (this->head_string[i] != str[i])
			return false;
	}
	return true;
}

int MyString::find(const char* user_string) {

	size_t len = strlen(user_string);
	for (int i = 0; i <= this->string_length - len; i++){
		MyString tmp(this->substr(i, len));
		if (tmp.same_string(user_string))
			return i;
	}
	cout << "String not found." << endl;
	return -1;
}
int MyString::find(const char* user_string, int index) {

	if (index >= 0) {
		size_t len = strlen(user_string);
		if (index > this->string_length - len) {
			cout << "Index is out of range." << endl;
			return -1;
		}
		for (size_t i = index; i <= this->string_length - len; i++)
		{
			MyString tmp(this->substr(i, len));
			if (tmp.same_string(user_string))
				return i;
		}
		return -1;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
		return -1;
	}

}
int MyString::find(string user_string) {
	return find(user_string.c_str());
}
int MyString::find(string user_string, int index) {
	return find(user_string.c_str(), index);
}
