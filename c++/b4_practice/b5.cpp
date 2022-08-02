#include<bits/stdc++.h> // sort - vector 안에 pair - 내림차순 
using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){ // 정렬을 위한 커스텀 함수 @@@@@@@@@@@@@@@@@ 나중에 다시 나옴 
	return a.first > b.first;
}

int main(){
	for(int i = 10; i >= 1; i--){
		v.push_back({i, 10 - i});
	}
	sort(v.begin(), v.end(), cmp);
	
	
	for(auto it : v) 
		cout << it.first << " : " << it.second << "\n";
	
	return 0;
}
