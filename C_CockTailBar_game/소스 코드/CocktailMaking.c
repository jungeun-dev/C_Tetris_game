#include "CocktailMaking.h"
#include "guest.h"
#include "FeverTime.h"

char* ingredientnum[16] = {
   "�����ᵥ","�����ᷳ","��������","�����Ẹ","�������","�ܡ����","�ɡ����","ũ����ũ","į����į","�ڡ�����","Ʈ����Ʈ","�����ἤ","�����Ḷ","������","�����᷹","ź����ź" };

int recipeIngredient[10][10] = {
	  {0,0,0,10,10,13,-1,-1,-1,-1},
	  {0,0,0,0,6,6,8,9,13,13},
	  {1,1,1,1,6,13,13,-1,-1,-1},
	  {1,1,1,6,13,15,15,15,15,-1},
	  {2,2,2,2,12,14,-1,-1,-1,-1},
	  {2,2,6,11,11,11,11,14,-1,-1},
	  {3,3,7,10,13,-1,-1,-1,-1,-1},
	  {3,3,10,13,-1,-1,-1,-1,-1,-1},
	  {4,4,4,4,5,5,14,14,-1,-1},
	  {4,4,4,6,14,-1,-1,-1,-1,-1}
};

char recipeGlass[10] = {
   'Q','E','E','W','E','E','E','Q','Q','Q'
};

int recipePrice[10] = { 7000,12000,8000,10000,8000,10000,8000,7000,9000,7000 };

