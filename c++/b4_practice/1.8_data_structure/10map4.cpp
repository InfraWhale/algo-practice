#include <bits/stdc++.h> // map 4 (주의점)

using namespace std;
map<int, int> mp;
map<string, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	if(mp.find(1) == mp.end()){ // 해당 방식 더 추천 
		mp[1] = 2;
	}
	
	for(auto i : mp) cout << i.first << " " << i.second;
	
	return 0;
}
