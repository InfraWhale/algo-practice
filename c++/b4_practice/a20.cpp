#include <bits/stdc++.h> // split
using namespace std;

vector<string> split(string input, string delimiter) { //vector<�ڷ���> ������(�Լ���) : ǥ�� ���̺귯���� �ִ� �����̳�. �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭 

	vector<string> ret;
	long long pos = 0;
	string token = "";
	
	while ((pos = input.find(delimiter)) != string::npos) { //pos�� ���� ��ġ ����. ������ ã�� ��쿡�� �ݺ������� 
		token = input.substr(0, pos); // ���� ���ڿ� ���ۺ��� ù ������� �̾Ƽ� token�� ���� 
		ret.push_back(token); // push_back(a) : vector ���� a�� �߰� | ret�� token�� ����� ���� ��ҷμ� ���� 
		input.erase(0, pos + delimiter.length()); //  erase(a,b) : vector�� a��°���� b��°���� ����. erase(a) ó�� �ϳ����� ����. | input�� ret�� ����� ���� ����  
	}
	
ret.push_back(input); // ���ڿ� �������� ������ ���� -> ���ڿ����� ���� ���� ret�� ������ ��ҷ� ���� 
return ret;
}
int main(){
	string s = "�׸޽ý� ���̵�ô� ī������� ���ٿ� ���ֳ���";
	string d = " ";
	vector<string> a = split(s, d);
	for(string b : a) 
		cout << b << "\n";
	
	return 0;
}
