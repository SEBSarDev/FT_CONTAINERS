#include <iostream>
#include <stack>
#include <deque>
#include <iterator> 
#include <utility>

using namespace std;

int main(void)
{
	stack<int> time;
	for (int i = 0; i < 10000000; i++)
		time.push(i);
	stack<int, deque<int> > time2;
	for (int i = 0; i < 10000000; i++)
		time2.push(i);
}
