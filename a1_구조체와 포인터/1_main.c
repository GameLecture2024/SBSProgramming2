#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 프로그래밍 언어 왜 사용하나요?
// 자료형(data type) 선언. 정수(int), 실수(float)
// data - value
// 데이터가 저장되는 시작 주소를 포인터로 표현할 수 있었다.
// int* a; &a; *a;

// 반복이 많이 생겼다.
// 배열
// 몬스터(체력,공격력,이름) int 2개, char* 1개

typedef struct // 
{
	int hp;
	int atk;
	const char* name;
	int def;
}Monster;

// Monster* monster	= ?;
// Monster	monster = ?;
// 구조체는 무조건 포인터로 쓰는게 좋은가요? 
void PrintMonsterInfo(const Monster* monster)
{
	printf("이름 : %s, 체력 : %d, 공격력 : %d, 방어력 : %d\n", monster->name, monster->hp, monster->atk, monster->def);
	//printf("이름 : %s, 체력 : %d, 공격력 : %d\n", name, hp, atk);
}

// 함수 왜 썻지?
// 함수 안에서 데이터 변경하고 싶다. -> 이유? 
// xxx 방법 -> 그것을 사용하는 '문법' 포인터
// 구조체에서 포인터를 사용할 때 연산자 실행에는 순서가 있다.

// Monster* monster = &goblin;
void SetMonsterData(Monster* monster) // 함수 안에서 몬스터의 데이터를 세팅하고 싶다.
{
	// 구조체의 주소로 부터 값을 가져온다. (*구조체포인터).변수
	// (*구조체포인터).변수 
	//  구조체포인터->변수
	// 둘은 같은 표현식이다.

	//printf("몬스터의 이름 : "); 이름은 내일 구현하는거 까지 해보겠습니다.
	//char temp[100];
	//scanf("%s", temp); // temp 
	//strcpy_s(monster->name, temp, 100); // ->""
	// 리터럴 상수 "" 비어 있는 메모리에 복사를 해야합니다. 
	printf("몬스터의 공격력 : ");
	scanf("%d", &monster->atk);             
	printf("몬스터의 체력 : ");
	scanf("%d", &monster->hp);
	printf("몬스터의 방어력 : ");
	scanf("%d", &monster->def);

}

int main()
{

	// 몬스터의 데이터 입력 ,초기화
	// 마리. 한번에 세팅하세요.

	Monster goblin; // 고블린 -> 오크
	goblin.hp = 10;
	goblin.atk = 1;
	goblin.name = "고블린";
	goblin.def = 2;
	SetMonsterData(&goblin);


	Monster Orc;
	Orc.hp = 15;
	Orc.atk = 2;
	Orc.name = "오크";
	Orc.def = 2;

	SetMonsterData(&Orc);

	PrintMonsterInfo(&goblin);
	PrintMonsterInfo(&Orc);

}