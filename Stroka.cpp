#include "Stroka.h"
#include<iostream>
using namespace std;

void Stroka::show(void)
{
	cout << "�������� ���� pointerChar: " << pointerChar << endl;
	cout << "�������� ���� length: " << length << endl;
}



Stroka::Stroka()
{
	length = 0;
	pointerChar = nullptr;
	cout << "��������� ����������� Stroka()" << endl;
}

Stroka::Stroka(int input)
{
	length = input;
	pointerChar = new char[length + 1];
	if (input == 0) pointerChar[0] = '\0';
	cout << "��������� ����������� Stroka(int)" << endl;
}

Stroka::Stroka(char input)
{
	length = 1;
	pointerChar = new char[length + 1];
	pointerChar[0] = input;
	pointerChar[1] = '\0';
	cout << "��������� ����������� Stroka(char)" << endl;
}

Stroka::Stroka(const char* input)
{
	length = strlen(input);
	pointerChar = new char[length + 1];
	strcpy_s(pointerChar, length + 1, input);
	cout << "��������� ����������� Stroka(const char*)" << endl;
}

Stroka::Stroka(const Stroka& input)
{
	length = input.length;
	pointerChar = new char[length + 1];
	strcpy_s(pointerChar, length + 1, input.pointerChar);
	cout << "��������� ����������� Stroka(const Stroka&)" << endl;
}

Stroka::~Stroka()
{
	if (pointerChar) delete[] pointerChar;
	cout << "��������� ���������� ~Stroka()" << endl;
}
