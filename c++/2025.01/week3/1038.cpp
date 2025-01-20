#include<bits/stdc++.h> // 백준 1038
// 31% 틀렸습니다.
using namespace std;

int n, cnt, pre, now;
bool flag = true;

int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if( n / 10 == 0) {
		cout << n;
		exit(-1);
	}

	cnt = 9;

	for (int i = 10; i <= 9876543210; i++) {
		int temp_i = i;
		now = temp_i % 10;
		flag = true;

		while( temp_i >= 10) {
			pre = now;
			temp_i /= 10;
			now = temp_i % 10;
			
			if( pre >= now ) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cnt += 1;
			if (cnt == n) {
				cout << i;
				exit(-1);
			}
		}
	}
	cout << -1;

	return 0;
}