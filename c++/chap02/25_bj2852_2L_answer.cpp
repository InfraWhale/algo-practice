#include<bits/stdc++.h> // 백준 2852 2L 정답
using namespace std;
#define prev kundol

int n, o, A, B, asum, bsum;
string s, prev;
string print(int a) {
	string d ="00" + to_string(a / 60);
	string e ="00" + to_string(a % 60);
	return d.substr(d.size() -2, 2) + ":" + e.substr(e.size() -2, 2);
}
int changeToInt(string a) {
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str()); //c.str() : 문자열을 C스타일 문자열로 바꿔줌
}
void go(int &sum, string s) { // 값을 복사하여 전달하는 것이 아니라, sum 자체를 바꿔야 하므로 참조에 의한 전달을 하여야 한다.
	sum += (changeToInt(s) - changeToInt(prev));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> s;
		if(A > B) go(asum, s); // A가 이긴 경우
		else if(B > A)go(bsum, s); // B가 이긴 경우
		o == 1 ? A++ : B++;
		prev = s;
	}
	if(A > B) go(asum, "48:00");
	else if(B > A) go(bsum, "48:00");
	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";
}
