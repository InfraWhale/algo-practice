#include<bits/stdc++.h> // 백준 11265 // 맞았습니다.
using namespace std;

int n, m;
int arr[501][501];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int count = 0; count < m; count++) {

		int a, b, c;
		cin >> a >> b >> c;

		if (arr[a-1][b-1] <= c) {
			cout << "Enjoy other party" << "\n";
		} else {
			cout << "Stay here" << "\n";
		}
	}

	return 0;
}