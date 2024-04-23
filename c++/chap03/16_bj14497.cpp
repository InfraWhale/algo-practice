#include<bits/stdc++.h> // 백준 14497 (=, == 헷갈리지좀 말자)
using namespace std;
#define y1 xoxo

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, a[304][304], visited[304][304], y1, x1, y2, x2, cnt;
vector<pair<int, int>> v;
string s;

void go(int y, int x) {
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny == y2 && nx == x2) {
			cout << cnt << "\n";
			exit(0);
		}

		if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		if(a[ny][nx] == 1) {
			visited[ny][nx] = 1;
			v.push_back({ny, nx});
			continue;
		} 
		go(ny, nx);

	}
	return;
}


int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	x1--; y1--; x2--; y2--;

	for(int i=0; i < n; i++) {
		cin >> s;
		for(int j=0; j < m; j++) {
			if(s[j]== '#' || s[j] == '*' ) a[i][j] = 0;
			else a[i][j] = s[j] -'0';
		}
	}
	if(y1==y2 && x1==x2) {
		cout << 0 << "\n";
		return 0;
	}

	while(true) {
		fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);
		
		cnt++;
		go(y1, x1);
		for (auto it : v) {
			a[it.first][it.second] = 0;
		}
		v.clear();
	}


	return 0;
}