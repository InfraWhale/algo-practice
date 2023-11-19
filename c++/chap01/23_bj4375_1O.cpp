#include <bits/stdc++.h> // 백준 4375 1-O
using namespace std;
typedef long long ll;

ll a;
int n, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(scanf("%d", &n) != EOF){
        a = 1;
        cnt = 1;
        while(a%n != 0){
            a = a * 10 + 1;
            a %= n;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}