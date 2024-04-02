#include<bits/stdc++.h> // 백준 2636 2Q (못품 -> 해답보고 품)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, cnt, ret, cheese, a[104][104], visited[104][104];

vector<pair<int, int>> v; 

void dfs(int y, int x) {
	visited[y][x] = 1;
	if(a[y][x] == 1) {
		cnt++;
		v.push_back({y, x});
		return;
	}
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
			continue;
		}
		if(!visited[ny][nx]) {
			dfs(ny,nx);
		}
	}
	return;
}
int main(){
	cin >> n >> m;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) {
				cheese++;
			}
		}
	}

	while(cheese > 0) {
		fill(&visited[0][0], &visited[0][0] + 104*104, 0);
		v.empty();
		cnt = 0;

		dfs(0, 0);

		for(auto it : v) {
			a[it.first][it.second] = 0;
		}
		
		ret++;
		cheese -= cnt;
	}

	cout << ret << "\n";
	cout << cnt << "\n";

	return 0;
}
