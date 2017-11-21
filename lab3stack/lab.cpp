#pragma once

#include <iostream>
#include "Tstack.h"
#include "TCalculator.h"

using namespace std;

void main() 
{
	TCalculator a;
	a.setinfix("2+2");
	cout << a.getpostfix();
	system("pause");
}