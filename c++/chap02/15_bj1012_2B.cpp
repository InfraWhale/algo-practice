#include<bits/stdc++.h> // 백준 1012 2B
using namespace std;

const int max_n = 51;
string s;
int a[max_n][max_n], visited[max_n][max_n], t, n, m, k, cnt, ret;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x) {
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(a[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		go(ny, nx);
	}
	return;
}

int main(){

	cin >> t;
	int retArr[t];

	while(cnt < t){
		fill(&a[0][0], &a[0][0] + max_n * max_n, 0); // 초기화 시켜줘야 함
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0); // 초기화 시켜줘야 함2

		ret = 0;
		
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
		}
	
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) {
				if(visited[i][j] == 0 && a[i][j] != 0){
					go(i, j);
					ret++;
				}
			}
		}
		retArr[cnt] = ret;
		cnt++;
	}

	for (int i = 0; i < t; i++) {
		cout << retArr[i] << "\n";
	}
	
    return 0;
} 
