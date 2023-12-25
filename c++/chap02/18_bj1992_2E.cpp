#include<bits/stdc++.h> // 백준 1992 1E
using namespace std;

const int max_n = 101;
int a[max_n][max_n], visited[max_n][max_n], n, m, k, area, cnt, ret;
vector<int> v;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void go(int y, int x) {
	visited[y][x] = 1;
	area++;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if(a[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		go(ny, nx);
	}
	a[y][x]--;
	return;
}

int main(){
	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 1;
		}
	}

	while(cnt < k) {
		int tx1, ty1, tx2, ty2;
		cin >> tx1 >> ty1 >> tx2 >> ty2;
		for(int i = ty1; i < ty2; i++) {
			for(int j = tx1; j < tx2; j++) {
				a[i][j] = 0;
			}
		}
		cnt++;
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) {
			if(visited[i][j] == 0 && a[i][j] != 0){
			area = 0;
			go(i, j);
			if(area > 0) {
				v.push_back(area);
			}
			ret++;
			}
		}
	}
	cout << ret << "\n";

	sort(v.begin(),v.end());

	for(int vv : v) {
		cout << vv << " ";
	}
	
    return 0;
}
