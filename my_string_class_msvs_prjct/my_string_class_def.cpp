//This file has all methods of MyString class defined
#include "my_string_class_header.h"

MyString::MyString() {
	this->head_string = NULL;
	this->string_length = 0;
}

MyString::MyString(const char* user_string) : MyString(user_string, strlen(user_string)) {
}

MyString::MyString(const initializer_list <char> str_as_list) : MyString(string(str_as_list)) {
}

MyString::MyString(const string user_string) : MyString(user_string.c_str()) {
}

MyString::MyString(const char* user_string, const size_t count) {
	if (is_max_input(count)) return;
	if (user_string == NULL) {
		set_fields_to_zero();
		return;
	}
	if (count > strlen(user_string)) {
		cout << "Count of inserted chars bigger then size of inset string" << endl;
		return;
	}
	//protection against \0 sym in the middle of the string and count>user_string_len
	size_t user_string_len = strlen(user_string);
	if (user_string_len > count) {
		user_string_len = count;
	}
	char* tmp = new char[user_string_len + 1];
	strncpy(tmp, user_string, user_string_len);
	tmp[user_string_len] = '\0';
	holy_trinity_init(tmp, strlen(tmp));
	delete[] tmp;
}

MyString::MyString(const size_t count, const char one_char) : MyString (string(count, one_char)) {
}

MyString::MyString(const MyString& other) {
	//protection against nullptr other object
	if (&other == NULL) {
		set_fields_to_zero();
		return;
	}
	//protection against nullptr other string
	if (other.head_string) {
		holy_trinity_init(other.head_string, other.string_length);
	}
	else {
		set_fields_to_zero();
	}
}

MyString::~MyString() {
	clear_inner();
}

void MyString::set_fields_to_zero() {
	this->head_string = NULL;
	this->string_length = 0;
}

