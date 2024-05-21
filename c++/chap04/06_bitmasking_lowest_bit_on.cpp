#include<bits/stdc++.h> // 최하위 켜져있는 비트 찾기
using namespace std;

int main() {

    int S = 18; // 10010
    int idx = (S & -S); // 0 27개 10010 & 1 27개 01101 + 1 ( -S = ~S + 1 이므로 )
    cout << idx << '\n'; // 2

    return 0;
}