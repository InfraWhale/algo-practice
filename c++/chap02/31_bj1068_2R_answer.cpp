#include<bits/stdc++.h> // 백준 1068 2R 정답
using namespace std;

int n, r, root, temp;
vector<int> adj[54];

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for(int there : adj[here]) {
		if(there == r) continue;
		ret += dfs(there);
		child++;
	}
	if(child == 0) return 1;
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i < n; i++) {
		cin >> temp;
		if(temp == -1) root = i;
		else adj[temp].push_back(i);
	}

	cin >> r;

	if(r == root) {
		cout << 0 << "\n";
		return 0;
	}

	cout << dfs(root) << "\n"; // 트리는 루트노드부터 탐색할 것!
	return 0;
}
