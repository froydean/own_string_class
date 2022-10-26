#include "pch.h"
#include "CppUnitTest.h"
#include "../my_string_class_msvs_prjct/my_string_class_header.h"
#include "../my_string_class_msvs_prjct/my_string_class_def.cpp"
#include <iostream>
#define CHECK_DATA_LEN_CAP(str, dat, len, cap) Assert::AreEqual(dat, str.data()); Assert::IsTrue(str.length() == (size_t)len && str.capacity() == (size_t)cap);
#define DEBUG_WITH_LIMITS 0

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MyStringTests)
	{
	public:

		TEST_METHOD(default_constr_test)
		{
			MyString test0_string;
			CHECK_DATA_LEN_CAP(test0_string, NULL, 0, 0)
		}

		TEST_METHOD(char_array_constr_test)
		{
			//MyString test0_string(NULL);
			MyString test1_string("Hello World!");
			CHECK_DATA_LEN_CAP(test1_string, "Hello World!", 12, 13)

			MyString test2_string("");
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)

			MyString test3_string("-");
			CHECK_DATA_LEN_CAP(test3_string, "-", 1, 2)

			//other languages
			MyString test4_string("世界");
			CHECK_DATA_LEN_CAP(test4_string, "世界", 2, 3)

			MyString test5_string("Привет how do you do my fellow kids");
			CHECK_DATA_LEN_CAP(test5_string, "Привет how do you do my fellow kids", 35, 36)

			//what if longer
			MyString test6_string("It's gonna be LEGEN--waitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforit--DARY!!!");
			CHECK_DATA_LEN_CAP(test6_string, "It's gonna be LEGEN--waitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforitwaitforit--DARY!!!", 192, 193)
			
			MyString test7_string("lawy\te\nre\0d!");
			CHECK_DATA_LEN_CAP(test7_string, "lawy\te\nre", 9, 10)
		}

		TEST_METHOD(init_list_constr_test)
		{
			MyString test1_string({ 'l', 'i','s','t' });
			CHECK_DATA_LEN_CAP(test1_string, "list", 4, 5)

			MyString test2_string({ 'l', 'i','s','t','\0','e','n' });
			CHECK_DATA_LEN_CAP(test2_string, "list", 4, 5)

			MyString test3_string({});
			CHECK_DATA_LEN_CAP(test3_string, "", 0, 1)

			MyString test4_string({ 44,127,24,97 });
			CHECK_DATA_LEN_CAP(test4_string, ",a", 4, 5) //del symbol

			//won't compile
			//MyString test5_string({ 'l', 'i','s','t', 2.0, 'nnnn'});
			//MyString test6_string({ 4004,1217,2344,2450,765453});

			MyString test7_string({ 'F' });
			CHECK_DATA_LEN_CAP(test7_string, "F", 1, 2)

			MyString test8_string({ 'b', '\t','a','\n','z', 'i', 'n', 'g', 'a' });
			CHECK_DATA_LEN_CAP(test8_string, "b\ta\nzinga", 9, 10)

			MyString test9_string({ NULL }); //the only NULL that works
			CHECK_DATA_LEN_CAP(test9_string, "", 0, 1)
		}

		TEST_METHOD(std_str_constr_test)
		{
			string test_std_string1 = "Ahoi!";
			MyString test1_string(test_std_string1);
			CHECK_DATA_LEN_CAP(test1_string, "Ahoi!", 5, 6)

			test_std_string1 = "";
			MyString test2_string(test_std_string1);
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)

			test_std_string1 = "A";
			MyString test3_string(test_std_string1);
			CHECK_DATA_LEN_CAP(test3_string, "A", 1, 2)

			//won't compile in unit test but in main program compile and call exeption
			//test_std_string1 = 0;
			//MyString test4_string(test_std_string1);
			//won't compile
			//test_std_string1 = NULL;
			//MyString test5_string(test_std_string1);

			test_std_string1 = "bangtan\tsonyeon\0dan";
			MyString test6_string(test_std_string1);
			CHECK_DATA_LEN_CAP(test6_string, "bangtan\tsonyeon", 15, 16)

			test_std_string1 = "\0";
			MyString test7_string(test_std_string1);
			CHECK_DATA_LEN_CAP(test7_string, "", 0, 1)
		}

		TEST_METHOD(char_n_array_constr_test)
		{
			MyString test1_string("Queen Rihanna", 8);
			CHECK_DATA_LEN_CAP(test1_string, "Queen Ri", 8, 9)

			MyString test2_string("Queen Rihanna", 0);
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)

			MyString test3_string("", 4);
			CHECK_DATA_LEN_CAP(test3_string, NULL, 0, 0)

			MyString test4_string("", 0);
			CHECK_DATA_LEN_CAP(test4_string, "", 0, 1)

			MyString test5_string("Queen\0 Rihanna", 9);
			CHECK_DATA_LEN_CAP(test5_string, NULL, 0, 0)

			MyString test6_string("Queen", -9);
			CHECK_DATA_LEN_CAP(test6_string, NULL, 0, 0)

			MyString test7_string("Queen", ULLONG_MAX);
			CHECK_DATA_LEN_CAP(test7_string, NULL, 0, 0)

			MyString test8_string("Queen", 9);
			CHECK_DATA_LEN_CAP(test8_string, NULL, 0, 0)

