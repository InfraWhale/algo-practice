#include <bits/stdc++.h> // 백준 9375 1J
using namespace std;

int n, m, l, k;
string s1, s2;

void print(vector<string> b){
    for(string i : b)cout << i << " ";
    cout << '\n';
}

void combi(int start, vector<string> b, string a[]){
    if(b.size() == k){
        print(b);
        return;
    }
    for(int i = start + 1; i < l; i++){
        b.push_back(a[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i < n; i++){
        cin >> m;
        map<string, int> mp;
        string arr[30];

        for(int j=0; j < m; i++){
            cin >> s1 >> s2;
            if(mp.find(s2) == mp.end()) {
                mp[s2] = 1;
                arr[j] = s2;
            } else {
                mp[s2]++;
            }
        }

        for(int j=1; j <= mp.size(); i++){
            vector<string> v;
            l = mp.size();
            k = j;
            combi(-1, v, arr);
        }
    }

    return 0;
}