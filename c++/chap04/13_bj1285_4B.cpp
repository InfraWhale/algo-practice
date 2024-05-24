#include<bits/stdc++.h> // 백준 1285 4B (모르겠음)
using namespace std;
const int INF=987654321;
int n, cnt, ret=INF; 
char a[24][24];

int main() { 
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'T') cnt++;
		}
	}

	for(int i = 0; i < n; i++) {
		int temp=0;
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'T') temp++;
		}
		ret = min(cnt+n-(temp*2), ret);
	}

	for(int i = 0; i < n; i++) {
		int temp=0;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == 'T') temp++;
		}
		ret = min(cnt+n-(temp*2), ret);
	}

	cout << ret;

    return 0;
}

