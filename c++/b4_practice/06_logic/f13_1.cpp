#include<bits/stdc++.h> // 2�����迭 ���� 
using namespace std;

	const int ay = 4; // �迭�� ���� �����ϴ°� ������ const ���� 
	const int ax = 5;
	
	int a[ay][ax] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 }
	};

void b(int a[][5]) { // �Լ��� �ѱ���� �ι�° ������ ä������ 
	a[0][4] = 44;
}

int main(){
	
	b(a);
	
	for(int i=0; i<ay ;i++){
		for(int j=0; j<ax; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
	
//	cout << a[0][4] << "\n";
	
	return 0;
}
