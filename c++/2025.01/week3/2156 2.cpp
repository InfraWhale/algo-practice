#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10001]; // 최대 10,000개의 포도주 잔
int dp[10001];  // 최대 포도주 양 저장

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << arr[0];
        return 0;
    }

    // 초기값 설정
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({arr[0] + arr[1], arr[0] + arr[2], arr[1] + arr[2]});

    // 점화식 적용
    for (int i = 3; i < n; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]});
    }

    // 최대값 출력
    cout << dp[n - 1];
    return 0;
}
