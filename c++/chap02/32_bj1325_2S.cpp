#include<bits/stdc++.h> // 백준 1325 2S
using namespace std;

int n, m, temp1, temp2, cnt;
vector<int> adj[10004];
vector<int> v;
int visited[10004];

void bfs(int here) {
	queue<int> q;
	visited[here] = 1;
	q.push(here);
	while(q.size()){
		int here = q.front(); 
		q.pop();
		for(int there : adj[here]){
			if(visited[there]) continue;
			visited[there] = visited[here] + 1;
			cnt++;
			q.push(there);
		}
	}
}

int main(){
	cin >> n >> m;

	while(m--) {
		cin >> temp1 >> temp2;
		adj[temp2].push_back(temp1);
	}

	int max = 0;

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		fill(&visited[0], &visited[10004], 0);
		bfs(i);

		if(cnt > max) {
			v.clear();
			v.push_back(i);
			max = cnt;
		} else if(cnt == max) {
			v.push_back(i);
		}
	}

	for(auto it : v) {
		cout << it << "\n";
	}
	return 0;
}
