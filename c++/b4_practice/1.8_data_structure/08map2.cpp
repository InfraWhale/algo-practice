#include <bits/stdc++.h> // map 2 (주의점) 

using namespace std;
map<int, int> mp;
map<string, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << mp[1] << '\n';
	cout << mp2["aaa"] << '\n';
	for(auto i : mp) cout << i.first << " " << i.second; // 참조만 해도 값이 생김. int의 경우 값 0 
	cout << '\n';
	for(auto i : mp2) cout << i.first << " " << i.second;// string의 경우 값 "" 
	return 0;
}

