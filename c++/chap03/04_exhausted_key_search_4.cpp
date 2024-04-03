#include<bits/stdc++.h> // 재귀를 이용한 완전탐색 2
using namespace std; 
int n, temp, ret, cnt;
vector<int> v;   
const int mod = 11;

void go(int idx, int sum){
	if(idx == n){
		ret = max(ret, sum % mod); 
		cnt++; 
		return;
	}
	go(idx + 1, sum + v[idx]);
	go(idx + 1, sum);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	go(0, 0);
	cout << ret << "\n"; 
	cout << cnt << "\n"; 
	return 0; 
}