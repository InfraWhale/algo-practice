#include<bits/stdc++.h> // 백준 9934 3N 정답(구간탐색 고려할 것)
using namespace std;

vector<int> ret[14];
int n, a[1030];

void go(int s, int e, int level) {
	if(s > e) return;
	if(s == e) {
		ret[level].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	ret[level].push_back(a[mid]);
	go(s, mid-1, level + 1);
	go(mid+1, e, level + 1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n;
	int end =  (int)pow(2, n) - 1;
	for (int i = 0; i < end; i++) {
		cin >> a[i];
	}
	go(0, end, 1);
	for(int i = 1; i <=n; i++){
		for(int j : ret[i]) {
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}