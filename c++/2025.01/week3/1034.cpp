#include<bits/stdc++.h> // 백준 1034
// 1% 시간초과
using namespace std;

// k가 홀수 -> 선택할 수 있는 열의 수 1, 3, 5, 7 ...
// k가 짝수 -> 선택할 수 있는 열의 수 2, 4, 6, 8 ...

int n, m, k, a[54][54], initial[54], selected[54], goal;

int ret = 0;

int countRow() {

	// for (int i=0; i<n; i++) {
	// 	cout << selected[i] << " ";
	// }
	// cout << "\n";

	int count = 0;
	for(int i=0; i<n; i++) {
		if (initial[i] + goal < m) {
			continue;
		}
		bool flag = true;
		for(int j=0; j<m; j++) {
			if ((selected[j] == 1 and a[i][j] == 1) or (selected[j] == 0 and a[i][j] == 0)) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			count++;
		}
	}
	// cout << count << "\n";
	return count;
}

void selectColumn(int point, int count) {
	if (count == goal) {
		ret = max(ret, countRow());
		return;
	}
	for(int i=point; i<m; i++) {
		selected[i]=1;
			selectColumn(i+1, count+1);
		selected[i]=0;
	}
	return;
}

int main() {

	cin >> n >> m;
	int initialCount;
	for(int i=0; i<n; i++) {
		initialCount = 0;
		for(int j=0; j<m; j++) {
			scanf("%1d", &a[i][j]);
			if (a[i][j] == 1) {
				initialCount += 1;
			}
		}
		initial[i] = initialCount;
	}
	cin >> k;

	goal = (k & 1 == 1) ? 1 : 0;

	for(goal; goal<=m; goal+=2) {
		selectColumn(0, 0);
	}
	cout << ret;

	return 0;
}