#include<bits/stdc++.h>
using namespace std;

int a, b, c, sum = 0;
int d[100];

int main(){

    fill(&d[0], &d[100], 0);
    cin >> a >> b >> c;

    for(int i=0; i<3; i++){
        pair<int, int> t;
        cin >> t.first >> t.second;
        for(int j=0; j<t.second; j++) d[j]++;
        for(int j=0; j<t.first; j++) d[j]--;
    }

    for(int i:d) {
        if(i == 1) {
            sum += a;
        }else if(i == 2) {
            sum += 2*b;
        }else if(i == 3) {
            sum += 3*c;
        }
    }
    
    cout << sum << '\n';

    return 0;
}