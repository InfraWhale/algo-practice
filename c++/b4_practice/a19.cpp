#include<bits/stdc++.h> // ���ڿ��� ���̴� �Լ� 
using namespace std;
string dopa = "amumu is best";
int main(){
	cout << dopa << "\n";
	
	if(dopa.find("amumu") != string::npos){ // dopa.find("amumu") : ��� ���ڿ��� ����ֳ� ã�� 
	cout << "dopa�ӿ� �ƹ����ִ�!\n";
	}
	
	cout << dopa.find("best") << "\n"; // ������ ã�� ���ڿ��� �ִ� ���� ���� ��ġ�� ��ȯ -> 9
	cout << dopa.find("abcd") << "\n"; // ������ ���ڿ� �� ��ġ�� string::npos�� ��ȯ -> 18446744073709551615
	
	cout << dopa.substr(0, 3) << "\n"; // dopa.substr(0, 3) : ���ڿ� dopa���� 0��°���� 3��°���� �̾Ƴ� 
	reverse(dopa.begin(), dopa.end()); // reverse(a, b) : a��°���� b��°���� ���� ���� | dopa.begin() : ���� ��ġ | dopa.end() :  �� ��ġ   
	cout << dopa << "\n";
	
	return 0;
}
