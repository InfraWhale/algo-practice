#include<bits/stdc++.h> // 백준 2870 2I (거의 다 풀었는데 모르겠음...)
using namespace std;

int n;
string s;
map<string, int> mp;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string temp;
		for (int j = 0; j < s.size(); j++) {
			if(s[j] >= '1' && s[j] <= '9') {
				temp += s[j];
			} 
			if( s[j] < '1' || s[j] > '9' || j == s.size() - 1) {
				if(temp != "") {
					if(mp[temp]) {
						mp[temp]++;
					} else {
						mp[temp] = 1;
					}
					temp = "";
				}
			}
		}
		if(s[s.size()-1] == '0') {
			mp["0"] = 1; 
		}
	}
	
	for(auto it : mp) {
		for (int i = 0; i < (it).second; i++) {
			cout << (it).first << "\n";
		}
	}
}
