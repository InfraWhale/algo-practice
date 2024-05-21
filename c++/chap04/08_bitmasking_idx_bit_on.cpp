#include<bits/stdc++.h> // idx의 비트 켜기
using namespace std;

int main() {

    int S = 18; // 10010
    int idx = 0; // 00001
    S |= (1 << idx); // 10010 | 00001
    cout << S << '\n';

}