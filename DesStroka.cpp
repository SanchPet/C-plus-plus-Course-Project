#include "DesStroka.h"
#include<iostream>
using namespace std;

bool DesStroka::IsPositive()
{
	if (pointerChar[0] == '-') return false;
	else return true;
}

DesStroka::DesStroka() : Stroka() {
	cout << "Отработал конструктор DesStroka()" << endl;
}

DesStroka::DesStroka(int input) : Stroka(input) {
	cout << "Отработал конструктор DesStroka(int)" << endl;
}

DesStroka::DesStroka(const char* input) : Stroka(input) {
	if ((pointerChar[0] >= '0' && pointerChar[0] <= '9') || (pointerChar[0] =='+') || (pointerChar[0] == '-')) {
		for (size_t i = 1; i < length; i++)
		{
			if ((pointerChar[i] >= '0' && pointerChar[i] <= '9')) {}
			else {
				if (pointerChar) delete[] pointerChar;
				length = 1;
				pointerChar = new char[length + 1];
				pointerChar[0] = '0';
				pointerChar[1] = '\0';
				cout << "Неверный формат десятичной строки" << endl << endl;
				cout << "Отработал конструктор DesStroka(const char*)" << endl;
				return;
			}
		}
	}
	else {
		if (pointerChar) delete[] pointerChar;
		length =1;
		pointerChar = new char[length + 1];
		pointerChar[0] = '0';
		pointerChar[1] = '\0';
		cout << "Неверный формат десятичной строки" << endl << endl;
		cout << "Отработал конструктор DesStroka(const char*)" << endl;
		return;
	}
	cout << "Отработал конструктор DesStroka(const char*)" << endl;
}

DesStroka::DesStroka(const DesStroka& input) : Stroka(input) {
	cout << "Отработал конструктор DesStroka(const DesStroka&)" << endl;
}

DesStroka::~DesStroka()
{
	if (pointerChar) delete[] pointerChar;
	cout << "Отработал деструктор ~DesStroka()" << endl;
}

DesStroka& DesStroka::operator=(const DesStroka& input)
{
	if (&input != this) {
		delete[] pointerChar;
		length = strlen(input.pointerChar);
		pointerChar = new char[length + 1];
		strcpy_s(pointerChar, length + 1, input.pointerChar);
	}
	cout << "Отработал оператор DestStroka::opreator =(const IdentStr&)" << endl;
	return *this;
}

DesStroka operator+(const DesStroka& inputFirst, const DesStroka& inputSecond)
{
	int sum = inputFirst.getvalue() + inputSecond.getvalue();
	DesStroka tmp(strlen(""+sum));
	strcpy_s(tmp.pointerChar, tmp.length + 1, ""+sum);
	cout << "Отработал оператор DesStroka operator+(const DesStroka& inputFirst, const DesStroka& inputSecond)" << endl;
	return tmp;
}

DesStroka operator+(const DesStroka& inputFirst, const char* inputSecond)
{
	int sum = inputFirst.getvalue() + atoi(inputSecond);
	DesStroka tmp(strlen("" + sum));
	strcpy_s(tmp.pointerChar, tmp.length + 1, "" + sum);
	cout << "Отработал оператор DesStroka operator+(const DesStroka& inputFirst, const char* inputSecond)" << endl;
	return tmp;
}

DesStroka operator+(const char* inputFirst, const DesStroka& inputSecond)
{
	int sum = inputSecond.getvalue() + atoi(inputFirst);
	DesStroka tmp(strlen("" + sum));
	strcpy_s(tmp.pointerChar, tmp.length + 1, "" + sum);
	cout << "Отработал оператор DesStroka operator+(const DesStroka& inputFirst, const char* inputSecond)" << endl;
	return tmp;
}
