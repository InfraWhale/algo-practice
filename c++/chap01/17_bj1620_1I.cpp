#include <bits/stdc++.h> // 백준 1620 1I
using namespace std;

int n, m;
string temp;
map<int, string> mp1;
map<string, int> mp2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        mp1.insert({i, temp});
        mp2.insert({temp, i});
    }

    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(atoi(temp.c_str()) != 0){
            cout << mp1[atoi(temp.c_str())] << "\n";
        } else if (atoi(temp.c_str()) == 0){
            cout << mp2[temp] << "\n";
        }
    }

    return 0;
}