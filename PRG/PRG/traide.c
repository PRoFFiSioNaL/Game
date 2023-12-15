#include "main.h"
typedef struct Character Character;

void Traid(Character* hero, int number_location) {
	srand(time(NULL));
	clear();
	DrawMenuMoney(hero);
	char c, v;
	int coefficient_usual, coefficient_rare, coefficient_mythical = 0;
	if (number_location < 6) { //������ ����� � ���������� � �� ������ �������
		coefficient_usual = 60 - (number_location * 10);
		coefficient_mythical = 0 + (number_location * 5);
		coefficient_rare = 100 - coefficient_usual - coefficient_mythical;
	}
	else if(number_location < 19) {
		coefficient_usual = 10;
		coefficient_mythical = 0 + (number_location * 5);
		coefficient_rare = 100 - coefficient_usual - coefficient_mythical;
	}
	else {
		coefficient_usual = 0;
		coefficient_rare = 0;
		coefficient_mythical = 100;
	}
	int number_items = 4 + (rand() % 5); //���-� ������� � ��������
	int* items = (int*)malloc(2 * number_items * sizeof(int)); //������ ������� ��������
	for (int i = 0; i < number_items; ++i) {
		int item = rand() % 10; //������ ������
		int rarity = rand() % 100; //������ �������� ������
		int rarity_item;
		if (rarity < coefficient_usual) rarity_item = 0;
		else if (rarity < (coefficient_usual + coefficient_rare)) rarity_item = 1;
		else rarity_item = 2;
		int is_repeat = 0;
		for (int j = 0; j < i; ++j) {
			if ((item == items[j * 2]) && (rarity_item == items[j * 2 + 1])) { //�������� �� ������
				is_repeat = 1;
				break;
			}
		}
		if (is_repeat == 1) {
			--i;
			continue;
		}
		attron(COLOR_PAIR(20));
		attroff(A_UNDERLINE | A_BOLD);
		switch (item)
		{
		case(0):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +5, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +10, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +20, ��������� - 1000 �����");
			}
			break;
		case(1):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +5, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +10, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� +20, ��������� - 1000 �����");
			}
			break;
		case(2):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� ������ +5, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� ������ +10, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "����� � ������� ��� ������ +20, ��������� - 1000 �����");
			}
			break;
		case(3):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +4, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +8, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +12, ��������� - 1000 �����");
			}
			break;
		case(4):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��������� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� +4, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��������� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� +8, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ��������� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� +12, ��������� - 1000 �����");
			}
			break;
		case(5):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ���� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +3, �������� +5, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ���� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +5, �������� +7, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ���� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +7, �������� +10, ��������� - 1000 �����");
			}
			break;
		case(6):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "��������� +5%%, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "��������� +15%%, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ����� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "��������� +25%%, ��������� - 1000 �����");
			}
			break;
		case(7):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - �������� �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� ������������ ����� +5%%, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - �������� ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� ������������ ����� +15%%, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - �������� ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���� ������������ ����� +25%%, ��������� - 1000 �����");
			}
			break;
		case(8):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +4, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +8, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "�������� +12, ��������� - 1000 �����");
			}
			break;
		case(9):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ �������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +3, �������� +5, ��������� - 100 �����");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +5, �������� +7, ��������� - 300 �����");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d ������� - ������ ����������� ��������", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "���������� ����� +7, �������� +10, ��������� - 1000 �����");
			}
			break;
		default:
			break;
		}
		items[i * 2] = item;
		items[i * 2 + 1] = rarity_item;
	}
	attroff(A_UNDERLINE | A_BOLD);
	attron(COLOR_PAIR(1));
	mvprintw(6 + (number_items * 2), (cols - 74) / 2, "%d ������� - ����� ��������", number_items + 1);
	mvprintw(6 + (number_items * 2) + 1, (cols - 74) / 2, "��������������� 15 ����� ��������, ��������� - 100 �����");
	while ((c = getch()) != 27) { //���� ������� �������
		if ((c > '0') && (c <= (number_items + 49))) {
			ClearRow(rows - 4);
			int number = c - 48;
			if (number == number_items + 1) { //������
				if (hero->money >= 100) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "�� ����� ������ ����������?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ��");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - ���");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
							hero->equipment[10]++;
							hero->money -= 100;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "������� �� �������, ��� �� ���?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 40) / 2, "� ��� ������������ ������ ��� ������������");
					attroff(A_UNDERLINE);
				}
			}
			else { //��������� ������
				number--;
				int item, rarity_item;
				item = items[number * 2];
				rarity_item = items[(number * 2) + 1];
				if (rarity_item == -1) {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 25) / 2, "�� ��� ������ ���� �������");
					attroff(A_UNDERLINE);
				}
				else if (rarity_item == 0 && hero->money >= 100) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "�� ����� ������ ����������?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ��");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - ���");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 100;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "������� �� �������, ��� �� ���?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else if (rarity_item == 1 && hero->money >= 300) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "�� ����� ������ ����������?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ��");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - ���");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 300;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "������� �� �������, ��� �� ���?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else if (rarity_item == 2 && hero->money >= 1000) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "�� ����� ������ ����������?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ��");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - ���");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 1000;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "������� �� �������, ��� �� ���?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 40) / 2, "� ��� ������������ ������ ��� ������������");
					attroff(A_UNDERLINE);
				}
			}
		}
	}
}

void DrawMenuMoney(Character* hero) {
	attron(COLOR_PAIR(10));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(2) | A_UNDERLINE);
	mvprintw(4, (cols - 7) / 2, "��������");
	mvprintw(rows - 3, (cols - 15) / 2, "���� ������ - %d", hero->money);
}

