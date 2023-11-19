#include <bits/stdc++.h> // 백준 1629 1-N
using namespace std;
typedef long long ll;

ll a, b, c, ret;

ll multi(ll m, ll n) {
    if(m == 1) {
        return n % c;
    } 
    ll ret= multi(m/2, n);
    ret = ret * ret % c;
    if(m & 1) {
        ret = ret * n % c;
    } 
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> a >> b >> c;

    ret = multi(b, a);

    cout << ret << "\n";

    return 0;
}