#include<bits/stdc++.h> // sort - vector �ȿ� pair 
using namespace std;

vector<pair<int, int>> v;

int main(){
	for(int i = 10; i >= 1; i--){
		v.push_back({i, 10 - i});
	}
	
	sort(v.begin(), v.end()); // sort�� first, second �߿� first �������� �������� ���ĵȴ�
	 
	for(auto it : v) // auto. Ÿ���� �������� ���� Ÿ��. ���⼱ pair<int, int> ��� ������ 
		cout << it.first << " : " << it.second << "\n";
	return 0;
}

