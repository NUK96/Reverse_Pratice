# 第八天

## 一、作业

### 第一题

1. 编写程序，输入10个整数，把这这些按从小倒大排序并且显示

  ```c
//编写程序，输入10个整数，把这这些按从小倒大排序并且显示

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int nArry[10] = { 0 };

	printf("[+] 请输入10个整数：");
	for (int i = 0; i < sizeof(nArry) / sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry) / sizeof(nArry[0]); j++)
	{
		for (int m = j+1; m < sizeof(nArry) / sizeof(nArry[0]); m++)
		{
			if (nArry[m] < nArry[j])
			{
				int nTemp = nArry[j];
				nArry[j] = nArry[m];
				nArry[m] = nTemp;
			}
		}
	}

	printf("[+] 排序后的10个数顺序如下所示：\n");
	for (int n = 0; n < sizeof(nArry) / sizeof(nArry[0]); n++)
	{
		printf("%d ", nArry[n]);
	}
	printf("\n");

	return 0;
}
  ```

### 第二题

1. 编写程序，输入10个整数，把这这些按从大倒小排序并且显示

```c
//编写程序，输入10个整数，把这这些按从大倒小排序并且显示
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int nArry[10] = { 0 };

	printf("[+] 请输入10个整数：");
	for (int i = 0; i < sizeof(nArry) / sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry) / sizeof(nArry[0]); j++)
	{
		for (int m = j+1; m < sizeof(nArry) / sizeof(nArry[0]); m++)
		{
			if (nArry[m] > nArry[j])
			{
				int nTemp = nArry[j];
				nArry[j] = nArry[m];
				nArry[m] = nTemp;
			}
		}
	}

	printf("[+] 排序后的10个数顺序如下所示：\n");
	for (int n = 0; n < sizeof(nArry) / sizeof(nArry[0]); n++)
	{
		printf("%d ", nArry[n]);
	}
	printf("\n");

	return 0;
}
```

### 第三题

1. 将2,4,6,8,10,12,14,16,18,20.这十个数放在数组中，并逆序输出。

```c
//将2, 4, 6, 8, 10, 12, 14, 16, 18, 20.这十个数放在数组中，并逆序输出。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nArry[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int nCount = sizeof(nArry) / sizeof(nArry[0]);

	for (int i = 0; i < nCount; i++)
	{
		for (int j = i+1; j < nCount; j++)
		{
			if (nArry[j] > nArry[i])
			{
				int nTemp = nArry[i];
				nArry[i] = nArry[j];
				nArry[j] = nTemp;
			}
		}
	}
	printf("[+] 排序之后的数列为：");
	for (int m = 0; m < nCount; m++)
	{
		printf("%d ", nArry[m]);
	}
	printf("\n");
}
```

### 第四题

1. 编写程序，输入10个整数，求这些数的和

```c
//编写程序，输入10个整数，求这些数的和

#include<stdio.h>
#include <stdlib.h>

int main()
{

	int sum = 0;
	int nArry[10] = { 0 };

	printf("Please Enter 10 Number:");
	for (int j = 0; j < sizeof(nArry) / sizeof(nArry[0]); j++)
	{
		scanf("%d", &nArry[j]);
	}

	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		sum += nArry[i];
	}

	printf("[+] Sum is:%d\n",sum);

	return 0;
}
```

### 第五题

1. 编写程序，输入10个整数，求这些数的平均值

```c
//编写程序，输入10个整数，求这些数的平均值

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int nArry[10] = { 0 };
	int sum = 0;
	float average = 0;

	printf("请输入10个整数：");
	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry) / sizeof(nArry[0]); j++)
	{
		sum += nArry[j];
	}
	average = sum / 2.0;		//注意：当整数和整数相除的时候，会直接舍去小数部分，只有两个数之间有一个为浮点数，得出的结果才不会舍去小数部分
	printf("[+] 这些数的平均值为：%2.2f\n",average);

	return 0;
}
```

### 第六题

1. 编写程序，输入10个整数，求这些数中最大的数

