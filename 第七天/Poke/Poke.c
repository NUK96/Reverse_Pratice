#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化扑克
void InitPoke(int poke[], int acolors[], int nCount)
{
	//注：操作这里的形参会影响实参，因为数组传过来的是数组开头的地址
	for (int i = 0; i < nCount; i++)	//给扑克牌赋值；
	{
		poke[i] = i % 13 + 2;
	}
	poke[52] = 15;	//处理大小王
	poke[53] = 16;

	for (int k = 0; k < 54; k++)	//给扑克牌设置花色；
	{
		acolors[k] = k % 4 + 3;		//4种花色，在ASCII码中，从3开始，然后循环往复；
	}
}

//随机洗牌
void RandPoke(int poke[], int acolors[], int nCount)
{
	for (int m = 0, n = nCount - 1; m < nCount - 1; m++, n--)
	{
		//随机数组下标
		int nIndex = rand() % n;

		//交换牌
		int nTemp = poke[nIndex];
		poke[nIndex] = poke[n];
		poke[n] = nTemp;

		//交换花色
		nTemp = acolors[nIndex];
		acolors[nIndex] = acolors[n];
		acolors[n] = nTemp;
	}
}

void ShowPoke(int acolors[], int poke[], int nCount)
{
	//显示
	for (int j = 0; j < nCount; j++)
	{
		switch (poke[j])	//替换显示
		{
		case 11:
			printf("%cJ   ", acolors[j]);
			break;
		case 12:
			printf("%cQ   ", acolors[j]);
			break;
		case 13:
			printf("%cK   ", acolors[j]);
			break;
		case 14:
			printf("%cA   ", acolors[j]);
			break;
		case 15:
			printf(" \x1   ");
			break;
		case 16:
			printf(" \x2   ");
			break;
		default:
			printf("%c%-3d ", acolors[j], poke[j]);
		}

		if (j != 0 && (j + 1) % 13 == 0)	//每13张进行换行
		{
			printf("\n");
		}

		else if (j != 0 && (j + 1) % 52 == 0)	//每13张进行换行
		{
			printf("\n\n");
		}
	}
	printf("\n");
}

void TakePoke(int poke[], int acolors[], int aHandCard1[], int aHandColor1[], int nHandCardCount)
{
	int nIndex = 0;

	for (int i = 0; i < nHandCardCount; i++)
	{
		aHandCard1[i] = poke[nIndex];
		aHandColor1[i] = acolors[nIndex];
		nIndex++;
	}
}

//扑克牌排序
void SortPoke(int aHandColor[], int aHandCard[], int nHandCardCount)
{
	//冒泡排序
	//for (int i = 0; i < nHandCardCount; i++)
	//{
	//	for (int j = 0; j < nHandCardCount - i -1; j++)	//这里循环的次数还是需要注意一下
	//	{
	//		if (aHandCard[j] > aHandCard[j+1] || aHandCard[j] == aHandCard[j+1] && aHandColor[j] > aHandColor[j+1])
	//		{
	//			int nTemp = aHandCard[j + 1];
	//			aHandCard[j + 1] = aHandCard[j];
	//			aHandCard[j] = nTemp;

	//			nTemp = aHandColor[j + 1];
	//			aHandColor[j + 1] = aHandColor[j];
	//			aHandColor[j] = nTemp;
	//		}
	//	}
	//}

	//选择排序
	for (int i = 0; i < nHandCardCount; i++)
	{
		int nMinIndex = i;
		for (int j = i + 1; j < nHandCardCount; j++)
		{
			if (aHandCard[j] < aHandCard[nMinIndex])
			{
				nMinIndex = j;
			}
		}
		if (nMinIndex != i)
		{
			int nTemp = aHandCard[i];
			aHandCard[i] = aHandCard[nMinIndex];
			aHandCard[nMinIndex] = nTemp;

			nTemp = aHandColor[i];
			aHandColor[i] = aHandColor[nMinIndex];
			aHandColor[nMinIndex] = nTemp;
		}
	}
}

//折半查找，折半查找使用前需要排序
int SearchPoke(int aHandCard[], int nHandCount, int ap)
{
	int nLeft = 0;
	int nRight = nHandCount - 1;
	int nMid = 0;

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (aHandCard[nMid] == ap)
		{
			return nMid;
		}
		else if (aHandCard[nMid] < ap)
		{
			nLeft = nMid + 1;
		}
		else
		{
			nRight = nMid - 1;
		}
	}
	return -1;
}

