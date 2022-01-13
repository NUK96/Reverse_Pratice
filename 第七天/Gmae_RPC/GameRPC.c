// 1、角色：Boss、Player
// 2、定义一个变量，保存Boss的血量
// 3、定义一个变量，保存玩家的血量
// 4、显示Boss的血量
// 5、玩家攻击
//	1）Boss血量减少
//	2）如果Boss没血，你赢了
// 6、Boss还击
//	1）玩家血量减少
//	2）如果玩家没血，Boss赢了
// 7、重复4
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
	printf("BossHP:");		//显示Boss的血量
	for (int i = 0; i < nBossHP; i++)
	{
		printf("%c", 3);
	}
	printf("\n");
}

void showPlayerHP()
{
	printf("PlayerHP");	//显示玩家的血量
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
	printf("Boss HP - %d\n", ch - '0');	//ch-'0'  其实就是ascii的值在进行相减
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
	srand((unsigned)time(NULL));	//设置随机种子
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
		showBossHP();	//展示Boss的血量

		showPlayerHP();	//展示玩家的血量

		showSkill();	//展示技能树

		GetInput();		//获取用户输入

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