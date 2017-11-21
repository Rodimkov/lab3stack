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
	void setinfix(string);			// установка строки в infix 
	string getinfix();				// получение строки из infix 
	string getpostfix();			// получение строки из postfix
	int priority(char);				// определение приоритета операции
	bool check();					// проверка корректности введенной строки 
	void topostfix();				// перевод из инфиксной записи в постфиксную
	double calk();					// вычисление выражения
};


