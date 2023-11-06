#include <bits/stdc++.h> // 백준 1213 1K
using namespace std;

string s, t;
map<char, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    t = s;

    sort(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++) {
        mp[s[i]] ++;
    }

    int flag = 0;
    int cnt = 0;

    for(auto it : mp) {
        if(it.second % 2 == 1){
            if(flag == 0){
                flag = 1;
                t[s.length()/2] = it.first;
            } else if(flag == 1){
                t = "I'm Sorry Hansoo";
                break;
            }
        }
        if(it.second != 1) {
            for(int i = cnt; i < cnt +it.second/2; i++){
                t[i] = it.first;
                t[s.length()-i-1] = it.first;
            }
        }
        cnt = cnt + it.second/2;
    }

    cout << t << "\n";

    return 0;
}