void SettingBar(int key) {
	int bar_num = -1;
	int idx;

	switch (key) {
	case TAB:
		idx = cursor[select_y][select_x].ingredient;
		if (ingredient[idx].cnt != 10) {
			minigameflag = 1;
			playMinigame();
		}
		break;

	case LEFT:
		if (canMoveTo(select_y, select_x - 1) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_x--;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case RIGHT:
		if (canMoveTo(select_y, select_x + 1) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_x++;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case UP:
		if (canMoveTo(select_y - 1, select_x) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_y--;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;
	case DOWN:
		if (canMoveTo(select_y + 1, select_x) == 1) {
			deleteIngredientBox();
			cursor[select_y][select_x].mode = 0;
			select_y++;
			ingredientBox();
			cursor[select_y][select_x].mode = 1;
		}
		break;

	case Q: case 113:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'Q';
			CleanTable(bar_num);
			Redrawsetting(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;
	case W: case 119:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'W';
			CleanTable(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;
	case E: case 101:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		if (makingBar[bar_num].shacking_num < 10);
		else if (makingBar[bar_num].guest.flag == 0);
		else {
			makingBar[bar_num].glass = 'E';
			CleanTable(bar_num);
			PrintOfferedCockTail(bar_num);
			bar_number = OfferCockTail(bar_num);
		}
		break;

	case DELETE: case 68:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		for (int j = 0; j < 10; j++) {
			makingBar[bar_num].in[j] = -1;
		}
		makingBar[bar_num].shacking = 0;
		makingBar[bar_num].shacking_num = 0;
		makingBar[bar_num].in_count = 0;
		Redrawsetting(bar_num);
		DrawCockTail(makingBar[bar_num]);
		break;

	case ONE:
		makingBar[0].selected = 1;
		makingBar[1].selected = 0;
		makingBar[2].selected = 0;
		for (int i = 0; i < 3; i++) { Redrawsetting(i); }
		for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		break;
	case TWO:
		makingBar[0].selected = 0;
		makingBar[1].selected = 1;
		makingBar[2].selected = 0;
		for (int i = 0; i < 3; i++) { Redrawsetting(i); }
		for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		break;
	case THREE:
		makingBar[0].selected = 0;
		makingBar[1].selected = 0;
		makingBar[2].selected = 1;
		for (int i = 0; i < 3; i++) { Redrawsetting(i); }
		for (int i = 0; i < 3; i++) { DrawCockTail(makingBar[i]); }
		break;

	case ENTER:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		//if (bar_num == -1) bar_num = 0;
		if (bar_num >= 0 && makingBar[bar_num].in_count < 10) {
			idx = selectIngredient();
			if (idx > -1) {
				makingBar[bar_num].in[makingBar[bar_num].in_count] = idx;
				makingBar[bar_num].in_count++;
				DrawCockTail(makingBar[bar_num]);
			}
		}
		break;

	case SPACE:
		for (int i = 0; i < 3; i++) {
			if (makingBar[i].selected == 1) bar_num = i;
		}
		makingBar[bar_num].shacking = 1;
		makingBar[bar_num].shacking_num++;
		DrawCockTail(makingBar[bar_num]);
		break;
	}
}

//���� �Լ� �߰� Ĭ���� ���� �� ���� Ĭ���� ����� �� ���
void RedrawOfferdBar(int bar_num) {
	int glass_start_x;
	int glass_start_y;
	int x, y;

	glass_start_x = makingBar[bar_num].GlassStart_x;
	glass_start_y = makingBar[bar_num].GlassStart_y;

	setcolor(7, 0);
	for (y = 0; y < 11; y++) {
		SetCurrentCursorPos(glass_start_x, glass_start_y + y);

		if (y == 10)printf("��");
		else {
			printf("��");
		}

		SetCurrentCursorPos(glass_start_x + GLASS_WIDTH * 2, y + glass_start_y);
		if (y == 10) printf("��");
		else printf("��");
	}

	for (x = 1; x < GLASS_WIDTH; x++) {
		SetCurrentCursorPos(x * 2 + glass_start_x, glass_start_y + 10);
		printf("��");
	}
}

// ���� �Լ� �߰�  �� ������ ���� �ع��� ����
void CleanTable(int bar_num) {
	int glass_start_x;
	int glass_start_y;
	int x, y;

	glass_start_x = makingBar[bar_num].GlassStart_x;
	glass_start_y = makingBar[bar_num].GlassStart_y;
	Redrawsetting(bar_num);
	setcolor(7, 0);
	for (y = 0; y < 11; y++) {
		SetCurrentCursorPos(glass_start_x, glass_start_y + y);

		if (y == 10)printf("  ");
		else {
			printf("  ");
		}

		SetCurrentCursorPos(glass_start_x + GLASS_WIDTH * 2, y + glass_start_y);
		if (y == 10) printf("  ");
		else printf("  ");
	}

	for (x = 1; x < GLASS_WIDTH; x++) {
		SetCurrentCursorPos(x * 2 + glass_start_x, glass_start_y + 10);
		printf("  ");
	}
}

//���� �Լ� �߰� ������ Ĭ���� ���
void PrintOfferedCockTail(int bar_num) {
	int glass_start_x;
	int glass_start_y;
	int money;
	int tip;
	money = RecipeCheck(bar_num);
	glass_start_x = makingBar[bar_num].GlassStart_x + 2;
	glass_start_y = makingBar[bar_num].GlassStart_y + 2;
	setcolor(7, 0);

	SetCurrentCursorPos(glass_start_x, glass_start_y);
	if (money == 0) return;
	if (money > 0)printf("%d��!!", money);
	else printf("%d���Ф�", money);
	glass_start_x += 2;
	glass_start_y += 2;
	SetCurrentCursorPos(glass_start_x, glass_start_y);
	if (makingBar[bar_num].glass == 'Q') {
		printf("��  ��");
		glass_start_y++;
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		printf("��������");
	}
	else if (makingBar[bar_num].glass == 'W') {
		printf("��  ��");
		glass_start_y++;
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		printf("��  ��");
		glass_start_y++;
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		printf("��������");
	}
	else if (makingBar[bar_num].glass == 'E') {
		printf(" ����");
		glass_start_y++;
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		printf("  ��");
		glass_start_y++;
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		printf("  ��");
	}
	glass_start_y += 2;
	glass_start_x -= 3;
	if (makingBar[bar_num].guest.clear == 1) {
		SetCurrentCursorPos(glass_start_x, glass_start_y);
		setcolor(13, 0);

		if (level == 2) {
			tip = rand() % (3000 - 1000 + 1) + 1000;
			tip = tip - tip % 100;
			printf(" tip: %d��", tip);
			score += tip;
		}
		else if (level == 3) {
			tip = rand() % (5000 - 2000 + 1) + 2000;
			tip = tip - tip % 100;
			printf(" tip: %d��", tip);
			score += tip;
		}
	}
}

//���� �Լ� �߰�Ĭ���� ���� �� �� ������ ������ ���̺� �ʱ�ȭ
int OfferCockTail(int bar_num) {
	score += RecipeCheck(bar_num);
	//���� �� ���� �ʱ�ȭ 
	makingBar[bar_num].guest_in = 0;
	makingBar[bar_num].shacking = 0;
	makingBar[bar_num].shacking_num = 0;
	makingBar[bar_num].in_count = 0;
	for (int j = 0; j < 10; j++) makingBar[bar_num].in[j] = -1;

	removeGuestBoard(guest[bar_num]);    // �մ� ��ǳ�� ����
	guest[bar_num].flag = 0;    // �մ� �ʱ�ȭ
	guest[bar_num].cocktail = -1;
	makingBar[bar_num].guest.flag = 0;
	makingBar[bar_num].guest.cocktail = -1;
	guestNum--;
	return bar_num;
}

int selectIngredient(void) {
	int idx = cursor[select_y][select_x].ingredient;
	if (ingredient[idx].cnt > 0) {
		ingredient[idx].cnt--;
		printIngredient();
		return idx;
	}
	else return -1;            //�ش� ��� �����Ұ�� -1 return
}

// ���� shackingGageBar ���
void DrawShakingGageBar(MAKINGBAR bar) {
	int gagebar_start_x = bar.GlassStart_x + GLASS_WIDTH * 2 + 2;
	int gagebar_start_y = bar.GlassStart_y;
	int y;
	int idx;

	// �ȿ� ä���
	for (y = 9, idx = 0; idx < bar.shacking_num; y--, idx++) {
		if (bar.shacking_num > 10) break;
		SetCurrentCursorPos(gagebar_start_x, gagebar_start_y + y);
		setcolor(7, 0);
		printf("��");
	}
	setcolor(7, 0);
	SetCurrentCursorPos(gagebar_start_x + TABLE_CENTER - 8, gagebar_start_y + 12);
	setcolor(7, 0);
	if (bar.shacking_num >= 10) {
		printf("Choose Glass!!");
	}
	else {
		printf("              ");
		SetCurrentCursorPos(gagebar_start_x + TABLE_CENTER - 8, gagebar_start_y + 12);
		printf("Shaking!!");
	}
}

void Redrawsetting(int bar_num) {
	int gagebar_start_x;
	int gagebar_start_y;
	int glass_start_x;
	int glass_start_y;
	int x, y;
	int idx = 0;

	gagebar_start_x = makingBar[bar_num].GlassStart_x + GLASS_WIDTH * 2 + 2;
	gagebar_start_y = makingBar[bar_num].GlassStart_y;
	glass_start_x = makingBar[bar_num].GlassStart_x;
	glass_start_y = makingBar[bar_num].GlassStart_y;

	setcolor(7, 0);

	SetCurrentCursorPos(glass_start_x + TABLE_CENTER - 5, glass_start_y + 12);
	printf("          ");

	// �۶� ���¸� �����
	for (y = 9, idx = 0; y >= 0; y--, idx++) {
		SetCurrentCursorPos(glass_start_x + 2, glass_start_y + y);
		printf("          ");
	}
	// shaking gage �����
	for (y = 9, idx = 0; idx < 10; y--, idx++) {
		if (makingBar[bar_num].shacking_num > 10) break;
		SetCurrentCursorPos(gagebar_start_x, gagebar_start_y + y);
		setcolor(7, 0);
		printf("  ");
	}
	//shaking ���� �����
	setcolor(7, 0);
	SetCurrentCursorPos(gagebar_start_x + TABLE_CENTER - 8, gagebar_start_y + 12);
	printf("              ");

}

//  �ȿ� ä��� �ش� ���� ��� , shaking bar ���
void DrawCockTail(MAKINGBAR bar) {
	int glass_start_x = bar.GlassStart_x;
	int glass_start_y = bar.GlassStart_y;
	int x, y;
	int idx = 0;
	setcolor(7, 0);
	if (bar.selected == 1) {
		SetCurrentCursorPos(glass_start_x + TABLE_CENTER - 5, glass_start_y + 12);
		printf("��Making��");
	}
	else {
		SetCurrentCursorPos(glass_start_x + TABLE_CENTER, glass_start_y + 12);
		printf("          ");
		SetCurrentCursorPos(glass_start_x + TABLE_CENTER, glass_start_y + 12);
		printf("%d", bar.Tablenum);

	}
	// �ȿ� ä���
	for (y = 9, idx = 0; y >= 0; y--, idx++) {
		SetCurrentCursorPos(glass_start_x + 2, glass_start_y + y);
		if (bar.in[idx] != -1) {
			if (bar.in[idx] < 5) setcolor(13, 0);
			else if (bar.in[idx] < 13) setcolor(14, 0);
			else setcolor(3, 0);
			printf("%s", ingredientnum[bar.in[idx]]);
		}
	}
	if (bar.shacking == 1) {
		DrawShakingGageBar(bar);
	}
}

void FirstSetBar(void) {
	int i;
	for (i = 0; i < 3; i++) {
		makingBar[i].Tablenum = i + 1;
		makingBar[i].GlassStart_x = 37 * i + GLASS_START;
		makingBar[i].GlassStart_y = 36;
		//makingBar[i].guest = guest[i];
	}

	//����ִ� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 3; i++) {
		if (i == 0)    makingBar[0].selected = 1;
		else makingBar[i].selected = 0;
		for (int j = 0; j < 10; j++) {
			makingBar[i].in[j] = -1;
		}
		makingBar[i].in_count = 0;
		makingBar[i].shacking = 0;
		makingBar[i].shacking_num = 0;
	}
}

void SetCocktailBar(void) {
	int glass_start_x;
	int glass_start_y;
	int x, y;

	for (int i = 0; i < 3; i++) {
		glass_start_x = makingBar[i].GlassStart_x;
		glass_start_y = makingBar[i].GlassStart_y;
		setcolor(7, 0);
		for (y = 0; y < 11; y++) {
			SetCurrentCursorPos(glass_start_x, glass_start_y + y);

			if (y == 10)printf("��");
			else {
				printf("��");
			}

			SetCurrentCursorPos(glass_start_x + GLASS_WIDTH * 2, y + glass_start_y);
			if (y == 10) printf("��");
			else printf("��");
		}

		SetCurrentCursorPos(1 + glass_start_x, glass_start_y + 10);
		printf("����������������������");

	}
}

int RecipeCheck(int MAKINGBAR_Tablenum)//makingbar.Tablenum ���� ȣ��
{

	int result;
	int dCocktail[10];
	int uCocktail[10];
	int dingredientNum = -1;
	int uingredientNum = -1;
	int wrongNum = 0;
	int pay = recipePrice[makingBar[MAKINGBAR_Tablenum].guest.cocktail];

	if (makingBar[MAKINGBAR_Tablenum].guest.flag == 0) result = 0;
	//������Է� �����ǿ� ���� �����Ǹ� ����
	for (int i = 0; i < 10; i++)
	{
		dCocktail[i] = recipeIngredient[makingBar[MAKINGBAR_Tablenum].guest.cocktail][i];
		uCocktail[i] = makingBar[MAKINGBAR_Tablenum].in[i];
		if (dCocktail[i] == -1 && dingredientNum == -1) dingredientNum = i; //  ������ ��� ����
		if (uCocktail[i] == -1 && uingredientNum == -1) uingredientNum = i; // ��� ��� ����

	}
	if (dingredientNum == -1) dingredientNum = 10;
	if (uingredientNum == -1) uingredientNum = 10;
	dingredientNum = dingredientNum + 1;//�ܸ��
	uingredientNum = uingredientNum + 1;//�ܸ��

	//��� üũ
	for (int i = 0; i < 10; i++) // user
	{
		if (uCocktail[i] == -1) continue;
		for (int j = 0; j < 10; j++)
		{
			if (dCocktail[j] == -1)
				continue;
			if (uCocktail[i] == dCocktail[j])
			{
				uCocktail[i] = -1;
				dCocktail[j] = -1;
				break;
			}
		}
	}
	if (dingredientNum > uingredientNum) {
		for (int i = 0; i < 10; i++) {
			if (dCocktail[i] != -1) wrongNum++;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (uCocktail[i] != -1) wrongNum++;
		}
	}

	//�� ��� üũ
	if (makingBar[MAKINGBAR_Tablenum].glass != recipeGlass[makingBar[MAKINGBAR_Tablenum].guest.cocktail])
		wrongNum += 1;

	if (wrongNum == 0) result = pay; //  �� ���� ���
	else if (dingredientNum / wrongNum <= 2)
		result = -1000;
	else {
		pay = pay - wrongNum * 1000;
		result = pay;
	}

	CheckComboAndFeverTime(result, recipePrice[makingBar[MAKINGBAR_Tablenum].guest.cocktail]);

	if (result == recipePrice[makingBar[MAKINGBAR_Tablenum].guest.cocktail]) {
		makingBar[MAKINGBAR_Tablenum].guest.clear = randInt(0, 1);
	}

	if (isFeverTime)return result * 3 / 2;
	return result;
}