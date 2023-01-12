#include <bits/stdc++.h> // type : string 2

using namespace std;

int main(){
	string a = "love is";
	a += " pain!";
	a.pop_back(); // ���� �� ��� ���� (!�� ������) 
	cout << a << " : " << a.size() << "\n";
	cout << char(* a.begin()) << '\n';
	cout << char(* (a.end() - 1)) << '\n';
	
	// string& insert (size_t pos, const string& str);
	a.insert(0, "test "); // 0 ��ġ�� ���ڿ� ���� 
	cout << a << " : " << a.size() << "\n";
	
	// string& erase (size_t pos = 0, size_t len = npos);
	a.erase(0, 5); //0���� 5���� ���� 
	cout << a << " : " << a.size() << "\n";
	
	// size_t find (const string& str, size_t pos = 0);
	auto it = a.find("love"); // Ư�� ���ڿ� ��ġ ��ȯ, ��ã���� string::npos ��ȯ
	if (it != string::npos){
		cout << "���ԵǾ� �ִ�." << '\n';
	}
	cout << it << '\n'; // find�� ���� love�� ù���� ��ġ�� it�� ����� 
	cout << string::npos << '\n'; // 64��Ʈ �ü�������� �ִ� ������ ���� 
	
	// string substr (size_t pos = 0, size_t len = npos) const;
	cout << a.substr(5, 2) << '\n'; // 5��°���� �����ؼ� 2���� ���� 
	
	return 0;
}

