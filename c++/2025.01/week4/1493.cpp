#include<bits/stdc++.h> // 백준 1493
using namespace std;
// 맞았습니다 -> 그림을 그려봤다면 쉽게 풀었을 것 같은 문제

int l, w, h, n;
int a[20], b[20];
int cnt;

void count_cube(int len, int wid, int hei) {
	// 기저사례
	if(len == 0 || wid == 0 || hei == 0) {
		return;
	}

	int min_side = min({len, wid, hei});
	int pos = -1;
	for (int i = n-1 ; i >= 0; i--) {
        if (b[i] > 0 && a[i] <= min_side) {
            pos = i;
            break;
        }
	}

	if (pos == -1) {
		cout << -1;
		exit(0);
	}

	cnt++;
	b[pos]--;

	int now_cube = a[pos];
	// cout << "now_cube : " << now_cube << "\n";
	count_cube(len - now_cube, wid, hei);
	count_cube(now_cube, wid - now_cube, hei);
	count_cube(now_cube, now_cube, hei - now_cube);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> w >> h;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp >> b[i];
		a[i] = (1 << temp);
	}

	cnt = 0;
	count_cube(l, w, h);
	cout << cnt;

	return 0;
}