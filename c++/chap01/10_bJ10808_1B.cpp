#include <bits/stdc++.h> // 백준 10808 1-B
using namespace std;
string s;
int a[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        int n = s[i] - 97;
        a[s[i] - 97]++;
    }

    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}