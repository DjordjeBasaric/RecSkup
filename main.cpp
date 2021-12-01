#define _CRT_SECURE_NO_WARNINGS 1 
#include "skup.h"
#include "rec.h"
void main() {
	
	string ime = "Banana";
	char g = 'G';
	char b = '6';
	char a = 'a';
	Skup s(ime);
	s += g;
	s += b;
	s += a;
	if (s('n')) printf("Nalazi se\n");
	else printf("ne nalazi se\n");
	if (s('6')) printf("Nalazi se\n");
	else printf("ne nalazi se\n"); 
	printf("%s\n", s.dohvStr());

	string ime1 = "Tatat5acsajnjatira";
	string ime2 = "TiRa";
	Rec r1(ime1);
	Rec r2(ime2);
	int t = +r1;
	int k = ~r1;
	printf("%s\n", r1);
	printf("3 slog: %d\n", r1(3));
	printf("3 od pozadi slog: %d\n", r1(-3));
	printf("0 slog: %d\n", r1(0));
	printf("Neuspesni slog %d\n", r1(123));
	if (r1 ^ r2) printf("rimuju se\n");
	else printf("ne rimiju se\n");
	
	cin >> r2;
	cout << r2;
	

}