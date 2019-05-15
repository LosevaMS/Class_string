// MyString.h

#include "stdafx.h"
#include "MyString.h"
#include <iostream>

using namespace std;


MyString::MyString() :str(" "){};
	MyString::MyString(char* s){
		str = new char[strlen(s) + 1];
		for (auto i = 0; i < strlen(s)+1; i++)
			str[i] = s[i];
		str[strlen(s)] = '\0';
	}
	MyString::MyString(string s){
		str = new char[s.size() + 1];
		copy(s.begin(), s.end(), str);
		str[s.size()] = '\0';
	}
	
	void MyString::setStr(char* s){
		str = new char[strlen(s) + 1];
		for (auto i = 0; i < strlen(s)+1; i++)
			str[i] = s[i];
		str[strlen(s)] = '\0';
	}
	void MyString::setStr(string s){
		str = new char[s.size() + 1];
		copy(s.begin(), s.end(), str);
		str[s.size()] = '\0';
	}
	istream& operator>> (istream &in, MyString &point)
	{
		int n;
		cout << " Enter the number of symbols... " << endl;
		cin >> n;
		cout << " Enter the string... " << endl;
		char *mas = new char[n];
		for (int i = 0; i < n; i++)
			in >> mas[i];
		mas[n] = '\0';
		point.str = new char[strlen(mas) + 1];
		for (auto i = 0; i < strlen(mas) + 1; i++)
			point.str[i] = mas[i];

		point.str[strlen(mas)] = '\0';
		return in;
	}
	MyString MyString::insertStr(char* s, int ind){
		int Size, Size3;
		Size = strlen(str) + strlen(s) + 1;
		Size3 = strlen(str) - ind;
		char *returnChar = new char[Size];
		char *temp = new char[Size3];
		strncpy(returnChar, str + 0, ind);
		returnChar[ind] = '\0';
		strcat(returnChar, s);
		strncpy(temp, str + ind, strlen(str) - ind);
		temp[strlen(str) - ind] = '\0';
		strcat(returnChar, temp);

		return returnChar;
	}
	MyString 
		MyString::operator+(const MyString &s){
		int Size, Size3;
		if (strlen(str) >= strlen(s)){
			Size = strlen(str) + strlen(s) + 1;
			Size3 = strlen(str) - strlen(s);
			char *returnChar = new char[Size];
			char *temp = new char[Size3];
			strncpy(returnChar, str + 0, strlen(str));
			returnChar[strlen(str)] = '\0';
			strcat(returnChar, s);
			strncpy(temp, str + strlen(str), strlen(str) - strlen(str));
			temp[strlen(str) - strlen(str)] = '\0';
			strcat(returnChar, temp);

			return returnChar;
		}
		if (strlen(str) < strlen(s)){
			Size = strlen(str) + strlen(s) + 1;
			Size3 = strlen(s) - strlen(str);
			char *returnChar = new char[Size];
			char *temp = new char[Size3];
			strncpy(returnChar, str + 0, strlen(str));
			returnChar[strlen(str)] = '\0';
			strcat(returnChar, s);
			strncpy(temp, str + strlen(str), strlen(str) - strlen(str));
			temp[strlen(str) - strlen(str)] = '\0';
			strcat(returnChar, temp);

			return returnChar;
		}
	}
	MyString
		MyString::operator=(const MyString &s){
		int Size, Size3;
		if (strlen(str) >= strlen(s)){
			for (int i = 0; i < strlen(s); i++)
				str[i] = s[i];
			str[strlen(s)] = '\0';
			return str;
		}
		if (strlen(str) < strlen(s)){
			char *returnChar = new char[strlen(s)];
			for (int i = 0; i < strlen(s); i++)
				returnChar[i] = s[i];
			returnChar[strlen(s)] = '\0';

			for (int i = 0; i < strlen(s); i++)
				str[i] = returnChar[i];
			str[strlen(s)] = '\0';
			return str;
		}
		/*if (strlen(str) < strlen(s)){
			Size = strlen(str) + strlen(s) + 1;
			Size3 = strlen(str) - strlen(s);
			char *returnChar = new char[Size];
			char *temp = new char[Size3];
			strncpy(returnChar, str + 0, strlen(str));
			returnChar[strlen(str)] = '\0';
			strcat(returnChar, s);
			strncpy(temp, str + strlen(str), strlen(str) - strlen(str));
			temp[strlen(str) - strlen(str)] = '\0';
			strcat(returnChar, temp);

			return returnChar;
		}*/
	}
	bool
		MyString::operator>(const MyString &_b)
	{
		if (strlen(str) > strlen(_b))
			return true;
		else return false;
	}
	bool
		MyString::operator<(const MyString &_b)
	{
		if (strlen(str) < strlen(_b))
			return true;
		else return false;
	}
	bool
		MyString::operator==(const MyString &_b)
	{
		int cnt = 0;
		if (strlen(str) != strlen(_b)) return false;
		if (strlen(str) == strlen(_b)){
			for (int i = 0; i < strlen(str); i++)
				if (str[i] == _b[i]) cnt++;
		}
		if (cnt == strlen(str)) return true;
		else return false;
	}
	size_t MyString::FindSubString(MyString &s)
	{
		if (strstr((char*)str, (char*)s) != NULL){
			return strstr((char*)str, (char*)s) - str;
		}
		else 
			cout << "string wasn't found "; return 0;
		
	}
	size_t MyString::FindSubString(char* s)
	{
		if (strstr((char*)str, (char*)s) != NULL){
			return strstr((char*)str, (char*)s) - str;
		}
		else
			cout << "string wasn't found "; return 0;

	}
	size_t MyString::FindSubString(string s)
	{
		const char* p1 = s.c_str();
		size_t slen = s.size();
		return strstr((char*)str, p1) - str;
	}
	MyString::~MyString()
	{
		delete[] str;
	}
	void MyString::print()const{
		cout << str;
	}
	MyString
		MyString::operator<<(MyString &s){
		s.print();
		return 0;
	}
	MyString::operator char* ()const
	{
		return getStr();
	}
	


