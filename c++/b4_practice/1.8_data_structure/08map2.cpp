#include <bits/stdc++.h> // map 2 (������) 

using namespace std;
map<int, int> mp;
map<string, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << mp[1] << '\n';
	cout << mp2["aaa"] << '\n';
	for(auto i : mp) cout << i.first << " " << i.second; // ������ �ص� ���� ����. int�� ��� �� 0 
	cout << '\n';
	for(auto i : mp2) cout << i.first << " " << i.second;// string�� ��� �� "" 
	return 0;
}

