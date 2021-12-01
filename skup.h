#define _CRT_SECURE_NO_WARNINGS 1 
#ifndef _skup_h_
#define _skup_h_
#include <string>
using namespace std;
class Skup {
	char* strin;
	//int broj;
public:
	Skup(string str);
	friend char* operator+=(Skup s, char c);
	char* dohvStr() { return strin; };
	bool operator()(char c);
	
};





#endif _skup_h_
