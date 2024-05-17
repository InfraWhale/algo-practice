#include<bits/stdc++.h> // 백준 15684 (어려웠음. 백트래킹 부분은 다른사람 풀이 참고)
using namespace std;

int n, m, h, a[34][14], t1, t2;

bool check(int start) {
	int now = start;
	int depth = 1;
	while(depth <= h) {
		if(a[depth][now]) {
			now++;
		} else if(a[depth][now - 1]){
			now--;
		}
		depth++;
	}
	return start == now;
}

bool finalCheck() {
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		if(!check(i)) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void go(int depth, int cnt, int y, int x) {
	if(depth == cnt) {
		// cout << y << " f: " << x << " f: " << depth << "\n";
		if(finalCheck()) {
			cout << cnt;
			exit(0);
		}
		return;
	}
	for(int i = y; i <= h; i++) {
		if(i != y) { // 이어서 탐색하기 위한 조건
			x = 1;
		}
		for(int j = x; j < n; j++) {
			if(a[i][j] || a[i][j-1]) continue;

			a[i][j] = 1;
			// cout << i << " : " << j << " : " << depth << "\n";
			go(depth+1, cnt, i, j);
			a[i][j] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> m >> h;
	for(int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		a[t1][t2] = 1;
	}

	if(finalCheck()) {
		cout << 0;
		return 0;
	}
	
	for(int i = 1; i <= 3; i++) {
		go(0, i, 1, 1);
	}

	cout << -1;
	
	return 0;
}