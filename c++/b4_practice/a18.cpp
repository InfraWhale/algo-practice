#include <bits/stdc++.h> // ���ڸ� ���ڷ� 
using namespace std;
int main(){
	char a = 'a';
	cout << (int)a - 97 << "\n";
	cout << a - 97 << "\n"; 

	cout << 97 - a << "\n";  
	cout << 97 - 'a' << "\n";
	
	cout << (int)a - 'a' << "\n"; // ���꿡 ���̸� 'a'�� ���ڰ� �ƴ϶� �ƽ�Ű�ڵ� 97�� ���� 
	
	char b = 'b';
	cout << (int)b - 97 << "\n";
	return 0;
}
