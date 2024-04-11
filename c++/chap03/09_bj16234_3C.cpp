#include<bits/stdc++.h> // 백준 16234 3C
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, l, r, ret, cnt, a[54][54], visited[54][54];
bool flag;
vector<pair<int, int>> v;
vector<int> v2;

void dfs(int y, int x) {
	visited[y][x] = cnt;
	v[cnt].first += a[y][x];
	v[cnt].second++;
	if(v[cnt].second > 1) {
		flag = 1;
	}

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int temp = abs(a[y][x] - a[ny][nx]);
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] != -1) {
			continue;
		}
		if(temp < l || temp > r) {
			continue;
		}
		dfs(ny,nx);
	}
	return;
}

int main() { 
	cin >> n >> l >> r;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	ret = 0;

	while(true) {

		fill(&visited[0][0], &visited[0][0] + 54*54, -1);
		v.clear();
		v2.clear();
		flag = 0;
		cnt = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {

				if(visited[i][j] == -1) {
					v.push_back({0, 0});
					dfs(i, j);
					cnt++;
				}

			}
		}

		if(flag == 0) {
			break;
		} else {
			ret++;
			// cout << ret << "\n";
			for(auto it : v) {
				v2.push_back(it.first / it.second);
				// cout << it.first << " : " << it.second << "\n";
			}

			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(visited[i][j] > -1) {
						a[i][j] = v2[visited[i][j]];
					}
				}
			}
		}
	}

	cout << ret << "\n";
}