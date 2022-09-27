//This file implements tests for each part and each method in it
//Tests has been named by input data
#include "my_string_class_header.h"
#define DEBUG_WITH_LIMITS 0

void run_tests_for_constructors(){
	
	//deafault constructor
	MyString string_no_args;
	string_no_args.printDebugInfo();
	
	char_array_test();
	init_list_test();
	std_string_test();
	char_n_array_test();
	n_chars_test();
	copy_constr_test();
}

void char_array_test() {
	MyString test0_string(NULL);
	test0_string.printDebugInfo();
	MyString test1_string("Hello World!");
	test1_string.printDebugInfo();
	MyString test2_string("");
	test2_string.printDebugInfo();
	MyString test3_string("-");
	test3_string.printDebugInfo();
	//other languages
	MyString test4_string("世界");
	test4_string.printDebugInfo();
	MyString test5_string("Привет how do you do my fellow kids");
	test5_string.printDebugInfo();
	//what if longer
	MyString test6_string("It's gonna be LEGEN--waitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforit--DARY!!!");
	test6_string.printDebugInfo();
	MyString test7_string("lawy\te\nre\0d!");
	test7_string.printDebugInfo();
}
void init_list_test() {
	MyString test1_string({ 'l', 'i','s','t' });
	test1_string.printDebugInfo();
	MyString test2_string({ 'l', 'i','s','t','\0','e','n'});
	test2_string.printDebugInfo();
	MyString test3_string({});
	test3_string.printDebugInfo();
	MyString test4_string({ 44,127,24,97 });
	test4_string.printDebugInfo();
	//won't compile
	// MyString test5_string({ 'l', 'i','s','t', 2.0, 'nnnn'});
	//test5_string.printDebugInfo();
	//MyString test6_string({ 4004,1217,2344,2450,765453});
	//test6_string.printDebugInfo();
	MyString test7_string({'F'});
	test7_string.printDebugInfo();
	MyString test8_string({ 'b', '\t','a','\n','z', 'i', 'n', 'g', 'a'});
	test8_string.printDebugInfo();
}

void std_string_test() {
	string test_std_string1 = "Ahoi!";
	MyString test1_string(test_std_string1);
	test1_string.printDebugInfo();
	test_std_string1 = "";
	MyString test2_string(test_std_string1);
	test2_string.printDebugInfo();
	test_std_string1 = "A";
	MyString test3_string(test_std_string1);
	test3_string.printDebugInfo();
	//won't allow assignment zero to string calls exception
	//string test_std_string2 = 0;
	//MyString test4_string(test_std_string2);
	//test4_string.printDebugInfo();
	//string test_std_string3 = NULL;
	//MyString test5_string(test_std_string3);
	//test5_string.printDebugInfo();
	test_std_string1 = "bangtan\tsonyeon\0dan";
	MyString test6_string(test_std_string1);
	test6_string.printDebugInfo();
}

void char_n_array_test() {
	//implement this
	MyString test1_string("Queen Rihanna",8);
	test1_string.printDebugInfo();
	MyString test2_string("Queen Rihanna", 0);
	test2_string.printDebugInfo();
	MyString test3_string("", 4);
	test3_string.printDebugInfo();
	MyString test4_string("", 0);
	test4_string.printDebugInfo();
	MyString test5_string("Queen\0 Rihanna", 9);
	test5_string.printDebugInfo();
	MyString test6_string("Queen", -9);
	test6_string.printDebugInfo();
	MyString test7_string("Queen", INT_MAX);
	test7_string.printDebugInfo();
	MyString test8_string("Queen", 9);
	test8_string.printDebugInfo();
#if DEBUG_WITH_LIMITS
	MyString test9_string("Queen", INT_MAX - 1);
	test9_string.printDebugInfo();
#endif
}

void n_chars_test() {
	MyString test1_string(10, '!');
	test1_string.printDebugInfo();
	MyString test2_string(40, 'http');
	test2_string.printDebugInfo();
	MyString test3_string(14, '\t');
	test3_string.printDebugInfo();
	MyString test4_string(10, '\n');
	test4_string.printDebugInfo();
	MyString test5_string(0, 'F');
	test5_string.printDebugInfo();
	MyString test6_string(-1, 'F');
	test6_string.printDebugInfo();
	MyString test7_string(4, '\0');
	test7_string.printDebugInfo();
	MyString test8_string(INT_MAX, 'F');
	test8_string.printDebugInfo();
#if DEBUG_WITH_LIMITS
	MyString test9_string(INT_MAX-1, 'F');
	test9_string.printDebugInfo();
#endif
}

void copy_constr_test() {
	MyString my_string_object1("Yet to come");
	MyString test1_string(my_string_object1);
	test1_string.printDebugInfo();
	MyString test2_string(test1_string);
	test2_string.printDebugInfo();
	MyString my_string_object2;
	MyString test3_string(my_string_object2);
	test3_string.printDebugInfo();
}