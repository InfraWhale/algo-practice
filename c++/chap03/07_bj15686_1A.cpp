#include<bits/stdc++.h> // 백준 15686 1A(못품)
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, cut, ret, a[54][54], visited[54][54];
vector<pair<int, int>> v1, v2;

int go(){
	int ans = 0;
	for(auto it : v1) {
		int y = it.first;
		int x = it.second;
		int flag = 0;
		int cnt = 0;
	
		queue<pair<int, int>> q; 
		visited[y][x] = 1;
		q.push({y, x});  
		while(q.size()){
			tie(y, x) = q.front(); 
			q.pop(); 
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i]; 
				int nx = x + dx[i]; 
				if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if(visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;

				if(a[ny][nx] == 2) {
					cnt = visited[ny][nx];
					flag = 1;
					break;
				}
				q.push({ny, nx}); 
			}
			if(flag == 1) break;
		}
		ans += cnt;
	}
	return ans;
}

void change(int c, int s) {
	if(c == cut) {
		ret = min(go(), ret);
		return;
	}

	for(int i = s; i < v2.size(); i++) {
		a[v2[i].first][v2[i].second] = 0;
		change(c+1, i+1);
		a[v2[i].first][v2[i].second] = 1;
	}
	return; 
}



int main() { 
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) v1.push_back({i, j});
			if(a[i][j] == 2) v2.push_back({i, j});
		}
	}

	cut = v2.size() - m; // 이 개수만큼 치킨집(2)을 0으로 바꿈 

	ret = 10000;

	change(0, 0);

	cout << ret << "\n";

    return 0;
}