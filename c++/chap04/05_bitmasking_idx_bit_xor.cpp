#include<bits/stdc++.h> // idx번째 비트 xor (0이라면 1로, 1이라면 0으로)
using namespace std;

int main() {

    int S = 18; // 10010
    int idx = 0; // 오른쪽부터 43210 idx
    S ^= (1 << idx); // 10010 ^ 00001 : 10011(19) 
    cout << S << '\n';

    return 0;
}