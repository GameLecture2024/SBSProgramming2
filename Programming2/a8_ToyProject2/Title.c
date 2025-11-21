#define _CRT_SECURE_NO_WARNINGS
#include "Title.h"
#include "Console.h"
#include "Screen.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 게임 시작  - 최고점수 - 게임 종료 .. 
void GameTitle()
{
    int titleCursor = 10;
	int input = 0;
	while (1)
	{
		GoToXY(16, titleCursor);
		SetDataYPosInput(&titleCursor, 10, 14, 2);
		
		//if ('a' == _getch() && titleCursor == 10)
		//{
		//	break;
		//}
		TitleRender(&titleCursor);


		// 텍스트 입력으로 진행 하는 구조 (1)
		//printf("0 : 시작 1: 점수 확인 2: 게임 종료");
		//int a = 0;
		//scanf("%d", &a);
		// 숫자 0  1  2

		// 입력으로 이동하는 구조.

	}

	
}


void TitleRender(int* titleCursor)
{
	ScreenClear();

	ScreenPrint(20, 4, "타이틀");
	ScreenPrint(20, 5, "게임을 시작하기 위해서 키보드를 입력해주세요");
	ScreenPrint(20, 10, "Start");
	ScreenPrint(20, 12, "Score");
	ScreenPrint(20, 14, "Quit");
	ScreenPrint(20, 4, "타이틀");
	ScreenPrint(16, *titleCursor, ">>");

	ScreenFlipping();

}

void SetDataYPosInput(int* y, int MINHEIGHT, int MAXHEIGHT, int interval)
{
	unsigned char input = 0; // 

	if (_kbhit()) // 키보드를 입력하면 True
	{
		input = _getch();

		if (input == 224 || input == 0)
		{
			input = _getch(); // 두 번째 문자 읽기
			switch (input) {
			case 72: // ↑
				// 플레이어의 현재 좌표를 -1 해주세요
				*y -= interval;

				if (*y < MINHEIGHT)
				{
					*y = MAXHEIGHT;
				}

				break;
			case 80: // ↓
				// 플레이어의 현재 좌표를 +1 해주세요
				*y += interval;

				if (*y > MAXHEIGHT)
				{
					*y = MINHEIGHT;
				}
				break;
			}
		}
	}
}