#include<bits/stdc++.h> // 백준 15686 1A(못품 -> 풀이보고 품)
using namespace std;

int n, m, ret, a[54][54];
vector<pair<int, int>> v1, v2;
vector<vector<int>> vc;
vector<int> v;

void combi(int start, vector<int> b){
	if(b.size() == m){
		vc.push_back(b);
		return;
	}
	for(int i = start + 1; i < v2.size(); i++){
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}

int main() { 
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) v1.push_back({i, j});
			if(a[i][j] == 2) v2.push_back({i, j});
		}
	}

	combi(-1, v);

	ret = 987654321;

	for(auto it1 : vc) { // 각각의 치킨집 조합
		int totalLength = 0;
		for(auto it2 : v1) { // 각각의 집의 경우
			int length = 987654321;
			for(auto i : it1) { // 각각의 치킨집 번호
				length = min(length, abs(it2.first - v2[i].first) + abs(it2.second - v2[i].second));
			}
			totalLength += length;
		}
		ret = min(ret, totalLength);
	}
	cout << ret << "\n";
}