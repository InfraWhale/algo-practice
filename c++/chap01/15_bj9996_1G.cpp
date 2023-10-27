#include <bits/stdc++.h> // 백준 9996 1-G
using namespace std;

int n;
string s, s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;
    s1 = s.substr(0, s.find("*"));
    s2 = s.substr(s.find("*")+1, s.size()-s.find("*")-1);

    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        if(s1 == temp.substr(0, s1.size())){
            temp.erase(0, s1.size());
            int a = temp.size()-s2.size();
            if( a >= 0  && s2 == temp.substr(a, s2.size())){
                cout << "DA" << "\n";
            }else {
                cout << "NE" << "\n";
            }
        }else{
            cout << "NE" << "\n";           
        }
    }

    return 0;
}