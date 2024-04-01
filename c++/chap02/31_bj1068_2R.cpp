#include<bits/stdc++.h> // 백준 1068 2R (어렵...)
using namespace std;

int n, m, root, temp, ret;
vector<int> adj[54];
int visited[54];

void dfs(int u) {
	int child = 0;
	visited[u] = 1;
	for(int v : adj[u]){
		if(visited[v] == 0 && v != m) {
			child ++;
			dfs(v);
		}
	}
	if(child == 0) {
		ret ++;
	}
	return;
}

int main(){
	cin >> n;
	for(int i=0; i < n; i++) {
		cin >> temp;
		if(temp == -1) {
			root = i;
		} else {
			adj[temp].push_back(i);
		}
	}

	cin >> m;

	if(m == root) {
		cout << 0 << "\n";
		return 0;
	}

	adj[m].clear();

	dfs(root);

	cout << ret << "\n";

	return 0;
}
