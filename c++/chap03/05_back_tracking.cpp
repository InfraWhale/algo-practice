#include<bits/stdc++.h> // 백트래킹 1
using namespace std; 
int n, temp, ret, cnt;
vector<int> v;   
const int mod = 11;

void go(int idx, int sum){
	if(ret == 10) return;
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