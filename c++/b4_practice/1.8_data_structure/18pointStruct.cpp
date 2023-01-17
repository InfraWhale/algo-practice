// point struct

struct Point{
	int y, x;
	
	Point(int y, int x) : y(y), x(x){} // 이 point 객체의 변수값을 다음 생성자로 정의함 / y위치의 값은 변수 y로 가고, x위치 값은 변수 x로 
	
	Point(){y = -1; x = -1;} // 정해지지 않은 경우 각 변수값 -1 
	
	bool operator < (const Point & a) const{ // 연산자 <를 오버로딩 
		if(x == a.x) return y < a.y; // 앞 뒤 x값이 같으면 뒤에 더 큰 y값이 오게 조정 
		return x < a.x; // 뒤에 더 큰 x값이 오게 조정 
	}
};
