#include <bits/stdc++.h> // 백준 4375 1-O 정답
using namespace std;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(scanf("%d", &n) != EOF){
        ll cnt = 1, ret = 1;
        while(true){
            if(cnt % n == 0){
                printf("%lld\n", ret);
                break;
            } else {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}