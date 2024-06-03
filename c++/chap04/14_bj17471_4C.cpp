#include<bits/stdc++.h> // 백준 17471 4C
using namespace std;
const int INF=987654321;
int n, people[14], color[14], visited[14], bCnt, rCnt, bSum, rSum, t, tt, ret = INF;
// 파란당은 1번, 빨간당은 2번
vector<int> adj[14];
bool bFlag, rFlag;

// 안되는 경우 :
// 파란당의 갯수가 0개 또는 전부라면 안된다.
// 아니라면 2개의 연결된 컴포넌트로 되어야 한다.

void dfs(int here, int hColor) {
	visited[here] = 1;
	for(int i : adj[here]) {
		if(visited[i]) continue;
		if(hColor != color[i]) continue;
		dfs(i, color[i]);
	}	
	return;
}

void go(int step) {
	if(step == n + 1) {
		// 초기화
		fill(&visited[0], &visited[14], 0);
		bFlag = 0, rFlag = 0, bSum = 0, rSum = 0;

		for(int i = 1; i <= n; i++) {
			if(color[i] == 1) {
				bSum += people[i];
				if(visited[i]) continue;
				if(!bFlag) {
					bFlag = 1;
					dfs(i, color[i]);
				} else return; // 2개의 파란당 연결된 컴포넌트가 존재할 경우
			} else if (color[i] == 2) {
				rSum += people[i];
				if(visited[i]) continue;
				if(!rFlag) {
					rFlag = 1;
					dfs(i, color[i]);
				} else return; // 2개의 빨간당 연결된 컴포넌트가 존재할 경우
			}
		}

		if(!bFlag || !rFlag) return; // 특정 당이 독점한 경우

		ret = min(abs(bSum - rSum), ret);

		return;
	}

	color[step] = 1;
	go(step + 1);

	color[step] = 2;
	go(step + 1);

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> t;
		for(int j = 1; j <= t; j++) {
			cin >> tt;
			adj[i].push_back(tt);
			adj[tt].push_back(i);
		}
	}
	
	go(1);

	if(ret == INF) cout << -1;
	else cout << ret;

    return 0;
}

