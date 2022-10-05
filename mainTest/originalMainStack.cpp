#include <iostream>
#include <vector>
#include <stack>
#include <iterator> 
#include <utility>

using namespace std;

void constructorTest(void)
{	
	cout << endl << endl  << " CONSTRUCTOR TEST" << endl;
	cout << "creation of stack<std::string> stackV;" << endl;
	stack<std::string> stackV;
	cout << "creation of stack<int, std::deque<int> > stackD;" << endl;
	stack<int, std::deque<int> > stackD;
	cout << "creation of stack<int, std::deque<int> > stackD2(stackD);" << endl;
	stack<int, std::deque<int> > stackD2(stackD);
}

void emptyTest(void)
{
	cout << endl << endl  << " EMPTY TEST" << endl;
	stack<std::string> stackV;
	stack<int, std::deque<int> > stackD;
	if (stackV.empty() == true)
		cout << "stackV est vide" << endl;
	else
		cout << "stackV n'est pas vide" << endl;
	if (stackD.empty() == true)
		cout << "stackV est vide" << endl;
	else
		cout << "stackV n'est pas vide" << endl;
}

void popTest(void)
{	
	stack<std::string> stackV;
	stack<int, std::deque<int> > stackD;
	cout << endl << endl  << " POP TEST" << endl;
	cout << " rempli les stack : " << endl;
	stackV.push("hello1");	
	stackV.push("hello2");	
	stackV.push("hello3");	
	stackV.push("hello4");	
	stackV.push("hello5");	
	stackV.push("hello6");	
	stackV.push("hello7");
	stackD.push(100);
	stackD.push(200);
	stackD.push(300);
	stackD.push(400);
	if (stackV.empty() == true)
		cout << "stackV est vide" << endl;
	else
		cout << "stackV n'est pas vide. dernier element = " << stackV.top() << " size = " << stackV.size() << endl;
	if (stackD.empty() == true)
		cout << "stackD est vide" << endl;
	else
		cout << "stackD n'est pas vide. dernier element = " << stackD.top() << "  size = " << stackD.size() << endl;
	cout << "enleve 1 element de chaque stack " << endl;
	stackV.pop();
	stackD.pop();
	if (stackV.empty() == true)
		cout << "stackV est vide" << endl;
	else
		cout << "stackV n'est pas vide. dernier element = " << stackV.top() << " size = " << stackV.size() << endl;
	if (stackD.empty() == true)
		cout << "stackD est vide" << endl;
	else
		cout << "stackD n'est pas vide. dernier element = " << stackD.top() << "  size = " << stackD.size() << endl;
}

void pushTest(void)
{	
	stack<std::string> stackV;
	stack<int, std::deque<int> > stackD;
	stackV.push("hello1");	
	stackV.push("hello2");	
	stackV.push("hello3");	
	stackV.push("hello4");	
	stackV.push("hello5");	
	stackV.push("hello6");	
	stackV.push("hello7");
	stackD.push(100);
	stackD.push(200);
	stackD.push(300);
	stackD.push(400);
	stackV.pop();
	stackD.pop();
	cout << endl << endl  << " PUSH TEST" << endl;
	cout << "dernier element de stackV = " << stackV.top() << endl;
	cout << " ajoute element 'coucou' " << endl;
	stackV.push("coucou");
	cout << "dernier element de stackV = " << stackV.top() << endl;
	cout << "dernier element de stackD = " << stackD.top() << endl;
	cout << " ajoute element 1 " << endl;
	stackD.push(1);
	cout << "dernier element de stackD = " << stackD.top() << endl;
	cout << "tentative d'ajouter str vide " << endl;
	stackV.push("");
	cout << "dernier element de stackD = " << stackD.top() << endl;

	cout << endl << endl  << " SIZE TEST" << endl;
	cout << "size of stackV = " << stackV.size() << endl;
	cout << "size of stackD = " << stackD.size() << endl;

	cout << endl << endl  << " TOP TEST" << endl;
	cout << "dernier element de stackV = " << stackV.top() << endl;
	cout << " ajoute element 'stackkk' " << endl;
	stackV.push("stackkk");
	cout << "dernier element de stackV = " << stackV.top() << endl;
	cout << "dernier element de stackD = " << stackD.top() << endl;
	cout << " ajoute element 666 " << endl;
	stackD.push(666);
	cout << "dernier element de stackD = " << stackD.top() << endl;
}

void relationaleOperatorTest(void)
{
	stack<std::string> stackV;
	stack<int, std::deque<int> > stackD;
	stackV.push("hello1");	
	stackV.push("hello2");	
	stackV.push("hello3");	
	stackV.push("hello4");	
	stackV.push("hello5");	
	stackV.push("hello6");	
	stackV.push("hello7");
	stackD.push(100);
	stackD.push(200);
	stackD.push(300);
	stackD.push(400);
	stackV.pop();
	stackD.pop();
	stackV.push("coucou");
	stackD.push(1);
	stackV.push("");
	stackD.push(666);
	cout << endl << endl  << " RELATIONAL OPERATORS TEST" << endl;
	stack<std::string> stackV3(stackV);
	stack<std::string> stackV2;
	stackV2.push("hey");
	stackV2.push("hey1");
	stackV2.push("hey2");
	stackV2.push("he3");
	stackV2.push("hey5");
	stackV2.push("hey7");
	if (stackV2 == stackV)
		cout << "stackV2 == stackV" << endl;
	if (stackV2 != stackV)
		cout << "stackV2 != stackV" << endl;
	if (stackV2 <= stackV)
		cout << "stackV2 <= stackV" << endl;
	if (stackV2 >= stackV)
		cout << "stackV2 >= stackV" << endl;
	if (stackV2 < stackV)
		cout << "stackV2 < stackV" << endl;
	if (stackV2 > stackV)
		cout << "stackV2 > stackV" << endl;
	if (stackV == stackV2)
		cout << "stackV == stackV2" << endl;
	if (stackV != stackV2)
		cout << "stackV != stackV2" << endl;
	if (stackV <= stackV2)
		cout << "stackV <= stackV2" << endl;
	if (stackV >= stackV2)
		cout << "stackV >= stackV2" << endl;
	if (stackV < stackV2)
		cout << "stackV < stackV2" << endl;
	if (stackV > stackV2)
		cout << "stackV > stackV2" << endl;
	if (stackV3 == stackV)
		cout << "stackV3 == stackV" << endl;
	if (stackV3 != stackV)
		cout << "stackV3 != stackV" << endl;
	if (stackV3 <= stackV)
		cout << "stackV3 <= stackV" << endl;
	if (stackV3 >= stackV)
		cout << "stackV3 >= stackV" << endl;
	if (stackV3 < stackV)
		cout << "stackV3 < stackV" << endl;
	if (stackV3 > stackV)
		cout << "stackV3 > stackV" << endl;
}


int main(void)
{
	cout << endl << endl  << "STACK TESTS : " << endl;
	constructorTest();
	emptyTest();
	popTest();
	pushTest();
	relationaleOperatorTest();
}
