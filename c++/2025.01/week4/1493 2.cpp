#include <bits/stdc++.h>
using namespace std;

int l, w, h, n;
int a[20], b[20]; // 입력의 최대 크기 n=20
int cnt = 0;

bool count_cube(int len, int wid, int hei) {
    // 기저사례
    if (len == 0 || wid == 0 || hei == 0) return true;

    int min_side = min({len, wid, hei}); // 현재 공간의 최소 변 길이
    int pos = -1;

    // 가장 큰 큐브부터 사용할 수 있는 큐브를 찾음
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] > 0 && a[i] <= min_side) { // 큐브가 남아있고 공간에 들어갈 수 있다면
            pos = i;
            break;
        }
    }

    // 유효한 큐브가 없는 경우
    if (pos == -1) return false;

    int now_cube = a[pos]; // 현재 선택한 큐브 크기
    b[pos]--;              // 큐브를 하나 사용
    cnt++;                 // 사용한 큐브 개수 증가

    // 현재 공간에서 큐브를 배치하고 나머지 공간을 재귀적으로 채움
    bool result = count_cube(len - now_cube, wid, hei) &&
                  count_cube(now_cube, wid - now_cube, hei) &&
                  count_cube(now_cube, now_cube, hei - now_cube);

    if (!result) {
        b[pos]++; // 실패한 경우 큐브 복구
        cnt--;    // 사용한 큐브 개수 감소
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> w >> h;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp >> b[i]; // 큐브 크기와 개수 입력
        a[i] = (1 << temp);  // 큐브의 변 크기를 2^temp로 저장
    }

    if (count_cube(l, w, h)) {
        cout << cnt << "\n";
    } else {
        cout << -1 << "\n"; // 공간을 채울 수 없는 경우
    }

    return 0;
}
