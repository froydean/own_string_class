//This file implements tests for each part and each method in it
//Tests has been named by input data
#include "my_string_class_header.h"
#define DEBUG_WITH_LIMITS 0

void run_tests_for_constructors(){
	
	//deafault constructor
	MyString string_no_args;
	string_no_args.print_debug_info();
	
	char_array_test();
	init_list_test();
	std_string_test();
	char_n_array_test();
	n_chars_test();
	copy_constr_test();
}

void char_array_test() {
	MyString test0_string(NULL);
	test0_string.print_debug_info();
	MyString test1_string("Hello World!");
	test1_string.print_debug_info();
	MyString test2_string("");
	test2_string.print_debug_info();
	MyString test3_string("-");
	test3_string.print_debug_info();
	//other languages
	MyString test4_string("世界");
	test4_string.print_debug_info();
	MyString test5_string("Привет how do you do my fellow kids");
	test5_string.print_debug_info();
	//what if longer
	MyString test6_string("It's gonna be LEGEN--waitforitwaitforitwaitforitwaitforitwait\
						foritwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitfor\
						itwaitforitwaitforitwaitforitwaitforitwaitforitwaitforit--DARY!!!");
	test6_string.print_debug_info();
	MyString test7_string("lawy\te\nre\0d!");
	test7_string.print_debug_info();
}

void init_list_test() {
	MyString test1_string({ 'l', 'i','s','t' });
	test1_string.print_debug_info();
	MyString test2_string({ 'l', 'i','s','t','\0','e','n'});
	test2_string.print_debug_info();
	MyString test3_string({});
	test3_string.print_debug_info();
	MyString test4_string({ 44,127,24,97 });
	test4_string.print_debug_info();
	//won't compile
	// MyString test5_string({ 'l', 'i','s','t', 2.0, 'nnnn'});
	//test5_string.print_debug_info();
	//MyString test6_string({ 4004,1217,2344,2450,765453});
	//test6_string.print_debug_info();
	MyString test7_string({'F'});
	test7_string.print_debug_info();
	MyString test8_string({ 'b', '\t','a','\n','z', 'i', 'n', 'g', 'a'});
	test8_string.print_debug_info();
	MyString test9_string({ NULL });
	test9_string.print_debug_info();
}

void std_string_test() {
	string test_std_string1 = "Ahoi!";
	MyString test1_string(test_std_string1);
	test1_string.print_debug_info();
	test_std_string1 = "";
	MyString test2_string(test_std_string1);
	test2_string.print_debug_info();
	test_std_string1 = "A";
	MyString test3_string(test_std_string1);
	test3_string.print_debug_info();
	//won't allow assignment zero to string calls exception
	//string test_std_string2 = 0;
	//MyString test4_string(test_std_string2);
	//test4_string.print_debug_info();
	//string test_std_string3 = NULL;
	//MyString test5_string(test_std_string3);
	//test5_string.print_debug_info();
	test_std_string1 = "bangtan\tsonyeon\0dan";
	MyString test6_string(test_std_string1);
	test6_string.print_debug_info();
}

void char_n_array_test() {
	MyString test1_string("Queen Rihanna",8);
	test1_string.print_debug_info();
	MyString test2_string("Queen Rihanna", 0);
	test2_string.print_debug_info();
	MyString test3_string("", 4);
	test3_string.print_debug_info();
	MyString test4_string("", 0);
	test4_string.print_debug_info();
	MyString test5_string("Queen\0 Rihanna", 9);
	test5_string.print_debug_info();
	MyString test6_string("Queen", -9);
	test6_string.print_debug_info();
	MyString test7_string("Queen", INT_MAX);
	test7_string.print_debug_info();
	MyString test8_string("Queen", 9);
	test8_string.print_debug_info();
#if DEBUG_WITH_LIMITS
	MyString test9_string("Queen", INT_MAX - 1);
	test9_string.print_debug_info();
#endif
	//won't compile
	//MyString test10_string(NULL, 9);
	//test10_string.print_debug_info();
}

void n_chars_test() {
	MyString test1_string(10, '!');
	test1_string.print_debug_info();
	MyString test2_string(40, 'http');
	test2_string.print_debug_info();
	MyString test3_string(14, '\t');
	test3_string.print_debug_info();
	MyString test4_string(10, '\n');
	test4_string.print_debug_info();
	MyString test5_string(0, 'F');
	test5_string.print_debug_info();
	MyString test6_string(-1, 'F');
	test6_string.print_debug_info();
	MyString test7_string(4, '\0');
	test7_string.print_debug_info();
	MyString test8_string(INT_MAX, 'F');
	test8_string.print_debug_info();
#if DEBUG_WITH_LIMITS
	MyString test9_string(INT_MAX-1, 'F');
	test9_string.print_debug_info();
#endif
}

void copy_constr_test() {
	MyString my_string_object1("Yet to come");
	MyString test1_string(my_string_object1);
	test1_string.print_debug_info();
	MyString test2_string(test1_string);
	test2_string.print_debug_info();
	MyString my_string_object2;
	MyString test3_string(my_string_object2);
	test3_string.print_debug_info();
}

