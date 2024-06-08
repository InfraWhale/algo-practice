#include<bits/stdc++.h> // 백준 14890 4E 정답
// 가로 한번, 세로 한번 힘들다
// 대칭을 이용해서 구현한다.

// cnt 사용해서 경사로 넣을 수 있을지 파악
// 구현 아이디어가 꽤 어려움 -> 다시보기

using namespace std;

int n, l, a[104][104], b[104][104], ret;
void solve(int a[104][104]) {
	for(int i = 0; i < n; i++) {
		int cnt = 1;
		int j;
		for(j = 0; j < n - 1; j++) {
			if(a[i][j] == a[i][j+1]) cnt++;
			else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
			else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		if(j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j]; // 대칭배열을 만듬
		}
	}
	solve(a); solve(b);
	printf("%d\n", ret);

    return 0;
}

