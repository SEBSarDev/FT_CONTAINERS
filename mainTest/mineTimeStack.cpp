#include <iostream>
#include <deque>
#include "../Stack/Stack.hpp"

using namespace ft;

int main(void)
{
	stack<int> time;
	for (int i = 0; i < 10000000; i++)
		time.push(i);
	stack<int, std::deque<int> > time2;
	for (int i = 0; i < 10000000; i++)
		time2.push(i);
}
