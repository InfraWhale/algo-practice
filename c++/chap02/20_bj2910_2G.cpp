#include<bits/stdc++.h> // 백준 2910 2G (추후에 개념이랑 같이 다시볼것 - 커스텀정렬, 맵)
using namespace std;
typedef long long ll;

int n, seq;
ll c;
map<ll, int> cntMap;
map<ll, int> seqMap;

bool cmp(const pair<ll,int>& a, const pair<ll,int>& b) {
	if (a.second == b.second) return seqMap[a.first] < seqMap[b.first];
	return a.second > b.second;
}

int main(){
	cin >> n >> c;
	seq = 1;

	for(int i = 0; i < n; i++) {
		ll temp;
		cin >> temp;

		if(cntMap[temp] == 0) {
			cntMap[temp] = 1;
			seqMap[temp] = seq;
			seq++;
		} else {
			cntMap[temp] ++;
		}
	}
	vector<pair<ll,int>> v(cntMap.begin(), cntMap.end());

	sort(v.begin(), v.end(), cmp);

	for(auto it : v) {
		for (int i = 0; i < it.second ; i++) {
			cout << it.first << " ";
		}
	}

    return 0;
}
