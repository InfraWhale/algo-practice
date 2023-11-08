#include <bits/stdc++.h> // 백준 1940 1L
using namespace std;

int n, m, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a[n];

    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        a[i] = t;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] + a[j] == m) cnt++;
        }
    }

    cout << cnt <<"\n";

    return 0;
}