void run_tests_for_operators() {
	opertr_plus();
	opertr_plus_equal();
	opertr_equal();
	opertr_ind();
	opertr_as();
}

void opertr_plus() {
	MyString test1_string("Bangtan "), test2_string("Sonyeondan"), test3_string;
	test3_string = test1_string + test2_string;
	test3_string.print_debug_info();
	MyString test4_string("Bangtan"), test5_string(""), test6_string;
	test6_string = test4_string + test5_string;
	test6_string.print_debug_info();
	MyString test7_string(""), test8_string("Sonyeondan"), test9_string;
	test9_string = test7_string + test8_string;
	test9_string.print_debug_info();
	MyString test10_string(""), test11_string(""), test12_string;
	test12_string = test10_string + test11_string;
	test12_string.print_debug_info();
	MyString test13_string("\0"), test14_string("Sonyeandan"), test15_string;
	test15_string = test13_string + test14_string;
	test15_string.print_debug_info();
	MyString test16_string("Bangtan"), test17_string("\0"), test18_string;
	test18_string = test16_string + test17_string;
	test18_string.print_debug_info();
	MyString test19_string("\0"), test20_string("\0"), test21_string;
	test21_string = test19_string + test20_string;
	test21_string.print_debug_info();
	MyString test22_string = ("Bangtan"), test23_string;
	test23_string = test22_string + "Sonyendan";
	test23_string.print_debug_info();
	MyString test24_string = ("\0"), test25_string;
	test25_string = test24_string + "annyeong\0haseyo";
	test25_string.print_debug_info();
	MyString test26_string = ("Nanyeun hagsenimnida"), test27_string;
	string str = "!";
	test27_string = test26_string + str;
	test27_string.print_debug_info();
	string str2 = "\0";
	test27_string = test26_string + str2;
	test27_string.print_debug_info();
	MyString test28_string(NULL), test29_string(NULL), test30_string;
	test30_string = test28_string + test29_string;
	test30_string.print_debug_info();
	MyString test31_string(NULL), test32_string("Hello!"), test33_string;
	test33_string = test31_string + test32_string;
	test33_string.print_debug_info();
}

void opertr_plus_equal() {
	MyString test1_string("Ave");
	test1_string += " Maria";
	test1_string.print_debug_info();
	test1_string += ", Gratia plena!";
	test1_string.print_debug_info();
	MyString test2_string;
	test2_string += NULL;
	test2_string.print_debug_info();
	test2_string += "Dominus tecum";
	test2_string.print_debug_info();
	test2_string += "";
	test2_string.print_debug_info();
	test2_string += "\0";
	test2_string.print_debug_info();
	MyString test3_string("Ave");
	//won't allow assignment zero to string calls exception
	//string  str = NULL;
	string  str = "\0";
	test3_string += str;
	test3_string.print_debug_info();
	str = "";
	test3_string += str;
	test3_string.print_debug_info();
	str = " Maria!";
	test3_string += str;
	test3_string.print_debug_info();
	str = "\0";
	test3_string += str;
	test3_string.print_debug_info();
	str = "Dominus tecum";
	test3_string += str;
	test3_string.print_debug_info();
	test3_string += str;
	test3_string.print_debug_info();
}

void opertr_equal() {
	MyString test1_string;
	//won't compile
	//test1_string = NULL;
	test1_string = "Hello!";
	test1_string.print_debug_info();
	test1_string = "Annyeong!";
	test1_string.print_debug_info();
	test1_string = "\0";
	test1_string.print_debug_info();
	MyString test2_string("Ave!");
	test2_string = "Maria!";
	test2_string.print_debug_info();
	string str = "Dominos!";
	test2_string = str;
	test2_string.print_debug_info();
	string str2 = "";
	test2_string = str2;
	test2_string.print_debug_info();
	MyString test3_string;
	test3_string = '\0'; //null pointer
	test3_string.print_debug_info();
	test3_string = 'F';
	test3_string.print_debug_info();
	test3_string = 'NULL';
	test3_string.print_debug_info();
}

void opertr_ind() {
	MyString test1_string;
	test1_string = "hello";
	cout << test1_string[2] <<endl;
	cout << test1_string[-10] << endl;
	cout << test1_string[5] << endl;
	cout << test1_string[10] << endl;
}

void opertr_as() {
	//play with lengths
	//play with ascii
	MyString test1_string, test2_string;
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test2_string = "aaaaaa";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test1_string = "a";//a==a
	test2_string = "a";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test1_string = "aaa";//aaa<aaaaaaa...
	test2_string = "aaaaaaaaaaaaaaa";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test1_string = "ax";//ax>aa
	test2_string = "aa";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test1_string = "aaa";//aaa>aaA
	test2_string = "aaA";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
	test1_string = "AVE MARIA"; //==
	test2_string = "AVE MARIA";
	cout << (test1_string == test2_string) << endl;
	cout << (test1_string != test2_string) << endl;
	cout << (test1_string > test2_string) << endl;
	cout << (test1_string >= test2_string) << endl;
	cout << (test1_string < test2_string) << endl;
	cout << (test1_string <= test2_string) << endl;
}


