#include <bits/stdc++.h> // 백준 9375 1J
using namespace std;

int n, m, ans;
string s1, s2;
vector<int>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i < n; i++){
        cin >> m;
        map<string, int> mp;
        ans = 1;

        for(int j=0; j < m; j++){
            cin >> s1 >> s2;
            if(mp.find(s2) == mp.end()) {
                mp[s2] = 1;
            } else {
                mp[s2]++;
            }
        }

        for(auto it : mp){
            ans *= ((it).second + 1);
        }

        v.push_back(ans-1);
    }

    for(int a : v) {
        cout << a << "\n";
    }

    return 0;
}