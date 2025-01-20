#include <bits/stdc++.h> // gpt 풀이
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 감소하는 수를 저장할 큐
    queue<long long> q;
    vector<long long> decreasing_numbers;

    // 한 자릿수 숫자(0~9)를 초기값으로 큐에 삽입
    for (int i = 0; i <= 9; i++) {
        q.push(i);
    }

    // BFS를 통해 감소하는 수 생성
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        decreasing_numbers.push_back(current);

        // 마지막 자릿수보다 작은 숫자를 붙여 감소하는 수 생성
        int last_digit = current % 10;
        for (int i = 0; i < last_digit; i++) {
            q.push(current * 10 + i);
        }
    }

    // 감소하는 수는 최대 1022개만 존재
    if (n >= decreasing_numbers.size()) {
        cout << -1 << '\n';
    } else {
        cout << decreasing_numbers[n] << '\n';
    }

    return 0;
}