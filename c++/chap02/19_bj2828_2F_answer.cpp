#include<bits/stdc++.h> // 백준 2828 2F 정답
using namespace std;

int n, m, j, l, r, temp, ret;

int main(){

	cin >> n >> m >> j;
	l = 1;
	for(int i = 0; i < j; i++) {
		r = l + m - 1;
		cin >> temp;
		if(temp >= l && temp <= r) continue;
		else {
			if(temp < l) {
				ret += (l - temp);
				l = temp;
			} else {
				l += (temp - r);
				ret += (temp - r);
			}
		}
	}

	cout << ret << "\n";
    return 0;
}
