#include <bits/stdc++.h> // 백준 1940 1L 정답
using namespace std;

int n, m, a[15001], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> a[i];

    // 이 if문은 없어도 됨. but, 설명을 위해
    if(m > 200000) cout << 0 << "\n";
    else {
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] + a[j] == m) cnt++;
            }
        }   
        cout << cnt <<"\n";
    }
}