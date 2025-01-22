#include<bits/stdc++.h> // 백준 16401
using namespace std;

int m, n, ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int start = 1;
	int end = arr[n-1];
	int mid, cnt;
	ret = 0;

	while(start <= end) {
		mid = (start+end) / 2;
		cnt = 0;
		for (int i = n-1; i >= 0; i--) {
			if (arr[i] < mid) break;
			cnt += (arr[i] / mid);
		}

		// 충족한 경우
		if (cnt >= m) {
			ret = max(ret, mid);
			start = mid+1;
		// 아닌 경우
		} else {
			end = mid-1;
		}
	}

	cout << ret;

	return 0;
}