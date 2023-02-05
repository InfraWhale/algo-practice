#include<bits/stdc++.h>
using namespace std;  
int N, M;
int cnt = 0;
void solve(int N, int M){
	int a = 1; 
	for (int i = 0; i < N; i++) {
		a *= i;
		cnt ++;
	}
	for (int j = 0; j < M; j++) {
		a *= j;
		cnt ++;   
	}
	cout << a << "\n"; 
}
int main(){
	cin >> N >> M; 
	solve(N, M);   
	cout << "cnt : " << cnt << '\n';   
	return 0;
} 
