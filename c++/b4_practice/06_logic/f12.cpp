#include <bits/stdc++.h> // 커스텀 정렬 - 내림차순 
using namespace std;

vector<int> v;

bool cmp(int a, int b){
	return a > b; // 앞에 오는게 더 크다 -> 내림차순...? 걍 이렇게 기억하면 되지 않으까? 
}

int main(){
	for(int i= 1; i <= 6; i++) v.push_back(i);
	
	for(int i : v) cout << i << ' ';
	cout << "\n"; 
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i : v) cout << i << ' ';
}
