#include<bits/stdc++.h>
using namespace std;

int a[26];
string stg;

int main(){

    fill(&a[0], &a[26], 0);
    cin >> stg;

     for(auto i : stg) {
        a[i-97]++;
    }

    for(int i = 0; i < 26; i++) {
        cout << a[i] << " ";
    }

    return 0;
}