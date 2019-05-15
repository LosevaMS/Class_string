
#include <iostream>
using namespace std;

class MyString {
public:
	MyString();
	MyString(char* s);
	MyString(string s);
	char* getStr()const{ return str; };
	void setStr(char* str);
	void setStr(string str);
	MyString insertStr(char* str,int ind);
	MyString operator+(const MyString &_b);

	MyString operator=(const MyString &_b);
	void print()const;
	bool operator==(const MyString &_b);
	bool operator>(const MyString &_b);
	bool operator<(const MyString &_b);
	MyString operator<<(MyString &s);
	size_t FindSubString(MyString &s);
	size_t FindSubString(string s);
	size_t FindSubString(char* s);
	friend std::istream& operator>> (std::istream &in, MyString &point);

	~MyString();
	operator char* ()const;

private:
	char* str;
	char* ustr;
	
};