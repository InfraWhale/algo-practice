// point struct

struct Point{
	int y, x;
	
	Point(int y, int x) : y(y), x(x){} // �� point ��ü�� �������� ���� �����ڷ� ������ / y��ġ�� ���� ���� y�� ����, x��ġ ���� ���� x�� 
	
	Point(){y = -1; x = -1;} // �������� ���� ��� �� ������ -1 
	
	bool operator < (const Point & a) const{ // ������ <�� �����ε� 
		if(x == a.x) return y < a.y; // �� �� x���� ������ �ڿ� �� ū y���� ���� ���� 
		return x < a.x; // �ڿ� �� ū x���� ���� ���� 
	}
};
