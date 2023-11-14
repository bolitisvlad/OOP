#include <iostream>

using namespace std;

class MyString {
	char* str = nullptr;
	int len = NULL;
public:
	void setStr(char* str) {
		if (this->str != nullptr)
			delete[] this->str;

		this->str = new char[strlen(str) + 1];
		strcpy_s(this->str, strlen(str) + 1, str);
	}

	void setLen(int len) {
		this->len = len;
	}

	char* getStr() {
		char* cpyStr = new char[strlen(this->str)];
		cpyStr = this->str;
		return cpyStr;
	}

	int getLen() { return this->len; }

	MyString(char* str, int len)
	{
		setStr(str);
		setLen(len);
	}

	MyString(MyString& string) {
		this->setStr(string.str);
		this->setLen(string.len);
	}

	~MyString() {
		delete[] this->str;
	}

	MyString& operator= (const MyString& string);
};

MyString& MyString::operator= (const MyString& string) {
	if (this == &string)
		return *this;

	this->setStr(string.str);
	len = string.len;

	return *this;
}

void main() {
	char* name1 = (char*)"Gregore";
	char* name2 = (char*)"Mihai";
	char* name3 = (char*)"Andrei";

	MyString first(name1, strlen(name1) + 1);
	MyString second(name2, strlen(name2) + 1);
	MyString third(name3, strlen(name3) + 1);

	cout << first.getStr() << endl;
	cout << second.getStr() << endl;
	cout << third.getStr() << endl;
	first = second = third;
	cout << first.getStr() << endl;
	cout << second.getStr() << endl;
	cout << third.getStr() << endl;

	MyString fourth = first;
	cout << endl << fourth.getStr();
}