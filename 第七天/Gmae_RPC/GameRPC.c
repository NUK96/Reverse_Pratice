// 1����ɫ��Boss��Player
// 2������һ������������Boss��Ѫ��
// 3������һ��������������ҵ�Ѫ��
// 4����ʾBoss��Ѫ��
// 5����ҹ���
//	1��BossѪ������
//	2�����BossûѪ����Ӯ��
// 6��Boss����
//	1�����Ѫ������
//	2��������ûѪ��BossӮ��
// 7���ظ�4
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

int nBossHP = 10;
int nPlayerHP = 5;

void showBossHP()
{
	printf("BossHP:");		//��ʾBoss��Ѫ��
	for (int i = 0; i < nBossHP; i++)
	{
		printf("%c", 3);
	}
	printf("\n");
}

void showPlayerHP()
{
	printf("PlayerHP");	//��ʾ��ҵ�Ѫ��
	for (int j = 0; j < nPlayerHP; j++)
	{
		printf("%c", 3);
	}
	printf("\n");
}

void showSkill()
{
	printf("Attack Skill:\n");
	printf("[+] 1.Common Attack\n");
	printf("[+] 2.Whirl wind\n");
}

void PlayerAttack(char ch)
{
	printf("Boss HP - %d\n", ch - '0');	//ch-'0'  ��ʵ����ascii��ֵ�ڽ������
	nBossHP -= (ch - '0');
}

bool showWin()
{
	if (nBossHP <= 0)
	{
		printf("\nPlayer Win!\n");
		return true;
	}
	return false;
}

bool showLose()
{
	if (nPlayerHP <= 0)
	{
		printf("[-] Sorry , You Lost, 50%% off VIP recharge activities\n");
		return true;
	}
	return false;
}

char GetInput()
{
	printf("Choice num for attack skill.......\n");
	char ch = _getch();

	PlayerAttack(ch);

	return ch;
}

void gameInit()
{

	system("chcp 437");
	srand((unsigned)time(NULL));	//�����������
}

void showMiss()
{
	if (rand() % 2 == 0)
	{
		printf("[+] Player Miss Attack...\n");
	}
	else
	{
		printf("nPlayer HP - 1\n");
		nPlayerHP--;
	}
}

void gameLoop()
{

	while (true)
	{
		showBossHP();	//չʾBoss��Ѫ��

		showPlayerHP();	//չʾ��ҵ�Ѫ��

		showSkill();	//չʾ������

		GetInput();		//��ȡ�û�����

		if (showWin())
			break;

		showMiss();
		if (showLose())
			break;
	}
}

int main()
{

	gameInit();
	gameLoop();

	return 0;
}