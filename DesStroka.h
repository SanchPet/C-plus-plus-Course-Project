#pragma once
#include "Stroka.h"
class DesStroka :
	public Stroka
{
public:
	bool IsPositive();
	int getvalue() const { return atoi(pointerChar); }

	DesStroka();
	DesStroka(int);
	DesStroka(const char*);
	DesStroka(const DesStroka&);
	~DesStroka();

	DesStroka& operator = (const DesStroka&);
	friend DesStroka operator + (const DesStroka&, const DesStroka&);
	friend DesStroka operator + (const DesStroka&, const char*);
	friend DesStroka operator + (const char*, const DesStroka&);
};

