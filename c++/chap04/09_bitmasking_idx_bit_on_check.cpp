#include<bits/stdc++.h> // idx의 비트 켜져있는지 확인
using namespace std;

int main() {

    int S = 18; // 10010
    int idx = 4; // 00001
    if(S & (1 << idx)) {
        cout << "해당 idx : " << idx << "가 켜져있습니다.\n";
    } else {
        cout << "해당 idx : " << idx << "가 꺼져있습니다.\n";
    }
}