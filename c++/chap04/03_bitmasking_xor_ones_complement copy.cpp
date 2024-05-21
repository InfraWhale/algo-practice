#include<bits/stdc++.h> // 비트연산자 ^, ~
using namespace std;

int main() {
    int a = 9;  // 1001
    int b = 10; // 1010
    
    // 같으면 0, 다르면 1
    cout << (a ^ b) << '\n'; // 0011 : 3

    // 1의 보수연산자(비트를 반전)
    // int는 32비트 : 3은 0 30개랑 11 -> 반전되면 1 30개랑 00
    // ~ value -> - (value + 1)
    cout << ( ~ 3) << '\n'; // 

    return 0;
}