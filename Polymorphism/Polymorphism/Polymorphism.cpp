// Polymorphism.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


class A
{
public:
	virtual int GetInt();	// ���������� ��������� �������
};
int A::GetInt() { return 1; }	// �������� virtual � ������

int main()
{
    return 0;
}


 