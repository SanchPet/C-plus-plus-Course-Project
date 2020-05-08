#pragma once
#include "Stroka.h"
class IdentStroka :
	public Stroka
{
public:
	IdentStroka();
	IdentStroka(char);
	IdentStroka(int);
	IdentStroka(const char*);
	IdentStroka(const IdentStroka&);
	~IdentStroka();

	IdentStroka& operator = (const IdentStroka&);
	char& operator [](int);
	friend IdentStroka operator + (const IdentStroka&, const IdentStroka&);
	friend IdentStroka operator + (const IdentStroka&, const char*);
	friend IdentStroka operator + (const char*, const IdentStroka&);
};

