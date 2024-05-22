#include<bits/stdc++.h> // 백준 19942 4A
using namespace std;

int n, mp, mf, ms, mv, p[20], f[20], s[20], v[20], c[20], ret = 987654321, bit;

int main() { 
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for(int i = 0; i < n; i++) { // p[0] -> 사실상 1
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}
	
	for(int i = 0; i < (1 << n); i++) {
		int tp=0, tf=0, ts=0, tv=0, tc=0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				tp += p[j];
				tf += f[j];
				ts += s[j];
				tv += s[j];
				tc += c[j];
			}
		}
		if(tp >= mp && tf >= mf && ts >= ms && tv >= mv && tc < ret) {
			// cout << tp << " : "<< tf << " : "<< ts << " : "<< tv << " : "<< tc << "\n";
			// cout << bit << "\n";
			ret = tc;
			bit = i;
		}
	}

	cout << ret << "\n";

	for(int i = 0; i < n; i++) {
		if(bit & (1 << i)) {
			cout << i+1 << " ";
		}
	}
    return 0;
}

