#pragma once

#include <iostream>
#include "Tstack.h"
#include "TCalculator.h"

using namespace std;

void main() 
{
	string infix = "";
	for(int i = 0 ; i < infix.size() ; i++)
		
		if(infix[i] == ' ')
		{
			infix.erase(i,i+1);
			i--;
		}
	system("pause");
}