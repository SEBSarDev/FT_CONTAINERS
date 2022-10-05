#include <iostream>
# include "../utils/ft.hpp"
# include "../Map/Map.hpp"

using std::cout;
using std::endl;
using namespace ft;

bool fncomp (char lhs, char rhs) { return lhs<rhs; }
struct classcomp { bool operator() (const char& lhs, const char& rhs) const { return lhs<rhs; } };

void coplienneTest(void)
{
  cout << endl << endl  << "TEST COPLIENNE  FORM" << endl;
  map<char,int> vide;
  map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  map<char,int> second (first.begin(),first.end());

  map<char,int> third (second);
  map<char,int> sixth;
  sixth = third;
  map<char,int> seventh = third;
  map<char,int,classcomp> fourth;
  fourth['z'] = 26;
  fourth['a'] = 1;
  fourth['j'] = 10;
  fourth['c'] = 3;
  fourth['d'] = 4;
  fourth['f'] = 6;
  fourth['p'] = 16;
  fourth['h'] = 8;
  fourth['b'] = 2;
  fourth['i'] = 9;
  fourth['k'] = 11;
  fourth['o'] = 15;
  fourth['l'] = 12;
  fourth['m'] = 13;
  fourth['g'] = 7;
  fourth['n'] = 14;
  fourth['w'] = 23;
  fourth['u'] = 21;
  fourth['q'] = 17;
  fourth['r'] = 18;
  fourth['e'] = 5;
  fourth['s'] = 19;
  fourth['v'] = 22;
  fourth['x'] = 24;
  fourth['t'] = 20;
  fourth['y'] = 25;

  bool(*fn_pt)(char,char) = fncomp;
  map<char,int,bool(*)(char,char)> fifth (fn_pt);
  fifth['h'] = 8;
  fifth['b'] = 2;
  fifth['i'] = 9;
  fifth['k'] = 11;
  fifth['o'] = 15;
  fifth['l'] = 12;
  fifth['m'] = 13;
  fifth['g'] = 7;
  fifth['n'] = 14;
  fifth['w'] = 23;

  cout << "in first = " << endl;
  for (map<char, int>::iterator beg = first.begin(); beg != first.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in second = " << endl;
  for (map<char, int>::iterator beg = second.begin(); beg != second.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in third = " << endl;
  for (map<char, int>::iterator beg = third.begin(); beg != third.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in fourth = " << endl;
  for (map<char, int>::iterator beg = fourth.begin(); beg != fourth.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in fifth = " << endl;
  for (map<char, int>::iterator beg = fifth.begin(); beg != fifth.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in sixth = " << endl;
  for (map<char, int>::iterator beg = sixth.begin(); beg != sixth.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  cout << "in seventh = " << endl;
  for (map<char, int>::iterator beg = seventh.begin(); beg != seventh.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
  seventh['a'] = 0;
  seventh['b'] = 0;
  seventh['c'] = 0;
  seventh['d'] = 0;
  cout << "in seventh = " << endl;
  for (map<char, int>::iterator beg = seventh.begin(); beg != seventh.end(); beg++)
		cout << beg->first << " = " << beg->second << endl;
}

void beginEndTest(void)
{
  cout << endl << endl << "TEST BEGIN ET END" << endl;

  map<char,int> begi;

  begi['b'] = 100;
  begi['a'] = 200;
  begi['c'] = 300;

  for (map<char,int>::iterator ite=begi.begin(); ite!=begi.end(); ite++)
    cout << ite->first << " => " << ite->second << '\n';
  
  for (map<char,int>::iterator ite2=--(begi.end()); ite2!=begi.begin(); ite2--)
    cout << ite2->first << " => " << ite2->second << '\n';
map<char,int>::iterator ite;
  ite = begi.begin();
  ite++;
    cout << "before  " << ite->first << " => " << ite->second << '\n';
	ite->second = 2;
    cout << "after  " << ite->first << " => " << ite->second << '\n';
  for (map<char,int>::iterator ite=begi.begin(); ite!=begi.end(); ite++)
    cout << ite->first << " => " << ite->second << '\n';
}

void rbeginRendTest(void)
{
  cout << endl << endl << "TEST RBEGIN ET REND" << endl;
  map<char,int> rev;

  rev['x'] = 100;
  rev['y'] = 200;
  rev['z'] = 300;

  map<char,int>::reverse_iterator rite;
  for (rite=rev.rbegin(); rite!=rev.rend(); rite++)
    cout << rite->first << " => " << rite->second << '\n';
  for (rite=--(rev.rend()); rite!=rev.rbegin(); rite--)
    cout << rite->first << " => " << rite->second << '\n';
	rite = rev.rend();
	rite--;
    cout << "before  " << rite->first << " => " << rite->second << '\n';
	rite->second = 2;
    cout << "after  " << rite->first << " => " << rite->second << '\n';
  for (rite=rev.rbegin(); rite!=rev.rend(); rite++)
    cout << rite->first << " => " << rite->second << '\n';
} 

void capacityTest(void)
{
  cout << endl << endl << "CAPACITY FUNCTIONS" << endl;
  map<int, std::string> emptyMap;
  if (emptyMap.empty() == true)
		  cout << "1, emptyMap est vide" << endl;
  else
		  cout << "1, emptyMap n'est pas vide" << endl;
  emptyMap[1] = "coucou";
  emptyMap[12] = "coucou";
  emptyMap[14] = "coucou";
  emptyMap[51] = "coucou";
  emptyMap[21] = "coucou";
  emptyMap[155] = "coucou";
  if (emptyMap.empty() == true)
		  cout << "2, emptyMap est vide" << endl;
  else
		  cout << "2, emptyMap n'est pas vide" << endl;

  cout << "size = " << emptyMap.size() << endl;
  cout << "max_size = " << emptyMap.max_size() << endl;
}

void insertTest(void)
{	
  cout << endl << endl << "TEST INSERT FUNCTION" << endl;
  map<char,int> ins;

  ins.insert ( ft::pair<char,int>('a',100) );
  ins.insert ( ft::pair<char,int>('z',200) );
  
  ft::pair<map<char,int>::iterator,bool> reti;
  reti = ins.insert ( ft::pair<char,int>('z',500) );
  if (reti.second==false)
  {
    cout << "element 'z' already existed";
    cout << " with a value of " << reti.first->second << '\n';
  }
  map<char,int>::iterator ito = ins.begin();
  map<char,int>::iterator ita;
  ita = ins.insert (ito, ft::pair<char,int>('b',300));  
    cout << ita->first << " => " << ita->second << '\n';
  ita = ins.insert (ito, ft::pair<char,int>('c',400));
    cout << ita->first << " => " << ita->second << '\n';
  cout << "ins contains:\n";
  for (ito=ins.begin(); ito!=ins.end(); ++ito)
    cout << ito->first << " => " << ito->second << '\n';

  map<char,int> ot;

  map<char,int>::iterator inf = ins.end();
  inf--;
  inf--;
  ot.insert(ins.begin(),inf);

  cout << "ot contains:\n";
  for (ito=ot.begin(); ito!= ot.end(); ++ito)
    cout << ito->first << " => " << ito->second << '\n';
}

void eraseTest(void)
{
    cout << endl << endl << "TEST ERASE FUNCTION" << endl;
  map<char,int> era;
  map<char,int>::iterator itq;

  era['a']=10;
  era['b']=20;
  era['c']=30;
  era['d']=40;
  era['e']=50;
  era['f']=60;

  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;

  itq=era.find('b');
  era.erase (itq);
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;

  era['z']=60;
  era['m']=60;
  itq=era.find('d');
  era.erase (itq);
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;
  
era['w']=60;
  era['y']=60;
  era['o']=60;
  itq=era.find('w');
  era.erase (itq);
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;

	era['l']=60;
  itq=era.find('z');
  era.erase (itq);
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;
  itq=era.find('y');
  era.erase (itq);
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;
  era.erase ('c');
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;

  itq=era.find ('e');
  era.erase ( itq, era.end() );
  cout << endl;
  for (itq=era.begin(); itq!=era.end(); ++itq)
    cout << itq->first << " => " << itq->second << endl;
}

void swapMemberTest(void)
{
    cout << endl << endl << "TEST SWAP MEMBER FUNCTION" << endl;
map<char,int> f,b;

  f['x']=100;
  f['y']=200;

  b['a']=11;
  b['b']=22;
  b['c']=33;

  f.swap(b);

  cout << "f contains:" << endl;
  for (map<char,int>::iterator it=f.begin(); it!=f.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  cout << "b contains:\n";
  for (map<char,int>::iterator it=b.begin(); it!=b.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
	cout << "size of f = " << f.size() << endl;
	cout << "size of b = " << b.size() << endl;
}

void clearTest(void)
{	
    cout << endl << endl << "TEST CLEAR FUNCTION" << endl;
	map<std::string,std::string> cl;
	cl["aa"] = "aaaaaaaa";
	cl["dd"] = "dddddd";
	cl["cc"] = "ccccc";
	cl["ee"] = "eeeeeeeeeeee";
	cl["ll"] = "lll";
	cl["ab"] = "aaabbbbaa";
  for (map<std::string,std::string>::iterator it=cl.begin(); it!=cl.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
	cout << "size of cl = " << cl.size() << endl;
  cl.clear();
  for (map<std::string,std::string>::iterator it=cl.begin(); it!=cl.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
	cout << "size of cl = " << cl.size() << endl;
	cl["ee"] = "eeeeeeeeeeee";
	cl["ll"] = "lll";
	cl["ab"] = "aaabbbbaa";
  for (map<std::string,std::string>::iterator it=cl.begin(); it!=cl.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
	cout << "size of cl = " << cl.size() << endl;
}

void keyCompTest(void)
{
	cout << endl << endl << "TEST KEY_COMP FUNCTION" << endl;
	map<char,int> kc;
	map<char,int>::key_compare mycomp = kc.key_comp();
	kc['a']=100;
	kc['b']=200;
	kc['c']=300;
	cout << "kc contains:\n";
	char highest = kc.rbegin()->first;
	map<char,int>::iterator it = kc.begin();
	do
	{
			cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
}

void valueCompTest(void)
{
	cout << endl << endl << "TEST VALUE_COMP FUNCTION" << endl;
	map<char,int> vc;
	vc['a']=1;
	vc['b']=2;
	vc['z'] = 4;
	vc['e'] = 33;
	map<char,int>::iterator itvc = vc.begin();
	map<char,int>::iterator itvc2 = vc.begin();
	itvc2++;
	if (vc.value_comp()(*itvc, *itvc2) == true)
			cout << itvc->first << " est inferieur a " << itvc2->first << endl;
	else
		cout << itvc->first << " est superieur ou egal a " << itvc2->first << endl;
	itvc++;
	if (vc.value_comp()(*itvc, *itvc2) == true)
			cout << itvc->first << " est inferieur a " << itvc2->first << endl;
	else
		cout << itvc->first << " est superieur ou egal a " << itvc2->first << endl;
	itvc++;
	if (vc.value_comp()(*itvc, *itvc2) == true)
			cout << itvc->first << " est inferieur a " << itvc2->first << endl;
	else
		cout << itvc->first << " est superieur ou egal a " << itvc2->first << endl;

	cout << endl << endl << "TEST FIND ET COUNT FUNCTIONS" << endl;
	map<std::string, std::string> ff;
	ff["s"] = "hello";
	ff["sa"] = "coucou";
	ff["sdl"] = "salut";
	ff["esu"] = "hola";
	ff["stde"] = "hey";
	ff["sh"] = "bonjour";

	map<std::string, std::string>::iterator itF = ff.find("sa");
	cout << itF->first << " => " << itF->second << endl;
	map<std::string, std::string>::const_iterator itFc = ff.find("sdl");
	cout << itFc->first << " => " << itFc->second << endl;
//	itFc->second = "change";
	itF = ff.find("hey");
	if (itF != ff.end())
		cout << itF->first << " => " << itF->second << endl;
	else
		cout << " no found " << endl;
	itFc = ff.find("no");
	if (itFc != ff.end())
		cout << itFc->first << " => " << itFc->second << endl;
	else
		cout << " no found " << endl;
	std::string strF = "sdl";
	if (ff.count(strF) > 0)
			cout << strF << " is in map" << endl;
	else
			cout << strF << " is not in map" << endl;
	strF = "no";
	if (ff.count(strF) > 0)
			cout << strF << " is in map" << endl;
	else
			cout << strF << " is not in map" << endl;
}

void lowerUpperTest(void)
{
	cout << endl << endl << "TEST LOWER ET UPPER BOUND FUNCTIONS" << endl;
	map<char,int> lub;
	map<char,int>::iterator itlow,itup, itlub;
	lub['a']=20;
	lub['b']=40;
	lub['d']=80;
	lub['e']=100;
	cout << "lower" << endl;
	itlub =  lub.lower_bound('b');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.lower_bound('c');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.lower_bound('d');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.lower_bound('f');
	if (itlub != lub.end())
		cout << itlub->first << " => " << itlub->second << endl;
	else
		cout << " end " << endl;
	cout << "upper" << endl;
	itlub =  lub.upper_bound('b');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.upper_bound('c');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.upper_bound('d');
	cout << itlub->first << " => " << itlub->second << endl;
	itlub = lub.upper_bound('f');
	if (itlub != lub.end())
		cout << itlub->first << " => " << itlub->second << endl;
	else
		cout << " end " << endl;
	
	itlow=lub.lower_bound ('b');
	itup=lub.upper_bound ('d');
	lub.erase(itlow,itup);
	for (map<char,int>::iterator it=lub.begin(); it!=lub.end(); ++it)
		cout << it->first << " => " << it->second << endl;
}

void equalRangeTest(void)
{
	cout << endl << endl << "TEST EQUAL RANGE FUNCTIONS" << endl;
	 map<char,int> eqR;

  eqR['a']=10;
  eqR['b']=20;
  eqR['c']=30;

  pair<map<char,int>::iterator,map<char,int>::iterator> ret;
  ret = eqR.equal_range('b');

  cout << "lower bound points to: ";
  cout << ret.first->first << " => " << ret.first->second << endl;

 cout << "upper bound points to: ";
  cout << ret.second->first << " => " << ret.second->second << endl;
}

void nonMemberFctnTest(void)
{
	cout << endl << endl << "TEST NON-MEMBER FUNCTION" << endl;
	map<int, std::string> nm;
	nm[2]="yoo";
	nm[25]="yoo";
	nm[89]="yoo";
	nm[38]="yoo";
	nm[57]="yoo";
	nm[9]="yoo";
	nm[321]="yoo";
	nm[4]="yoo";
	nm[66]="yoo";
	nm[73]="yoo";

	map<int, std::string> nm2;
	nm2[2]="yoo";
	nm2[25]="yoo";
	nm2[89]="yoo";
	nm2[38]="yoo";
	nm2[57]="yoo";

	cout << "nm size = " <<  nm.size() << endl;
	cout << "nm containt :" << endl;
	for (map<int,std::string>::iterator it = nm.begin(); it != nm.end(); it++)
			cout << it->first << " => " << it->second << endl;
	cout << "nm2 size = " <<  nm2.size() << endl;
	cout << "nm2 containt :" << endl;
	for (map<int,std::string>::iterator it = nm2.begin(); it != nm2.end(); it++)
			cout << it->first << " => " << it->second << endl;
	cout << "nm.swap(nm2)" << endl;
	nm.swap(nm2);
	cout << "nm size = " <<  nm.size() << endl;
	cout << "nm containt :" << endl;
	for (map<int,std::string>::iterator it = nm.begin(); it != nm.end(); it++)
			cout << it->first << " => " << it->second << endl;
	cout << "nm2 size = " <<  nm2.size() << endl;
	cout << "nm2 containt :" << endl;
	for (map<int,std::string>::iterator it = nm2.begin(); it != nm2.end(); it++)
			cout << it->first << " => " << it->second << endl;
	if (nm2 == nm)
			cout << " nm2 == nm -> true" << endl;
	else
			cout << "nm2 == nm -> false" << endl;
	if (nm2 != nm)
			cout << " nm2 != nm -> true" << endl;
	else
			cout << "nm2 != nm -> false" << endl;
	if (nm2 <= nm)
			cout << " nm2 <= nm -> true" << endl;
	else
			cout << "nm2 <= nm -> false" << endl;
	if (nm2 < nm)
			cout << " nm2 < nm -> true" << endl;
	else
			cout << "nm2 < nm -> false" << endl;
	if (nm2 >= nm)
			cout << " nm2 >= nm -> true" << endl;
	else
			cout << "nm2 >= nm -> false" << endl;
	if (nm2 > nm)
			cout << " nm2 > nm -> true" << endl;
	else
			cout << "nm2 > nm -> false" << endl;
	if (nm > nm2)
			cout << " nm > nm2 -> true" << endl;
	else
			cout << "nm > nm2 -> false" << endl;
	if (nm < nm2)
			cout << " nm < nm2 -> true" << endl;
	else
			cout << "nm < nm2 -> false" << endl;
	if (nm >= nm2)
			cout << " nm >= nm2 -> true" << endl;
	else
			cout << "nm >= nm2 -> false" << endl;
	if (nm <= nm2)
			cout << " nm <= nm2 -> true" << endl;
	else
			cout << "nm <= nm2 -> false" << endl;
	if (nm > nm)
			cout << " nm > nm -> true" << endl;
	else
			cout << "nm > nm -> false" << endl;
	if (nm < nm)
			cout << " nm < nm -> true" << endl;
	else
			cout << "nm < nm -> false" << endl;
	if (nm <= nm)
			cout << " nm <= nm -> true" << endl;
	else
			cout << "nm <= nm -> false" << endl;
	if (nm >= nm)
			cout << " nm >= nm -> true" << endl;
	else
			cout << "nm >= nm -> false" << endl;
	if (nm == nm)
			cout << " nm == nm -> true" << endl;
	else
			cout << "nm == nm -> false" << endl;
	if (nm != nm)
			cout << " nm != nm -> true" << endl;
	else
			cout << "nm != nm -> false" << endl;
}

void constIteTest(void)
{	
	cout << endl << endl << "TEST CONST_ITERATOR FUNCTION" << endl;
	map<std::string, std::string> cMap;
	cMap["wingardium"]= "leviosa";	
	cMap["aloho"]= "mora";	
	cMap["levi"]= "corpus";	
	cMap["avada"]= "kedavra";	
	cMap["finite"]= "incantatum";	
	cMap["petrificus"]= "totalus";	
	map<std::string, std::string>::const_iterator a;
	a = cMap.begin();
	cout << a->first << "  " << a->second << endl;
	a++;
	cout << a->first << "  " << a->second << endl;
//	a->second = "change"; // must not compile
	a = cMap.end();
	a--;
	cout << a->first << "  " << a->second << endl;
	a--;
	cout << a->first << "  " << a->second << endl;
	map<std::string, std::string>::const_reverse_iterator b2;
	b2 = cMap.rbegin();
	b2++;
	cout << b2->first << "  " << b2->second << endl;
	b2++;
	cout << b2->first << "  " << b2->second << endl;
	b2 = cMap.rend();
	b2--;
	cout << b2->first << "  " << b2->second << endl;
	b2--;
	cout << b2->first << "  " << b2->second << endl;

	a = cMap.find("levi");
	cout << a->first << "  " << a->second << endl;
	a++;
	cout << a->first << "  " << a->second << endl;
	a = cMap.find("no key");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.lower_bound("finite");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.upper_bound("finite");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.lower_bound("no key");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.upper_bound("no key");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.lower_bound("aloho");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.upper_bound("aloho");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.lower_bound("wingardium");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	a = cMap.upper_bound("wingardium");
	if (a == cMap.end())
			cout << "key not found" << endl;
	else
		cout << a->first << "  " << a->second << endl;
	ft::pair<map<std::string, std::string>::const_iterator, map<std::string, std::string>::const_iterator> constPair;
	constPair = cMap.equal_range("avada");
	cout << constPair.first->first << "  " << constPair.first->second << endl;
	cout << constPair.second->first << "  " << constPair.second->second << endl;
	map<std::string,std::string>::iterator itnc;
	map<std::string,std::string>::const_iterator itc;
	itc = itnc;
}

int main(void)
{
  cout << endl << endl  << " MAP TESTS : " << endl;
	coplienneTest();
	beginEndTest();
	rbeginRendTest();
	capacityTest();
	insertTest();
	eraseTest();
	swapMemberTest();
	clearTest();
	keyCompTest();
	valueCompTest();
	lowerUpperTest();
	equalRangeTest();
	nonMemberFctnTest();
	constIteTest();
}
