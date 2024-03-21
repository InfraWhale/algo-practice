#include<bits/stdc++.h> // 백준 2910 2G 정답
using namespace std;
typedef long long ll;

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return mp_first[a.second] < mp_first[b.second]; // 큰게 뒤에 오도록
	}
	return a.first > b.first; // 큰게 앞에 오도록
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; // 수열에서 처음 나오는 수라면, 먼저 나온 수를 판단하기 위해 순서를 기록
	}
	for(auto it : mp) {
		v.push_back({it.second, it.first});
	}
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v) {
		for (int j = 0; j < i.first ; j++) {
			cout << i.second << " ";
		}
	}

    return 0;
}
