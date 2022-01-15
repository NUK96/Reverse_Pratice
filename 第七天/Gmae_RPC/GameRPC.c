//已知数组声明为”int a[6] = { 10, 20, 30, 40, 50 }; ”, 前五个数组元素是按升序排列的，输入一个整数并插入到数组中

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[6] = { 10, 20, 30, 40, 50 };
	int nInsertNum;
	int nCount = 0;

	printf("请输入你要插入的数：");
	scanf("%d",&nInsertNum);

	nCount = sizeof(a) / sizeof(a[0]);

	printf("%d\n",nCount);
}