#include <bits/stdc++.h>// 내림차순 정렬 - pair<int, int> 일때 
using namespace std;

vector<pair<int, int>> v;

int main(){
	
	for(int i= 1; i <= 6; i++) 
		v.push_back({i, i});
	
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	
	for(auto i : v) 
		//cout << i.first << ' ';
		printf("{%d, %d} ",i.first, i.second);
}
