#include<bits/stdc++.h> // 백준 9934 3N
using namespace std;

int k, a[14];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> k;
	int n =  pow(2, k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	return 0;
}