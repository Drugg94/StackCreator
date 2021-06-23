#include <iostream>
#include <cassert>
#include "myStack.h"

using namespace std;

int main()
{
	stackedTypes<int> s1(12);
	stackedTypes<int> s2(15);

	cout << "Inserting elements to both the stacks. "
		<< endl;

	for (int i = 5; i < 50; i += 5)
	{
		s1.push(i);
		s2.push(i);
	}

	if (s1 == s2)
		cout << "Both stacks are equal "
		<< endl;
	else
		cout << "Both stacks are not equal "
		<< endl;
	cout << "Inserting eleventh element. "
		<< endl;

	s2.push(11);

	if (s1 == s2)
		cout << "Both stacks are equal. "
		<< endl;
	else
		cout << "Both stacks are not equal. "
		<< endl;

	return 0;
}