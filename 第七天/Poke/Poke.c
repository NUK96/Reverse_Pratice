#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ���˿�
void InitPoke(int poke[], int acolors[], int nCount)
{
	//ע������������βλ�Ӱ��ʵ�Σ���Ϊ���鴫�����������鿪ͷ�ĵ�ַ
	for (int i = 0; i < nCount; i++)	//���˿��Ƹ�ֵ��
	{
		poke[i] = i % 13 + 2;
	}
	poke[52] = 15;	//�����С��
	poke[53] = 16;

	for (int k = 0; k < 54; k++)	//���˿������û�ɫ��
	{
		acolors[k] = k % 4 + 3;		//4�ֻ�ɫ����ASCII���У���3��ʼ��Ȼ��ѭ��������
	}
}

//���ϴ��
void RandPoke(int poke[], int acolors[], int nCount)
{
	for (int m = 0, n = nCount - 1; m < nCount - 1; m++, n--)
	{
		//��������±�
		int nIndex = rand() % n;

		//������
		int nTemp = poke[nIndex];
		poke[nIndex] = poke[n];
		poke[n] = nTemp;

		//������ɫ
		nTemp = acolors[nIndex];
		acolors[nIndex] = acolors[n];
		acolors[n] = nTemp;
	}
}

void ShowPoke(int acolors[], int poke[], int nCount)
{
	//��ʾ
	for (int j = 0; j < nCount; j++)
	{
		switch (poke[j])	//�滻��ʾ
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

		if (j != 0 && (j + 1) % 13 == 0)	//ÿ13�Ž��л���
		{
			printf("\n");
		}

		else if (j != 0 && (j + 1) % 52 == 0)	//ÿ13�Ž��л���
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

//�˿�������
void SortPoke(int aHandColor[], int aHandCard[], int nHandCardCount)
{
	//ð������
	//for (int i = 0; i < nHandCardCount; i++)
	//{
	//	for (int j = 0; j < nHandCardCount - i -1; j++)	//����ѭ���Ĵ���������Ҫע��һ��
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

	//ѡ������
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

//�۰���ң��۰����ʹ��ǰ��Ҫ����
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

	//ϴ��
	for (int i = 0; i < 2; i++)
	{
		RandPoke(poke, acolors, nCount);
	}
	//ע�������ʵ�κ��βΣ�˳��Ҫ��Ӧ

	//����
	int nHandCardCount = sizeof(aHandCard1) / sizeof(aHandCard1[0]);
	//���1������
	TakePoke(poke, acolors, aHandCard1, aHandColor1, nHandCardCount);
	//���2������
	TakePoke(poke + 17, acolors + 17, aHandCard2, aHandColor2, nHandCardCount);
	//���3������
	TakePoke(poke + 34, acolors + 34, aHandCard3, aHandColor3, nHandCardCount);

	ShowPoke(acolors, poke, nCount);

	//���1��������
	SortPoke(aHandColor1, aHandCard1, nHandCardCount);
	//���2��������
	SortPoke(aHandColor2, aHandCard2, nHandCardCount);
	//���3��������
	SortPoke(aHandColor3, aHandCard3, nHandCardCount);
	//������
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
* ��ʼֵ��3 2 5 1 4
*
* ��һ������
* 2 3 5 1 4	//2��3���бȽϣ����������
* 2 3 5 1 4	//3��5���бȽϣ�3��5С��ԭ�ز���
* 2 3 1 5 4	//1��5���бȽϣ����������
* 2 3 1 4 5	//5��4���бȽϣ����������
*
* �ڶ��֣�����һ�ּ������бȽϣ�
* 2 3 1 4 (5)
* 2 1 3 4 (5)
* 2 1 3 4 (5)
*
* �����֣�����һ�ּ������бȽϣ�
* 1 2 3 (4) (5)
* 1 2 3 (4) (5)
*
* �����֣�����һ�ּ������бȽϣ�
* 1 2 (3) (4) (5)
*/

/*
* ѡ������
*
* ��ʼֵ��3 2 5 1 4
*
* ��һ��
* 3 2 5 1 4	//��3 2 5 1 4��ѡ��һ����С�����͵�һλ���н�������С����Ϊ1����1��3�໥����λ�ã�������ʾ
* 1 2 5 3 4
*
* �ڶ���
* 2 5 3 4	//��2 5 3 4��ѡ��һ����С�������һλ���н���������С����2����һλҲ��2����ô�Ͳ���
* 2 5 3 4
*
* ������
* 5 3 4		//��5 3 4��ѡ��һ����С�������һλ���н���������С����3����5���н���
* 3 5 4
*
* ������
* 5 4		//��5��4��ѡ��һ������С�������һλ���н���������С������3����5���н���
* 4 5
*/
