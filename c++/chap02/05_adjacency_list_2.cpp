#include<bits/stdc++.h> // 연결 리스트 2
using namespace std; 

const int V = 10;
vector<int> adj[V];
int visited[V];

void go(int idx) {
	visited[idx] = 1;
	cout << idx << "\n";
	for(int there : adj[idx]) {
		if(visited[there]) continue;
			cout << idx << "->" << there << "\n";
			go(there);
	}
	return;
}

int main(){
	adj[1].push_back(2);
	adj[2].push_back(1);

	adj[1].push_back(3);
	adj[3].push_back(1);

	adj[3].push_back(4);
	adj[4].push_back(3);


	for(int i=0; i<V; i++) {
		if(adj[i].size() && visited[i] == 0) go(i);
	}

	return 0;
} 
