#include <bits/stdc++.h> // map 3 (������)
 
using namespace std;
map<int, int> mp;
map<string, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	if(mp[1] == 0){ // �����ϸ鼭 �����𸣰� �Ҵ�Ǿ��� �� �����Ƿ�, �̹� �ִ��� Ȯ���� �Ŀ� �� ���Ҵ� 
		mp[1] = 2;
	}
	
	for(auto i : mp) cout << i.first << " " << i.second;
	return 0;
}

