#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy  두 문자열을 복사 ( A <-B)
#include <stdlib.h> // malloc, free함수
// intuct number; -> 4바이트, 정수로 읽겠다. 시작하는 주소가 있어야 한다.
typedef struct {
	int number;
	char* name;
	char* comment;
}Student;


// Item Inventory 구조체 만들어보세요.
// 몬스터 처치했다. -> 인벤토리에 보상을 저장.
// Reward()  <<  Inventory  << Item
// 동적으로 변할 수 있도록 설정.
// 내 아이템의 크기를 변경해주는 함수. SetMyInventory()




// char A[80]; 배열로 표현하는 것과 -> 컴파일러가 주소를 직접 배정을 해준다. 정적할당.
// char* Ab = malloc(sizeof(char) * 100));	// 실행 중에 메모리를 할당한다. 동적할당.
// char* A[100];

// 동적할당 왜 필요한가요?
// 인벤토리. 몬스터의 보상을 저장을 한다. 아이템1개.
// 인벤토리의 공간을 얼마나 할당을 해야 하나요?
// 적정한 인벤토리의 갯수는요? 80개
// 이 게임은 진행하는 동안 평생 80개 까지만 저장할 수 있다.
// 아이템 공간 확장 기능. 80 -> 90 1000
// 10000000, 10개 필요하면 10개만 만들자. 20개 필요하면 20개 만들자. 
// 4개.
// A,B	<< 2개. 3개
// A,B,C

// [메모리 할당을 하면 - 메모리 해제] -> 에러. 공유 포인터.

void Test()
{
	int a; // 값은 들어 있지않아도 주소는 생성된다.
	printf("a의 주소 : %p\n", &a);
	char* name;	// 주소를 저장하는 타입인데 주소가 저장되어 있지 않다.(초기화되어 있지않습니다.)
	name = malloc(sizeof(char) * 100); // 주소를 직접 지정을 해주겠다.(프로그래머의 명령문)
	//printf("name 주소 : %p\n", &name);

	char nameArray[100]; // 주소가 만들어 져있다.

	// 주소는 변수만들 때 무조건 만들어지구나!
	// 어떤 Type 선언할 때 그 데이터를 저장할 수 있는 주소가 만들어지는구나.

	// 중단점을 걸기위함 _getch()
	//scanf("%d", &a);
	free(name);
}

void SetStudentInfo(Student* student)
{
	printf("학생의 이름을 작성해주세요 : ");
	char* temp = malloc(sizeof(char) *100);
	scanf("%s", temp);

	// student학생의 char주소에 이름을 저장하고 싶어요.
	// student->name 주소는 지금 컴퓨터 메모리에 할당되어 있지 않은 상태.
	// 메모리 할당을 어떻게 할 수 있나요? malloc함수
	// 메모리 할당을 하면 어떤 일이 일어나나요?
	student->name = malloc(sizeof(char) * 100);
	strcpy(student->name, temp); // 두번쨰 에러
	printf("학생의 번호를 작성해주세요 : ");

	scanf("%d", &student->number);
	printf("학생에게 하고 싶은 말 : ");
	student->comment = malloc(sizeof(char) * 100);
	scanf("%s", temp);
	strcpy(student->comment, temp);
	//student->comment
	// char name[100]
	// char* name = malloc(sizeof(char)*100);

	free(student->comment);
}

// Student,  Student*
// Student student = s1;
void PrintStudentInfo(Student student)
{
	printf("학생의 번호 : %d , 학생의 이름 : %s, 학생 코멘트 : %s \n",
		student.number, student.name, student.comment);
}

// Student,  Student*
void PrintStudentInfoPtr(Student* student)
{
	// (*student.)number

	printf("학생의 번호 : %d , 학생의 이름 : %s \n", student->number , student->name);
}


							   // Player의 이동 구조체 구현해서 함수로 설정할 수 있게 만들어보세요.
// 텍스트도 포인터로 받아올 수 있게 되었다.
int main()
{
	while (1)
	{
		Test();
		break;
	}
	
	Student s1;
	Student s2;

	SetStudentInfo(&s1);
	PrintStudentInfo(s1);


	//Release(학생);
	// 프로그램이 끝날 때 동적할당으로 만든 주소들을 해제해야한다.
	//PrintStudentInfoPtr(&s2);
}

// 윈도우 OS 파일 읽어오고 실행하고.. 메모리를 자동으로 해제.

