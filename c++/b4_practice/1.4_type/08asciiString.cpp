#include <bits/stdc++.h> // �ƽ�Ű�ڵ�� ���ڿ� 

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "123"; // s[0]�� "1" -> �ƽ�Ű�ڵ忡�� 049 
	s[0]++; // �ƽ�Ű�ڵ� 049�� 1�� ���� 050 -> ���ڷδ� "2" 
	cout << s << "\n"; // 223
	return 0;
}

// 065 -> "A"
// 097 -> "a"

