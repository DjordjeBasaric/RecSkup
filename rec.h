#ifndef _rec_h_
#define _rec_h_
#include <iostream>
#include <istream>
using namespace std;
class Rec {
	char* str;

public:
	Rec(string str);
	char* dohvStr() { return str; };

	friend int operator+(Rec r);
	friend int operator~(Rec r);
	int operator()(int n);
	friend bool operator^(Rec r1, Rec r2);

	friend istream& operator>>(istream& is, Rec& r);
	friend void operator<<(ostream& os, Rec& r);

	//Rec(Rec&& b) = delete;
	//Rec(const Rec& b) = delete;
};




#endif
