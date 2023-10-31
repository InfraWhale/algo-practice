#include <bits/stdc++.h> // 백준 2559 수열
using namespace std;

int n, m, l;

vector<int> v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }

    l = 0;

    for(int i=0; i<m; i++) {
        l += v1[i];
    }

    v2.push_back(l);

    for(int i=1; i<n-m+1; i++) {
        l -= v1[i-1];
        l += v1[m+i-1];
        v2.push_back(l);
    }

    cout << *max_element(v2.begin(),v2.end()) << "\n";

    return 0;
}