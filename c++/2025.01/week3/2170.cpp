#include<bits/stdc++.h> // 백준 2170
// 2% 시간초과 , 입출력 tie(NULL) 해주니 해결 ...
using namespace std;

int n, ret;
vector<pair<int, int>> v;
stack<pair<int, int>> stk;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first; // second가 같으면 first를 오름차순으로 정렬
    }
    return a.second < b.second; // second를 우선 기준으로 오름차순 정렬
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int start, end;
	for(int i=0; i<n; i++) {
		// cin >> v[i].first >> v[i].second;
		cin >> start >> end;
		v.push_back({start, end});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto now : v) {
		if(!stk.empty() and stk.top().second == now.second) {
			continue;
		}
		while (!stk.empty() and stk.top().second >= now.first) {
			pair<int, int> prev = stk.top();
			now = {min(prev.first, now.first), max(prev.second, now.second)};
			ret -= (prev.second - prev.first);
			stk.pop();
		}
		// cout << now.first << " : " << now.second << "\n";
		stk.push(now);
		ret += (now.second - now.first);
	}

	cout << ret;
	return 0;
}