#include <iostream>
#include "../Map/Map.hpp"

using namespace ft;

int main(void)
{
	map<int, char> time;
	for (int i = 0; i < 1000000; i++)
		time.insert(ft::pair<int,char>(i, 'a'));
}
