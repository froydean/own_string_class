#include "my_string_class_header.h"
using namespace std;

class MyString {
public:
	MyString() {
		ch = 'H';
	}
	MyString(char sym) {
		ch = sym;
	}
	char  ch;
};

int main() {
	MyString a;
	a.ch = 'A';
	MyString b('G');
	MyString c;
	cout << a.ch <<b.ch<<c.ch<< endl;
	return 0;
}