#include<Windows.h>
#include<time.h>
#include<stdio.h> 
#include<stdlib.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#pragma once

// ����ü
typedef struct guest {
	int num;
	int cocktail;
	int flag;
	int clear;
} GUEST;

typedef struct makingbar {
	GUEST guest;
	int guest_in; // �մ� ����
	int Tablenum;
	int GlassStart_x;
	int GlassStart_y;
	int selected; // �ش��ڸ����� ����� �����Ҷ� 1 
	int in[10];//����ִ� ����
	int in_count; //����ִ� ���� �� ����
	int shacking; // shacking ����
	int shacking_num;// shacking Ƚ��
	char glass;
}MAKINGBAR;

typedef struct ingredient {
	char str[10];
	int cnt;
	short color;
}INGREDIENT;

typedef struct ingredientcursor {
	int mode;
	int ingredient;
}INGREDIENTCURSOR;

typedef struct gamestart {
	int origin_x;
	int origin_y;
	int selected;
}GAMESTART;

// ���� ����
extern GUEST guest[3];
extern MAKINGBAR makingBar[3];
extern GAMESTART gamest[2];

extern int gamestartflag;
extern int minigameflag;		

extern int score;
extern int level;

//����
extern int cockTail_level1[4];
extern int cockTail_level2[5];
extern int cockTail_level3[6];

// �Լ� ����
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos();
void setcolor(unsigned short text, unsigned short back);
void RemoveCursor();
int randInt(int min, int max);
void ProcessKeyInput();