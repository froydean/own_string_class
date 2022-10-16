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

MyString::MyString(const char* user_string) : MyString(user_string, strlen(user_string)) {
}

MyString::MyString(const initializer_list <char> str_as_list) : MyString(string(str_as_list)) {
}

MyString::MyString(string user_string) : MyString(user_string.c_str()) {
}

MyString::MyString(const char* user_string, const int count) {
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

MyString::MyString(const int count, const char one_char) : MyString (string(count, one_char)) {
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

//do all help funcs private/protected
void MyString::set_fields_to_zero() {
	this->head_string = NULL;
	this->string_length = 0;
}

bool MyString::check_for_max_neg_input(const int count) {
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

void MyString::holy_trinity_init(const char* str, const size_t len) {
	this->string_length = len;
	this->head_string = new char[len + 1];
	strcpy(this->head_string, str);
}

bool MyString::same_string(const char* str) const {
	for (int i = 0; i < this->string_length; i++) {
		if (this->head_string[i] != str[i])
			return false;
	}
	return true;
}

void MyString::clear_inner() {
	delete[] this->head_string;
	this->head_string = NULL;
	this->string_length = 0;
}

MyString MyString::operator+(const MyString& other) const {
	return this->operator+(other.head_string);
}

MyString MyString::operator+(const char* user_string) const {
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

MyString MyString::operator+(string user_string) const {
	return operator+(user_string.c_str());
}

void MyString::operator+=(const char* user_string) {
	this->append(user_string);
}

void MyString::operator+=(string user_string) {
	this->operator+=((const char*)user_string.c_str());
}

void MyString::operator=(const char* user_string) {
	if (this->head_string) {
		clear_inner();
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
	this->operator=(string(1, sym));
}

void MyString::operator=(const MyString& other) {
	this->operator+(other.head_string);
}

//returns NULL if unsuccessfull
char MyString::operator[](const int index) const {
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
bool MyString::operator> (const MyString & other) const {
	if (this->head_string && other.head_string) {
		return !operator<=(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator< (const MyString & other) const {
	if (this->head_string && other.head_string) {
		return !operator>=(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator>= (const MyString & other) const {
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

bool MyString::operator<= (const MyString & other) const {
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

bool MyString::operator!= (const MyString & other) const {
	if (this->head_string && other.head_string) {
		return !operator==(other);
	}
	else {
		cout << "One or both of the strings has null pointer. Compare is not possible." << endl;
		return false;
	}
}

bool MyString::operator== (const MyString & other) const {
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

char* MyString::c_str() const {
	return this->head_string;
}

char* MyString::data() const {
	return this->head_string;
}

size_t MyString::length() const {
	return this->string_length;
}

size_t MyString::size() const {
	return this->string_length;
}

bool MyString::empty() const {
	if (this->string_length) return false;
	return true;
}

size_t MyString::capacity() const {
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

void MyString::insert(const int index, const int count, const char sym) {
	insert(index, string(count, sym));
}

void MyString::insert(const int index, const char* user_string) {
	insert(index, user_string, strlen(user_string));
}

void MyString::insert(const int index, const char* user_string, const int count) {
	if (index >= 0 && count >=0) {
		if (user_string == NULL || user_string == "" || count == 0) return;
		if (index > this->string_length) {
			cout << "Index is out of range" << endl;
			return;
		}
		if (user_string[0] == '/0') {
			//change to erase
			char* buf = new char[index + 1];
			strncpy(buf, this->head_string, index);
			buf[index] = '\0';
			*this = (const char*)buf;
			delete[] buf;
			return;
		}
		char* buf = new char[this->string_length + count + 1];
		strncpy(buf, this->head_string, index);
		for (int i = index, k = 0; i < count + index; i++, k++) {
			buf[i] = user_string[k];
		}
		memcpy((buf + index + count), (this->head_string + index), (this->string_length - index));
		buf[this->string_length + count] = '\0';
		*this = (const char*)buf;
		delete[] buf;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
}

void MyString::insert(const int index, string user_string) {
	insert(index, user_string.c_str());
}

void MyString::insert(const int index, string user_string, const int count) {
	insert(index, user_string.c_str(), count);
}

void MyString::erase(const int index, const int count) {
	if (index >= 0 && count >= 0) {
		if (count == 0)return;
		if (index >= this->string_length) { //NOTE: >=!!!
			cout << "Index is out of range" << endl;
			return;
		}
		size_t new_len = this->string_length - count;
		char* buf = new char[new_len + 1];
		strncpy(buf, this->head_string, index);
		memcpy((buf + index), (this->head_string + index + count), (this->string_length - index-count));
		buf[new_len] = '\0';
		strcpy(this->head_string,buf);
		this->string_length = new_len;
		delete[] buf;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
	}
	
}

void MyString::append(const int count, const char sym) {
	insert(this->string_length, count, sym);
}

void MyString::append(const char* user_string) {
	insert(this->string_length, user_string);

}

void MyString::append(const char* user_string, const int index, const int count) {
	insert(this->string_length, user_string+index, count);
}

void MyString::append(string user_string) {
	insert(this->string_length, user_string);
}

void MyString::append(string user_string, const int index, const int count) {
	insert(this->string_length, (user_string.c_str()+index), count);
}

void MyString::replace(const int index, const int count, const char* user_string) {
	erase(index, count);
	insert(index, user_string);
}

void MyString::replace(const int index, const int count, string user_string) {
	erase(index, count);
	insert(index, user_string);
}

MyString MyString::substr(const int index) const {
	return this->substr(index, this->string_length - index);
}

MyString MyString::substr(const int index, const int count) const {
	if (index >= 0 && count>0) {
		if (count == 0) {
			cout << "One element should be substracted at least." << endl;
			return NULL;
		}
		if (count > this->string_length - index) {
			cout << "Count of substracted elements is out of range." << endl;
			return NULL;
		}
		MyString tmp;
		tmp = *this;
		tmp.erase(0, index);
		tmp.erase(count, this->string_length - index-count);
		tmp.shrink_to_fit();
		return tmp;
	}
	else {
		cout << "Negative arguments not allowed." << endl;
		return NULL;
	}
}

int MyString::find(const char* user_string) const {
	return find(user_string, 0);
}

int MyString::find(const char* user_string, const int index) const {

	if (index >= 0) {
		size_t len = strlen(user_string);
		if (index > this->string_length - len) {
			cout << "Index is out of range." << endl;
			return -1;
		}
		for (size_t i = index; i <= this->string_length - len; i++){
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

int MyString::find(string user_string) const{
	return find(user_string.c_str());
}

int MyString::find(string user_string, const int index) const{
	return find(user_string.c_str(), index);
}
