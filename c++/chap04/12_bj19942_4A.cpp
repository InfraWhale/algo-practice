#include<bits/stdc++.h> // 백준 19942 4A (사전순에서 틀리는거 같은데 모르겠음)
using namespace std;

// 실수로 하는 변수중복은 피하자...!!!

int n, mp, mf, ms, mv, p[20], f[20], s[20], v[20], c[20], ret = 987654321, bit;
bool flag;
vector<vector<int>> vv;

int main() { 
	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for(int i = 0; i < n; i++) { // p[0] -> 사실상 1
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}
	
	for(int i = 0; i < (1 << n); i++) {
		int tp=0, tf=0, ts=0, tv=0, tc=0;
		vector<int> vec;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				vec.push_back(j + 1);
				tp += p[j];
				tf += f[j];
				ts += s[j];
				tv += v[j];
				tc += c[j];
			}
		}
		// cout << tp << " : "<< tf << " : "<< ts << " : "<< tv << " : "<< tc << "\n";
		// cout << bit << "\n";
		if(tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
			// cout << tp << " : "<< tf << " : "<< ts << " : "<< tv << " : "<< tc << "\n";
			// cout << bit << "\n";
			if(tc < ret) {
				vv.clear();
				vv.push_back(vec);
				ret = tc;
			} else if (tc == ret) {
				vv.push_back(vec);
			}
		}
	}
	if(ret != 987654321) {
		cout << ret << "\n";

		sort(vv.begin(), vv.end());
		for(int i : vv[0]) {
			cout << i << " ";
		}
	} else {
		cout << -1;
	}

    return 0;
}

