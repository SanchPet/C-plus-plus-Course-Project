#pragma once
#include <vector> 

class Stroka
{
protected:
	int length;
	char* pointerChar;
public:
	char* GetStr() const { cout << "Отработал метод Stroka::getStr()";  return  pointerChar; }
	int GetLen() const { cout << "Отработал метод Stroka::getLen()";  return length; }
	void Show();


	Stroka();
	Stroka(int);
	Stroka(char);
	Stroka(const char*);
	Stroka(const Stroka&);
	~Stroka();
};

