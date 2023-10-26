#include <bits/stdc++.h> // 백준 11655 1-F
using namespace std;

string s, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    for(int c : s) {
        if(c >='A' && c <='Z') {
            c += 13;
            if(c>'Z'){
                c = c - 'Z' + 'A' - 1;
            }
            ret += (char)c;
        } else if(c>='a' && c<='z') {
            c += 13;
            if(c>'z'){
                c = c - 'z' + 'a' - 1;
            }
            ret += (char)c;
        } else {
            ret += (char)c;
        }
    }
    cout << ret <<"\n";

    return 0;
}