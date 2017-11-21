#pragma once

#include <iostream>
#include "Tstack.h"
#include "TCalculator.h"

using namespace std;

void main() 
{
	string s;
	s = "   12";
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] == ' ')
		{
			s.erase(i,i+1);
			i--;
		}
	cout << s;
	system("pause");
}