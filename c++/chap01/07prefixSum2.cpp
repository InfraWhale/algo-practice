#include<bits/stdc++.h> // 누적합 사용 후
using namespace std;   

typedef long long ll;     
int a[100004], b, c, psum[100004], n ,m;

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
	//	cin >> a[i];
		a[i] = i;
		psum[i] = psum[i - 1] + a[i]; 
	}
	for(int i = 0 ; i < m; i++){
		
		cin >> b >> c; 
		cout << "입력완료!" << "\n";
		
		cout << psum[c] - psum[b - 1] << "\n";
		cout << "출력완료!" << "\n";
	} 
	return 0;
}
