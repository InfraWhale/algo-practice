#include<bits/stdc++.h> // BFS
using namespace std;

int n, m, a, b, c, d;
int mp[104][104], visited[104][104];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	while(q.size()){
		pair<int, int> here = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = here.first + dy[i];
			int nx = here.second + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if(mp[ny][nx] == 1 && !visited[ny][nx]) {
				cout << "->" << ny << " : " << nx << " : " << '\n';
				visited[ny][nx] = visited[here.first][here.second] + 1;
				q.push({ny, nx});
			}
		}
	}
}

int main(){

	cin >> n >> m;
	cin >> a >> b;
	cin >> c >> d;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			cin >> mp[i][j];
		}
	}
	
    bfs(a,b);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			cout << i << " : " << j << " : " << visited[i][j] << '\n';
		}
	}

     cout << "당근마킷의 최단거리는: " <<  visited[c][d] << '\n';

	return 0;
} 
