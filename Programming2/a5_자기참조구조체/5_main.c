#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 구조체 struct. 참조ref. Self 자기 



typedef void (*CallBack)(int a, int b);

void Sample(void (*Cback)(int, int), int x, int y)
{
	printf("Hello World\n");
	Cback(x,y);
}

void Plus(int a, int b)
{
	printf("두 수를 더한 값 : %d\n", a + b);
}

typedef struct Data{
	int value;			 
	struct Data* next;
	void (*fp)(CallBack cb, int a, int b);
}Data;

typedef struct DataManager
{
	Data* head;
}DataManager;

typedef struct Text
{
	char c1;
	int d1;
}Text;

typedef struct Stat
{
	char name[100];
	double value;
}Stat;

typedef struct Item
{
	char* namePtr;
	char name[5];   // 동적 할당
	int price;
	Stat stat;
}Item;

// 또다른 Monster참조할 수 있게 만들어 보세요. 
// 형제를 가지는 몬스터다. => this 가지면 안된다.
typedef struct Monster
{
	int hp;
	int atk;
	struct Monster* other;
	void (*Action1)(struct Monster*);
	void (*Action2)(this);
	void (*Action3)(this);
}Monster;

void ActionWithFriend(Monster* friend)
{
	printf("동료와 함께하는 기술!\n");
}


// 구조체, 자료형이 가지고 있는 크기를 더하면 사이즈가 나온다.
// 4+ 8 + 8 = 20
// 4(4) + 8 + 8 = 24
int main()
{
	Monster goblin;
	goblin.hp = 10;
	goblin.atk = 1;
	goblin.Action1 = ActionWithFriend;
	goblin.Action2 = ActionWithFriend;
	goblin.Action3 = ActionWithFriend;
	Monster goblin2;
	goblin2.hp = 10;
	goblin2.atk = 1;
	goblin2.Action1 = ActionWithFriend;
	goblin2.Action2 = ActionWithFriend;
	goblin2.Action3 = ActionWithFriend;
	goblin.other = &goblin2;
	goblin2.other = &goblin;

	goblin.Action1(goblin.other);
	goblin.Action2(goblin.other);

	Item item;
	item.namePtr = malloc(sizeof("빛나는 티끌"));
	item.namePtr = "빛나는 티끌";
	strcpy(item.name,"빛나는 티끌");  //  
	printf("item의 배열 이름 : %s\n", item.name);
	printf("item의 포인터 이름 : %s\n", item.namePtr);
	printf("item의 크기 : %d\n", sizeof(Item));
	printf("item의 크기 : %d\n", sizeof(item.name));
	printf("item의 크기 : %d\n", sizeof(item.namePtr));
	printf("item의 크기 : %d\n", sizeof(item.price));
	printf("item의 크기 : %d\n", sizeof(item.stat));


	Data d1;
	printf("Data구조체의 크기 : %d\n", sizeof(d1.fp));
	printf("Data구조체의 크기 : %d\n", sizeof(d1.next));
	printf("Data구조체의 크기 : %d\n", sizeof(d1.value));
	printf("Data구조체의 크기 : %d\n", sizeof(d1));
	d1.value = 1;
	d1.fp = Sample;
	d1.fp(Plus, 2, 4);
	Data d2;
	d2.value = 10;
	d1.next = &d2;
	Data d3;
	d2.next = &d3;
	d3.value = 20;
	DataManager dm;
	dm.head = &d1;
	printf("dm의 첫번째 데이터의 값 : %d \n", dm.head->value);
	printf("dm이 두번째 데이터의 값 : %d \n", dm.head->next->value);
	printf("dm의 세번째 데이터의 값 : %d \n", dm.head->next->next->value);

	// head n번째 떨어져있는 value 출력하시오.
	int n = 2;

	dm.head->next->next->next->next->value;

	Data* temp = dm.head;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;
	}

	printf("head에서 2번째 떨어져있는 값 : %d \n", temp->value);

	// 몬스터들을 저장하는 Manager 타입을 만들었다.
	// Manager n번째 저장된 데이터를 접근할 수 있게 되었다.
	// n번째 들어있는 타입의 아무거나 사용할 수 있다.
}