#include<bits/stdc++.h> // 백준 1005
// 54% 틀렸습니다. -> 벡터도 초기화하도록 변경
using namespace std;

int t, n, k, x, y, w;
int delay[1004], in_degree[1004], dp[1004];
vector<int> links[1004];

void topology_sort() {
	queue<int> que;

	for (int i = 1; i <= n; i++) {
		if(in_degree[i] == 0) que.push(i);
		dp[i] = delay[i];
	}

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int next : links[now]) {
			dp[next] = max(dp[next], dp[now] + delay[next]);

			if(--in_degree[next] == 0) {
				que.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int repeat = 0; repeat < t; repeat++) {
		cin >> n >> k;

        fill(delay, delay + 1004, 0);
        fill(in_degree, in_degree + 1004, 0);
        fill(dp, dp + 1004, 0);

		for (int i = 1; i <= n; i++) {
			links[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			cin >> delay[i];
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			links[x].push_back(y);
			in_degree[y]++;
		}
		cin >> w;

		topology_sort();
		
		cout << dp[w] << "\n";
	}
	

	return 0;
}