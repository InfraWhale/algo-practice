#include<bits/stdc++.h> // 백준 13913 3H
using namespace std;

int n, k, pre[100004], visited[100004], x;

queue<int> q;

stack<int> stk;


int main() { 
	cin >> n >> k;

	q.push(n);
	visited[n] = 1;

	while(q.size()) {
		x = q.front();
		q.pop();

		if(x == k) break;

		for(int y : {x-1, x+1, x*2}) {
			if(y >= 0 && y <= 100000) {
				if(!visited[y]) {
					visited[y] = visited[x] + 1;
					pre[y] = x;
					q.push(y);
				} 
			}
		}
	}
	int temp = k;
	while(temp != n) {
		stk.push(pre[temp]);
		temp = pre[temp];
	}

	cout << visited[k] - 1<< "\n";
	while(stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << k << "\n";

	return 0;
}