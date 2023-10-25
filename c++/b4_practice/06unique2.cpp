#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> v2 {1,1,2,2,3,3,5,6,7,8,9};
vector<int> v3 {2,2,1,1,2,2,3,3,5,6,7,8,9};

int main(){
    for(int i=1; i<=5; i++){
        v.push_back(i);
        v.push_back(i);
    }

    for(int i : v) cout << i << " ";
    cout << '\n';

    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n';
    for(int i : v) cout << i << " ";
    cout << '\n';

    auto it2 = unique(v2.begin(), v2.end());
    for(int i : v2) cout << i << " ";
    cout << '\n'; 

    sort(v3.begin(), v3.end()); 
    v3.erase(unique(v3.begin(), v3.end()), v3.end());
    for(int i : v3) cout << i << " ";
    cout << '\n'; 

    return 0;
}