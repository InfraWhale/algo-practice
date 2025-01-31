#include<bits/stdc++.h> // 백준 2230
using namespace std;

int n, m, ret;
int a[100004];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);
	ret = 2000000001;
	int front = 0;
	int back = 0;

	while( front <= n || back <= n ) {
		if(a[back]-a[front] < m) {
			back++;
		} else if (a[back]-a[front] > m) {
			ret = min(ret, a[back]-a[front]);
			front++;
		} else {
			ret = m;
			break;
		}
	}

	cout << ret;

	return 0;
}