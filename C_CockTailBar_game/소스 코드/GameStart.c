#include "GameStart.h"

void printKeyManual() {
	int x = 119;
	int y = 15;

	setcolor(15, 0);

	SetCurrentCursorPos(x, y);
	printf("�Ǧ�����������������������KEYS��������������������������");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" ���� ");
	setcolor(15, 0);
	printf(": �մ� ������ �̵�     ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" ����Ű ");
	setcolor(15, 0);
	printf(": ��� ����          ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" ���� ");
	setcolor(15, 0);
	printf(": ��� ����            ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" D ");
	setcolor(15, 0);
	printf(": ����Ŀ �ʱ�ȭ           ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" TABŰ ");
	setcolor(15, 0);
	printf(": ��� ����           ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" �����̽��� ");
	setcolor(15, 0);
	printf(": ����Ŀ ����  ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" Q,W,E ");
	setcolor(15, 0);
	printf(": �۶� ����, ����   ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�� ");
	setcolor(11, 0);
	printf(" Z ");
	setcolor(15, 0);
	printf(": ��ȭ ����               ��");
	SetCurrentCursorPos(x, ++y);
	printf("��                              ��");
	SetCurrentCursorPos(x, ++y);
	printf("�Ŧ�������������������������������������������������������������");

}

void gameboard(void) {
	printf("������������������������������������������������������������");
	for (int i = 1; i < 50; i++) {
		SetCurrentCursorPos(0, i);
		printf("��");
		SetCurrentCursorPos(116, i);
		printf("��");
	}
	SetCurrentCursorPos(0, 50);
	printf("������������������������������������������������������������");
}

void printbartender(int color_change) {
	int line = 5;

	// ��
	if (color_change >= 1) setcolor(9, 0);
	else setcolor(7, 0);
	SetCurrentCursorPos(10, line++);
	printf("��    ��    ��");
	SetCurrentCursorPos(10, line++);
	printf("�����    ��");
	SetCurrentCursorPos(10, line++);
	printf("��    ��    ����");
	SetCurrentCursorPos(10, line++);
	printf("�����    ��");
	SetCurrentCursorPos(10, line++);
	printf("            ��");
	SetCurrentCursorPos(10, line++);
	printf("    ����    ");
	SetCurrentCursorPos(10, line++);
	printf("   ��    ��    ");
	SetCurrentCursorPos(10, line++);
	printf("    ����    ");
	line++;
	SetCurrentCursorPos(10, line++);
	printf("�����������");


	//��
	if (color_change >= 2) setcolor(9, 0);
	else setcolor(7, 0);
	line = 5;
	SetCurrentCursorPos(30, line++);
	printf("  �����");
	SetCurrentCursorPos(30, line++);
	printf("        ��");
	SetCurrentCursorPos(30, line++);
	printf("        ��");
	line++;
	SetCurrentCursorPos(30, line++);
	printf("�������");
	SetCurrentCursorPos(30, line++);
	printf("     ��");
	SetCurrentCursorPos(30, line++);
	printf("     ��");
	SetCurrentCursorPos(30, line++);
	printf("     ��");
	line++;
	SetCurrentCursorPos(30, line++);
	printf("���������");

	//��
	if (color_change >= 3) setcolor(9, 0);
	else setcolor(7, 0);
	line = 5;
	SetCurrentCursorPos(45, line++);
	printf("    ��         ��");
	SetCurrentCursorPos(45, line++);
	printf("  ��  ��       ��");
	SetCurrentCursorPos(45, line++);
	printf(" ��    ��  ����");
	SetCurrentCursorPos(45, line++);
	printf("��      ��     ��");
	SetCurrentCursorPos(45, line++);
	printf("               ��");

	SetCurrentCursorPos(45, line++);
	printf("      �����");
	SetCurrentCursorPos(45, line++);
	printf("            ��");
	SetCurrentCursorPos(45, line++);
	printf("            ��");
	line++;
	SetCurrentCursorPos(45, line++);
	printf("����������");


	//��
	if (color_change >= 4) setcolor(12, 0);
	else setcolor(7, 0);
	line = 19;
	SetCurrentCursorPos(40, line++);
	printf("��    ��    ��");
	SetCurrentCursorPos(40, line++);
	printf("��    ��    ��");
	SetCurrentCursorPos(40, line++);
	printf("�����    ��");
	SetCurrentCursorPos(40, line++);
	printf("��    ��    ����");
	SetCurrentCursorPos(40, line++);
	printf("��    ��    ��");
	SetCurrentCursorPos(40, line++);
	printf("�����    ��");
	SetCurrentCursorPos(40, line++);
	printf("            ��");

	//��
	if (color_change >= 5) setcolor(13, 0);
	else setcolor(7, 0);
	line = 18;
	SetCurrentCursorPos(60, line++);
	printf("�����      �� ��");
	SetCurrentCursorPos(60, line++);
	printf("��            �� ��");
	SetCurrentCursorPos(60, line++);
	printf("�����  ���� ��");
	SetCurrentCursorPos(60, line++);
	printf("��            �� ��");
	SetCurrentCursorPos(60, line++);
	printf("�����      �� ��");
	line++;
	SetCurrentCursorPos(60, line++);
	printf("    ��");
	SetCurrentCursorPos(60, line++);
	printf("    ��");
	SetCurrentCursorPos(60, line++);
	printf("    �������");

	//��
	if (color_change >= 6) setcolor(14, 0);
	else setcolor(7, 0);
	line = 20;
	SetCurrentCursorPos(82, line++);
	printf("�����      ��");
	SetCurrentCursorPos(82, line++);
	printf("��            ��");
	SetCurrentCursorPos(82, line++);
	printf("��        ����");
	SetCurrentCursorPos(82, line++);
	printf("��            ��");
	SetCurrentCursorPos(82, line++);
	printf("�����      ��");
	if (color_change >= 6) {
		SetCurrentCursorPos(100, 23);
		printf("  ��");
	}
	//�Ϳ�� ��
	setcolor(7, 0);
	line = 24;
	SetCurrentCursorPos(100, line++);
	printf(" ����");
	SetCurrentCursorPos(100, line++);
	printf("  �� ");
	SetCurrentCursorPos(100, line++);
	printf("  �� ");
	SetCurrentCursorPos(100, line++);

}


void printword(void) {

	setcolor(7 + 6 * gamest[0].selected, 0);
	SetCurrentCursorPos(80, 35);
	printf("�� GAME START ��");
	setcolor(7 + 6 * gamest[1].selected, 0);
	SetCurrentCursorPos(80, 38);
	printf("�� HOW TO PLAY ��");
}

void printbox(GAMESTART gamest) {
	setcolor(7, 0);
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("�Ǧ���������������������������������������");
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("��");
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y);
	printf("�Ŧ���������������������������������������");
	gamest.origin_x += 20;
	gamest.origin_y -= 1;
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("��  ENTER!!");

}
void erasebox(GAMESTART gamest) {
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("                                      ");
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("  ");
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y);
	printf("                                       ");
	gamest.origin_x += 20;
	gamest.origin_y -= 1;
	SetCurrentCursorPos(gamest.origin_x, gamest.origin_y++);
	printf("           ");

}

void chooseStart(key) {

	switch (key) {
	case UP:
		if (gamest[1].selected == 1) {
			gamest[0].selected = 1;
			gamest[1].selected = 0;
			erasebox(gamest[1]);
			printbox(gamest[0]);

			printword();
		}
		break;

	case DOWN:
		if (gamest[0].selected == 1) {
			gamest[1].selected = 1;
			gamest[0].selected = 0;
			erasebox(gamest[0]);
			printbox(gamest[1]);
			setcolor(9, 0);
			printword();
		}

		break;
	case ENTER:
		if (gamest[0].selected == 1) {
			//���� ����
			gamestartflag = 1;
			break;
		}
		else {
			//���� ��� ������
			gamestartflag = 2;
			break;
		}


	}
}

void gamestartset(void) {
	gamest[0].selected = 1;
	gamest[0].origin_x = 77;
	gamest[0].origin_y = 34;
	gamest[1].selected = 0;
	gamest[1].origin_x = 77;
	gamest[1].origin_y = 37;

	//gameboard();

	printword();
	printbox(gamest[0]);
}

void PrintYourNameFrame(void) {
	int ORIGIN_X = 14, ORIGIN_Y = 22;
	setcolor(7, 0);
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 1);
	printf("��                                                                                ��");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 2);
	printf("��                                                                                ��");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 3);
	printf("��                                                                                ��");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 4);
	printf("��                                                                                ��");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 5);
	printf("��                                                                                ��");
	SetCurrentCursorPos(ORIGIN_X, ORIGIN_Y + 6);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������");

}
void YourName(void) {
	int i;
	char* name1 = "����, ", * name2 = "!! �汸�� Ĭ���� ���� <�ְ���>�� �Ǿ�� - ...";
	setcolor(7, 0);
	SetCurrentCursorPos(16, 23);
	printf(" ����� �̸��� ?   ");
	scanf("%s", Name);

	SetCurrentCursorPos(16, 23);
	printf("                                       ");
	SetCurrentCursorPos(16, 23);

	PlaySound(TEXT("typewriter.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	for (i = 0; i < strlen(name1); i++) {
		printf("%c", name1[i]);
		if (name1[i] != ' ') {
			Sleep(100);
		}
	}
	for (i = 0; i < strlen(Name); i++) {
		printf("%c", Name[i]);
		Sleep(100);
	}
	for (i = 0; i < strlen(name2); i++) {
		printf("%c", name2[i]);
		Sleep(100);
	}
	PlaySound(NULL, 0, 0);

	Sleep(2000);

}

void YourNameQuestion(void) {
	PrintYourNameFrame();
	YourName();
}
