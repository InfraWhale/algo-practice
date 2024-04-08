#include<bits/stdc++.h> // 백준 15686 3A 정답
using namespace std;

int n, m, a[54][54], result = 987654321;
vector<vector<int>> chickenList; // chicken의 번호의 조합들을 담는 List
vector<pair<int, int>> _home, chicken;
void combi(int start, vector<int> v) {
	if(v.size() == m) {
		chickenList.push_back(v);
		return;
	}
	for(int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main() { 
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) _home.push_back({i, j});
			if(a[i][j] == 2) chicken.push_back({i, j});
		}
	}
	vector<int> v;
	combi(-1, v);
	for(vector<int> cList : chickenList) { // 각 조합별로 경우의 수 나눔
		int ret =0;
		for(pair<int, int> home : _home) { // 각각의 집에서 출발
			int _min = 987654321;
			for(int ch : cList) { // 모든 치킨집에 도착하는 경우의 수 별로
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second); // 거리 계산
				_min = min(_min, _dist);
			}
			ret += _min; // 모든 집의 최솟값 더함
		}
		result = min(result, ret); // 가장 작은 경우 구함
	}
	cout << result << "\n";
    return 0;
}