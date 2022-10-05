#include <iostream>
#include <vector>
#include <iterator> 
#include <utility>

using namespace std;

void constructorTest(void)
{
	cout << endl << endl  << "TEST CONSTRUCTOR" << endl;
	vector<int> cons1;
	cout << "cons1 contains : " << endl;
	for (size_t i = 0; i < cons1.size(); i++)
			cout << " " << cons1[i];
	cout << endl;
	vector<int> cons2(0, 2);
	cout << "cons2 contains : " << endl;
	for (size_t i = 0; i < cons2.size(); i++)
			cout << " " << cons2[i];
	cout << endl;
	vector<int> cons3(200, 18);
	cout << "cons3 contains : " << endl;
	for (size_t i = 0; i < cons3.size(); i++)
			cout << " " << cons3[i];
	cout << endl;
	int tabCons[] = {10, 20, 334, 41, 95, 346, 67, 238, 49, 100, 11};
	vector<int> cons4(tabCons + 2, tabCons + 9);
	cout << "cons4 contains : " << endl;
	for (size_t i = 0; i < cons4.size(); i++)
			cout << " " << cons4[i];
	cout << endl;
	vector<int> cons5(cons4);
	cout << "cons5 contains : " << endl;
	for (size_t i = 0; i < cons5.size(); i++)
			cout << " " << cons5[i];
	cout << endl;
	vector<std::string> cons6(80, "coucou toi c'est moi");
	cout << "cons6 contains : " << endl;
	for (size_t i = 0; i < cons6.size(); i++)
			cout << " " << cons6[i];
	cout << endl;

	cout << endl << endl  << "TEST OPERATOR=" << endl;
	cons1 = cons4;
	cout << "cons1 now contains : " << endl;
	for (size_t i = 0; i < cons1.size(); i++)
			cout << " " << cons1[i];
	cout << endl;

	cout << endl << endl  << " TEST DE END ET BEGIN " << endl;
	vector<char> eb(17, 'c');
	eb.push_back('a');
	cout << *(eb.begin()) << endl;
	cout << *(eb.end() - 1) << endl;
	
	cout << endl << endl  << " TEST DE REND ET RBEGIN " << endl;
	vector<int> vv(5);
	int i = 0;
	vector<int>::reverse_iterator rit = vv.rbegin();
	for (; rit != vv.rend(); ++rit)
		*rit = ++i;
	rit = vv.rbegin();
	cout << "AVVVVVAAANNNNNNNNNNNNNNNNNNNNNNNNNNNT  " << *rit << endl;
	*rit = 18;
	cout << "APREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES  " << *rit << endl;
	cout << "my vector contains : ";
	for (vector<int>::iterator it = vv.begin(); it != vv.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
}

void capacityBlockTest()
{
	cout << endl << endl << " TEST DU BLOCK CAPACITY " << endl;
	cout << endl << " test de size " <<endl;
	vector<std::string> si(340, "lala");
	cout << "size " << si.size() << endl;
	cout << endl << " test de max_size " <<endl;
	vector<std::string> msi(340, "lala");
	cout << " max_size " << msi.max_size() << endl;
	cout << endl << " test de capacity " << endl;
	cout << "capacity " << msi.capacity() << endl;
	cout << endl << " test de resize " << endl;
	vector<int> f(6,100);
	vector<int>::iterator itt1;
	f.resize(20, 0);
	for (itt1 = f.begin(); itt1 < f.end();itt1++)
		cout << " " << *itt1;
	f.resize(100, 0);
	cout << "size after resize " << f.size() << endl;
	cout << endl << " test de empty " << endl;
	vector<int> emptyy;
	if (emptyy.empty() == true)
			cout << "is empty" << endl;
	else
			cout << "is not empty" << endl;
	emptyy.push_back(2);
	if (emptyy.empty() == true)
			cout << "is empty" << endl;
	else
			cout << "is not empty" << endl;
	emptyy.pop_back();
	if (emptyy.empty() == true)
			cout << "is empty" << endl;
	else
			cout << "is not empty" << endl;
	cout << endl << " test de reserve " << endl;
	vector<int> bar;
	bar.reserve(100);
		cout << "capacity changed: " << bar.capacity() << '\n';
	bar.reserve(200);
		cout << "capacity changed: " << bar.capacity() << '\n';
}
	
void accessTest()
{	
	cout << endl << endl << " TEST DE ACCESS ELEMENT " << endl;
	vector<int> w;
	w.push_back(10);
	w.push_back(98);
	w.push_back(11);
	w.push_back(63);
	w.push_back(0);
	w.push_back(13);
	w.push_back(22);
	w.push_back(1);
	w.push_back(100);
	w.push_back(19);
	cout << "front : ";
	cout << w.front() << endl;
	cout << "back : ";
	cout << w.back() << endl;
	while (w.back() != 0)
	{
			w.push_back (w.back() - 1);
	}
	cout << "operator[]  ";
	for (size_t i = 0; i < w.size() ; i++)
			cout << "[" << i << "]" << '=' << w[i] << endl;
	cout << endl;
	cout << "at(3) : ";
	cout << w.at(3) << endl;
}

void assignTest(void)
{	
	cout << endl << endl << " TEST DE ASSIGN " << endl;
	int tab[10] = {89, 45, 3, 34, 76, 6, 12, 56, 23, 46};
	vector<int> assigne(12, 4);
	cout << " vector au debut : ";
	for (size_t i = 0; i < assigne.size() ; i++)
		cout << " " << assigne[i] ;
	cout << endl;
	assigne.assign(20, 1);
	cout << " vector au apres assigne(20, 1): ";
	for (size_t i = 0; i < assigne.size() ; i++)
		cout << " " << assigne[i] ;
	cout << endl;
	assigne.assign(&tab[0], &tab[9]);
	cout << " vector apres assigne(&tab[0], &tab[9]): ";
	for (size_t i = 0; i < assigne.size() ; i++)
		cout << " " << assigne[i] ;
	cout << endl;
}

void pushPopTest(void)
{
	cout << endl << endl << " TEST PUSH ET POP BACK " << endl;
	vector<int> pp;
	cout << "push : " << endl;
	pp.push_back(89);
	for (int i = 200 ; i > 154 ; i--)
			pp.push_back(i);
	for (size_t i = 0; i < pp.size() ; i++)
			cout << " " << pp[i];
	cout << endl;
	cout << "pop : " << endl;
	for (int i = 0 ; i < 13; i++)
			pp.pop_back();
	for (size_t i = 0; i < pp.size() ; i++)
			cout << " " << pp[i];
	cout << endl;
}

void insertTest(void)
{
	cout << endl << endl << " TEST DE INSERT " << endl;
	vector<int> e(6,100);
	vector<int>::iterator it1;
	it1 = e.begin();
	it1 = e.insert(it1, 200);
	e.insert(it1, 2, 300);
	it1 = e.begin();
	vector<int> anothervector(2,400);
	e.insert(it1+2, anothervector.begin(), anothervector.end());
	int array[] = {501, 502, 503};
	e.insert(e.begin(), array, array + 3);
	cout << "my vector contain ";
	for (it1 = e.begin(); it1 < e.end();it1++)
		cout << " " << *it1;
	cout << endl;
	it1 = e.begin() + 4;
	cout << *it1 << endl;
	vector<int>::iterator it2;
	it2 = e.insert(it1, 2);
	cout << *it2 << endl;
	cout << "my vector contain ";
	for (it1 = e.begin(); it1 < e.end(); it1++)
		cout << ' ' << *it1;
	cout << endl;
}

void erraseTest(void)	
{
	cout << endl << endl << " TEST DE ERRASE " << endl;
	vector<int> er;
	for (int i = 1; i <= 10; i++)
		er.push_back(i);
	er.erase (er.begin()+5);
	er.erase (er.begin());
	er.erase (er.end() - 1);
	er.erase (er.begin(), er.begin()+3);
	cout << "my vector contains:";
	for (size_t i = 0; i < er.size(); ++i)
		cout << ' ' << er[i];
	cout << endl;
}

void swapTest(void)
{	
	cout << endl << endl << " TEST DE SWAP " << endl;
	vector<std::string> bonjour(9, "bonjour");
	vector<std::string> aurevoir(1, "aurevoir");
	cout << "vector bonjour:";
	for (size_t i = 0; i < bonjour.size(); ++i)
		cout << ' ' << bonjour[i] << endl;
	cout << "vector aurevoir:";
	for (size_t i = 0; i < aurevoir.size(); ++i)
		cout << ' ' << aurevoir[i] << endl;
	cout << "bonjour.swap(aurevoir)" << endl;
	cout << "vector bonjour:";
	for (size_t i = 0; i < bonjour.size(); ++i)
		cout << ' ' << bonjour[i] << endl;
	cout << "vector aurevoir:";
	for (size_t i = 0; i < aurevoir.size(); ++i)
		cout << ' ' << aurevoir[i] << endl;
}

void clearTest(void)
{	
	cout << endl << endl << " TEST DE CLEAR " << endl;
	vector<int> cl;
	cl.push_back (100);
	cl.push_back (200);
	cl.push_back (300);
	cout << "vector contains:";
	for (size_t i = 0; i < cl.size(); i++)
		cout << ' ' << cl[i];
	cout << endl;
	cl.clear();
	cl.push_back (1101);
	cl.push_back (2202);
	cout << "vector contains:";
	for (size_t i = 0; i < cl.size(); i++)
		cout << ' ' << cl[i];
	cout << endl;

	cout << endl << endl << "TEST GET ALLOCATOR " << endl;
	int *ptr;
	ptr = cl.get_allocator().allocate(5);
	for (int i = 0; i < 5; i++)
		cl.get_allocator().construct(&ptr[i],i);
	std::cout << "The allocated array contains:";
	for (int i = 0; i < 5; i++)
		cout << ' ' << ptr[i];
	cout << endl;
	for (int i = 0; i < 5; i++)
		cl.get_allocator().destroy(&ptr[i]);
	cl.get_allocator().deallocate(ptr,5);
}

void nonMemberFctnTest(void)
{
	cout << endl << endl << "TEST OVERLOAD ET FCNT NON MEMBRE " << endl;
	vector<int> nm1 (3,100);
	vector<int> nm2 (2,200);
	vector<int> nm3 (3,100);
	vector<int> nm4 (3,200);
	vector<int> nm5 (3,20);
	if (nm1==nm2) cout << "nm1 and nm2 are equal\n";
	if (nm1!=nm2) cout << "nm1 and nm2 are not equal\n";
	if (nm1< nm2) cout << "nm1 is less than nm2\n";
	if (nm1> nm2) cout << "nm1 is greater than nm2\n";
	if (nm1<=nm2) cout << "nm1 is less than or equal to nm2\n";
	if (nm1>=nm2) cout << "nm1 is greater than or equal to nm2\n";	
	if (nm1==nm3) cout << "nm1 and nm3 are equal\n";
	if (nm1==nm4) cout << "nm1 and nm4 are equal\n";
	if (nm1> nm4) cout << "nm1 is greater than nm4\n";
	if (nm1<=nm4) cout << "nm1 is less than or equal to nm4\n";
	if (nm1> nm5) cout << "nm1 is greater than nm5\n";
	if (nm1<=nm5) cout << "nm1 is less than or equal to nm5\n";

	vector<int> sw1(4,100);
	vector<int> sw2(10,4);
	cout << "sw1 contains:";
	for (size_t i = 0; i < sw1.size(); i++)
		cout << ' ' << sw1[i];
	cout << endl;
	cout << "sw2 contains:";
	for (size_t i = 0; i < sw2.size(); i++)
		cout << ' ' << sw2[i];
	cout << endl;
	swap(sw1, sw2);
	cout << "sw1 contains:";
	for (size_t i = 0; i < sw1.size(); i++)
		cout << ' ' << sw1[i];
	cout << endl;
	cout << "sw2 contains:";
	for (size_t i = 0; i < sw2.size(); i++)
		cout << ' ' << sw2[i];
	cout << endl;
}

int main(void)
{
	cout << endl << endl  << " VECTOR TESTS : " << endl;
	constructorTest();
	capacityBlockTest();
	accessTest();
	assignTest();
	pushPopTest();
	insertTest();
	erraseTest();
	swapTest();
	clearTest();
	nonMemberFctnTest();
}
