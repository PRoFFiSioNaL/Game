#include "main.h"

typedef struct Character Character;
typedef struct CharacterBattle CharacterBattle;
typedef struct Enemy Enemy;

enum Location { 
	treasure, 
	cave, 
	traid, 
	foe
} location;

int MiddlePhase(Character hero, int num_loc) {
	char c, v;
	clear();
	int i = num_loc;
	srand(time(NULL));
	if (i == 1) {
		hero.money = 500;
		attron(COLOR_PAIR(6));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(20));
		mvprintw(4, (cols - 22) / 2, "����� ���������� � ���!");
		attroff(A_UNDERLINE);
		attron(COLOR_PAIR(2));
		mvprintw(6, (cols - 53) / 2, "�� ���������� � ��������� ������ � ������� �����������");
		mvprintw(7, (cols - 42) / 2, "�� ����� ���� ����� ���������� ������������");
		mvprintw(8, (cols - 29) / 2, "������ ����������� � ��������?");
		attron(COLOR_PAIR(4));
		mvprintw(10, (cols / 2) - 10, "z - ��");
		attron(COLOR_PAIR(1));
		mvprintw(10, (cols / 2) + 3, "x - ���");
		while ((v = getch()) != 27) {
			if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
				Traid(&hero, 0);
				break;
			}
			else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
				break;
			}
		}
	}
	while(1) {
		clear();
		DrawMenuDay(i);
		c = getch();
		while ((c < 49) || (c > 52)) c = getch();
		int choose_path = c - 48;
		if (choose_path == 1) {
			clear();
			attroff(A_UNDERLINE | A_BOLD);
			attron(COLOR_PAIR(11));
			DrawBorder();
			int location_rand = rand() % 100;
			if (location_rand < kTreasureChance) location = treasure;
			else if (location_rand < kTreasureChance + kCaveChance) location = cave;
			else if (location_rand < kTreasureChance + kCaveChance + kTraiderChance) location = traid;
			else location = foe;
			if (i == kLocationLength) location = foe;
			switch (location)
			{
			case treasure:;
				int item = rand() % 11;
				int rarity_item = hero.equipment[item];
				while (rarity_item == 3) { //�������� ���� �� ������ � ����� �������� �� ��� ��������
					int item = rand() % 11;
					int rarity_item = hero.equipment[item];
				}
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(6, (cols - 43) / 2, "������� ������ �� ������������� ������������");
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8 , (cols - 19) / 2, "�� ������ ���������?");
				attroff(A_BOLD | A_UNDERLINE);
				attron(COLOR_PAIR(4));
				mvprintw(9, (cols / 2) - 10, "z - ��");
				attron(COLOR_PAIR(1));
				mvprintw(9, (cols / 2) + 3, "x - ���");
				while (v = getch()) {
					if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(2));
						mvprintw(8 , (cols - 10) / 2, "�� ��������");
						switch (item)
						{
						case(0):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 46) / 2, "��� �������� �������� - ����� � ������� ��� +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 46) / 2, "��� ������� �������� - ����� � ������� ��� +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 46) / 2, "��� ����������� �������� - ����� � ������� ��� +20");
							}
							break;
						case(1):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 46) / 2, "��� �������� �������� - ����� � ������� ��� +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 46) / 2, "��� ������� �������� - ����� � ������� ��� +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 46) / 2, "��� ����������� �������� - ����� � ������� ��� +20");
							}
							break;
						case(2):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 54) / 2, "����� �������� �������� - ����� � ������� ��� ������ +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 54) / 2, "����� ������� �������� - ����� � ������� ��� ������ +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 54) / 2, "����� ����������� �������� - ����� � ������� ��� ������ +20");
							}
							break;
						case(3):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 38) / 2, "������ �������� �������� - �������� +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 38) / 2, "������ ������� �������� - �������� +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 38) / 2, "������ ����������� �������� - �������� +12");
							}
							break;
						case(4):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 36) / 2, "��������� �������� �������� - ���� +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 36) / 2, "��������� ������� �������� - ���� +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 36) / 2, "��������� ����������� �������� - ���� +12");
							}
							break;
						case(5):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 56) / 2, "���� �������� �������� - ���������� ����� +3, �������� +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 56) / 2, "���� ������� �������� - ���������� ����� +5, �������� +7");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 56) / 2, "���� ����������� �������� - ���������� ����� +7, �������� +10");
							}
							break;
						case(6):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 38) / 2, "����� �������� �������� - ��������� +5%%");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 38) / 2, "����� ������� �������� - ��������� +15%%");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 38) / 2, "����� ����������� �������� - ��������� +25%%");
							}
							break;
						case(7):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 55) / 2, "�������� �������� �������� - ���� ������������ ����� +5%%");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 55) / 2, "�������� ������� �������� - ���� ������������ ����� +15%%");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 55) / 2, "�������� ����������� �������� - ���� ������������ ����� +25%%");
							}
							break;
						case(8):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 37) / 2, "������ �������� �������� - �������� +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 37) / 2, "������ ������� �������� - �������� +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 37) / 2, "������ ����������� �������� - �������� +12");
							}
							break;
						case(9):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 58) / 2, "������ �������� �������� - ���������� ����� +3, �������� +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 58) / 2, "������ ������� �������� - ���������� ����� +5, �������� +7");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 58) / 2, "������ ����������� �������� - ���������� ����� +7, �������� +10");
							}
							break;
						case(10):
							attroff(A_UNDERLINE | A_BOLD);
							attron(COLOR_PAIR(1));
							mvprintw(9, (cols - 49) / 2, "����� �������� - ��������������� 15 ����� ��������");
							break;
						default:
							break;
						}
						hero.equipment[item]++;
						attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
						mvprintw(13, (cols - 39) / 2, "������������ �������� �� ���������� ����");
						attroff(A_UNDERLINE | A_BOLD);
						getch();
						break;
					}
					else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 31) / 2, "�� ������ ���� �� �������� � ��");
						break;
					}
				}
				break;
			case cave:
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(6, (cols - 37) / 2, "������� ������ �� ������������� ������");
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8 , (cols - 25) / 2, "�� ������ ��������� � ���?");
				attroff(A_BOLD | A_UNDERLINE);
				attron(COLOR_PAIR(4));
				mvprintw(9, (cols / 2) - 10, "z - ��");
				attron(COLOR_PAIR(1));
				mvprintw(9, (cols / 2) + 3, "x - ���");
				while (v = getch()) {
					if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
						ClearRow(8);
						ClearRow(9);
						int cave_rand = rand() % 100;
						if (cave_rand < 80) {
							attron(COLOR_PAIR(1));
							mvprintw(13, (cols - 26) / 2, "�� ������������� ����������");
							Enemy enemy = CreateEnemy(i);
							getch();
							int is_win = Battle(&hero, enemy);
							if (is_win == 0) return 0;
						}
						else if (cave_rand < 95) {
							ClearRow(8);
							ClearRow(9);
							attron(COLOR_PAIR(20));
							mvprintw(13, (cols - 42) / 2, "��������� ������ � �� �������������� ������");
							getch();
							
						}
						else {
							ClearRow(8);
							ClearRow(9);
							attron(COLOR_PAIR(2));
							mvprintw(8, (cols - 28) / 2, "�� �������� ������ ����������");
							int spell = rand() % 5;
							while (hero.spells[spell] != 0) spell = rand() % 5;
							attron(COLOR_PAIR(2) | A_BOLD);
							attroff(A_UNDERLINE);
							switch (spell)
							{
							case(1):
								mvprintw(9, (cols - 13) / 2, "1 - ����������");
								mvprintw(10, (cols - 40) / 2, "��������� ����� ������������ � ������ 50%%");
								mvprintw(11, (cols - 8) / 2, "�� 2 ����");
								break;
							case(2):
								mvprintw(9, (cols - 13) / 2, "2 - ����������");
								mvprintw(10, (cols - 45) / 2, "�������� ����� ��������� �� 3(+�������� * 0.2)");
								mvprintw(11, (cols - 10) / 2, "�� ��� ����");
								break;
							case(3):
								mvprintw(9, (cols - 10) / 2, "3 - �������");
								mvprintw(10, (cols - 48) / 2, "��������������� ���� 10(+��������) ����� ��������");
								break;
							case(4):
								mvprintw(9, (cols - 7) / 2, "4 - ����");
								mvprintw(10, (cols - 57) / 2, "�������� ���� ������ � ����� �� 2 (+�������� * 0.5) ������");
								break;
							case(5):
								mvprintw(9, (cols - 9) / 2, "5 - ������");
								mvprintw(10, (cols - 50) / 2, "�������� ���� ������ �� 3, �� �������� ����� �� 50%%");
								break;
							default:
								break;
							}
							attroff(A_BOLD);
							hero.spells[spell]++;
							getch();
						}
						break;
					}
					else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 33) / 2, "�� ������ �������� ������ ��������");
						break;
					}
				}
				break;
			case traid:
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8, (cols - 52) / 2, "�� ���������� ��������, ������ ������ ��� �� �������?");
				attron(COLOR_PAIR(4));
				mvprintw(10, (cols / 2) - 10, "z - ��");
				attron(COLOR_PAIR(1));
				mvprintw(10, (cols / 2) + 3, "x - ���");
				while (v = getch()) {
					if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
						Traid(&hero, i);
						break;
					}
					else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 55) / 2, "�� ������ ���� ��������, ��� � �� �������� �� ��� ������");
						break;
					}
				}
				break;
			case foe:
				attron(COLOR_PAIR(1));
				mvprintw(13, (cols - 26) / 2, "�� ������������� ����������");
				Enemy enemy = CreateEnemy(i);
				getch();
				int is_win = Battle(&hero, enemy);
				if (is_win == 0) return 0;
				if (hero.experience >= hero.experience_for_levelup) {
					int tmp_strength, tmp_agility, tmp_intellect;
					DrawDistribution();
					curs_set(1);
					echo();
					attron(COLOR_PAIR(1));
					attroff(A_UNDERLINE | A_BOLD);
					mvprintw(23, (cols / 2) - 17, "����:");
					scanw("%d", &tmp_strength);
					while (tmp_strength < 0 || tmp_strength > 5) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
						getch();
						curs_set(1);
						DrawDistribution();
						attron(COLOR_PAIR(1));
						attroff(A_UNDERLINE | A_BOLD);
						mvprintw(23, (cols / 2) - 17, "����:");
						scanw("%d", &tmp_strength);
					}
					attron(COLOR_PAIR(9));
					attroff(A_BOLD);
					DrawBorder();
					attron(COLOR_PAIR(4));
					mvprintw(23, (cols / 2) - 7, "��������:");
					scanw("%d", &tmp_agility);
					while (tmp_agility < 0 || tmp_agility > (5 - tmp_strength)) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
						getch();
						curs_set(1);
						DrawDistribution();
						attron(COLOR_PAIR(1));
						attroff(A_UNDERLINE | A_BOLD);
						mvprintw(23, (cols / 2) - 17, "����:%d", tmp_strength);
						attron(COLOR_PAIR(4));
						mvprintw(23, (cols / 2) - 7, "��������:");
						scanw("%d", &tmp_agility);
					}
					attron(COLOR_PAIR(9));
					attroff(A_BOLD);
					DrawBorder();
					attron(COLOR_PAIR(3));
					mvprintw(23, (cols / 2) + 7, "���������:");
					scanw("%d", &tmp_intellect);
					while (tmp_intellect < 0 || tmp_intellect > (5 - tmp_strength - tmp_agility)) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
						getch();
						curs_set(1);
						DrawDistribution();
						attron(COLOR_PAIR(1));
						attroff(A_UNDERLINE | A_BOLD);
						mvprintw(23, (cols / 2) - 17, "����:%d", tmp_strength);
						attron(COLOR_PAIR(4));
						mvprintw(23, (cols / 2) - 7, "��������:%d", tmp_agility);
						attron(COLOR_PAIR(3));
						mvprintw(23, (cols / 2) + 7, "���������:");
						scanw("%d", &tmp_intellect);
					}
					noecho();
					curs_set(0);
					attron(COLOR_PAIR(9));
					attroff(A_BOLD);
					DrawBorder();
					hero.strenhgt += tmp_strength;
					hero.agility += tmp_agility;
					hero.intellect += tmp_intellect;
					hero.level++;
					hero.experience -= hero.experience_for_levelup;
					hero.experience_for_levelup = 20 + (hero.level * 5);
				}
				if (is_win == 2) {
					return 1;
				}
				break;
			default:
				break;
			}
		}
		else if (choose_path == 2) {
			Save(&i, &hero);
			--i;
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(rows / 2, (cols - 19) / 2, "�� ��������� � ������");
			attroff(A_BOLD | A_UNDERLINE);
			getch();
		}
		else if (choose_path == 3) {
			--i;
			DrawStatistics(hero);
			getch();
		}
		else if (choose_path == 4) return 2;
		++i;
	}
}

