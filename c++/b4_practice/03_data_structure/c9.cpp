#include<bits/stdc++.h> // �迭 �ʱ�ȭ : fill�� memset 
using namespace std;

int n = 5;
	
//vector �ʱ�ȭ�ϱ�
vector<int> v1[10]; // v1 ���� 10�� ���� 
vector<int> v2(n, 0); // 0�̶�� ���� ���� n���� v2 ���͸� ����

//vector�� 2���� �迭 ��Ʈ���� �����
vector<vector<int>> v3(n + 1, vector<int> (n + 1,0));
 
//�迭 �ʱ�ȭ shortcut -> ��ü 0���� �ʱ�ȭ 
int dp1[10] = {0,};
int dp2[10][10] = {{0, } };

//�κ��ʱ�ȭ 
int a[10] = {3,4};


int main() {
	
	//����
	 
	fill(v3.begin(), v3.end(), vector<int>(10,10)); // fill�� �ʱ�ȭ 
	
	for(vector<int> a : v3) {
		for(int b : a) {
			cout << b <<" ";
		}
		cout << "\n";
	}
	
	//�迭
	
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
	fill(&dp2[0][0], &dp2[0][0] + 10*10, 7); // &dp2 -> dp2�� �ּҸ� ����ִ� ��� ������. �ּҴ� �޿� ���ӵǹǷ� &dp2[0][0] + 10*10�� ��� dp[9][9]�� �ּҰ� �ȴ�. 
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cout << dp2[i][j] <<" ";
		}
		cout << "\n";
	}
	
	//�κ� �ʱ�ȭ 
	cout << "----------------------------------------------" << "\n";
	
	for(int i=0; i<10; i++) {
		cout << a[i] <<" ";
	}
	cout << "\n";
	
	// memset�̿�
	cout << "----------------------------------------------" << "\n";
	
	memset(dp2, -1, sizeof(dp2)); // 0 Ȥ�� -1�θ� �ʱ�ȭ ���� 
	
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			cout << dp2[i][j] <<" ";
		}
		cout << "\n";
	}
		 
	return 0;
} 