int main()
{

	int poke[54] = { 0 };
	int acolors[54] = { 0 };
	int nCount = 0;
	int aHandCard1[17] = { 0 };
	int aHandColor1[17] = { 0 };
	int aHandCard2[17] = { 0 };
	int aHandColor2[17] = { 0 };
	int aHandCard3[17] = { 0 };
	int aHandColor3[17] = { 0 };
	int ap;
	int position;

	system("chcp 437");
	srand((unsigned)time(0));

	nCount = sizeof(poke) / sizeof(poke[0]);

	InitPoke(poke, acolors, nCount);

	//洗牌
	for (int i = 0; i < 2; i++)
	{
		RandPoke(poke, acolors, nCount);
	}
	//注：传入的实参和形参，顺序要对应

	//发牌
	int nHandCardCount = sizeof(aHandCard1) / sizeof(aHandCard1[0]);
	//玩家1的手牌
	TakePoke(poke, acolors, aHandCard1, aHandColor1, nHandCardCount);
	//玩家2的手牌
	TakePoke(poke + 17, acolors + 17, aHandCard2, aHandColor2, nHandCardCount);
	//玩家3的手牌
	TakePoke(poke + 34, acolors + 34, aHandCard3, aHandColor3, nHandCardCount);

	ShowPoke(acolors, poke, nCount);

	//玩家1手牌排序
	SortPoke(aHandColor1, aHandCard1, nHandCardCount);
	//玩家2手牌排序
	SortPoke(aHandColor2, aHandCard2, nHandCardCount);
	//玩家3手牌排序
	SortPoke(aHandColor3, aHandCard3, nHandCardCount);
	//地主牌
	SortPoke(acolors + 51, poke + 51, 3);


	printf("\nPlayer1:\n");
	ShowPoke(aHandColor1, aHandCard1, nHandCardCount);

	printf("\nPlayer2:\n");
	ShowPoke(aHandColor2, aHandCard2, nHandCardCount);

	printf("\nPlayer3:\n");
	ShowPoke(aHandColor3, aHandCard3, nHandCardCount);

	printf("\nPoke:\n");
	ShowPoke(acolors + 51, poke + 51, 3);

	printf("Please Input Your Poke:");
	scanf("%d", &ap);
	position = SearchPoke(aHandCard1, nHandCardCount, ap);
	if (position != -1)
	{
		printf("Poke Position is: %d\n", position);
	}
	else
	{
		printf("Invaild Find !\n");
	}

	return 0;
}

/*
* 初始值：3 2 5 1 4
*
* 第一轮排序
* 2 3 5 1 4	//2和3进行比较，大的往后排
* 2 3 5 1 4	//3和5进行比较，3比5小，原地不动
* 2 3 1 5 4	//1和5进行比较，大的往后排
* 2 3 1 4 5	//5和4进行比较，大的往后排
*
* 第二轮（继上一轮继续进行比较）
* 2 3 1 4 (5)
* 2 1 3 4 (5)
* 2 1 3 4 (5)
*
* 第三轮（继上一轮继续进行比较）
* 1 2 3 (4) (5)
* 1 2 3 (4) (5)
*
* 第四轮（继上一轮继续进行比较）
* 1 2 (3) (4) (5)
*/

/*
* 选择排序：
*
* 初始值：3 2 5 1 4
*
* 第一轮
* 3 2 5 1 4	//在3 2 5 1 4中选择一个最小的数和第一位进行交换，最小的数为1，即1和3相互交换位置，如下所示
* 1 2 5 3 4
*
* 第二轮
* 2 5 3 4	//在2 5 3 4中选择一个最小的数与第一位进行交换，即最小数是2，第一位也是2，那么就不动
* 2 5 3 4
*
* 第三轮
* 5 3 4		//在5 3 4中选择一个最小的数与第一位进行交换，即最小数是3，和5进行交换
* 3 5 4
*
* 第四轮
* 5 4		//在5和4中选择一个中最小的数与第一位进行交换，即最小的数是3，和5进行交换
* 4 5
*/
