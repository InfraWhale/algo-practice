#include<bits/stdc++.h> // 2�����迭 ȸ�� 
using namespace std;
	
vector<vector<int>> v = {
	{ 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 },
	{ 13, 14, 15, 16 }
};

void antiClock90(vector<vector<int>> &key){ // �������� 90��
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

void clock90(vector<vector<int>> &key){ // ���������� 90��
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

int main(){
	
	for (vector<int> vc : v) {
	    for (int vcc : vc)
	        printf("%2d ", vcc);
	    cout << "\n";
	}
	cout << "\n";
	
	antiClock90(v);
	
	for (vector<int> vc : v) {
	    for (int vcc : vc)
	        printf("%2d ", vcc);
	    cout << "\n";
	}
	cout << "\n";
	
	clock90(v);
	
	for (vector<int> vc : v) {
	    for (int vcc : vc)
	        printf("%2d ", vcc);
	    cout << "\n";
	}
	
	return 0;
}
