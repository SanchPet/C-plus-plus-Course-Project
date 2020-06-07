#include "Stroka.h"
#include<iostream>

using namespace std;

void Stroka::Diagnostic()
{
	cout << "����������� Stroka(): " << ConstrWithoutArgs << " ���." << endl;
	cout << "����������� Stroka(int): " << ConstrInt << " ���." << endl;
	cout << "����������� Stroka(char): " << ConstrChar << " ���." << endl;
	cout << "����������� Stroka(const char*): " << ConstrConstChar << " ���." << endl;
	cout << "����������� Stroka(const Stroka&): " << ConstrConstStroka << " ���." << endl;
	cout << "-----------------------------------------------" << endl;
}

void Stroka::Show(void)
{
	cout << "�������� ���� pointerChar: " << pointerChar << endl;
	cout << "�������� ���� length: " << length << endl;
	cout << "��������� ����� Stroka::Show" << endl;
}

Stroka::Stroka()
{
	ConstrWithoutArgs++;
	length = 0;
	pointerChar = nullptr;
	cout << "��������� ����������� Stroka()" << endl;
}

Stroka::Stroka(int input)
{
	ConstrInt++;
	length = input;
	pointerChar = new char[length + 1];
	if (input == 0) pointerChar[0] = '\0';
	cout << "��������� ����������� Stroka(int)" << endl;
}

Stroka::Stroka(char input)
{
	ConstrChar++;
	length = 1;
	pointerChar = new char[length + 1];
	pointerChar[0] = input;
	pointerChar[1] = '\0';
	cout << "��������� ����������� Stroka(char)" << endl;
}

Stroka::Stroka(const char* input)
{
	ConstrConstChar++;
	length = strlen(input);
	pointerChar = new char[length + 1];
	strcpy_s(pointerChar, length + 1, input);
	cout << "��������� ����������� Stroka(const char*)" << endl;
}

Stroka::Stroka(const Stroka& input)
{
	ConstrConstStroka++;
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
