#include<bits/stdc++.h>
using namespace std;

stack<string> stk;

int main() {
	
	
	ios_base::sync_with_stdio(false); // c�� stdio�� cpp�� iostream ���� ����ȭ ���� -> c�� ���� stdio�� ���� ��� ���ϹǷ� ������ �߻� ���� 
	cin.tie(NULL); // cin�� cout�� ������ Ǯ����. �̷��� io �۾� �� �ڵ����� ���� ���Ⱑ �ȵǹǷ� ��� ���� ���� ������ ��. 
	// https://jaimemin.tistory.com/1521 ���� 
	
	stk.push("��");
	stk.push("��");
	stk.push("��");
	stk.push("ȭ");
	stk.push("��");
	stk.push("��");

	while(stk.size()){
		cout << stk.top() << "\n";
		stk.pop();
	}
}
