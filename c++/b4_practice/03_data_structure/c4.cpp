#include<bits/stdc++.h> // sort - vector 안에 pair 
using namespace std;

vector<pair<int, int>> v;

int main(){
	for(int i = 10; i >= 1; i--){
		v.push_back({i, 10 - i});
	}
	
	sort(v.begin(), v.end()); // sort시 first, second 중에 first 기준으로 오름차순 정렬된다
	 
	for(auto it : v) // auto. 타입이 정해지지 않은 타입. 여기선 pair<int, int> 대신 쓰였다 
		cout << it.first << " : " << it.second << "\n";
	return 0;
}

