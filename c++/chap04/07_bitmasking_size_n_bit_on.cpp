#include<bits/stdc++.h> // 크기가 n인 집합의 모든 비트를 켜기
using namespace std;

int main() {

    int n = 4;
    cout << (1 << n) - 1 << '\n'; // 10000 -1 -> 1111

    n = 6;
    int m = 4;
    cout << ((1 << n) - 1) - ((1 << m) - 1) << '\n'; // 1000000 -1 -> 111111 | 10000 -1 -> 1111 : 110000
    return 0;
}