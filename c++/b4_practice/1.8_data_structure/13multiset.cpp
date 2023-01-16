#include <bits/stdc++.h> // multi set 

using namespace std;
multiset<int> s;

int main() {
	for(int i = 5; i >= 1; i--){
		s.insert(i);
		s.insert(i);
	}
	for(int it : s) cout << it << " "; // 중복 허용, 자동 정렬 
	cout << '\n'; 
	return 0;
}
