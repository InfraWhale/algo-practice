#include<bits/stdc++.h> // 백준 12851 3G (못품)
using namespace std;

int n, k, cnt[100004], visited[100004], x, ret;

queue<int> q;


int main() { 
	cin >> n >> k;

	ret = 987654321;

	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;

	while(q.size()) {
		x = q.front();
		q.pop();

		if(visited[x] > ret) break;

		if(x == k) {
			ret = visited[x];
			continue;
		}

		for(int y : {x-1, x+1, x*2}) {
			if(y >= 0 && y <= 100000) {
				if(!visited[y]) {
					visited[y] = visited[x] + 1;
					cnt[y] += cnt[x];
					q.push(y);
				} else if(visited[y] == visited[x] + 1) {
					cnt[y] += cnt[x];
				}
			}
		}
	}

	cout << visited[k] - 1<< "\n";
	cout << cnt[k] << "\n";

	return 0;
}