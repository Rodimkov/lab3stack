#include "TCalculator.h"

TCalculator::TCalculator(void)
{
}


TCalculator::~TCalculator(void)
{
}

int TCalculator::priority(char c)
{
	if ( c == '(' ) return 0;
	if ( c == '+' || c == '-' ) return 1;
	if ( c == '*' || c == '/' ) return 2;
	if ( c == '^' ) return 3;
	if ( c == ')' ) return 4;
}

bool TCalculator::check()
{
	stc.clear();
	for ( int i = 0 ; i < infix.size() ; i++ )
	{
		if ( infix[i] == '(' ) 
			stc.push('(');
		if ( infix[i] == ')')
			if ( stc.isempty() )  return false;
			else stc.pop();
	}
	if ( !stc.isempty() ) return false;
	else return true;
}

void TCalculator::topostfix()
{
	stc.clear();
	postfix = "";
	string buf = '(' + infix + ')';
	for( int i = 0 ; i < buf.size() ; i++)
	{
		if( buf[i] == '(') 
			stc.push(buf[i]);
		if( buf[i] >= '0'  && buf[i] <= '9' || buf[i] == '.')
			postfix += buf[i];
		if( buf[i] == ')' )
		{
			char el = stc.pop();
			while( el != '(' )
			{
				postfix += el;
				el = stc.pop();
			}
		}
		if(  buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^' )
		{
			postfix += ' ';
			while ( (priority(stc.top()) >= priority(buf[i])) ) 
				postfix += stc.pop();
			stc.push(buf[i]);
		}
	}
}


double TCalculator::calk()
{
	double res;
	std.clear();
	topostfix();
	for(int i = 0 ; i < postfix.size() ; i++)
	{
		if( postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double op1,op2 = std.pop();
			op1 = std.pop();
			switch(postfix[i]) 
			{
			case '+':
				std.push(op1+op2);
				break;
			case '-':
				std.push(op1-op2);
				break;
			case '*':
				std.push(op1*op2);
				break;
			case '/':
				std.push(op1/op2);
				break;
			case '^':
				std.push(pow(op1,op2));
				break;
			}
		}
		if(postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')
		{
			char *tmp;
			std.push(strtod(&postfix[i], &tmp));
			i +=  tmp - &postfix[i] -1;
		}
	}
	if( std.isempty() ) throw -1;
	res = std.pop();
	if( !std.isempty() ) throw -1;
	return res;
}


void TCalculator::setinfix(string s)
{
	if( !(s[0] >= '0' && s[0] <= '9' || s[0] == '.'))
		throw -1;
	if( !(s[s.size()-1] >= '0' && s[s.size()-1] <= '9' || s[s.size()-1] == '.'))
		throw -1;
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] == ' ')
		{
			s.erase(i,i+1);
			i--;
		}
	if( s == "")
		throw -1;
	for(int i = 0 ; i < s.size() ; i++)
		if( !(s[i] >= '0' && s[i] <= '9' || s[i] == '.') && !(s[i+1] >= '0' && s[i+1] <= '9' || s[i+1] == '.'))
	infix = s;
}

string TCalculator::getinfix()
{
	return infix;
}

string TCalculator::getpostfix()
{
	return postfix;
}

Tcalculator::Tcalculator(void)
{
}


Tcalculator::~Tcalculator(void)
{
}
