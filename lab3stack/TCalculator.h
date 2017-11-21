#pragma once

#include "Tstack.h"
#include <string>
using namespace std;

class TCalculator
{
private:
	string infix;
	string postfix;
	Tstack<char> stc;
	Tstack<double> std;
public:
	TCalculator(void);
	~TCalculator(void);
	void setinfix(string);			// ��������� ������ � infix 
	string getinfix();				// ��������� ������ �� infix 
	string getpostfix();			// ��������� ������ �� postfix
	int priority(char);				// ����������� ���������� ��������
	bool check();					// �������� ������������ ��������� ������ 
	void topostfix();				// ������� �� ��������� ������ � �����������
	double calk();					// ���������� ���������
};


