#include<bits/stdc++.h> // 백준 1062 4F
using namespace std;

int n, k, bit, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> k;

	bit = 0;
	cnt = 0;

	string s1 = "antatica";
	for(int i = 0; i < s1.size(); i++) {
		int t1 = 1 << (s1[i] - 'a');
		if(!(bit & t1)) { // 비트가 안채워져 있으면
			if(k < 0) { // 가르쳐준 단어를 넘어갔으면
				cout << 0;
				return 0;
			}
			bit += t1;
			k--;
		}

	}

	for(int i = 0; i < n; i++) {
		string s2;
		cin >> s2;

		for(int j = 4; j < s2.size() - 4; j++) {
			int t2 = 1 << (s2[j] - 'a');
			if(!(bit & t2)) { // 비트가 안채워져 있으면
				if(k < 0) { // 가르쳐준 단어를 넘어갔으면
					cnt++;
					break;
				}
				bit += t2;
				k--;
			}
		}
	}

	cout << n - cnt;
    return 0;
}

