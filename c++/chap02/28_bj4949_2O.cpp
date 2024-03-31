#include<bits/stdc++.h> // 백준 4949 2O
using namespace std;

int n;
string s;

int main(){
	while(true) {
		getline(cin, s);
		if(s == ".") break;
		stack<char> stk;
		for(char c : s) {
			if(c == '(' || c == '[') {
				stk.push(c);
			} else if (c == ')') { 
				if(stk.size() == 0 || stk.top() != '(') {
					stk.push(c);
					break;
				} else {
					stk.pop();
				}
			} else if (c == ']') { 
				if(stk.size() == 0 || stk.top() != '[') {
					stk.push(c);
					break;
				} else {
					stk.pop();
				}
			}
		}
		
		if(!stk.size()) {
			cout << "yes\n"; 
		} else {
			cout << "no\n"; 
		}
	}

	return 0;
}
