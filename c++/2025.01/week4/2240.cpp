#include<bits/stdc++.h> // 백준 2240 // 못품
using namespace std;

int t, w, pos, cnt, jadu, max_val;
int dp[1004][30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;

	fill(dp, dp+1004*30, 0);

	cnt = 0;
	max_val;
	pos = 1;
	jadu = 0;

	for (int i = 0; i < t; i++) {
		int now;
		cin >> now;
		for (int j = 0; i < w; i++) {
			if (now == pos) {

			}
		}
		if (now == pos) {

			
		} else {
			if(cnt < w) {
				cnt++;
				max_val += jadu;
			} else {
				if (que.front() < jadu) {
					max_val = max_val - que.front() + jadu;
				}
				que.pop();
			}
			que.push(jadu);
			jadu = 1;
			pos = now;
		}
	}

	// if(cnt < w) {
	// 	max_val += jadu;
	// } else {
	// 	if (que.front() < jadu) {
	// 		max_val = max_val - que.front() + jadu;
	// 	}
	// }



	for (int i = 0; i < t; i++) {
		int now;
		cin >> now;
		if (now == pos) {
			jadu++;
		} else {
			que.push(jadu);
			jadu = 1;
			pos = now;
		}
	}
	que.push(jadu);



	cout << max_val;

	return 0;
}