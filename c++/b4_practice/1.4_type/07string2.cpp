#include <bits/stdc++.h> // type : string 2

using namespace std;

int main(){
	string a = "love is";
	a += " pain!";
	a.pop_back(); // 제일 뒤 요소 삭제 (!가 삭제됨) 
	cout << a << " : " << a.size() << "\n";
	cout << char(* a.begin()) << '\n';
	cout << char(* (a.end() - 1)) << '\n';
	
	// string& insert (size_t pos, const string& str);
	a.insert(0, "test "); // 0 위치에 문자열 삽입 
	cout << a << " : " << a.size() << "\n";
	
	// string& erase (size_t pos = 0, size_t len = npos);
	a.erase(0, 5); //0부터 5까지 삭제 
	cout << a << " : " << a.size() << "\n";
	
	// size_t find (const string& str, size_t pos = 0);
	auto it = a.find("love"); // 특정 문자열 위치 반환, 못찾으면 string::npos 반환 @@@@@@@@@@@@@@@@@@@@@@@@@@ 
	if (it != string::npos){
		cout << "포함되어 있다." << '\n';
	}
	cout << it << '\n';
	cout << string::npos << '\n';
	
	// string substr (size_t pos = 0, size_t len = npos) const;
	cout << a.substr(5, 2) << '\n';
	
	return 0;
}

