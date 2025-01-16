#include<bits/stdc++.h> // 백준 1034
// gpt 풀이
// 두 행이 완벽하게 같지 않으면, 스위치를 아무리 누른 들 두 행이 동시에 켜저있는 행이 될 순 없다.
using namespace std;

int n, m, k;
vector<string> lamp;
map<string, int> stateCount;

int main() {
    cin >> n >> m;
    lamp.resize(n); // n개만큼 ""으로 초기화

    // 입력받기 및 상태 카운트
    for (int i = 0; i < n; i++) {
        cin >> lamp[i];
        stateCount[lamp[i]]++;
    }

    cin >> k;

    int result = 0;

    // 모든 행의 상태를 순회
    for (auto it = stateCount.begin(); it != stateCount.end(); ++it) {
        string state = it->first;  // 상태 문자열
        int count = it->second;   // 상태 개수

		// 범위 안의 원소들 중 특정 조건을 만족하는 원소의 갯수를 센다.
        int offCount = count_if(state.begin(), state.end(), [](char c) { return c == '0'; });

        // 꺼진 램프 수와 k 관계 확인
        if (offCount <= k && (k - offCount) % 2 == 0) {
            result = max(result, count);
        }
    }

    cout << result << endl;

    return 0;
}