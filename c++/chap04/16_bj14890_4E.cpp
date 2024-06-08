#include<bits/stdc++.h> // 백준 14890 4E
using namespace std;

int n, l, ret;
int a[104][104], v1[104][104], v2[104][104];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> l;

	ret = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		bool flag =0;
		for(int j = 0; j < n; j++) {

			if(j == 0) continue; // 첫번째

			//cout << "abs : " << abs(a[i][j] - a[i][j-1]) << "\n";
			if(abs(a[i][j] - a[i][j-1]) > 1) break; // 높이차 2 이상

			if((a[i][j] - a[i][j-1]) == 1) { // 높이차 1 (올라감)
				for(int k = 1; k <= l; k++) {
					//cout << "b4 i : j-k = " << i << " : " << j-k <<  "\n";
					if((j-k < 0) || (a[i][j-k] != a[i][j-1]) || v1[i][j-k]) {
						flag = 1;
						break;
					}
					//cout << "af i : j-k = " << i << " : " << j-k <<  "\n";
					v1[i][j-k] = 1;
				}
				if(flag) break;
			}

			if((a[i][j] - a[i][j-1]) == -1) { // 높이차 1 (내려감)
				for(int k = 0; k < l; k++) {
					if((j+k >= n) || (a[i][j+k] != a[i][j]) || v1[i][j+k]){
						flag = 1;
						break;
					}
					v1[i][j+k] = 1;
				}
				if(flag) break;
			}

			if(j == n - 1) { // 마지막 도달
				ret++;
				// cout << i << " : i " << "\n";
			}
		}
		
	}

	for(int j = 0; j < n; j++) {
		bool flag=0;
		for(int i = 0; i < n; i++) {

			if(i == 0) continue; // 첫번째 혹은 이전과 같음

			//cout << "abs : " << abs(a[i][j] - a[i-1][j]) << "\n";
			if(abs(a[i][j] - a[i-1][j]) > 1) break; // 높이차 2 이상

			if((a[i][j] - a[i-1][j]) == 1) { // 높이차 1 (올라감)
				for(int k = 1; k <= l; k++) {
					if((i-k < 0) || (a[i-k][j] != a[i-1][j]) || v2[i-k][j]){
						flag = 1;
						break;
					}
					v2[i-k][j] = 1;
				}
				if(flag) break;
			}

			if((a[i][j] - a[i-1][j]) == -1) { // 높이차 1 (내려감)
				for(int k = 0; k < l; k++) {
					if((i+k >= n) || (a[i+k][j] != a[i][j]) || v2[i+k][j]){
						flag = 1;
						break;
					}
					v2[i+k][j] = 1;
				}
				if(flag) break;
			}

			if(i == n - 1) { // 마지막 도달
				ret++;
				// cout << j << " : j " << "\n";
			}
		}
		
	}

	cout << ret;
    return 0;
}

