#include <bits/stdc++.h> // 내림차순 정렬

using namespace std;
vector<int> v;

int main(){
	for(int i= 1; i <= 6; i++) v.push_back(i);
	sort(v.begin(), v.end());
	for(int i : v) cout << i << ' ';
	
	cout << "\n";
	
	sort(v.begin(), v.end(), greater<int>());
	for(int i : v) cout << i << ' ';
}
