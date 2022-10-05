#include <iostream>
#include <map>
#include <iterator> 
#include <utility>

using namespace std;

int main(void)
{
	map<int, char> time;
	for (int i = 0; i < 1000000; i++)
		time.insert(std::pair<int,char>(i, 'a'));
}
