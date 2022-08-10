#include<bits/stdc++.h>
using namespace std;

struct Point{
	int y, x;
	
	Point(int a, int b) : y(a), x(b){} // 생성자 -> 변수 y에 a값, 변수 x에 b값 
	Point(){y = -1; x = -1; }
	
	bool operator < (const Point & a) const{ // const Point & a -> 걍 a라는 구조체라고 생각하면 될듯? | const는 왜붙은거? 
		if(x == a.x) 
			return y < a.y; // 이 구조체의 x 값과 a라는 구조체의 x란 값이 같다면 y보다 a.y가 크다고 리턴 
	return x < a.x; // 아니라면 x보다 a.x가 크다고 리턴 | 오름차순
	// return x > a.x; // | 내림차순	 
	}

};

vector<Point> v;

int main(){
	for(int i = 10; i >= 1; i--){
		Point a = {i, -i};
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	for(auto it : v) 
		cout << it.y << " : " << it.x << '\n';
	
	return 0;
}

