//��֪��������Ϊ��int a[6] = { 10, 20, 30, 40, 50 }; ��, ǰ�������Ԫ���ǰ��������еģ�����һ�����������뵽������

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[6] = { 10, 20, 30, 40, 50 };
	int nInsertNum;
	int nCount = 0;

	printf("��������Ҫ���������");
	scanf("%d",&nInsertNum);

	nCount = sizeof(a) / sizeof(a[0]);

	printf("%d\n",nCount);
}