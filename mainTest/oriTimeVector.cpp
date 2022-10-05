#include <iostream>
#include <vector>
#include <iterator> 
#include <utility>

using namespace std;

int main(void)
{
	vector<int> time;
	for (int i = 0; i < 10000000; i++)
		time.push_back(i);
}
