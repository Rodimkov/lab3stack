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

	if( infix == "")
		return false;

	for(int i = 0 ; i < infix.size() ; i++)
		{
			if(infix[i] == ' ')
			{
				infix.erase(i,i+1);
				i--;
			}
			if( ( infix[i] >= '?' && infix[i] <= 'Z' )  || ( infix[i] >= 'a' && infix[i] <= 'z' ) )
				return false;
		}

	// корректность введеных скобок
	for ( int i = 0 ; i < infix.size() ; i++ )
	{
		if ( infix[i] == '(' ) 
			stc.push('(');
		if ( infix[i] == ')')
			if ( stc.isempty() )  return false;
			else stc.pop();
	}
	if ( !stc.isempty() ) return false;
	// корректность введного конца
	if( !(infix[0] >= '0' && infix[0] <= '9' || infix[0] == '.'))
		return false;
	if( !(infix[infix.size()-1] >= '0' && infix[infix.size()-1] <= '9' || infix[infix.size()-1] == '.'))
		return false;

	for(int i = 0 ; i < infix.size() ; i++)
		if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^' )
			if( !(infix[i-1] >= '0' && infix[i-1] <= '9' || infix[i-1] == '.' ||  infix[i-1] == ')' ) || !(infix[i+1] >= '0' && infix[i+1] <= '9' || infix[i+1] == '.' || infix[i+1] == '('))
				return false;
	//пустота строки
	if( infix == "")
		return false;


	return true;
}

void TCalculator::topostfix()
{
	if(check()) 
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
	else throw -1;
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
	infix = s;
}

string TCalculator::getinfix()
{
	topostfix();
	return infix;
}

string TCalculator::getpostfix()
{
	return postfix;
}
