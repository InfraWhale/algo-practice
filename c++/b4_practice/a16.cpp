#include <bits/stdc++.h>
using namespace std;

int a = 1;
char s = 'a';
string str = "�����";
double b = 1.223123;

int main(){
	printf("���̿��� ���̾�� : %d\n",a); // int
	printf("���̿��� ���̾�� : %c\n",s); // char
	printf("���̿��� ���̾�� : %s\n",str.c_str()); // string
	// printf("���̿��� ���̾�� : %s\n",str); // printf�� c�� �Լ��Ƿ�, ���� ���� c_str()�� �Ἥ c ��Ÿ�� ���ڿ�(char *)�� ��ȯ	
	printf("���̿��� ���̾�� : %lf\n",b); // double
	return 0;
}

