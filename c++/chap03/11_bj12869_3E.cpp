#include<bits/stdc++.h> // 백준 12869 3E (모르겠음)
using namespace std;

int n, temp, dmg, ret;
vector<int> v;


int main() { 
	cin >> n;

	for(int i=0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	while(v.size()) {
		sort(v.begin(), v.end(), greater<int>());
		dmg = 9;
		for(int i = 0; i < v.size(); i++) {
			v[i] -= dmg;
			dmg /= 3;
		}

		for(int i = v.size() - 1; i > -1; i--) {
			if(v[i] <= 0) v.pop_back();
		}
		ret++;
	}
	
	cout << ret << "\n";

	return 0;
}