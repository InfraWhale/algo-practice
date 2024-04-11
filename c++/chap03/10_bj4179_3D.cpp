#include<bits/stdc++.h> // 백준 4179 3D (맞왜틀)
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1}; 
int r, c, ret, visitedF[1004][1004], visitedJ[1004][1004];
bool flag;
pair<int, int> j;
vector<pair<int, int>> f;
char a[1004][1004];

void bfsF(int y, int x) {
    visitedF[y][x] = 1;
	queue<pair<int, int>> q;  
    q.push({y, x});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == '#') continue; 
            if(visitedF[ny][nx] && visitedF[y][x] + 1 >= visitedF[ny][nx]) continue; 
            visitedF[ny][nx] = visitedF[y][x] + 1;
            q.push({ny, nx});
        } 
    }
	return;
}

void bfsJ(int y, int x) {
    visitedJ[y][x] = 1;
	queue<pair<int, int>> q;  
    q.push({y, x});  
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == '#') continue; 
            if(visitedJ[ny][nx]) continue; 
			if(visitedF[ny][nx] && visitedJ[y][x] + 1 >= visitedF[ny][nx]) {
				continue;
			}
            visitedJ[ny][nx] = visitedJ[y][x] + 1;
			if(ny == 0 || ny == r-1 || nx == 0 || nx == c-1) {
				ret = min(ret, visitedJ[ny][nx]);
				flag = 1;
			}
            q.push({ny, nx});
        } 
    }
	return;
}

int main() { 
	cin >> r >> c;
	
	for(int i = 0; i < r; i++) {
		for(int k = 0; k < c; k++) {
			cin >> a[i][k];
			if (a[i][k] == 'J') j = {i, k};
			else if(a[i][k] == 'F') f.push_back({i, k});
		}
	}

	if(f.size()) {
		for(auto it : f) {
			bfsF(it.first, it.second);
		}
	}

	ret = 987654321;
	flag = 0;
	if(j.first == 0 || j.first == r-1 || j.second == 0 || j.second == c-1) {
		flag = 1;
		ret = 1;
	} else bfsJ(j.first, j.second);

	if (flag) cout << ret << "\n";
	else cout << "IMPOSSIBLE" << "\n";

}