#include<bits/stdc++.h>
using namespace std;   

int a, sum;
vector<int> v1, v2;

void df(int n) {
	if(sum > 100) {
		return;
	}
	for(int i = n; i < 9; i++) {
		v2.push_back(v1[i]);
		sum += v2.back();
		
		if (sum == 100) {
			sort(v2.begin(), v2.end());
			for(int i = 0; i < v2.size()-1; i++) cout << v2[i] << '\n';
 			cout << v2.back();
			exit(0);
		}
		
		df(n + 1);
		
		sum -= v2.back();
		v2.pop_back();
	}
	return;
}

int main() {
	
	for(int i = 0; i < 9; i++) {
		cin >> a;
		v1.push_back(a);
	}
		
	df(0);

	return 0;
}
