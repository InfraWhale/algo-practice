#include<bits/stdc++.h> // 백준 9012 2N
using namespace std;

int n;
string s;


int main(){

	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> stk;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if(s[j] == '(') {
				stk.push(s[j]);
			} else if(s[j] == ')') {
				if(stk.size() == 0 || stk.top() == ')') {
					stk.push(s[j]);
				} else {
					stk.pop();
				}
			}
		}

		if(!stk.size()) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		} 
	}
		

	return 0;
}
