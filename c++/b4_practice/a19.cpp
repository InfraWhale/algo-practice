#include<bits/stdc++.h> // 문자열서 쓰이는 함수 
using namespace std;
string dopa = "amumu is best";
int main(){
	cout << dopa << "\n";
	
	if(dopa.find("amumu") != string::npos){ // dopa.find("amumu") : 어떠한 문자열이 들어있나 찾음 
	cout << "dopa속에 아무무있다!\n";
	}
	
	cout << dopa.find("best") << "\n"; // 있으면 찾는 문자열이 있는 곳의 시작 위치를 반환 -> 9
	cout << dopa.find("abcd") << "\n"; // 없으면 문자열 끝 위치인 string::npos를 반환 -> 18446744073709551615
	
	cout << dopa.substr(0, 3) << "\n"; // dopa.substr(0, 3) : 문자열 dopa에서 0번째부터 3번째까지 뽑아냄 
	reverse(dopa.begin(), dopa.end()); // reverse(a, b) : a번째부터 b번째까지 순서 역전 | dopa.begin() : 시작 위치 | dopa.end() :  끝 위치   
	cout << dopa << "\n";
	
	return 0;
}
