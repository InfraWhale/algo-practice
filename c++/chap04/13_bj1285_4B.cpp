#include<bits/stdc++.h> // 백준 1285 4B (모르겠음)
using namespace std;
const int INF=987654321;
int n, ret=INF, a[24];
string s;

void go(int step) {
	if(step == n) {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			int temp = 0;
			for(int j = 0; j < n; j++) {
				if (a[j] & (1 << i)) temp++;
			}
			if(temp > (n-temp)) temp = n-temp;
			cnt += temp;
		}
		ret = min(ret, cnt);
		return;
	}

	go(step + 1);

	//~a[step]; 이렇게 했을땐 틀렸었음
	a[step] = ~a[step];
	go(step + 1);
	a[step] = ~a[step]; // 이게 들어가는게 더 맞다고 생각함

	return;
}

int main() { 
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		int temp=0;
		for(int j = 0; j < n; j++) {
			if(s[j] == 'T') temp += (1 << j);
		}
		a[i] = temp;
	}

	go(0);

	cout << ret;

    return 0;
}

