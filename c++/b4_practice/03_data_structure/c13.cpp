#include <bits/stdc++.h> // map ��ȸ 
using namespace std;

int main(){
	map<string, int> _map;
	
	_map["ū��"]++;
	_map["ū��"]++;
	
	for(auto c : _map){
		cout << c.first << " : " << c.second <<"\n";
	}
	
	return 0;
}

