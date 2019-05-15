// Class_string.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>
using namespace std;


int main(){

	MyString s = "hello, world!";
	MyString s1("beautiful");
	MyString beautiful("beautiful");
	MyString s2;
	cin >> s2;
	cout << s1;
	cout << "\n";
	cout << s;
	cout << "\n";
	cout << s.FindSubString(s2)<<endl;  
	cout << "\n";
	cout << s.insertStr(s1, 6) << endl;
	cout << "\n";
	cout << s2 + s1;
	if (s > s1) cout << endl << s << " > " << s1 << endl; 
	if (s2 < s1) cout << endl << s2 << " < " << s1 << endl;
	if (beautiful == s1) cout << endl << beautiful << " = " << s1 << endl;
	s2 = s1;
	cout << s2 << endl;;
	system("pause");
}

