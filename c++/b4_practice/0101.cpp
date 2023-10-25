#include<bits/stdc++.h>
using namespace std;

int a[9];
int sum, b, c = 0;

int main(){

    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+9);

    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if (sum - a[i] - a[j] == 100) {
                b = i;
                c = j;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        if (i != b && i != c) {
            cout << a[i] << '\n';
        }
    }

    return 0;
}