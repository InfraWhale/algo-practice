#include<bits/stdc++.h> // 붙어있는거 입력받기 - string으로 받기 

using namespace std;
int n, m, a[10][10];
string s;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j] - '0';
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << '\n';
	}
}

