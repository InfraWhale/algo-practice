#include<bits/stdc++.h>
using namespace std;

int i;
int main(){
    cout << &i << '\n';
    i = 0;
    cout << &i << '\n'; // 값 할당해도 주소가 같음
    
}

