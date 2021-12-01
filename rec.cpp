#define _CRT_SECURE_NO_WARNINGS 1 
#include "rec.h"
#include "skup.h"
#include <string>
int operator+(Rec r)
{
	return strlen(r.str);
}
bool provera(char str) {
	//Skup sam("aeiou")
	//Skup son("rln")
	//sam(str);
	//son(str);
	if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u' ||
		str == 'A' || str == 'E' || str == 'I' || str == 'O' || str == 'U') {
		return true;
	}
	else return false;
}
int operator~(Rec r)
{
	int brslogova = 0;
	for (int i = 0; i < +r; i++) {
		if (provera(r.str[i])) {
			brslogova++;
		}
		if (r.str[i] == 'l' || r.str[i] == 'n' || r.str[i] == 'r'||
			r.str[i] == 'L' || r.str[i] == 'N' || r.str[i] == 'R') {
			if (i == 1) {
				if (!provera(r.str[i + 1])) {
					brslogova++;
				}
			}
			if (i>1 && i<+r) {
				if (!provera(r.str[i - 1]) && !provera(r.str[i + 1])) {
					brslogova++;
				}

			}
			if (i == +r-1) {
				if (!provera(r.str[i - 1])) {
					brslogova++;
				}
			}
		}
	}
	return brslogova;
	
}
int provera_pozitivni(int n, char* str) {
	int flag = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (provera(str[i])) {

			if (flag == n) return i;
			flag++;
		}
		if (str[i] == 'l' || str[i] == 'n' || str[i] == 'r' ||
			str[i] == 'L' || str[i] == 'N' || str[i] == 'R') {
			if (i == 0) {
				if (!provera(str[i + 1])) {

					if (flag == n) return i;
					flag++;
				}
			}
			if (i > 1 && i < strlen(str)) {
				if (!provera(str[i - 1]) && !provera(str[i + 1])) {

					if (flag == n) return i;
					flag++;
				}

			}
			if (i == strlen(str) - 1) {
				if (!provera(str[i - 1])) {

					if (flag == n) return i;
					flag++;
				}
			}
		}
	}
	return -1;
}
int provera_negativni(int k, char* str) {
	int n = abs(k)-1;
	int flag = 0;
	for (int i = strlen(str)-1; i >= 0; i--) {
		if (provera(str[i])) {
			if (flag == n) return i;
			flag++;
		}

		if (str[i] == 'l' || str[i] == 'n' || str[i] == 'r' ||
			str[i] == 'L' || str[i] == 'N' || str[i] == 'R') {
			if (i == strlen(str)-1) {
				if (!provera(str[i - 1])) {

					if (flag == n) return i;
					flag++;
				}
			}
			if (i > 0 && i < strlen(str)-1) {
				if (!provera(str[i - 1]) && !provera(str[i + 1])) {

					if (flag == n) return i;
					flag++;
				}

			}
			if (i==0) {
				if (!provera(str[i + 1])) {

					if (flag == n) return i;
					flag++;
				}
			}
		}
	}
	return -1;
}
int Rec::operator()(int n)
{
	if (n >= 0) {
		return provera_pozitivni(n, str);
	}
	else return provera_negativni(n, str);
}

bool operator^(Rec r1, Rec r2)
{
	if (~r1 == 1 && ~r2 == 1) {
		int temp1 = r1.str[r1(-1)];
		int temp2 = r2.str[r2(-1)];
		if ((97 <= temp1) && (temp1 <= 122)){
			temp1-= 32;
		}
		if ((97 <= temp2) && (temp2 <= 122)) {
			temp2 -= 32;
		}

		if (char(temp1) == char(temp2)) return true;
		else return false;
	}
	else {
		int temp1 = r1.str[r1(-1)];
		int temp2 = r2.str[r2(-1)];
		int temp3 = r1.str[r1(-2)];
		int temp4 = r2.str[r2(-2)];
		if ((97 <= temp1) && (temp1 <= 122)) {
			temp1 -= 32;
		}
		if ((97 <= temp2) && (temp2 <= 122)) {
			temp2 -= 32;
		}
		if ((97 <= temp3) && (temp3 <= 122)) {
			temp3 -= 32;
		}
		if ((97 <= temp4) && (temp4 <= 122)) {
			temp4 -= 32;
		}

		
		//if (r1.str[r1(-1)] == r2.str[r2(-1)] && r1.str[r1(-2)] == r2.str[r2(-2)]) return true;
		if (char(temp1) == char(temp2) && char(temp3) == char(temp4)) return true;
		else return false;
	}
}

istream& operator>>(istream& is, Rec& r)
{
	string bbb;
	is >> bbb;
	
	r.str = new char[bbb.size()];
	int i;
	int j;
	for (i = 0, j = 0; i < bbb.size(); i++) {
		if (65 <= int(bbb[i]) && int(bbb[i])<= 90) {
			
			r.str[j] = bbb[i];
				j++;
		}
		else if (97 <= int(bbb[i]) && int(bbb[i]) <= 122) {
			r.str[j] = bbb[i];
				j++;
		}
	}
	r.str[j] = '\0';
	return is;
}

void operator<<(ostream& os, Rec& r){
	cout << r.dohvStr();
}


Rec::Rec(string str1){
	
	str = new char[str1.size()];
	int i;
	int j;
	for (i = 0, j = 0; i < str1.size(); i++) {
		if (65 <= int(str1[i]) && int(str1[i]) <= 90) {

			str[j] = str1[i];
			j++;
		}
		else if (97 <= int(str1[i]) && int(str1[i]) <= 122) {
			str[j] = str1[i];
			j++;
		}
	}
	str[j] = '\0';
	
}
