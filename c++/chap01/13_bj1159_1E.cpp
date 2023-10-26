#include <bits/stdc++.h> // 백준 1159 1-E
using namespace std;

int N;
map<char, int> mp;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        if(mp.find(s[0]) == mp.end()) {
            mp.insert({s[0], 1});
        } else {
            mp[s[0]]++;
        }
    }

    for(auto m:mp) {
        if(m.second >= 5) {
            v.push_back(m.first);
        }
    }

    sort(v.begin(), v.end());

    if(v.size() > 0 ) {
        for(auto c:v) {
            cout << c;
        }
        cout << "\n";
    }else {
        cout << "PREDAJA" << "\n";
    }

    return 0;
}