#if DEBUG_WITH_LIMITS
			//should set long_string with ullong-2 length
			MyString test9_string("LONG_STRING", ULLONG_MAX - 2);
			CHECK_DATA_LEN_CAP(test6_string, NULL, 0, 0)
#endif

			//won't compile
			//MyString test10_string(NULL, 9);
		}

		TEST_METHOD(n_chars_constr_test)
		{
			//won't compile
			//MyString test10_string(0, '');
			//MyString test10_string(0, NULL);

			MyString test10_string(3, NULL); //the other NULL that works fine
			CHECK_DATA_LEN_CAP(test10_string, "", 0, 1)

			MyString test1_string(10, '!');
			CHECK_DATA_LEN_CAP(test1_string, "!!!!!!!!!!", 10, 11)

			MyString test2_string(40, 'http');
			CHECK_DATA_LEN_CAP(test2_string, "pppppppppppppppppppppppppppppppppppppppp", 40, 41)

			MyString test3_string(14, '\t');
			CHECK_DATA_LEN_CAP(test3_string, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t", 14, 15)

			MyString test4_string(10, '\n');
			CHECK_DATA_LEN_CAP(test4_string, "\n\n\n\n\n\n\n\n\n\n", 10, 11)

			MyString test5_string(0, 'F');
			CHECK_DATA_LEN_CAP(test5_string, "", 0, 1)

			MyString test7_string(4, '\0');
			CHECK_DATA_LEN_CAP(test7_string, "", 0, 1)

			//calls exception too long string
			Assert::ExpectException<exception>([&]{
				MyString test6_string(-30, 'F');
			});

			Assert::ExpectException<exception>([&] {
				MyString test8_string(ULLONG_MAX, 'F');
			});

#if DEBUG_WITH_LIMITS
			Assert::ExpectException<exception>([&] {
				MyString test9_string(ULLONG_MAX - 2, 'F');
			});
#endif
		}

		TEST_METHOD(copy_constr)
		{
			MyString my_string_object1("Yet to come");
			MyString test1_string(my_string_object1);
			CHECK_DATA_LEN_CAP(test1_string, "Yet to come", 11, 12)

			MyString test2_string(test1_string);
			CHECK_DATA_LEN_CAP(test2_string, "Yet to come", 11, 12)

			MyString my_string_object2;
			MyString test3_string(my_string_object2);
			CHECK_DATA_LEN_CAP(test3_string, NULL, 0, 0)

			MyString* my_string_object3 = NULL;
			MyString test4_string(*my_string_object3);
			CHECK_DATA_LEN_CAP(test4_string, NULL, 0, 0);
		}

		TEST_METHOD(op_plus_obj_test)
		{
			MyString test1_string("Bangtan "), test2_string("Sonyeondan"), test3_string;
			test3_string = test1_string + test2_string;
			CHECK_DATA_LEN_CAP(test3_string, "Bangtan Sonyeondan", 18, 19)

			MyString test4_string("Bangtan"), test5_string(""), test6_string;
			test6_string = test4_string + test5_string;
			CHECK_DATA_LEN_CAP(test6_string, "Bangtan", 7, 8)

			MyString test7_string(""), test8_string("Sonyeondan"), test9_string;
			test9_string = test7_string + test8_string;
			CHECK_DATA_LEN_CAP(test9_string, "Sonyeondan", 10, 11)

			MyString test10_string(""), test11_string(""), test12_string;
			test12_string = test10_string + test11_string;
			CHECK_DATA_LEN_CAP(test12_string, NULL, 0, 0)

			MyString test13_string("\0"), test14_string("Sonyeondan"), test15_string;
			test15_string = test13_string + test14_string;
			CHECK_DATA_LEN_CAP(test15_string, "Sonyeondan", 10, 11)

			MyString test16_string("Bangtan"), test17_string("\0"), test18_string;
			test18_string = test16_string + test17_string;
			CHECK_DATA_LEN_CAP(test18_string, "Bangtan", 7, 8)

			MyString test19_string("\0"), test20_string("\0"), test21_string;
			test21_string = test19_string + test20_string;
			CHECK_DATA_LEN_CAP(test21_string, NULL, 0, 0)

			MyString* my_string_object3 = NULL;
			MyString test22_string("Hello"), test23_string;
			test23_string = test22_string + *my_string_object3;
			CHECK_DATA_LEN_CAP(test23_string, NULL, 0, 0);
		}

		TEST_METHOD(op_plus_char_array_test)
		{
			MyString test22_string = ("Bangtan"), test23_string;
			test23_string = test22_string + "Sonyendan";
			CHECK_DATA_LEN_CAP(test23_string, "BangtanSonyendan", 16, 17)

			MyString test24_string = ("\0"), test25_string;
			test25_string = test24_string + "annyeong\0haseyo";
			CHECK_DATA_LEN_CAP(test25_string, "annyeong", 8, 9)
			
			MyString test1_string = (""), test2_string;
			test2_string = test1_string + "";
			CHECK_DATA_LEN_CAP(test2_string, NULL, 0, 0)
		}

		TEST_METHOD(op_plus_str_test)
		{
			MyString test26_string = ("Nanyeun hagsenimnida"), test27_string;
			string str = "!";
			test27_string = test26_string + str;
			CHECK_DATA_LEN_CAP(test27_string, "Nanyeun hagsenimnida!", 21, 22)

			string str2 = "\0";
			test27_string = test26_string + str2;
			CHECK_DATA_LEN_CAP(test27_string, "Nanyeun hagsenimnida", 20, 22)

			//MyString test28_string(NULL), test29_string(NULL), test30_string;
			//test30_string = test28_string + test29_string;
			//MyString test31_string(NULL), test32_string("Hello!"), test33_string;
			//test33_string = test31_string + test32_string;
		}

		TEST_METHOD(op_plus_eq_char_array_test)
		{
			MyString test1_string("Ave");
			test1_string += " Maria";
			CHECK_DATA_LEN_CAP(test1_string, "Ave Maria", 9, 10)

			test1_string += ", Gratia plena!";
			CHECK_DATA_LEN_CAP(test1_string, "Ave Maria, Gratia plena!", 24, 25)

			MyString test2_string;
			//test2_string += NULL;
			test2_string += "Dominus tecum";
			CHECK_DATA_LEN_CAP(test2_string, "Dominus tecum", 13, 14)

			test2_string += "";
			CHECK_DATA_LEN_CAP(test2_string, "Dominus tecum", 13, 14)

			test2_string += "\0";
			CHECK_DATA_LEN_CAP(test2_string, "Dominus tecum", 13, 14)
		}

		TEST_METHOD(op_plus_eq_str_test)
		{
			MyString test3_string("Ave");
			//xstring won't allow assignment zero to string calls exception
			//string  str = NULL;
			string  str = "\0";
			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave", 3, 4)

			str = "";
			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave", 3, 4)

			str = " Maria!";
			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave Maria!", 10, 11)

			str = "\0";
			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave Maria!", 10, 11)

			str = "Dominus tecum";
			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave Maria!Dominus tecum", 23, 24)

			test3_string += str;
			CHECK_DATA_LEN_CAP(test3_string, "Ave Maria!Dominus tecumDominus tecum", 36, 37)
		}

		TEST_METHOD(op_eq_char_array_test)
		{
			MyString test1_string;

			//won't compile
			//test1_string = NULL;

			test1_string = "Hello!";
			CHECK_DATA_LEN_CAP(test1_string, "Hello!", 6, 7)
				 
			test1_string = "Annyeong!";
			CHECK_DATA_LEN_CAP(test1_string, "Annyeong!", 9, 10)

			test1_string = "\0";
			CHECK_DATA_LEN_CAP(test1_string, "", 0, 10)

			MyString test2_string("Ave!");
			test2_string = "Maria!";
			CHECK_DATA_LEN_CAP(test2_string, "Maria!", 6, 7)
		}

		TEST_METHOD(op_eq_str_test)
		{
			MyString test2_string("Ave!");

			string str = "Dominos!";
			test2_string = str;
			CHECK_DATA_LEN_CAP(test2_string, "Dominos!", 8, 9)

			str = "";
			test2_string = str;
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 9)
		}

		TEST_METHOD(op_eq_char_test)
		{
			MyString test3_string;

			test3_string = '\0';
			CHECK_DATA_LEN_CAP(test3_string, NULL, 0, 0)

			test3_string = 'F';
			CHECK_DATA_LEN_CAP(test3_string, "F", 1, 2)

			test3_string = 'NULL';
			CHECK_DATA_LEN_CAP(test3_string, "L", 1, 2)
		}

		TEST_METHOD(op_eq_obj_test)
		{
			MyString test1_string, test2_string;
			test1_string = test2_string;
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			test2_string = "Gracias";
			test1_string = test2_string;
			CHECK_DATA_LEN_CAP(test1_string, "Gracias", 7, 8)

			test1_string = "Thanks";
			test1_string = test2_string;
			CHECK_DATA_LEN_CAP(test1_string, "Gracias", 7, 8)

			MyString* my_string_object3 = NULL;
			test1_string = *my_string_object3;
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)
		}

		TEST_METHOD(op_ind_test)
		{
			MyString test1_string;
			test1_string = "hello";
			Assert::AreEqual('l', test1_string[2]);
			Assert::AreEqual((char)NULL, test1_string[-10]);
			Assert::AreEqual((char)NULL, test1_string[5]);
			Assert::AreEqual((char)NULL, test1_string[10]);
		}

		TEST_METHOD(op_as_test)
		{
			//play with lengths
			//play with ascii
			MyString test1_string, test2_string;
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(false, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(false, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(false, test1_string <= test2_string);

			test2_string = "aaaaaa";
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(false, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(false, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(false, test1_string <= test2_string);

			test1_string = "a";//a==a
			test2_string = "a";
			Assert::AreEqual(true, test1_string == test2_string);
			Assert::AreEqual(false, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(true, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(true, test1_string <= test2_string);

			test1_string = "aaa";//aaa<aaaaaaa...
			test2_string = "aaaaaaaaaaaaaaa";
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(true, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(false, test1_string >= test2_string);
			Assert::AreEqual(true, test1_string < test2_string);
			Assert::AreEqual(true, test1_string <= test2_string);

			test1_string = "ax";//ax>aa
			test2_string = "aa";
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(true, test1_string != test2_string);
			Assert::AreEqual(true, test1_string > test2_string);
			Assert::AreEqual(true, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(false, test1_string <= test2_string);

			test1_string = "aaa";//aaa>aaA
			test2_string = "aaA";
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(true, test1_string != test2_string);
			Assert::AreEqual(true, test1_string > test2_string);
			Assert::AreEqual(true, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(false, test1_string <= test2_string);

			test1_string = "AVE MARIA"; //==
			test2_string = "AVE MARIA";
			Assert::AreEqual(true, test1_string == test2_string);
			Assert::AreEqual(false, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(true, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(true, test1_string <= test2_string);

			test1_string = "";
			test2_string = "";
			Assert::AreEqual(true, test1_string == test2_string);
			Assert::AreEqual(false, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(true, test1_string >= test2_string);
			Assert::AreEqual(false, test1_string < test2_string);
			Assert::AreEqual(true, test1_string <= test2_string);

			test1_string = '\0'; //eq ok, but can't const MyString test1_string = '\0';
			test2_string = "guenchana";
			Assert::AreEqual(false, test1_string == test2_string);
			Assert::AreEqual(true, test1_string != test2_string);
			Assert::AreEqual(false, test1_string > test2_string);
			Assert::AreEqual(false, test1_string >= test2_string);
			Assert::AreEqual(true, test1_string < test2_string);
			Assert::AreEqual(true, test1_string <= test2_string);

			test1_string = "Hello";
			MyString* my_string_object3 = NULL;
			Assert::AreEqual(false, test1_string == *my_string_object3);
			Assert::AreEqual(false, test1_string != *my_string_object3);
			Assert::AreEqual(false, test1_string > *my_string_object3);
			Assert::AreEqual(false, test1_string >= *my_string_object3);
			Assert::AreEqual(false, test1_string < *my_string_object3);
			Assert::AreEqual(false, test1_string <= *my_string_object3);
		}

		TEST_METHOD(single_test)
		{
			//do more pretty
			MyString test1_string("Hello, world!");

			Assert::AreEqual("Hello, world!", test1_string.c_str());
			Assert::AreEqual("Hello, world!", test1_string.data());
			Assert::AreEqual((size_t)13, test1_string.size());
			Assert::AreEqual((size_t)13, test1_string.length());
			Assert::AreEqual((size_t)14, test1_string.capacity());
			Assert::AreEqual(false, test1_string.empty());

			test1_string = "";
			Assert::AreEqual(true, test1_string.empty());

			test1_string = '\0';
			Assert::AreEqual(true, test1_string.empty());
		}

		TEST_METHOD(shrink_test)
		{
			MyString test1_string;
			test1_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			MyString test2_string("\0");
			test2_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)

			test1_string = "Hello";
			test1_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test1_string, "Hello", 5, 6)

			test1_string = "H";
			test1_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test1_string, "H", 1, 2)
			
			test1_string = "Hello, world!";
			test1_string.erase(5, 8);
			test1_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test1_string, "Hello", 5, 6)

			test1_string.clear();
			test1_string.shrink_to_fit();
			CHECK_DATA_LEN_CAP(test1_string, "", 0, 1)
		}

		TEST_METHOD(clear_test)
		{
			MyString test1_string;
			test1_string.clear();
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			MyString test2_string("\0");
			test1_string.clear();
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)
			
			test2_string = "Shut Down";
			test2_string.clear();
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 10)
		}

		TEST_METHOD(cap_test)
		{
			MyString test1_string;
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			MyString test2_string("\0");
			CHECK_DATA_LEN_CAP(test2_string, "", 0, 1)

			test1_string = "Bangtan";
			CHECK_DATA_LEN_CAP(test1_string, "Bangtan", 7, 8)

			test1_string = "tan";
			CHECK_DATA_LEN_CAP(test1_string, "tan", 3, 8)

			test1_string = "Bangtan Sonyeondan";
			CHECK_DATA_LEN_CAP(test1_string, "Bangtan Sonyeondan", 18, 19)

			test1_string.erase(17, 1);
			CHECK_DATA_LEN_CAP(test1_string, "Bangtan Sonyeonda", 17, 19)

			test1_string.clear();
			CHECK_DATA_LEN_CAP(test1_string, "", 0, 19)
		}

		TEST_METHOD(cout_test)
		{
			string expected = "Hello World! 12 13\nString has null pointer\nNULL pointer of object.\n";
			stringstream buffer;
			streambuf* sbuf = cout.rdbuf(); // Save cout's buffer
			cout.rdbuf(buffer.rdbuf()); // Redirect cout to the stringstream buffer

			//test
			MyString test1_string("Hello World!");
			cout << test1_string << endl;

			MyString test2_string;
			cout << test2_string << endl;

			MyString* my_string_object3 = NULL;
			cout << *my_string_object3 << endl;

			// When finished, redirect cout to the original buffer 
			cout.rdbuf(sbuf);
			cout << "std original buffer: \n";
			cout << buffer.get();

			// Test
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(cin_test)
		{
			MyString test1_string;
			istringstream in("HelloWorld!");

			in >> test1_string;
			CHECK_DATA_LEN_CAP(test1_string, "HelloWorld!", 11, 12)

			MyString test2_string("\0");
			istringstream in2("Bang");
			in2 >> test2_string;
			CHECK_DATA_LEN_CAP(test2_string, "Bang", 4, 5)

			istringstream in3("Bangtan");
			in3 >> test2_string;
			CHECK_DATA_LEN_CAP(test2_string, "Bangtan", 7, 8)

			istringstream in4("bts");//impossible to cin empty string
			in4 >> test2_string;
			CHECK_DATA_LEN_CAP(test2_string, "bts", 3, 8)


			string expected = "NULL pointer of object.\n";
			stringstream buffer;
			streambuf* sbuf = cout.rdbuf(); // Save cout's buffer
			cout.rdbuf(buffer.rdbuf()); // Redirect cout to the stringstream buffer

			//test
			MyString* my_string_object3 = NULL;
			cin >> *my_string_object3;

			// When finished, redirect cout to the original buffer 
			cout.rdbuf(sbuf);
			cout << "std original buffer: \n";
			cout << buffer.get();

			// Test
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(ins_char_count_test)
		{
			//NULL sym
			MyString test1_string("Hello, World!");
			
			test1_string.insert(2, 3, '@');
			CHECK_DATA_LEN_CAP(test1_string, "He@@@llo, World!", 16, 17)
			
			test1_string.insert(4, 0, 'F');
			CHECK_DATA_LEN_CAP(test1_string, "He@@@llo, World!", 16, 17)
			
			test1_string.insert(16, 1, 'F');
			CHECK_DATA_LEN_CAP(test1_string, "He@@@llo, World!F", 17, 18)

			test1_string.insert(18, 1, 'F');
			CHECK_DATA_LEN_CAP(test1_string, "He@@@llo, World!F", 17, 18)

			test1_string.insert(16, 4, '\0');
			CHECK_DATA_LEN_CAP(test1_string, "He@@@llo, World!F", 17, 18)

			MyString test2_string;
			
			test2_string.insert(0, 0, 'F');
			CHECK_DATA_LEN_CAP(test2_string, NULL, 0, 0)

			test2_string.insert(1, 0, 'F');
			CHECK_DATA_LEN_CAP(test2_string, NULL, 0, 0)

			test2_string.insert(0, 3, 'F');
			CHECK_DATA_LEN_CAP(test2_string, "FFF", 3, 4)
		}

		TEST_METHOD(ins_char_array_test)
		{
			MyString test2_string("Hello, World!");

			test2_string.insert(0, "STRING");
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(4, "\0");
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(4, "");
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)
			
			test2_string.insert(19, "STRING");
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!STRING", 25, 26)

			test2_string.insert(26, "STRING");
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!STRING", 25, 26)

			MyString test1_string;

			test1_string.insert(1, "FFF");
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			test1_string.insert(0, "FFF");
			CHECK_DATA_LEN_CAP(test1_string, "FFF", 3, 4)

			test1_string.insert(0, "\0");
			CHECK_DATA_LEN_CAP(test1_string, "FFF", 3, 4)
		}

		TEST_METHOD(ins_char_array_count_test)
		{
			MyString test3_string("Hello, World!");
			test3_string.insert(1, "STRING", 3);
			CHECK_DATA_LEN_CAP(test3_string, "HSTRello, World!", 16, 17)

			MyString test2_string("Hello, World!");

			test2_string.insert(0, "STRING",6);
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(4, "\0", 8);
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(4, "", 0);
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(19, "STRING", 0);
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			test2_string.insert(20, "STRING", 3);
			CHECK_DATA_LEN_CAP(test2_string, "STRINGHello, World!", 19, 20)

			MyString test1_string;

			test1_string.insert(1, "FFF", 2);
			CHECK_DATA_LEN_CAP(test1_string, NULL, 0, 0)

			test1_string.insert(0, "FFF", 2);
			CHECK_DATA_LEN_CAP(test1_string, "FF", 2, 3)

			test1_string.insert(0, "\0", 1);
			CHECK_DATA_LEN_CAP(test1_string, "FF", 2, 3)
		}

		TEST_METHOD(ins_str_test)
		{
			string str = "STRinG";
			MyString test4_string("Hello, World!");
			
			test4_string.insert(12, str);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinG!", 19, 20)

			test4_string.insert(12, str);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTRinG!", 25, 26)

			str = "";
			test4_string.insert(12, str);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTRinG!", 25, 26)
		}

		TEST_METHOD(ins_str_count_test)
		{
			string str = "STRinG";
			MyString test4_string("Hello, World!");

			test4_string.insert(12, str, 3);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTR!", 16, 17)

			test4_string.insert(12, str, 6);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTR!", 22, 23)

			str = "";
			test4_string.insert(12, str, 6);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTR!", 22, 23)

			str = "Ave Maria!";
			test4_string.insert(22, str, 10);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTR!Ave Maria!", 32, 33)

			test4_string.insert(22, str, 0);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTR!Ave Maria!", 32, 33)

			test4_string.insert(22, str, -1);
			CHECK_DATA_LEN_CAP(test4_string, "Hello, WorldSTRinGSTR!Ave Maria!", 32, 33)
		}

		TEST_METHOD(erase_test)
		{
			MyString a1("Hello world!");
			
			a1.erase(5, 6);
			CHECK_DATA_LEN_CAP(a1, "Hello!", 6, 13)
			
			a1.erase(12, 6);
			CHECK_DATA_LEN_CAP(a1, "Hello!", 6, 13)
			
			a1.erase(1, 0);
			CHECK_DATA_LEN_CAP(a1, "Hello!", 6, 13)
		}

		TEST_METHOD(ap_char_count_test)
		{
			MyString a1;

			a1.append(3, '!');
			CHECK_DATA_LEN_CAP(a1, "!!!", 3, 4)

			a1.append(3, '@');
			CHECK_DATA_LEN_CAP(a1, "!!!@@@", 6, 7)

			a1.append(0, '@');
			CHECK_DATA_LEN_CAP(a1, "!!!@@@", 6, 7)
		}

		TEST_METHOD(ap_char_array_test)
		{
			MyString a2("\0");

			a2.append("Hello ");
			CHECK_DATA_LEN_CAP(a2, "Hello ", 6, 7)

			a2.append("world");
			CHECK_DATA_LEN_CAP(a2, "Hello world", 11, 12)

			a2.append("");
			CHECK_DATA_LEN_CAP(a2, "Hello world", 11, 12)
		}

		TEST_METHOD(ap_char_array_count_test)
		{
			MyString a3;

			a3.append("Hello world", 0, 6);
			CHECK_DATA_LEN_CAP(a3, "Hello ", 6, 7)

			a3.append("Hello world", 6, 5);
			CHECK_DATA_LEN_CAP(a3, "Hello world", 11, 12)
			
			a3.append("Hello world", 0, 0);
			CHECK_DATA_LEN_CAP(a3, "Hello world", 11, 12)
		}

		TEST_METHOD(ap_str_test)
		{
			MyString a4;
			string s1 = "Hello ", s2 = "world", s3 = "\0";

			a4.append(s1);
			CHECK_DATA_LEN_CAP(a4, "Hello ", 6, 7)

			a4.append(s2);
			CHECK_DATA_LEN_CAP(a4, "Hello world", 11, 12)

			a4.append(s3);
			CHECK_DATA_LEN_CAP(a4, "Hello world", 11, 12)
		}

		TEST_METHOD(ap_str_count_test)
		{
			MyString a5;
			string s3 = "Hello world";

			a5.append(s3, 0, 6);
			CHECK_DATA_LEN_CAP(a5, "Hello ", 6, 7)
			
			a5.append(s3, 6, 5);
			CHECK_DATA_LEN_CAP(a5, "Hello world", 11, 12)

			a5.append(s3, 6, 0);
			CHECK_DATA_LEN_CAP(a5, "Hello world", 11, 12)
		}

		TEST_METHOD(replace_test)
		{
			MyString a1 = "hello amazing world";
			
			a1.replace(6, 7, "wonderful");
			CHECK_DATA_LEN_CAP(a1, "hello wonderful world", 21, 22)

			a1.replace(6, 9, "wonderful");
			CHECK_DATA_LEN_CAP(a1, "hello wonderful world", 21, 22)

			a1.replace(6, 0, "wonderful");
			CHECK_DATA_LEN_CAP(a1, "hello wonderfulwonderful world", 30, 31)

			MyString a2 = "hello amazing world";
			string s1 = "wonderful";
			
			a2.replace(6, 7, s1);
			CHECK_DATA_LEN_CAP(a2, "hello wonderful world", 21, 22)

			a2.replace(6, 0, s1);
			CHECK_DATA_LEN_CAP(a2, "hello wonderfulwonderful world", 30, 31)
			
			a2.replace(35, 7, s1);
			CHECK_DATA_LEN_CAP(a2, "hello wonderfulwonderful world", 30, 31)

			s1 = "\0";
			a2.replace(6, 0, s1);
			CHECK_DATA_LEN_CAP(a2, "hello wonderfulwonderful world", 30, 31)
		}

		TEST_METHOD(substr_test)
		{
			MyString a1 = "hello amazing world", a2;
			
			a2 = a1.substr(6);
			CHECK_DATA_LEN_CAP(a2, "amazing world", 13, 14)

			a2 = a1.substr(0);
			CHECK_DATA_LEN_CAP(a2, "hello amazing world", 19, 20)

			a2 = a1.substr(30);
			CHECK_DATA_LEN_CAP(a2, NULL, 0, 0)

			MyString a3 = "hello amazing world", a4;
			
			a4 = a3.substr(6, 7);
			CHECK_DATA_LEN_CAP(a4, "amazing", 7, 8)

			a4 = a3.substr(6, 0);
			CHECK_DATA_LEN_CAP(a4, NULL, 0, 0)

			a4 = a3.substr(60, 0);
			CHECK_DATA_LEN_CAP(a4, NULL, 0, 0)

			a4 = a3.substr(6, 60);
			CHECK_DATA_LEN_CAP(a4, NULL, 0, 0)

			MyString a5, a6;

			a5 = a6.substr(6);
			CHECK_DATA_LEN_CAP(a5, NULL, 0, 0)
		}

		TEST_METHOD(find_test)
		{
			MyString a = "hello amazing world amazing";
			Assert::AreEqual((size_t)6, a.find("amazing"));
			Assert::AreEqual((size_t)20, a.find("amazing", 7));
			
			string s = "amazing";
			Assert::AreEqual((size_t)6, a.find(s));
			Assert::AreEqual((size_t)20, a.find(s, 7));

			MyString a1;
			Assert::AreEqual((size_t)-1, a1.find("amazing"));
			Assert::AreEqual((size_t)-1, a1.find("amazing", 7));

			Assert::AreEqual((size_t)-1, a1.find(s));
			Assert::AreEqual((size_t)-1, a1.find(s, 7));

			s = "";
			Assert::AreEqual((size_t)-1, a1.find(s));
			Assert::AreEqual((size_t)-1, a1.find(s, 7));
		}

	};
}
