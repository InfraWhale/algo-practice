#include<bits/stdc++.h> // 백준 17071 3I (못품) , 메모리초과-> visited인 경우 방문 안하게 하여 해결
using namespace std;

int n, k, visited[2][500004], x, cnt, ret;
bool flag;

queue<int> q;


int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> n >> k;

	if(n == k) {
		cout << 0 << "\n";
		return 0;
	}

	q.push(n);
	visited[0][n] = 1;

	while(q.size()) {

		cnt++;
		k += cnt; 
		if(k > 500000) break;

		int qSize = q.size();
		for(int i=0; i < qSize; i++) {
			x = q.front();
			q.pop();
			for(int y : {x-1, x+1, x*2}) {
				if(y < 0 || y > 500000 || visited[cnt % 2][y]) continue;
					visited[cnt % 2][y] = 1;
					if(visited[cnt % 2][k]) {
						flag = 1;
						break;
					}
					q.push(y);
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) cout << cnt << "\n";
	else cout << - 1 << "\n";

	return 0;
}