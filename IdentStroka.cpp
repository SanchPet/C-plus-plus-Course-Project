#include "IdentStroka.h"
#include<iostream>
using namespace std;

void cat(char* str1, char* str2) {
	while (*str1 != '\0') str1++;
	while (*str1++ = *str2++);
}

char ToUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (char)(ch - 32);
	return ch;
}

IdentStroka::IdentStroka() : Stroka(){
	cout << "��������� ����������� IdentStroka()" << endl;
}

IdentStroka::IdentStroka(char input) : Stroka(input) {
	if ((pointerChar[0] >= 'A' && pointerChar[0] <= 'Z') || (pointerChar[0] >= 'a' && pointerChar[0] <= 'z') || (pointerChar[0]=='_')) {
		pointerChar[0] = ToUpper(pointerChar[0]);
		cout << "��������� ����������� IdentStroka(char)" << endl;
	}
	else {
		if (pointerChar) delete[] pointerChar;
		length = 0;
		pointerChar = new char[length + 1];
		pointerChar[0] = '\0';
		cout << "������������ �������� ��� ��������������" << endl << endl;
		cout << "��������� ����������� IdentStroka(char)" << endl;
	}	
}

IdentStroka::IdentStroka(int input) : Stroka(input)
{
	cout << "��������� ����������� IdentStroka(int)" << endl;
}

IdentStroka::IdentStroka(const char* input) : Stroka(input) {
	if ((pointerChar[0] >= 'A' && pointerChar[0] <= 'Z') || (pointerChar[0] >= 'a' && pointerChar[0] <= 'z') || (pointerChar[0] == '_')) {
		for (size_t i = 0; i < length; i++)
		{
			if ((pointerChar[i] >= 'A' && pointerChar[i] <= 'Z') || (pointerChar[i] >= 'a' && pointerChar[i] <= 'z') || (pointerChar[i] == '_') || (pointerChar[i] >= '0' && pointerChar[i] <= '9')) {}
			else {
				if (pointerChar) delete[] pointerChar;
				length = 0;
				pointerChar = new char[length + 1];
				pointerChar[0] = '\0';
				cout << "������������ �������� ��� ��������������" << endl << endl;
				cout << "��������� ����������� IdentStroka(const char*)" << endl;
				return;
			}
		}
	}
	else {
		if (pointerChar) delete[] pointerChar;
		length = 0;
		pointerChar = new char[length + 1];
		pointerChar[0] = '\0';
		cout << "������������ �������� ��� ��������������" << endl << endl;
		cout << "��������� ����������� IdentStroka(const char*)" << endl;
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		pointerChar[i] = ToUpper(pointerChar[i]);
	}
	cout << "��������� ����������� IdentStroka(const char*)" << endl;
}

IdentStroka::IdentStroka(const IdentStroka& input) : Stroka(input)
{
	cout << "��������� ����������� IdentStroka(const IdentStroka&)" << endl;
}

IdentStroka::~IdentStroka()
{
	if (pointerChar) delete[] pointerChar;
	cout << "��������� ���������� ~IdentStroka()" << endl;
}

IdentStroka& IdentStroka::operator=(const IdentStroka& input)
{
	if (&input != this) {
		delete[] pointerChar;
		length = strlen(input.pointerChar);
		pointerChar = new char[length + 1];
		strcpy_s(pointerChar, length + 1, input.pointerChar);
	}
	cout << "��������� �������� IdentStr::opreator =(const IdentStr&)" << endl;
	return *this;
}

char& IdentStroka::operator[](int index)
{
	if ((index >= 0) && (index <= length))
	{
		cout << "���������� ��������� ��������� IdentStr::operator [](int)" << endl;
		return pointerChar[index];
	}
	else
	{
		cout << "������������ ������. � ��������� ����� ������ ������ ������." << endl << endl;
		return pointerChar[0];
	}
}

IdentStroka operator+(const IdentStroka& inputFrist, const IdentStroka& inputSecond)
{
	IdentStroka tmp(inputFrist.getlen() + inputSecond.getlen());
	strcpy_s(tmp.pointerChar, tmp.length + 1, inputFrist.getstr());
	cat(tmp.pointerChar, inputSecond.getstr());
	cout << "��������� �������� IdentStroka operator + (const IdentStroka&, const IdentStroka&)" << endl;
	return tmp;
}

IdentStroka operator+(const IdentStroka& inputFirst, const char* inputSecond)
{
	IdentStroka tmp((int)(inputFirst.getlen() + strlen(inputSecond)));
	strcpy_s(tmp.pointerChar, tmp.length + 1, inputFirst.getstr());
	cat(tmp.pointerChar, (char*)inputSecond);
	cout << "��������� �������� IdentStroka operator + (const IdentStroka&, const char*)" << endl;
	return tmp;
}

IdentStroka operator+(const char* inputFirst, const IdentStroka& inputSecond)
{
	char* tmp = new char[strlen(inputFirst)+inputSecond.getlen()];
	strcpy_s(tmp, strlen(inputFirst) + 1, inputFirst);
	cat(tmp, inputSecond.pointerChar);
	return tmp;
}


