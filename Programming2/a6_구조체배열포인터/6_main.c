#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>
#define 몬스터의대사의최대수 3

typedef struct Pos
{
	int x;
	int y;
}Pos;

// 구조체 선언
typedef struct Monster
{
	char name[100];	  // 배열도 포인터, 포인터로 표현할 수 있다.
	char dialogue[몬스터의대사의최대수][100]; // 대사. 첫 조우 대사	 -> 대사를 번호에다가 저장 1번 대사 : 2번 대사 : 3번 대사 :
	Pos pos;
}Monster;

typedef enum Location
{
	 물, 숲, 산, 들판
}Location;

void MonsterTalking(Monster* a, Monster* b);

// 배열

// 포인터

// 모든 몬스터가 같이 사용하는 함수, 몬스터 정보, 장소
void MonsterEncount(Monster* monster, Monster* other, Location location)  // 포인터? Type
{
	//if() // 몬스터가 누군가와 조우했을 때만 실행해야한다.
	//         몬스터의 좌표가 같을 때만 아래 코드를 실행하세요

	bool encount = monster->pos.x == other->pos.x && monster->pos.y == other->pos.y; 

	if (!encount)
	{
		printf("[Log] 두 몬스터의 좌표가 일치하지 않습니다.");
		return;
	}

	char locationName[100];

	if (location == 숲)
	{
		strcpy(locationName, "숲");
	}
	else if (location == 산)
	{
		strcpy(locationName, "산");
	}
	else
	{
		printf("지정되지 않은 지역입니다. location 조건을 추가해주세요.");
		return;
	}

	printf("%s에서, %s이(가) 나타났다.\n", locationName, monster->name);

	MonsterTalking(monster, other);

	//int index = 0;
	//if (index >= 몬스터의대사의최대수)
	//{
	//	printf("[에러] 몬스터 저장할 수 있는 최대 수 보다 큰 인덱스에 접근하고 있습니다.\n");
	//	return;
	//}
	//printf("[%s] : %s\n", monster->name, monster->dialogue[index]);
}


void MonsterTalking(Monster* a, Monster* b)
{
	for (int index = 0; index < 몬스터의대사의최대수; index++)
	{
		printf("[%s] : %s\n", a->name, a->dialogue[index]);
		printf("[%s] : %s\n", b->name, b->dialogue[index]);
		Sleep(1000);
	}	
}

int main()
{
	Monster goblin;
	Location currentLocation = 숲;
	goblin.pos.x = 10;
	goblin.pos.y = 10;
	strcpy(goblin.name,"고블린");
	strcpy(goblin.dialogue[0], "크아악!\n");
	strcpy(goblin.dialogue[1], "인간이다! \n");
	strcpy(goblin.dialogue[2], "약탈하자!\n");

	Monster rabbit;
	rabbit.pos.x = 10;
	rabbit.pos.y = 10;
	strcpy(rabbit.name, "토끼");
	strcpy(rabbit.dialogue[0], "이봐, \n");
	strcpy(rabbit.dialogue[1], "당근이라도 \n");
	strcpy(rabbit.dialogue[2], "좀 줄 텐가?\n");

	MonsterEncount(&goblin, &rabbit, currentLocation);
	//MonsterTalking(&goblin, &rabbit);
	//MonsterEncount(&rabbit, currentLocation);
}
