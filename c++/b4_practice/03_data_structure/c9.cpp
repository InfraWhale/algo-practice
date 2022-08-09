#include<bits/stdc++.h> // 배열 초기화 : fill과 memset 
using namespace std;

int n = 5;
	
//vector 초기화하기
vector<int> v1[10]; // v1 벡터 10개 생성 
vector<int> v2(n, 0); // 0이라는 값을 가진 n개의 v2 벡터를 생성

//vector로 2차원 배열 매트릭스 만들기
vector<vector<int>> v3(n + 1, vector<int> (n + 1,0));
 
//배열 초기화 shortcut -> 전체 0으로 초기화 
int dp1[10] = {0,};
int dp2[10][10] = {{0, } };

//부분초기화 
int a[10] = {3,4};


int main() {
	
	//벡터
	 
	fill(v3.begin(), v3.end(), vector<int>(10,10)); // fill로 초기화 
	
	for(vector<int> a : v3) {
		for(int b : a) {
			cout << b <<" ";
		}
		cout << "\n";
	}
	
	//배열
	
	cout << "----------------------------------------------" << "\n";
	
	for(int i=0; i<10; i++) {
		cout << dp1[i] <<" ";
	}
	cout << "\n";
	
	cout << "\n";
	
	fill(dp1, dp1 + 10, 3);
	
	for(int i=0; i<10; i++) {
		cout << dp1[i] <<" ";
	}
	cout << "\n";
	
	cout << "\n";
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cout << dp2[i][j] <<" ";
		}
		cout << "\n";
	}
	
	cout << "\n";
	
	// fill(&dp2[0][0], &dp2[10 - 1][10], 7);
	fill(&dp2[0][0], &dp2[0][0] + 10*10, 7); // &dp2 -> dp2의 주소를 담고있는 상수 포인터. 주소는 쭈욱 연속되므로 &dp2[0][0] + 10*10의 경우 dp[9][9]의 주소가 된다. 
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cout << dp2[i][j] <<" ";
		}
		cout << "\n";
	}
	
	//부분 초기화 
	cout << "----------------------------------------------" << "\n";
	
	for(int i=0; i<10; i++) {
		cout << a[i] <<" ";
	}
	cout << "\n";
	
	// memset이용
	cout << "----------------------------------------------" << "\n";
	
	memset(dp2, -1, sizeof(dp2)); // 0 혹은 -1로만 초기화 가능 
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cout << dp2[i][j] <<" ";
		}
		cout << "\n";
	}
		 
	return 0;
} 