void DrawStatistics(Character hero) {
	clear();
	attron(COLOR_PAIR(11));
	DrawBorder();
	attron(COLOR_PAIR(3) | A_UNDERLINE);
	mvprintw(2, (cols - 9) / 2, "����������");
	attroff(A_UNDERLINE);
	attron(COLOR_PAIR(2) | A_BOLD);
	mvprintw(4, (cols - 74) / 2, "���� - %s", hero.race);
	mvprintw(8, (cols - 74) / 2, "�������� - %d", hero.hp);
	mvprintw(5, (cols - 74) / 2, "������ - %d", hero.money);
	mvprintw(6, (cols - 74) / 2, "���� - %d", hero.strenhgt);
	mvprintw(7, (cols - 74) / 2, "�������� - %d", hero.agility);
	mvprintw(8, (cols - 74) / 2, "�������� - %d ", hero.intellect);
	mvprintw(9, (cols - 74) / 2, "������ ���� - %d", hero.damage);
	mvprintw(10, (cols - 74) / 2, "���������� ����� - %d", hero.physical_armor);
	mvprintw(11, (cols - 74) / 2, "���������� ����� - %d", hero.magic_armor);
	mvprintw(12, (cols - 74) / 2, "������� ���� ����� - %d", hero.critical_chance);
	mvprintw(13, (cols - 74) / 2, "������� ��������� - %d", hero.dodge_chance);
	mvprintw(14, (cols - 74) / 2, "������� ������ - %d", hero.fright_chance);
	mvprintw(15, (cols - 74) / 2, "���� - %d/%d", hero.experience, hero.experience_for_levelup);
	mvprintw(16, (cols - 74) / 2, "������� - %d", hero.level);
	int lot = 0;
	attron(COLOR_PAIR(20));
	for (int item = 0; item < 11; ++item) {
		int rarity_item = hero.equipment[item];
		switch (item)
		{
		case(0):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "��� �������� ��������, ����� � ������� ��� +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "��� ������� ��������, ����� � ������� ��� +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "��� ����������� ��������, ����� � ������� ��� +20");
			break;
		case(1):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "��� �������� ��������, ����� � ������� ��� +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "��� ������� ��������, ����� � ������� ��� +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "��� ����������� ��������, ����� � ������� ��� +20");
			break;
		case(2):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "����� �������� ��������, ����� � ������� ��� ������ +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "����� ������� ��������, ����� � ������� ��� ������ +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "����� ����������� ��������, ����� � ������� ��� ������ +20");
			break;
		case(3):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "������ �������� ��������, �������� +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ������� ��������, �������� +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ����������� ��������, �������� +12");
			break;
		case(4):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "��������� �������� ��������, ���� +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "��������� ������� ��������, ���� +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "��������� ����������� ��������, ���� +12");
			break;
		case(5):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "���� �������� ��������, ���������� ����� +3");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "���� ������� ��������, ���������� ����� +5");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "���� ����������� ��������, ���������� ����� +7");
			break;
		case(6):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "����� �������� ��������, ��������� +5%%");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "����� ������� ��������, ��������� +15%%");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "����� ����������� ��������, ��������� +25%%");
			break;
		case(7):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "�������� �������� ��������, ���� ������������ ����� +5%%");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "�������� ������� ��������, ���� ������������ ����� +15%%");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "�������� ����������� ��������, ���� ������������ ����� +25%%");
			break;
		case(8):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "������ �������� ��������, �������� +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ������� ��������, �������� +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ����������� ��������, �������� +12");
			break;
		case(9):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "������ �������� ��������, ���������� ����� +3");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ������� ��������, ���������� ����� +5");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "������ ����������� ��������, ���������� ����� +7");
			break;
		case(10):
			mvprintw(16 + (lot++), (cols - 74) / 2, "����� ��������: %d", rarity_item);
			break;
		default:
			break;
		}
	}
	for (int spell = 0; spell < 5; ++spell) {
		switch (spell)
		{
		case(0):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "����������: ��������� ����� ������������ � ������ 50%% �� 2 �����");
			break;
		case(1):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "����������: �������� ����� ��������� �� 3(+�������� * 20%) �� 3 �����");
			break;
		case(2):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "�������: ��������������� ���� 10(+��������) ����� ��������");
			break;
		case(3):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "����: �������� ���� ������ � ����� �� 2 (+�������� * 0.5) ������ �� 5 �����");
			break;
		case(4):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "������: �������� ���� ������ �� 3, �� �������� ����� �� 50%%");
			break;
		default:
			break;
		}
	}
}