```c
//编写程序，输入10个整数，求这些数中最大的数

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int nArry[10] = { 0 };
	int nMaxIndex = 0;

	printf("请输入10个整型数：");

	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry)/sizeof(nArry[0]); j++)
	{
		for (int k = j+1; k < sizeof(nArry)/sizeof(nArry[0]); k++)
		{
			if (nArry[k] > nArry[nMaxIndex])
			{
				nMaxIndex = k;
			}
		}
	}
	printf("[+] 整数中最大的数为：%d\n", nArry[nMaxIndex]);
}
```

### 第七题

1. 编写程序，输入10个整数，求这些数中最小的数

```c
//编写程序，输入10个整数，求这些数中最小的数

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int nArry[10] = { 0 };
	int nMaxIndex = 0;

	printf("请输入10个整型数：");

	for (int i = 0; i < sizeof(nArry) / sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry) / sizeof(nArry[0]); j++)
	{
		for (int k = j + 1; k < sizeof(nArry) / sizeof(nArry[0]); k++)
		{
			if (nArry[k] < nArry[nMaxIndex])
			{
				nMaxIndex = k;
			}
		}
	}
	printf("[+] 整数中最大的数为：%d\n", nArry[nMaxIndex]);
}
```

### 第八题

1. 编写程序，输入10个整数，求这些数中最大的3数

```

```

### 第九题

1. 编写程序，输入10个整数，求这些数中最小的3数

```

```

### 第十题

1. 编写程序，输入10个整数，求这些数中大于平均值得数

```c
//编写程序，输入10个整数，求这些数中大于平均值得数

#include <stdio.h>
#include <stdio.h>

int main()
{
	int nArry[10] = { 0 };
	int sum = 0;
	double average = 0;

	printf("[+] 请输入10个整型数：");
	
	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		scanf("%d", &nArry[i]);
	}

	for (int j = 0; j < sizeof(nArry)/sizeof(nArry[0]); j++)
	{
		sum += nArry[j];
	}
	average = sum / 2.0;
    
	printf("[+] 平均数为:%2.2f\n",average);

	for (int k = 0; k < sizeof(nArry)/sizeof(nArry); k++)
	{

		if (nArry[k] > (int)average)
		{
			printf("[+] 大于平均数的整型值有:");
			printf("%d ", nArry[k]);
		}
		else
		{
			printf("[-] 没有比平均值大的数值！\n");
		}
	}
	printf("\n");

	return 0;
}
```

### 第十一题

1. 编写程序，输入10个整数，显示这些数中的素数

```c
////编写程序，输入10个整数，显示这些数中的素数
////思路：需把 m 被 2 ~ m-1 之间的每一个整数去除，如果都不能被整除，那么 m 就是一个素数。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nArry[10] = { 0 };
	int nCount = 0;

	printf("[+] 请输入10个整型数：");
	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		scanf("%d",&nArry[i]);
	}

	printf("[+] 输入的整数中是素数的如下所示：");
	for (int j = 0; j < sizeof(nArry)/sizeof(nArry[0]); j++)
	{
		for (int m = 2; m < nArry[j]; m++)
		{
			if (nArry[j] % m == 0)
			{
				nCount++;
			}
		}

		if (nCount == 0)
		{
			printf("%d ", nArry[j]);
		}
		else
		{
			nCount = 0;	//这里需要注意，如果发现不是素数的时候，计数器需要归零
		}
	}
	printf("\n");
}
```

### 第十二题

1. 输入十个分数，去掉最高分和最低分后求平均分，保留一位小数。

```c
//输入十个分数，去掉最高分和最低分后求平均分，保留一位小数。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nArry[10] = { 0 };
	int sum = 0;
	double average = 0;

	printf("请输入10个整型数：");
	for (int i = 0; i < sizeof(nArry)/sizeof(nArry[0]); i++)
	{
		scanf("%d",&nArry[i]);
	}
	
	for (int j = 0; j < sizeof(nArry)/sizeof(nArry[0]); j++)
	{
		int nMinIndex = j;
		for (int m = j+1; m < sizeof(nArry)/sizeof(nArry[0]); m++)
		{
			if (nArry[m] < nArry[nMinIndex])
			{
				nMinIndex = m;
			}
		}
		if (nMinIndex != 0)
		{
			int nTemp = nArry[j];
			nArry[j] = nArry[nMinIndex];
			nArry[nMinIndex] = nTemp;
		}
	}

	printf("[+] 排序后的值：");
	for (int n = 0; n < sizeof(nArry)/sizeof(nArry[0]); n++)
	{
		printf("%d ", nArry[n]);
	}
	printf("\n");

	for (int k = 1; k <(sizeof(nArry)/sizeof(nArry[0]))-1; k++)
	{
		sum += nArry[k];
	}
	printf("[+]掐头去尾之后为：%d\n", sum);
	average = sum / 2.0;
	printf("[*] 掐头去尾之后的平均数为：%2.1f\n", average);

	return 0;
}
```

