#include <bits/stdc++.h> // printf ���� ���� 2

using namespace std;
int a = 1;
char s = 'a';
string str = "�����";
double b = 1.223123;

int main(){
	printf("���̿��� ���̾�� : %d\n",a);
	printf("���̿��� ���̾�� : %c\n",s);
	printf("���̿��� ���̾�� : %s\n",str.c_str()); //string�� �׳� ��� �ȵǰ� ���ڿ��� ���� ������ Ÿ������ �ٲ���� ��(char *), cout ���°� ���� 
	printf("���̿��� ���̾�� : %lf\n",b);
	return 0;
}

