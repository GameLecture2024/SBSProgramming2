#pragma once

// Rpg skill
// 스킬 이름

typedef enum SkillGrade
{
	노말,레어 = 5,엘리트 = 10,레전더리 = 100
}SkillGrade;

typedef struct ShopSkillInfo
{
	int price;
	int ExpressWeight;   // 등급에 따라 등장하는 수치를 다르게 한다. (1 ~90) 100  높은 등급은 숫자가 크다.
}ShopSkillInfo;

typedef struct Skill
{	
	SkillGrade Grade;
	ShopSkillInfo shopInfo;
	char name[50];
}Skill;

typedef struct ShopManager
{
	Skill skill[5];	        // 어떤 기능을 해금을 해서 상점에 나오는 아이템의 수가 1증가한다.
}ShopManager;

// Skill skill;
// skill.shopInfo;

typedef struct Player
{
	int money;
}Player;

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CalculateGradeWithExpressWeight(Skill skill)
{
	return skill.Grade * 10; //   0 - 50 - 100 -  1000 
}

void ShopPhase(ShopManager manager, Player player)
{
	printf(" == 상점에서 팔고 있는 아이템의 목록 == \n\n");

	for (int i = 0; i < 5; i++)
	{
		printf("[%d] | %s | %d \n", i, manager.skill[i].name, manager.skill[i].shopInfo.price);
	}

}

void BuySkill(int money, ShopSkillInfo info)
{
	if (money < info.price) return;	  // 구매할 수 있는 조건이 아니면 실행하지 말 것

	// 유저의 스킬에 포함시킨다.
}

void ExecuteSampale()
{
	ShopManager manager;
	Player player;
	player.money = 100;
	// 데이터 초기화.  이 상점이 어떤 아이템을 팔 것인가?
	strcpy(manager.skill[0].name,"포션");
	manager.skill[0].Grade = 노말;
	manager.skill[0].shopInfo.price = 10;
	manager.skill[0].shopInfo.ExpressWeight = CalculateGradeWithExpressWeight(manager.skill[0]);

	strcpy(manager.skill[1].name, "포션");
	manager.skill[1].Grade = 노말;
	manager.skill[1].shopInfo.price = 10;
	manager.skill[1].shopInfo.ExpressWeight = CalculateGradeWithExpressWeight(manager.skill[1]);

	strcpy(manager.skill[2].name, "포션");
	manager.skill[2].Grade = 노말;
	manager.skill[2].shopInfo.price = 10;
	manager.skill[2].shopInfo.ExpressWeight = CalculateGradeWithExpressWeight(manager.skill[2]);

	strcpy(manager.skill[3].name, "포션");
	manager.skill[3].Grade = 레어;
	manager.skill[3].shopInfo.price = 10;
	manager.skill[3].shopInfo.ExpressWeight = CalculateGradeWithExpressWeight(manager.skill[3]);

	strcpy(manager.skill[4].name, "포션");
	manager.skill[4].Grade = 노말;
	manager.skill[4].shopInfo.price = 10;
	manager.skill[4].shopInfo.ExpressWeight = CalculateGradeWithExpressWeight(manager.skill[4]);
	ShopPhase(manager, player);
}