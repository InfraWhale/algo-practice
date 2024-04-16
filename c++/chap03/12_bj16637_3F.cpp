#include<bits/stdc++.h> // 백준 12869 3F (모르겠음...풀이 봐도 모르겠음 -> 품)
using namespace std;

int n, ret;
string s;
char temp;
vector<int> vInt;
vector<char> vChar;

int oper(char a, int b, int c) {
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}

void go(int pos, int ans) {
	if(pos == vInt.size() - 1) {
		ret = max(ret, ans);
		return;
	}

	go(pos + 1, oper(vChar[pos], ans, vInt[pos+1]));

	// if(pos <= vInt.size() - 3) { // 이렇게 하면 OutOfBounds... 왜?
	if(pos + 2 <= vInt.size() - 1) {
		go(pos + 2, oper(vChar[pos], ans, oper(vChar[pos+1], vInt[pos+1], vInt[pos+2])));
	}
	return;
}

int main() { 
	cin >> n;
	cin >> s;

	for(int i = 0; i < n; i++) {
		if(i % 2 == 1) {
			vChar.push_back(s[i]);
		} else {
			vInt.push_back(s[i] - '0');
		}
	}

	ret = -987654321;
	go(0, vInt[0]);

	cout << ret << "\n";

	return 0;
}