#include<bits/stdc++.h> // 비트연산자 <<, >>
using namespace std;

int main() {
    int a = 7; // 1001
    cout << (a << 1) << '\n'; // 14 : 10010
    cout << (a << 2) << '\n'; // 28 : 100100
    cout << (a << 3) << '\n'; // 56 : 1001000

    cout << (1 << 3) << '\n'; // 8 : 3+1번째의 비트가 켜져있다

    cout << (11 >> 2) << '\n'; // 1011 (11) -> 10 (2)

    return 0;
}