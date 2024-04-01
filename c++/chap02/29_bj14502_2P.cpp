#include<bits/stdc++.h> // 백준 14502 2P (못품 -> 풀이보고 해결)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, ret, ny, nx;
int a [12][12];
bool visited[12][12]; 

vector<pair<int, int>> v0, v2;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(a[ny][nx] != 1 && !visited[ny][nx]) {
			dfs(ny,nx);
		}
	}
	return;
}

int solve() {
	fill(&visited[0][0], &visited[0][0] + 12*12, 0);
	int cnt = 0;
	for(int i = 0; i < v2.size(); i++) {
		if(!visited[v2[i].first][v2[i].second]) {
			dfs(v2[i].first, v2[i].second);
		}
	}

	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			if(a[i][j] == 0 && !visited[i][j]) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main(){
	cin >> n >> m;

	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) {
				v0.push_back({i, j});
			} else if(a[i][j] == 2) {
				v2.push_back({i, j});
			}
		}
	}

	for(int i = 0; i < v0.size(); i++ ) {
		for(int j = 0; j < i; j++) {
			for(int k = 0; k < j; k++) {
				a[v0[i].first][v0[i].second] = 1;
				a[v0[j].first][v0[j].second] = 1;
				a[v0[k].first][v0[k].second] = 1;
				ret = max(ret, solve());
				
				a[v0[i].first][v0[i].second] = 0;
				a[v0[j].first][v0[j].second] = 0;
				a[v0[k].first][v0[k].second] = 0;

			}
		}
	}

	cout << ret << "\n";

	return 0;
}
