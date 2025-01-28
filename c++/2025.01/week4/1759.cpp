#include<bits/stdc++.h> // 백준 1759
using namespace std;

int L, C, ja, mo;
char arr[15];
string pw;

void password(int now, int depth) {
	if (depth == L) {
		if (ja >= 2 && mo >= 1) {
			cout << pw <<"\n";
		}
		return;
	}

	for (int i = now; i < C; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
			mo += 1;
			pw.push_back(arr[i]);
			password(i+1, depth+1);
			mo -= 1;
			pw.pop_back();
		} else {
			ja += 1;
			pw.push_back(arr[i]);
			password(i+1, depth+1);
			ja -= 1;
			pw.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + C);
	ja = 0;
	mo = 0;

	password(0, 0);

	return 0;
}