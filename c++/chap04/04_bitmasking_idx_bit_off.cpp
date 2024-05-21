#include<bits/stdc++.h> // idx번째 비트 끄기
using namespace std;

int main() {

    int S = 18; // 10010
    int idx = 1; // 오른쪽부터 43210 idx
    S &= ~(1 << idx); // 10010 & 00010 -> 11101 : 10000(16) 
    cout << S << '\n';

    return 0;
}