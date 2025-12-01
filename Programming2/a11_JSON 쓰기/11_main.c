// JSON 파일 가져오기.
// Input 설정
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "parson.h"

typedef struct Item
{
	char name[50];
	int price;
}Item;

// JSON 예제 코드 구현. 저장 시스템.  Player 데이터를 저장. 최고 점수를 저장하는 시스템.

// (1) Player 정보를 저장 및 로드하는 시스템 구현

// (2) Game에 Score를 저장하고 BestScore와 비교해서 저장하는 시스템

typedef struct GameScore
{
	char name[100];
	int score;

}GameScore;

typedef struct Player
{
	char name[100];
	int level;
	int stage;
}Player;

void SaveFruitData()
{
	JSON_Value* rootValue = json_value_init_object(); // default Object생성
	JSON_Object* rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "name", "apple");
	json_object_set_number(rootObject, "price", 10);

	json_object_dotset_string(rootObject, "skill.name", "Thunder");
	json_object_dotset_number(rootObject, "skill.pp", 5);

	json_serialize_to_file_pretty(rootValue, "fruit.json");
	json_value_free(rootValue);
}
void LoadFruitData()
{
	JSON_Value* loadValue = json_parse_file("fruit.json");
	JSON_Object* loadrootObject = json_value_get_object(loadValue);

	printf("name : %s\n", json_object_get_string(loadrootObject, "name"));
	printf("price : %.0f\n", json_object_get_number(loadrootObject, "price"));

	printf("skill name : %s\n", json_object_dotget_string(loadrootObject, "skill.name"));
	printf("skill pp : %.0f\n", json_object_dotget_number(loadrootObject, "skill.pp"));
}
void SavePlayerData(const Player* player)
{
	JSON_Value* rootValue = json_value_init_object(); // default Object생성
	JSON_Object* rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "name", player->name);
	json_object_set_number(rootObject, "level", player->level);
	json_object_set_number(rootObject, "stage", player->stage);

	json_serialize_to_file_pretty(rootValue, "player.json");
	json_value_free(rootValue);
}

void SaveScoreData(const GameScore* score)
{
	JSON_Value* rootValue = json_value_init_object(); // default Object생성
	JSON_Object* rootObject = json_value_get_object(rootValue);

	json_object_set_string(rootObject, "name", score->name);
	json_object_set_number(rootObject, "score", score->score);

	json_serialize_to_file_pretty(rootValue, "score.json");
	json_value_free(rootValue);
}

// void << 



// Player player = LoadPlayerData();

Player LoadPlayerData()
{
	JSON_Value* loadValue = json_parse_file("player.json");
	JSON_Object* loadrootObject = json_value_get_object(loadValue);

	printf("name : %s\n", json_object_get_string(loadrootObject, "name"));
	printf("level : %.0f\n", json_object_get_number(loadrootObject, "level"));
	printf("stage : %.0f\n", json_object_get_number(loadrootObject, "stage"));

	Player newPlayer;
	strcpy(newPlayer.name, json_object_get_string(loadrootObject, "name"));
	newPlayer.level = json_object_get_number(loadrootObject, "level");
	newPlayer.stage = json_object_get_number(loadrootObject, "stage");

	return newPlayer;
}

int main()
{
	printf("JSON 입력 예제 구현 \n\n"); // Save 구현, [Player데이터, BestScore]

	// 포인터 주소. 초기화. NULL

	LoadFruitData();
	SaveFruitData();
	// 플레이어 구조체를 저장 및 로드 하기 예제

	Player player;
	player.level = 10;
	strcpy(player.name,"Hero"); // 저장은 영어 이름만 가능
	player.stage = 5;

	printf("저장하시겠습니까?  [0] Yes [1] No");
	int select = 0;
	scanf("%d", &select);
	if (select == 0)
	{
		SavePlayerData(&player);
	}
	else {

	}

	// 만약에 player.json 경로가 있으면 파일을 가져와라
	player = LoadPlayerData();


	
}
