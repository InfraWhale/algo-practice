#include<bits/stdc++.h> // 백준 6987
using namespace std;

int arr[6][3], score[6][3], ret[4];
vector<pair<int, int>> v;
bool flag;

void bt(int depth) {
	if (depth == 15) { // 총 경기 수. 재귀 15번 타고 얻은 값이 초기 입력값이랑 같은지 확인한다.
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if(arr[i][j] != score[i][j]) {
					return;
				}
			}
		}
		flag = true;
		return;
	}

	const int a = v[depth].first;
	const int b = v[depth].second;

	// a 승 , b 패의 경우
	score[a][0]++;
	score[b][2]++;
	bt(depth+1);
	score[a][0]--;
	score[b][2]--;

	// a 무 , b 무의 경우
	score[a][1]++;
	score[b][1]++;
	bt(depth+1);
	score[a][1]--;
	score[b][1]--;

	// a 패 , b 승의 경우
	score[a][2]++;
	score[b][0]++;
	bt(depth+1);
	score[a][2]--;
	score[b][0]--;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 6; j++) {
			v.push_back({i, j});
		}
	}

	for (int idx = 0; idx < 4; idx++) {

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}

		flag = false;

		bt(0);

		if (flag) {
			ret[idx] = 1;
		} else {
			ret[idx] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << ret[i] << " ";
	}
	
	return 0;
}