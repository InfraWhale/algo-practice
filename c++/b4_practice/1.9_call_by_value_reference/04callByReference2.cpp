#include<bits/stdc++.h> // 참조에 의한 호출 2

using namespace std;

vector<int> v(3, 0);

void go(vector<int> &v){
	v[1] = 100;
}
int main(){
	go(v);
	for(int i : v) cout << i << '\n';
}
