#include<bits/stdc++.h> // 백준 2156
// 2% 시간초과 -> 2% 틀렸습니다. -> 86% 틀렸습니다.
using namespace std;

int n;

int main() {
	cin >> n;
	int arr[n], dp[n][2];
	fill(&dp[0][0], &dp[0][0] + n * 2 , 0);

	// cout << "n : " << n << "\n";

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		cout << arr[0];
	} else if (n == 2) {
		cout << arr[0]+arr[1];
	} else if (n == 3) {
		cout << max(arr[0]+arr[2], arr[1]+arr[2]);
	} else {
		dp[0][0] = arr[0];
		dp[1][0] = arr[0]+arr[1];
		dp[1][1] = arr[1];
		dp[2][0] = arr[1]+arr[2];
		dp[2][1] = arr[0]+arr[2];
		dp[2][2] = arr[2];

		for (int i = 3; i < n; i++) {
			dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[i];
			dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
			dp[i][2] = max(dp[i-3][0], dp[i-3][1]) + arr[i];
		}
		cout << max(max(dp[n-1][0], dp[n-1][1]), max(dp[n-2][0], dp[n-1][2]));
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < 2; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	return 0;
}