### 第十三题

1. 输入10个数到数组t中，再输入x，如果有与x相等的数组元素，输出该数组元素的下标；否则，输出-1。

```c
//输入10个数到数组t中，再输入x，如果有与x相等的数组元素，输出该数组元素的下标；否则，输出 - 1。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nArry[10] = { 0 };
	int nSelectNmuber;
	int nLeft = 0;
	int nRight = 0;
	int nMid = 0;
	int nCount = 0;

	nCount = sizeof(nArry) / sizeof(nArry[0]);

	printf("[+] 请输入10个整型数：");

	for (int i = 0; i < nCount; i++)
	{
		scanf("%d", &nArry[i]);
	}

	printf("[+] 请输入你要查询的数据：");
	scanf("%d", &nSelectNmuber);

	//选择排序法
	for (int m = 0; m < nCount; m++)
	{
		int nMinIndex = m;
		for (int n = m+1; n < nCount; n++)
		{
			if (nArry[n] < nArry[nMinIndex])
			{
				nMinIndex = n;
			}
		}
		if (nMinIndex != 0)
		{
			int nTemp = nArry[nMinIndex];
			nArry[nMinIndex] = nArry[m];
			nArry[m] = nTemp;
		}
	}

	printf("[+] 排完序之后的数如下：");
	for (int x = 0; x < nCount; x++)
	{
		printf("%d ", nArry[x]);
	}
	printf("\n");

	nRight = nCount - 1;
	//折半查找法
	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (nArry[nMid] == nSelectNmuber)
		{
			printf("[*] 你要查询的数的下标为：%d\n",nMid);
			break;
		}
		else if(nArry[nMid] < nSelectNmuber)
		{
			nLeft = nMid + 1;
		}
		else if(nArry[nMid] > nSelectNmuber)
		{
			nRight = nMid - 1;
		}
	}
	return -1;
}
```

### 第十四题

1. 已知数组声明为”int a[6] = {10, 20, 30, 40, 50};”,前五个数组元素是按升序排列的，输入一个整数并插入到数

```c

```



1. 组a中，要求六个数组元素是按升序排列的，输出数组。
2. 猜数游戏，定义一个数列，即从键盘中任意输入一个数据，判断数列中是否包含此数。
3. 编写一个程序，手动输入一个3行4列的二维数组，并像表格一样排列打印出来
4. 输入六个数到2行3列的二维数组a中， 将二维数组a中的数组元素转置，即行列互换，存储到3行2列的二维数组b中，输出二维数组b中的数组元素。
5. 求3行5列的二维数组中的最大值
6. 计算并输出如图所示的杨辉三角形。
	  1
	  1  1
	  1  2  1
	  1  3  3  1
	  1  4  6  4  1
	  1  5  10 10 5  1
	  1  6  15 20 15 6  1
	  1  7  21 35 35 21 7  1
7. 用5行3列的二维数组存储5名学生3门课程的考试成绩，计算每名学生的平均成绩。
8. 求3行5列二维数组中的最小值，及最小值在数组中的行号和列号，并输出。
9. 求3行5列二维数组中每列数组元素的最小值，并输出。
10. 求3行3列二维数组主对角线(从左上角到右下角)上元素之和。
11. 二维数组a(2行3列)表示矩阵A，二维数组b(3行2列)表示矩阵B，计算矩阵A和矩阵B的乘积(2行2列)。矩阵乘法公式如下：

```c
                    B1   B4  
A1  A2  A3 		                 A1*B1+A2*B2+A3*B3  A1*B4+A2*B5+A3*B6
              *     B2   B5  =      
A4  A5  A6	                     A4*B1+A5*B2+A6*B3  A4*B4+A5*B5+A6*B6
                    B3   B6       
```

