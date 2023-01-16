#include <bits/stdc++.h> // map 3 (주의점)
 
using namespace std;
map<int, int> mp;
map<string, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	if(mp[1] == 0){ // 참조하면서 나도모르게 할당되었을 수 있으므로, 이미 있는지 확인한 후에 값 재할당 
		mp[1] = 2;
	}
	
	for(auto i : mp) cout << i.first << " " << i.second;
	return 0;
}

