#include<bits/stdc++.h>
using namespace std;

stack<string> stk;

int main() {
	
	
	ios_base::sync_with_stdio(false); // c의 stdio와 cpp의 iostream 간의 동기화 해제 -> c에 속한 stdio의 버퍼 사용 안하므로 딜레이 발생 방지 
	cin.tie(NULL); // cin과 cout의 묶음을 풀어줌. 이러면 io 작업 전 자동으로 버퍼 비우기가 안되므로 출력 전에 버퍼 비워줘야 함. 
	// https://jaimemin.tistory.com/1521 참고 
	
	stk.push("엄");
	stk.push("준");
	stk.push("식");
	stk.push("화");
	stk.push("이");
	stk.push("팅");

	while(stk.size()){
		cout << stk.top() << "\n";
		stk.pop();
	}
}
