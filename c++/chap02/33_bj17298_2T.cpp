#include<bits/stdc++.h> // 백준 17298 2T (못품. 이게 짝짓기?)
using namespace std;

int n, cnt, a[1000001], b[1000001];
stack<int> stk;

int main(){
	cin >> n;

	fill(&a[0], &a[0] + 1000001, -1);
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		while(stk.size() && b[i] > b[stk.top()]) {
			a[stk.top()] = b[i];
			stk.pop();
		}
		stk.push(i);
	}

	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}
