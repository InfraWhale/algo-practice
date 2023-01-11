#include <bits/stdc++.h> // getline 여러번 

using namespace std;
int T;
string s;

int main(){
	cin >> T;
	string bufferflush;
	getline(cin, bufferflush); // 잘 모르겠음 
	for(int i = 0; i < T; i++){
		getline(cin, s);
		cout << s << "\n";
	}
	return 0;
}

