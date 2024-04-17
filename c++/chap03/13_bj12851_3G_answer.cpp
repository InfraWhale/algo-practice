#include<bits/stdc++.h> // 백준 12851 3G 정답
using namespace std;
const int MAX = 100000;
int visited[MAX+4];
long long cnt[MAX+4];
int n, m;
int main() { 
	cin >> n >> m;
	if(n == m) { // 다를경우 말고 같을경우의 반례
		puts("0"); puts("1");
		return 0;
	}
	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);

	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int next : {now-1, now+1, now*2}) {

			if(0 <= next && next <= MAX) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now]; // ex : now로 가는 경우의 수가 2이고, now를 거치지 않고 next로 가는 경우의 수가 1이라면, 결국 next로 가는 경우의 수는 3이다.
				} else if (visited[next] == visited[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}
	cout << visited[m] - 1<< "\n";
	cout << cnt[m] << "\n";

	return 0;
}