#include<bits/stdc++.h> // 백준 17298 2T (못품. 이게 짝짓기?)
using namespace std;

int n, pre, nge, flag, a[1000001];

int main(){
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	pre = 0;
	for (int i = 1; i <= n; i++) {
		if(a[i] > a[i-1] || pre == -1) {
			flag = 0;
			for(int j = i; j <= n; j++) {
				if(a[j] > a[i]) {
					nge = a[j];
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				nge = -1;
			}
		} else {
			nge = pre;
		}
		cout << nge << " ";
		pre = nge;
	}
	return 0;
}
