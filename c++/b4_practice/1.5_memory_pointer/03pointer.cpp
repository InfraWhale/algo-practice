#include<bits/stdc++.h> // Æ÷ÀÎÅÍ 

using namespace std;
int i;
string s = "kundol";

int main(){
	i = 0;
	int * a = & i;
	cout << a << '\n';
	cout << * a << '\n';

	string * b = &s;
	cout << b << '\n';
	cout << * b << '\n';
	
	return 0;
}