void DrawDistribution() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 15) / 2, "��������� ������");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 30) / 2, "������������ ���� �������������");
	attron(COLOR_PAIR(1));
	attroff(A_BOLD);
	mvprintw(8, (cols - 3) / 2, "����");
	attroff(A_UNDERLINE);
	mvprintw(9, (cols - 34) / 2, "����������� ���� � ������� ��� �� 1");
	mvprintw(10, (cols - 30) / 2, "����������� �������� ����� �� 2");
	attron(COLOR_PAIR(4) | A_UNDERLINE);
	mvprintw(12, (cols - 7) / 2, "��������");
	attroff(A_UNDERLINE);
	mvprintw(13, (cols - 34) / 2, "����������� ���� � ������� ��� �� 1");
	mvprintw(14, (cols - 40) / 2, "����������� ���������� ����� ����� �� 0.5");
	attron(COLOR_PAIR(3) | A_UNDERLINE);
	mvprintw(16, (cols - 8) / 2, "���������");
	attroff(A_UNDERLINE);
	mvprintw(17, (cols - 26) / 2, "���������� ���� ������ �� 1");
	mvprintw(18, (cols - 41) / 2, "����������� ����������� ����� ����� �� 0.5");
	attron(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
	mvprintw(21, (cols - 12) / 2, "� ��� 5 �����");
}

void DrawMenuDay(int i) {
	attron(COLOR_PAIR(6));
	attroff(A_BOLD | A_UNDERLINE);
	DrawBorder();
	attron(A_BOLD | COLOR_PAIR(2));
	mvprintw(6, (cols - 64) / 2, "���� %d", i);
	mvprintw(8, (cols - 64) / 2, "1 - ���������� ����");
	mvprintw(9, (cols - 64) / 2, "2 - ������������ �� ������(�����������)");
	mvprintw(10, (cols - 64) / 2, "3 - ��������� ���������");
	mvprintw(11, (cols - 64) / 2, "4 - �����");
	attroff(A_BOLD);
}