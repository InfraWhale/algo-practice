#include <bits/stdc++.h> // 백준 9375 1J 정답
using namespace std;
int t, n;
string a, b;
int main() {
    cin >> t;
    while(t--){
        map<string, int>_map;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            _map[b]++;
        }
        long long ret = 1;
        for(auto c : _map){
            ret *= ((long long)c.second + 1);
        }
        ret--;
        cout << ret << "\n";
    }
    return 0;
}