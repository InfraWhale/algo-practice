#include<bits/stdc++.h> // 백준 9934 3N (모르겠음 -> inorder 떠올려야 함)
using namespace std;

int k, a[1030];
vector<int> v[14];

void go(int start, int end, int depth) {
	if(start > end) return;
	if(start == end) {
		v[depth].push_back(a[start]);
		return;
	}
	int mid = (start + end) / 2;
	v[depth].push_back(a[mid]);

	go(start, mid - 1, depth + 1);
	go(mid + 1, end, depth + 1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> k;
	int n = pow(2, k) - 1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(0, n-1, 0);

	for(int i = 0; i < k; i++) {
		for(int it : v[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}