#include <iostream>
#include <vector>
#include <iterator> 
#include <utility>

using namespace std;

bool mycomp (char c1, char c2) { return tolower(c1)<tolower(c2); }
bool mypredicate (int i, int j) { return (i==j); }

void reverseIteratorTest(void)
{	
	cout << endl << endl  << " TEST DE REVERSE ITERATOR" << endl;
	vector<int> rev;
	for (int i=1; i<10; i++)
			rev.push_back(i);
	typedef vector<int>::iterator iter_type;
	vector<int>::reverse_iterator rev_end (rev.begin());
	vector<int>::reverse_iterator rev_begin (rev.end());
	if (rev_end != rev_begin)
		cout << "!= works ! " << endl;
	cout << "myvector:";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		cout << ' ' << *it;
	cout << '\n';
	
	iter_type it = rev_end.base();
	cout << "rev_end - 1: ";
	rev_end--;
	cout << ' ' << *rev_end << '\n';
	cout << "rev_end.base():";
	cout << ' ' << *it << '\n';
	it++;
	cout << "it++:";
	cout << ' ' << *it << '\n';
	it = rev_begin.base();
	cout << "rev_begin: ";
	cout << ' ' << *rev_begin << '\n';
	cout << "rev_begin.base()-- :";
	it--;
	cout << ' ' << *it << '\n';
	*rev_begin++;
	cout << "*rev_begin++:";
	cout << ' ' << *rev_begin << '\n';

	vector<int> rev2;
	for (int i = 1; i < 10; i++)
		rev2.push_back(i);
	typedef vector<int>::iterator iter;
	iter fr(rev2.begin());
		cout << *fr << endl;
	iter u(rev2.end());
	for (iter fr = rev2.begin(); fr != u; fr++)
		cout << *fr << " ";
	cout <<endl;
	vector<int>::reverse_iterator ru(fr);
	vector<int>::reverse_iterator rf(u);
	ru--;
	cout << *ru << endl;
	cout << *rf << endl;
	iter bu = ru.base();
	cout << *bu << endl;
	iter bf = rf.base();
	bf--;
	cout << *bf << endl;
	cout << "myvector : ";
	while(rf != ru)
		cout << ' ' << *rf++;
	cout << endl;
	
	cout << endl << " compare reverse et iterator " << endl;
	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	vector<int>::iterator itt = v.begin() + 3;
	cout << "ite : " << *itt << endl;
	vector<int>::reverse_iterator revit(itt);
	cout << "reverse : " << *revit << endl;
}

void lexicographicalCompareTest(void)
{	
	cout << endl << endl << " TEST LEXICOGRAPHICAL_COMPARE " << endl;
	char foo[]="Apple";
	char bar[]="apartment";
	cout << std::boolalpha;
	cout << "Comparing foo and bar lexicographically (foo<bar):\n";
	cout << "Using default comparison (operator<): ";
	cout << lexicographical_compare(foo,foo+5,bar,bar+9);
	cout << endl;
	cout << "Using mycomp as comparison object: ";
	cout << lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	cout << endl;
}

void equalTest(void)
{	
	cout << endl << endl << " TEST EQUAL " << endl;
	int tabeq[] = {20,40,60,80,100};
	vector<int> eq(tabeq, tabeq + 5);
	if ( equal (eq.begin(), eq.end(), tabeq) )
		cout << "The contents of both sequences are equal.\n";
	else
		cout << "The contents of both sequences differ.\n";
	eq[3]=81;
	if ( equal (eq.begin(), eq.end(), tabeq, mypredicate) )
		cout << "The contents of both sequences are equal.\n";
	else
		cout << "The contents of both sequences differ.\n";
}

void pairTest(void)
{
	cout << endl << endl << " TEST DE PAIR " << endl;
	pair <std::string,double> product1;
	pair <std::string,double> product2 ("tomatoes",2.30);
	pair <std::string,double> product3 (product2);
	product1 = std::make_pair(std::string("lightbulbs"),0.99);
	product2.first = "shoes";
	product2.second = 39.90;
	cout << "The price of " << product1.first << " is $" << product1.second << endl;
	cout << "The price of " << product2.first << " is $" << product2.second << endl;
	cout << "The price of " << product3.first << " is $" << product3.second << endl;
}

int main(void)
{
	cout << endl << endl  << " FT TESTS : " << endl;
	reverseIteratorTest();
	lexicographicalCompareTest();	
	equalTest();
	pairTest();
}
