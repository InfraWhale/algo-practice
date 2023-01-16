#include <cstdio> // lower bound & upper bound
#include <vector>
#include <algorithm>

#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v;
	int a[5] = {1, 2, 2, 2, 3};
	
	for(int i = 0; i < 5; i++){
		v.push_back(a[i]);
	}
	int x = 2;
	int c = (int)(upper_bound(v.begin(),v.end(),x) - lower_bound(v.begin(),v.end(),x));
	int f = (int)(lower_bound(v.begin(),v.end(),x) - v.begin()); // lower_bound는 0번째 배열의 원소부터 찾아서 어떠한 값의 "이상이 되는 위치"를 반환
	int t = (int)(upper_bound(v.begin(),v.end(),x) - v.begin()); // upper_bound는 그 값이 시작되기 전의 위치를 반환
	int f2 = *lower_bound(v.begin(),v.end(),x);
	int t2 = *upper_bound(v.begin(),v.end(),x);
	
	printf("%d의 갯수 : %d, 시작되는 점 : %d 끝나는 점 : %d\n", x, c, f, t);
	printf("lower bound가 시작되는 점의 값 : %d, upper bound가시작되는 점의 값 : %d\n", f2, t2);
	
	int aa = *upper_bound(v.begin(),v.end(),x);
	cout << aa << "\n";
	
	c = (int)(upper_bound(a, a + 5, x) - lower_bound(a, a + 5, x));
	f = (int)(lower_bound(a, a + 5, x) - a);
	t = (int)(upper_bound(a, a + 5, x) - a);
	f2 = *lower_bound(a, a + 5, x);
	t2 = *upper_bound(a, a + 5, x);
	printf("%d의 갯수 : %d, 시작되는 점 : %d 끝나는 점 : %d\n", x, c, f, t);
	printf("lower bound가 시작되는 점의 값 : %d, upper bound가시작되는 점의 값 : %d\n", f2, t2);
	return 0;
}
