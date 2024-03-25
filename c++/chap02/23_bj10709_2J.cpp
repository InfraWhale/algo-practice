#include<bits/stdc++.h> // 백준 10709 2J
using namespace std;

int h, w;
char a[104][104];
int v[104][104];

int main(){

	fill(&v[0][0], &v[0][0] + 104 * 104, -1);
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++){
			int cnt = 0;
			while(cnt <= j) {
				if(a[i][j-cnt] == 'c') {
					v[i][j] = cnt;
					break;
				}
				cnt++;
			}
			cout << v[i][j] << " ";
		}
		cout <<"\n";
	}

	return 0;
}
