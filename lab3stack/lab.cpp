#pragma once

#include <iostream>
#include "Tstack.h"
#include "TCalculator.h"

using namespace std;

void main() 
{
	TCalculator a;

	a.setinfix("2+2");
	cout << "postfix = " << a.getpostfix() << endl;
	cout << "2+2 = " << a.calk() << endl << endl;

	a.setinfix("2+2*2^(-3+3)*8");
	cout << "postfix = " << a.getpostfix() << endl;
	cout << "2+2*2^(3+3)*8 = " << a.calk() << endl << endl;

	a.setinfix("3*(-4)");
	cout << "postfix = " << a.getpostfix() << endl;
	cout << "3*(-4) = " << a.calk() << endl << endl;

	a.setinfix("7+(-3)*2+6");
	cout << "postfix = " << a.getpostfix() << endl;
	cout << "7+(-3)*2+6 = " << a.calk() << endl << endl;
	system("pause");
}