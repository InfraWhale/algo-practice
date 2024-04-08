#include<bits/stdc++.h> // 백준 2589 3B
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int n, m, y, x, ret, visited[54][54];
string s, a[54][54];

int bfs(int sy, int sx){
	fill(&visited[0][0], &visited[0][0] + 54*54, -1);
	int cnt = 0;
	queue<pair<int, int>> q;  
    visited[sy][sx] = 0;
    q.push({sy, sx});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == "W") continue; 
            if(visited[ny][nx] > -1) continue; 
            visited[ny][nx] = visited[y][x] + 1;
			cnt = max(cnt, visited[ny][nx]);
            q.push({ny, nx}); 
        } 
    }
	return cnt;
}

int main() { 
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == "L") {
				ret = max(ret, bfs(i, j));
			}
		}
	}
	
	cout << ret << "\n";
}