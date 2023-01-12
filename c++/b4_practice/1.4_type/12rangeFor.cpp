#include<bits/stdc++.h> // 범위기반 for 루프 

using namespace std;
string a[2] = {"out of time", "i love you"};

int main(){
	for(string b : a) cout << b << '\n';
	for(int i = 0; i < 2; i++) cout << a[i] << "\n";
}
