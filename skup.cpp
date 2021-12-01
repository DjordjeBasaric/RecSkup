#define _CRT_SECURE_NO_WARNINGS 1 
#include "skup.h"
#include<string>

char* operator+=(Skup s, char c) {
	for (int i = 0; i < strlen(s.strin); i++) {
		if (s.strin[i] == c) {
			return s.strin;
		}
	}
	strncat(s.strin, &c, 1);
	return s.strin;

}

Skup::Skup(string str){
	//char* novi;
	/*for (i = 0; i < str.size(); i++) {
		if (str[i])
	}*/
	strin = new char[str.size()];
	int i;
	for (i=0; i < str.size(); i++) {
		strin[i] = str[i];
	}
	strin[i] = '\0';
	
}

bool Skup::operator()(char c)
{
	for (int i = 0; i < strlen(strin); i++) {
		if (strin[i] == c) {
			return true;
		}
	}
	return false;
}
