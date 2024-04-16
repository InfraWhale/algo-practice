#include<bits/stdc++.h> // 백준 12869 3E 정답
using namespace std;

int n, ret = -987654321;
string s;
char temp;
vector<int> num;
vector<char> oper_str;
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int oper(char a, int b, int c) {
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}

void go(int here, int _num) { // 두 가지 경우로 나뉨

	cout << here << " : " << _num << "\n";

	if(here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	cout << "case1" << "\n";
	go(here + 1, oper(oper_str[here], _num, num[here + 1])); // 다음꺼에 괄호를 안 씌우는 경우

	if(here + 2 <= num.size() -1) {
		int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]); 
		cout << "case2" << "\n";
		go(here + 2, oper(oper_str[here], _num, temp)); // 다음꺼에 괄호를 씌우는 경우
	}
	return;
}

int main() { 
	fastIO();
	cin >> n;
	cin >> s;

	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) num.push_back(s[i] - '0');
		 else oper_str.push_back(s[i]);
	}

	go(0, num[0]);

	cout << ret << "\n";

	return 0;
}