#include<bits/stdc++.h>
using namespace std;

struct Point{
	int y, x;
	
	Point(int a, int b) : y(a), x(b){} // ������ -> ���� y�� a��, ���� x�� b�� 
	Point(){y = -1; x = -1; }
	
	bool operator < (const Point & a) const{ // const Point & a -> �� a��� ����ü��� �����ϸ� �ɵ�? | const�� �ֺ�����? 
		if(x == a.x) 
			return y < a.y; // �� ����ü�� x ���� a��� ����ü�� x�� ���� ���ٸ� y���� a.y�� ũ�ٰ� ���� 
	return x < a.x; // �ƴ϶�� x���� a.x�� ũ�ٰ� ���� | ��������
	// return x > a.x; // | ��������	 
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