bool MyString::is_max_input(const size_t count) {
	//uint_max is limit
	if (count >= ULLONG_MAX-1) {
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

void MyString::clear_inner() {
	delete[] this->head_string;
	set_fields_to_zero();
}

MyString MyString::operator+(const MyString& other) const {
	//protection against nullptr other object
	if (&other == NULL) {
		MyString tmp;
		return tmp;
	}
	return this->operator+(other.head_string);
}

MyString MyString::operator+(const char* user_string) const {
	if (user_string == NULL) return *this;
	MyString tmp;
	tmp.append(this->head_string);
	tmp.append(user_string);
	return tmp;
}

MyString MyString::operator+(const string user_string) const {
	return operator+(user_string.c_str());
}

void MyString::operator+=(const char* user_string) {
	this->append(user_string);
}

void MyString::operator+=(const string user_string) {
	this->operator+=((const char*)user_string.c_str());
}

void MyString::operator=(const char* user_string) {
	if (user_string && strlen(user_string) > 0) {
		if (this->head_string) {
			if (this->string_length < strlen(user_string)) {
				clear_inner();
				holy_trinity_init(user_string, strlen(user_string));
			}
			else {
				this->string_length = strlen(user_string);
				strcpy(this->head_string, user_string);
			}
		}
		else {
			holy_trinity_init(user_string, strlen(user_string));
		}
	}
	else if (user_string == NULL) {
		clear_inner();
	}
	else {
		if (this->head_string) {
			this->string_length = 0;
			this->head_string[0] = '\0';
		}
		else {
			set_fields_to_zero();
		}
	}
}

void MyString::operator=(const string user_string) {
	this->operator=((const char*)user_string.c_str());
}

void MyString::operator=(const char sym) {
	this->operator=(string(1, sym));
}

void MyString::operator=(const MyString& other) {
	//protection against nullptr other object
	if (&other == NULL) {
		set_fields_to_zero();
		return;
	}
	this->operator=(other.head_string);
}

//returns NULL if unsuccessfull
char MyString::operator[](const size_t index) const {
	if (index >= this->string_length) {
		cout << "Index is out of range." << endl;
		return NULL;
	}
	else {
		return this->head_string[index];
	}
}

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
	if (this->head_string) {
		return _msize(this->head_string) / sizeof(char);
	}
	else {
		cout << "String has null pointer." << endl;
		return 0;
	}
}

void MyString::shrink_to_fit() {
	if (this->head_string) {
		if(this->head_string = (char*)realloc(this->head_string, sizeof(char) * (this->string_length + 1))){
			this->head_string[this->string_length] = '\0';
		}
		else {
			cout << "String has null pointer. Bad memory allocation." << endl;
		}
	}
	else {
		cout << "String has null pointer." << endl;
	}
}

void MyString::clear() {
	if (this->head_string) strcpy(this->head_string, "\0");
	this->string_length = 0;
}

ostream& operator<<(ostream & out, const MyString & current_obj){
	if (current_obj.head_string) {
		out << current_obj.head_string<<" "<<current_obj.string_length<<" "<< current_obj.capacity();
	}else
		out << "String has null pointer";
	return out;
}

istream& operator>>(istream& in, MyString & current_obj){
	char * buf = new char[ULONG_MAX];
	in >> buf;
	if (current_obj.head_string) {
		if (strlen(buf) > current_obj.string_length) {
			current_obj.clear_inner();
			current_obj.head_string = new char[strlen(buf) + 1];
		}
		else {
			current_obj.clear(); //useless
		}
	}
	else {
		current_obj.head_string = new char[strlen(buf) + 1];
	}
	strcpy(current_obj.head_string, buf); //can be replaced with holy_trinity_init();
	current_obj.string_length = strlen(current_obj.head_string);
	delete[] buf;
	return in;
}

void MyString::insert(const size_t index, const size_t count, const char sym) {
	insert(index, string(count, sym));
}

void MyString::insert(const size_t index, const char* user_string) {
	insert(index, user_string, (const int)strlen(user_string));
}

void MyString::insert(const size_t index, const char* user_string, const size_t count) {
	if (user_string == NULL || user_string == "" || count == 0 || user_string[0] == '/0') return;
	if (index > this->string_length) {
		cout << "Index is out of range" << endl;
		return;
	}
	if (count > strlen(user_string)) {
		cout << "Count of inserted chars bigger then size of inset string" << endl;
		return;
	}
	char* buf = new char[this->string_length + count + 1];
	strncpy(buf, this->head_string, index);
	for (size_t i = index, k = 0; i < count + index; i++, k++) {
		buf[i] = user_string[k];
	}
	memcpy((buf + index + count), (this->head_string + index), (this->string_length - index));
	buf[this->string_length + count] = '\0';
	*this = (const char*)buf;
	delete[] buf;
}

void MyString::insert(const size_t index, const string user_string) {
	insert(index, user_string.c_str());
}

void MyString::insert(const size_t index, const string user_string, const size_t count) {
	insert(index, user_string.c_str(), count);
}

void MyString::erase(const size_t index, const size_t count) {
	if (count == 0)return;
	if (index >= this->string_length) { //NOTE: >=!!!
		cout << "Index is out of range" << endl;
		return;
	}
	if (count > this->string_length - index) {
		cout << "Erase more chars than stringhas not possible." << endl;
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

void MyString::append(const size_t count, const char sym) {
	insert(this->string_length, count, sym);
}

void MyString::append(const char* user_string) {
	insert(this->string_length, user_string);
}

void MyString::append(const char* user_string, const size_t index, const size_t count) {
	insert(this->string_length, user_string+index, count);
}

void MyString::append(const string user_string) {
	insert(this->string_length, user_string);
}

void MyString::append(const string user_string, const size_t index, const size_t count) {
	insert(this->string_length, (user_string.c_str()+index), count);
}

void MyString::replace(const size_t index, const size_t count, const char* user_string) {
	erase(index, count);
	insert(index, user_string);
}

void MyString::replace(const size_t index, const size_t count, const string user_string) {
	erase(index, count);
	insert(index, user_string);
}

MyString MyString::substr(const size_t index) const {
	return this->substr(index, this->string_length - index);
}

MyString MyString::substr(const size_t index, const size_t count) const {
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

size_t MyString::find(const char* user_string) const {
	return find(user_string, 0);
}

size_t MyString::find(const char* user_string, const size_t index) const {
	size_t len = strlen(user_string);
	if (index > this->string_length - len) {
		cout << "Index is out of range." << endl;
		return -1;
	}
	for (size_t i = index; i <= this->string_length - len; i++){
		MyString tmp = this->substr(i, len);
		if (tmp == user_string)
			return i;
	}
	return -1;
}

size_t MyString::find(const string user_string) const{
	return find(user_string.c_str());
}

size_t MyString::find(const string user_string, const size_t index) const{
	return find(user_string.c_str(), index);
}
