// Polymorphism.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


class A
{
public:
	virtual int GetInt();	// оголошення віртуальної функції
};
int A::GetInt() { return 1; }	// наявність virtual є зайвою

int main()
{
    return 0;
}


 