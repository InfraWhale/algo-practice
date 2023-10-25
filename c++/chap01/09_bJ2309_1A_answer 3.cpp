#include <bits/stdc++.h> // 백준 2309 1-A 정답 3 (재귀함수 사용)
using namespace std;

int a[9], sum;
int n = 9, r = 7;
void solve()
{
	int sum = 0;
	for (int i = 0; i < r; i++) {
		sum += a[i];
	}
	if (sum == 100) {
		sort(a, a + 7);
		for (int i = 0; i < r; i++)
			cout << a[i] << "\n";
		exit(0); // 메인함수 자체 종료
	}
}
void print() {
	for (int i = 0; i < r; i++)
		cout << a[i] << " ";
	cout << "\n";
}
void makePermutaiton(int n, int r, int depth) {
	if (r == depth) {
		solve();
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(a[i], a[depth]);
		makePermutaiton(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
	return;
}
int main() {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	makePermutaiton(n, r, 0);
	return 0;
}
