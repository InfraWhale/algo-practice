#include<bits/stdc++.h> // 백준 12869 3E (모르겠음->품 & 메모리초과였으나 for문 안에 visited 방문 안하게 처리 후 풀림)
using namespace std;

int n, a[3], visited[64][64][64], x, y, z, nx, ny, nz;
struct D {
	int f, s, t; 
};
queue<D> q;

vector<D> v = {
	{9, 3, 1} ,
	{9, 1, 3} ,
	{3, 9, 1} ,
	{3, 1, 9} ,
	{1, 9, 3} ,
	{1, 3, 9}
}; 

int main() { 
	cin >> n;

	for(int i=0; i < n; i++) {
		cin >> a[i];
	}

	q.push({a[0], a[1], a[2]});
	visited[a[0]][a[1]][a[2]] = 0;
	while(q.size()) {
		x = q.front().f;
		y = q.front().s;
		z = q.front().t;
		q.pop();
		if(visited[0][0][0]) break;
		for(int i = 0; i < 6; i++) {
			nx = max(0, x - v[i].f);
			ny = max(0, y - v[i].s);
			nz = max(0, z - v[i].t);
			if(visited[nx][ny][nz]) continue;
			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({nx, ny, nz});
		}
	}

	cout << visited[0][0][0] << "\n";

	return 0;
}