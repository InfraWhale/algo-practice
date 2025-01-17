#include<bits/stdc++.h> // 백준 2170
// 2% 시간초과
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second; 
    }
    return a.first < b.first;
}

int n, ret;
stack<pair<int, int>> stk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	pair<int, int> a[n];
	int start, end;
	for(int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a+n, cmp);
	start = a[0].first;
	end = a[0].second;
	for(int i=1; i<n; i++) {
		if (start == a[i].first) {
			continue;
		} else if (end >= a[i].first) {
			//end = a[i].second;
			end = max(end, a[i].second);
		} else {
			ret += (end-start);
			start = a[i].first;
			end = a[i].second;
		}
	}

	ret += (end-start);
	cout << ret;
	return 0;
}