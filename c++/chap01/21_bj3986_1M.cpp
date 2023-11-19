#include <bits/stdc++.h> // 백준 3986 1M
using namespace std;

int n, cnt, a, b;
string temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> temp;
        stack<char> stk;

        for(int j=0; j < temp.length(); j++){
            if(stk.empty() || stk.top() != temp[j]){
                stk.push(temp[j]);
            } else if (stk.top() == temp[j]){
                stk.pop();
            }
        }
        if(stk.size() == 0) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}