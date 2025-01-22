#include<bits/stdc++.h> // 백준 2170
using namespace std;
// 11% 틀렸습니다.
// https://astrid-dm.tistory.com/510#google_vignette
// 답을 봐도 이해가...?

int ret[4];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int idx = 0; idx < 4; idx++) {
		int arr[18];
		for (int i = 0; i < 18; i++) {
			cin >> arr[i];
		}

		bool flag = true;
		int win = 0;
		int draw = 0;
		int maxDraw = 0;
		int lose = 0;

		// 모든 나라는 승 + 무 + 패 = 5
		for (int i = 0; i < 18; i += 3){
			// cout << arr[i] << " : " << arr[i+1] << " : " << arr[i+2] << "\n";
			if (arr[i] + arr[i+1] + arr[i+2] != 5) {
				flag = false;
				break;
			}

			int winChange = 0;
			int loseChange = 0;

			if (arr[i] >= lose) {
				loseChange -= lose;
				winChange += (arr[i] - lose);
			} else {
				loseChange -= arr[i];
			}

			if (arr[i+2] >= win) {
				winChange -= win;
				loseChange += (arr[i+2] - win);
			} else {
				winChange -= arr[i+2];
			}

			win += winChange;
			lose += loseChange;

			draw += arr[i+1];
			maxDraw = max(maxDraw, arr[i+1]);
		}

		// cout << "win" << " : " << "draw" << " : " << "lose" << "\n";
		// cout << win << " : " << draw << " : " << lose << "\n";

		// 승수와 패수는 같음 && 무는 무조건 짝수 && 한 국가에서 과반의 무승부를 하지 않을 것
		if(flag && win == lose && draw % 2 == 0 && draw / 2 >= maxDraw) {
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