#include "guest.h"

void initGuest() {
	int i;
	for (i = 0; i < 3; i++) {	// �մ� �ʱ�ȭ
		guest[i].flag = 0;
		guest[i].num = i;
		guest[i].clear = 0;
	}
}

void welcomeGuest() {
	int i, min = 0, max = 0;
	int r = randInt(0, 2), rr;

	if (level == 1) {
		min = 9;
		max = 12;
	}
	else if (level == 2) {
		min = 8;
		max = 11;
	}
	else if (level == 3) {
		min = 6;
		max = 9;
	}

	// ���ο� �մ� ����
	if (guestNum == 0 || t - lastGuestTime > randInt(min, max)) {
		lastGuestTime = t;

		if (guestNum == 3) {	// �մ��� �� ������ ���
			waitingGuest++;
		}
		else {
			for (i = 0; i < 3; i++) {
				rr = (r + i) % 3;

				if (guest[rr].flag == 0) {
					guestNum++;

					guest[rr].flag = 1;
					if (level == 1)	guest[rr].cocktail = cockTail_level1[randInt(0, 3)];
					else if (level == 2) guest[rr].cocktail = cockTail_level2[randInt(0, 4)];
					else guest[rr].cocktail = cockTail_level3[randInt(0, 5)];
					makingBar[rr].guest = guest[rr];	// ���̺�� �մ� ���� �߰�
					printGuestBoard(guest[rr]);
					break;
				}
			}
		}
	}
	// ��� �մ� ����
	if (guestNum < 3 && waitingGuest > 0) {
		waitingGuest--;
		for (i = 0; i < 3; i++) {
			rr = (r + i) % 3;

			if (guest[rr].flag == 0) {
				guestNum++;

				guest[rr].flag = 1;
				if (level == 1)	guest[rr].cocktail = cockTail_level1[randInt(0, 3)];
				else if (level == 2) guest[rr].cocktail = cockTail_level2[randInt(0, 4)];
				else guest[rr].cocktail = cockTail_level3[randInt(0, 5)];
				makingBar[rr].guest = guest[rr];	// ���̺�� �մ� ���� �߰�
				printGuestBoard(guest[rr]);

				SetCurrentCursorPos(97, 3);
				if (level == 3 && waitingGuest >= 3) setcolor(4, 0);
				else setcolor(15, 0);
				printf("��� �մ� �� : %d\n", waitingGuest);

				break;
			}
		}
	}
}

void printGuestBoard(GUEST g) {
	switch (g.num)
	{
	case 0:
		printSpeechBubble(0, 4);
		printRecipe(g.cocktail, 2, 5);
		printOrder(g.cocktail, 11, 11);
		break;
	case 1:
		printSpeechBubble(38, 4);
		printRecipe(g.cocktail, 40, 5);
		printOrder(g.cocktail, 49, 11);
		break;
	case 2:
		printSpeechBubble(76, 4);
		printRecipe(g.cocktail, 78, 5);
		printOrder(g.cocktail, 87, 11);
		break;
	default:
		break;
	}
}

void removeGuestBoard(GUEST g) {
	switch (g.num)
	{
	case 0:
		for (int y = 4; y < 18; y++) {
			for (int x = 0; x < 37; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	case 1:
		for (int y = 4; y < 18; y++) {
			for (int x = 38; x < 75; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	case 2:
		for (int y = 4; y < 18; y++) {
			for (int x = 76; x < 113; x++) {
				SetCurrentCursorPos(x, y);
				printf(" ");
			}
		}
		break;
	default:
		break;
	}
}

void printSpeechBubble(int x, int y) {
	setcolor(15, 0);
	SetCurrentCursorPos(x, y);
	printf("��������������������������������������������������������������������������\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��������������������������������������������������������������������������\n");
	SetCurrentCursorPos(x, ++y);
	printf("��������������������������������������������������������������������������\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��                                   ��\n");
	SetCurrentCursorPos(x, ++y);
	printf("��������������������������������������������������������������������������\n");
	SetCurrentCursorPos(x, ++y);
	printf("            ��/                       \n");
	SetCurrentCursorPos(x, ++y);
	printf("         (��'v'��)                     \n");
}

void printRecipe(int cocktail, int x, int y) {
	switch (cocktail) {
	case 0:	// ������Ÿ
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("��ų�� 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Ʈ���ü� 1.0oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q �۶�\n");
		break;
	case 1:	// �ÿ���Ÿ
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("��ų�� 2oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("���ý÷� 1.0oz į�ĸ� 0.5oz\n");
		SetCurrentCursorPos(x, ++y);
		printf("�ڸ��ֽ� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 1oz ");
		setcolor(15, 0);
		printf("E �۶�\n");
		break;
	case 2:	// ����Ű��
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("�� 2oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("���ý÷� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 1.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E �۶�\n");
		break;
	case 3:	// ������
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("�� 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("���ý÷� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz ź��� 2.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("W �۶�\n");
		break;
	case 4:	// �����̼�
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("�� 2.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("����Ű�� ��ť�� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E �۶�\n");
		break;
	case 5:	// ����ġ75
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("�� 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("���ý÷� 0.5oz ������ 2oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E �۶�\n");
		break;
	case 6:	// �ڽ���
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("����ī 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Ʈ���ü� 0.5oz ũ������ �ֽ� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("E �۶�\n");
		break;
	case 7:	// ī��ī��
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("����ī 1.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Ʈ���ü� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q �۶�\n");
		break;
	case 8:	// ��巯��
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("���� 2.0oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("�� 1.0oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 1.0oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q �۶�\n");
		break;
	case 9:	// ����Ű ���
		setcolor(13, 0);
		SetCurrentCursorPos(x, y);
		printf("���� 1.5oz\n");
		setcolor(14, 0);
		SetCurrentCursorPos(x, ++y);
		printf("���ý÷� 0.5oz\n");
		setcolor(3, 0);
		SetCurrentCursorPos(x, ++y);
		printf("������ 0.5oz\n");
		setcolor(15, 0);
		SetCurrentCursorPos(x, ++y);
		printf("Q �۶�\n");
		break;
	default:
		break;
	}
}

void printOrder(int cocktail, int x, int y) {
	SetCurrentCursorPos(x, y);

	switch (cocktail)
	{
	case 0:
		printf("������Ÿ �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000��");
		break;
	case 1:
		printf("�ÿ���Ÿ �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("12000��");
		break;
	case 2:
		printf("����Ű�� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000��");
		break;
	case 3:
		SetCurrentCursorPos(++x, y);
		printf("������ �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("10000��");
		break;
	case 4:
		SetCurrentCursorPos(--x, y);
		printf("�����̼� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000��");
		break;
	case 5:
		printf("����ġ75 �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("10000��");
		break;
	case 6:
		SetCurrentCursorPos(++x, y);
		printf("�ڽ��� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("8000��");
		break;
	case 7:
		printf("ī��ī�� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000��");
		break;
	case 8:
		printf("��巯�� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("9000��");
		break;
	case 9:
		SetCurrentCursorPos(x - 2, y);
		printf("����Ű ��� �ּ���!\n");
		SetCurrentCursorPos(x + 5, y + 2);
		printf("7000��");
		break;
	default:
		break;
	}
}