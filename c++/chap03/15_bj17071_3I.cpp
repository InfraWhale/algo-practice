#include<bits/stdc++.h> // 백준 17071 3I (못품)
using namespace std;

int n, k, visited[500004], x, cnt, ret;
bool flag;

queue<int> q;


int main() { 
	cin >> n >> k;

	if(n == k) {
		cout << 0 << "\n";
		return 0;
	}

	q.push(n);
	visited[n] = 1;

	while(q.size()) {
		x = q.front();
		q.pop();

		for(int y : {x-1, x+1, x*2}) {
			if(y >= 0 && y <= 500000) {
				visited[y] = visited[x] + 1;
				if((visited[y]-1) > cnt) {
					cnt++;
					k += cnt;
				}
				cout << "y : " << y << " k : " << k <<"\n";
				if(y == k) {
					ret = k;
					flag = 1;
					break;
				}
				cout << "y : " << y << " k : " << k << "in" <<"\n";
				q.push(y);
			}
		}

		if(flag) {
			break;
		}

		if(k >= 500000) break;

		if(cnt == 7) break;
	}
	if(flag) cout << visited[ret] - 1<< "\n";
	else cout << - 1 << "\n";

	return 0;
}