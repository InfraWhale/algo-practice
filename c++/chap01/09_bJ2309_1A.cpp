#include<bits/stdc++.h> // 백준 2309 1-A 
using namespace std;   

int a, sum;
vector<int> v1, v2;

void df(int n) {
	if(sum > 100) {
		return;
	}
	for(int i = n; i < 9; i++) {
		v2.push_back(v1[i]);
		//cout << v2.back() << '\n';
		sum += v2.back();
		//cout << "더했을때 sum : " <<sum << '\n';
		
		if (sum == 100) {
			sort(v2.begin(), v2.end());
			for(int i = 0; i < v2.size()-1; i++) cout << v2[i] << '\n';
 			cout << v2.back();
			exit(0);
		}
		
		df(n + 1);
		
		sum -= v2.back();
		//cout << "뺐을때 sum : " <<sum << '\n';
		v2.pop_back();
		//cout << v2.back() << '\n';
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
