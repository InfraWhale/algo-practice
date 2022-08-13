#include <bits/stdc++.h> // split
using namespace std;

vector<string> split(string input, string delimiter) { //vector<자료형> 변수명(함수명) : 표준 라이브러리에 있는 컨테이너. 자동으로 메모리가 할당되는 배열 

	vector<string> ret;
	long long pos = 0;
	string token = "";
	
	while ((pos = input.find(delimiter)) != string::npos) { //pos에 공백 위치 저장. 공백을 찾을 경우에만 반복문으로 
		token = input.substr(0, pos); // 나눌 문자열 시작부터 첫 공백까지 뽑아서 token에 저장 
		ret.push_back(token); // push_back(a) : vector 끝에 a를 추가 | ret에 token에 저장된 값을 요소로서 넣음 
		input.erase(0, pos + delimiter.length()); //  erase(a,b) : vector의 a번째부터 b번째까지 지움. erase(a) 처럼 하나만도 가능. | input에 ret에 저장된 값을 지움  
	}
	
ret.push_back(input); // 문자열 마지막은 공백이 없음 -> 문자열에서 남은 것을 ret의 마지막 요소로 넣음 
return ret;
}
int main(){
	string s = "네메시스 보이드시더 카르노모프 락다운 우주냥이";
	string d = " ";
	vector<string> a = split(s, d);
	for(string b : a) 
		cout << b << "\n";
	
	return 0;
}
