#include<bits/stdc++.h> // 백준 1992 2E 정답
using namespace std;
int n;
string s;
char a[101][101];

string quard(int y, int x, int size) {
	if(size == 1) return string(1, a[y][x]);
		
	char b = a[y][x];
	string ret = "";

	for(int i = y; i < y + size; i++) {
		for(int j = x; j < x + size; j++) {
			if (b != a[i][j]) { // 다른게 하나라도 있을 시, 4부분으로 쪼갬
				ret += '(';
				ret += quard(y, x, size/2);
				ret += quard(y, x + size/2, size/2);
				ret += quard(y + size/2, x, size/2);
				ret += quard(y + size/2, x + size/2, size/2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, a[y][x]); // 전부 같으면 같은걸로 반환
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	cout << quard(0, 0, n) << '\n';
    return 0;
}