void run_single_tests() {
	////do more pretty
	//MyString test1_string("Hello, world!");
	//cout << "String in C goes: " << test1_string.c_str() << endl;
	//cout << "Data of the string: " << test1_string.data() << endl;
	//cout << "Size: " << test1_string.size()<<"\tLength: " << test1_string.length() << "\tCapacitiy: " << test1_string.capacity() << endl;
	//cout << "Is string empty: " << test1_string.empty() << endl;
	////add movement
	//test1_string.shrink_to_fit();
	//cout << "Shinkage is done." << endl << "Size: " << test1_string.size() <<
	//	"\tLength: " << test1_string.length() << "\tCapacitiy: " << test1_string.capacity() << endl;
	//test1_string.clear();
	////calls exception
	////cout << "Clear is done." << endl << "Data: " << test1_string.data() <<
	////	"Size: " << test1_string.size() << "Capacity: " << test1_string.capacity();
	//cout << "Clear is done." << endl;
	//printf_s("Data of the string: %s\n", test1_string.data());
	//printf_s("Size : %i\tLength: %i\tCapacity: %i\n", test1_string.size(), test1_string.length(), test1_string.capacity());
	MyString test("Hello, world!");
	//cout << "\tData: " << test.data() << endl;
	//cout << "Capacitiy: " << test.capacity() << endl;
	////for shrink to fit do all test where malloc/crealloc funcs is
	////realloc does do \0 everywhere?
	//test.clear2();
	//cout <<  "Capacitiy: " << test.capacity() << endl;
	//test.shrink_to_fit();
	///*
	//* shrink to fit nothing change, 1char, 0 value
	//*/
	//cout << "Shrinkage done." << endl << "Capacitiy: " << test.capacity() << endl;
	cout << test << endl;
	MyString test1;
	cin >> test1;
	cout << test1 << endl;
}

void run_insert_tests() {
	//sym null
	//sym ""
	MyString test1_string("Hello, World!");
	test1_string.insert(2,3,'@');
	cout<< test1_string << endl;

	MyString test2_string("Hello, World!");
	test2_string.insert(0, "STRING");
	cout << test2_string << endl;

	MyString test3_string("Hello, World!");
	test3_string.insert(1,"STRING",3);
	cout << test3_string << endl;

	string str = "STRinG";

	MyString test4_string("Hello, World!");
	test4_string.insert(12, str);
	cout << test4_string << endl;

	MyString test5_string("Hello, World!");
	test5_string.insert(13, str, 3);
	cout << test5_string << endl;

}

void run_erase_tests() {
	MyString a1("Hello world!");
	a1.erase(5, 6);
	cout << a1 << endl;
	a1.shrink_to_fit();
	cout << a1 << endl;
}

void run_append_tests() {
	MyString a1;
	a1.clear();
	a1.append(3, '!');
	std::cout << a1 << std::endl;
	a1.append(3, '@');
	std::cout << a1 << std::endl;

	MyString a2;
	a2.clear();
	a2.append("Hello ");
	std::cout << a2 << std::endl;
	a2.append("world");
	std::cout << a2 << std::endl;

	MyString a3;
	a3.clear();
	a3.append("Hello world", 0, 6);
	std::cout << a3 << std::endl;
	a3.append("Hello world", 6, 5);
	std::cout << a3 << std::endl;

	MyString a4;
	std::string s1 = "Hello ", s2 = "world";
	a4.clear();
	a4.append(s1);
	std::cout << a4 << std::endl;
	a4.append(s2);
	std::cout << a4 << std::endl;

	MyString a5;
	std::string s3 = "Hello world";
	a5.clear();
	a5.append(s3, 0, 6);
	std::cout << a5 << std::endl;
	a5.append(s3, 6, 5);
	std::cout << a5 << std::endl;

}

void run_replace_tests() {
	MyString a1 = "hello amazing world";
	std::cout << a1 << std::endl;
	a1.replace(6, 7, "wonderful");
	std::cout << a1 << std::endl;

	MyString a2 = "hello amazing world";
	std::string s1 = "wonderful";
	a2.replace(6, 7, s1);
	std::cout << a2 << std::endl;
}

void run_substr_tests() {
	MyString a1 = "hello amazing world", a2;
	a2 = a1.substr(6);
	std::cout << a2 << std::endl;

	MyString a3 = "hello amazing world", a4;
	a4 = a3.substr(6, 7);
	std::cout << a4 << std::endl;

}

void run_find_tests() {
	MyString a = "hello amazing world amazing";
	int i;
	i = a.find("amazing");
	std::cout << i << std::endl;

	i = a.find("amazing", 7);
	std::cout << i << std::endl;

	std::string s = "amazing";
	i = a.find(s);
	std::cout << i << std::endl;


	i = a.find(s, 7);
	std::cout << i << std::endl;

}