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
		if( ( buf[i] == '+') || (buf[i] == '-') || (buf[i] == '*') || (buf[i] == '/') || (buf[i] == '^') )
		{
			while ( (priority(stc.top()) >= priority(buf[i])) && buf[i] != '(' ) // чуть чуть не то //еще если скобка ее не выкидываем 
				postfix += stc.pop();
			stc.push(buf[i]);
		}
	}
}


void TCalculator::setinfix(string s)
{
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