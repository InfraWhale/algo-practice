#include<bits/stdc++.h> // 백준 1285 4B 정답
// 행을 뒤집는 모든 경우의 수를 고려
// 그 후 열의 경우는 모든 경우의 수를 고려할 필요가 없음
using namespace std;
const int INF=987654321;
int n, a[44], ret=INF; 
string s;
void go(int here) {
	if(here == n + 1) {
		int sum = 0;
		for(int i = 1; i <= (1 << (n-1)); i *= 2) {
			int cnt = 0;
			for(int j=1; j <=n; j++) if(a[j] & i)cnt++; // 각 행의 첫번째..두번째..세번째 순으로 비트마스킹
			sum += min(cnt, n-cnt); // 뒷면이 더 적은 경우 픽 
		}
		ret = min(ret, sum);
		return;
	}
	go(here + 1); // 안뒤집는 경우

	a[here] = ~a[here]; // 맨 앞이 뒤집혀서 -가 붙긴 하는데, 쓰는건 어짜피 맨 뒤부터 쓰니 상관없다.
	go(here + 1); // 뒤집는 경우
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		int value = 1;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == 'T')a[i] |= value; // 문자열 배열을 하나의 숫자로 만듬
			value *= 2;
		}
	}

	//for(int i = 1; i <= n; i++) cout << a[i] << " ";
	go(1);
	cout << ret << "\n";

    return 0;
}

