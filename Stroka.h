#pragma once
#include <vector> 
#include<iostream>
using namespace std;

class Stroka
{
protected:
	int length;
	char* pointerChar;
public:
	char* GetStr() const { cout << "��������� ����� Stroka::getStr() ";  return  pointerChar; }
	int GetLen() const { cout << "��������� ����� Stroka::getLen() ";  return length; }
	void Show();


	Stroka();
	Stroka(int);
	Stroka(char);
	Stroka(const char*);
	Stroka(const Stroka&);
	~Stroka();
};

