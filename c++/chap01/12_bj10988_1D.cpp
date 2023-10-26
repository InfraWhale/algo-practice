#include <bits/stdc++.h> // 백준 10988 1-D
using namespace std;

string str;
int ret = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(str[i] != str[str.length()-(i+1)]) {
            ret = 0;
            break;
        }
    }

    cout << ret << '\n';
    return 0;
}