#include<bits/stdc++.h> // 백준 1992 2E - 분할정복 (정답부터 보고 풀었음)
using namespace std;

char a[68][68];
int n;

string div(int y, int x, int length) {
	if (length == 1) return string(1, a[y][x]);
		
	char start = a[y][x];
	string ret = "";
	for(int i = y; i < y + length; i++) {
		for(int j = x; j < x + length; j++) {
			if (start != a[i][j]) {
				ret += '(';
				ret += div(y, x, length/2);
				ret += div(y, x + length/2, length/2);
				ret += div(y + length/2, x, length/2);
				ret += div(y + length/2, x + length/2, length/2);
				ret += ')';
				return ret;
			}
		}
	}
	ret += string(1, a[y][x]);
	return ret;
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << div(0, 0, n) << "\n";

    return 0;
}
