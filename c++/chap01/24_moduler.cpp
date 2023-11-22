#include <bits/stdc++.h> // 모듈러 연산
using namespace std;
void f(int n){
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                int ret = (i * j + k) % n;
                int ret2 = (i % n * j + k) % n;
                if(ret != ret2) {
                    cout << i << " : " << j << " : " << k << '\n';
                }
            }
        }
    }
}

int main() {
    cout << "start" << '\n';
    for (int n = 2; n <= 100; n++) {
        f(n);
    }
    cout << "end" << '\n';
    return 0;
}