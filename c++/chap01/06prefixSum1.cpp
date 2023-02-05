#include<bits/stdc++.h> // 누적합 사용 전 
using namespace std;   

typedef long long ll;     
int a[100004], b, c, psum[100004], n ,m;

int main(){
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
	//	cin >> a[i];
	a[i] = i;
	}
	for(int i = 0 ; i < m; i++){
		cin >> b >> c; 
		int sum = 0; 
		for(int j = b; j <= c; j++) sum += a[j];
		cout << sum << '\n'; 
	} 
	return 0;
}
