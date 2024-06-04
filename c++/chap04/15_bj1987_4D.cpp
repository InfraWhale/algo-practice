#include<bits/stdc++.h> // 백준 1987 4D (비트마스킹으로 풀기)
using namespace std;

int R, C, ret, ny, nx;
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt) {
	ret =max(ret, cnt);
	for(int i = 0; i < 4; i++) {
		ny = y +dy[i], nx = x + dx[i];
		if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
		int _next = (1 << (int)(a[ny][nx] - 'A')); // A -> 1(2), // B -> 10(2) ...
		if((num & _next) == 0) go(ny, nx, num | _next, cnt + 1); 
		// _next에 해당하는 비트 없으면, | 연산자로 해당 비트 추가 후 다음으로 진행
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
	cout << ret << '\n';
    return 0;
}

