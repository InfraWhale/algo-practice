#include<bits/stdc++.h> // Ŀ���� ������ 

using namespace std;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first > b.first; //�տ� ���� �ְ� �ڿ� ���� �ֺ��� ũ�� ������  
}

int main(){
	for(int i = 10; i >= 1; i--){
		v.push_back({i, 10 - i});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto it : v) cout << it.first << " : " << it.second << "\n";
	return 0;
}
