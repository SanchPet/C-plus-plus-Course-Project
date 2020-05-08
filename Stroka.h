#pragma once

class Stroka
{
protected:
	int length;
	char* pointerChar;
public:
	char* getstr() const { return  pointerChar; }
	int getlen() const { return length; }
	void show();

	Stroka();
	Stroka(int);
	Stroka(char);
	Stroka(const char*);
	Stroka(const Stroka&);
	~Stroka();
};

