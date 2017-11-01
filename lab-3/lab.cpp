#include <iostream>
#include "Tstack.h"
using namespace std;

void main() 
{
	Tstack<int> a(10),b;
	int c = 5;
	a.push(5);
	a.push(6);
	a.push(7);
	Tstack<int> q(a);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;

	if( true && false || true )
		cout << "f";

	if(a.isfull()) cout << "oh" << endl ;
	if(a.isempty()) cout << "hello" << endl;

	system("pause");
}