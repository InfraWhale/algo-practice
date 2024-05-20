#include<bits/stdc++.h> // 비트연산자 & , |
using namespace std;

int main() {
    int a = 9; // 1001
    int b = 8; // 1000
    cout << (a & b) << '\n'; // 8 : 1000

    a = 9; // 1001
    b = 7; // 0111
    cout << (a | b) << '\n'; // 15 : 1111
    return 0;
}