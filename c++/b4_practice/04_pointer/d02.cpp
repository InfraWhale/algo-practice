#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    for(int i = 1; i <= 5; i++)
        v.push_back(i);
    for(int i = 0; i < 5; i++){
        cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";
        cout << &*(v.begin() + i) << '\n';
    }
// cout << v.begin() << '\n'; //에러 // 이터레이터는 주소값을 바로 반환하지 않는다. 쓸려면 &* 붙혀줘야함 
}
