#include<bits/stdc++.h> // ����
using namespace std;   

string dopa = "abcde";

int main() {
	// 3�����
	cout << dopa.substr(0, 3) << '\n'; 
	// �Ųٷ� ���
	reverse(dopa.begin(), dopa.end());
	cout << dopa << '\n'; 
	// ���ؽ� �߰� ���
	dopa += "umzunsic";
	cout << dopa << '\n';
	
	return 0;
}
