#include <bits/stdc++.h> // 2차원 배열 회전 

using namespace std;
vector<vector<int>> v;

// 왼쪽으로 90도
void rotateLeft90(vector<vector<int>> &key){
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			temp[i][j] = key[j][m - i - 1];
		}
	}
	key = temp;
	return;
}

// 오른쪽으로 90도
void rotateRight90(vector<vector<int>> &key){
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			temp[i][j] = key[m - j - 1][i];
		}
	}
	key = temp;
	return;
}

int main() {
	
	for(int i = 0; i < 10; i++){
		vector<int> vv(10, i);
		v.push_back(vv);
	}
	
	for(vector<int> vv : v){
		for(int i : vv) cout << i << ' ';
		cout << '\n';
	}
	cout << '\n';
	
	rotateLeft90(v);
	
		for(vector<int> vv : v){
		for(int i : vv) cout << i << ' ';
		cout << '\n';
	}
	cout << '\n';
	
	rotateRight90(v);
	
		for(vector<int> vv : v){
		for(int i : vv) cout << i << ' ';
		cout << '\n';
	}
	cout << '\n';
	
	return 0;
}
