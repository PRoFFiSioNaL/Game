#include "main.h"

typedef struct Character Character;

Character CreateCharacter() {
	Character hero = {0};
	char c, v = 'x';
	clear();
	DrawMenuCharacterRace();
	while (v != 'z' && v != '�' && v != 'Z' && v != '�') {
		c = getch();
		if (c == '1') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 6) / 2, "�������");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "���������� �����������");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 34) / 2, "���������� ����������� ����� �� 25%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "��������������");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "20 - ���� ��������");
			mvprintw(21, (cols - 8) / 2, "5 - �����");
			mvprintw(22, (cols - 19) / 2, "1 - ���������� �����");
			mvprintw(23, (cols - 19) / 2, "1 - ���������� �����");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "�� ������ ������� ��� ����?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ��");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - ���");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
					strcpy(hero.race, "human");
					hero.hp = 20;
					hero.damage = 5;
					hero.physical_armor = 1;
					hero.magic_armor = 1;
					hero.coefficient_experience = 1.25;
					hero.coefficient_critical_damage = 1.5;
					break;
				}
				else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '2') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 4) / 2, "����");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "���������� �����������");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 46) / 2, "����������� ��������� �� ���������� ���� �� 20%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "��������������");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "10 - ���� ��������");
			mvprintw(21, (cols - 8) / 2, "7 - �����");
			mvprintw(22, (cols - 19) / 2, "2 - ���������� �����");
			mvprintw(23, (cols - 19) / 2, "2 - ���������� �����");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "�� ������ ������� ��� ����?");
			attroff(A_BOLD | A_UNDERLINE);
			attron( COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ��");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - ���");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
					strcpy(hero.race, "elf");
					hero.hp = 10;
					hero.damage = 7;
					hero.physical_armor = 2;
					hero.magic_armor = 2;
					hero.dodge_chance = 20;
					hero.coefficient_experience = 1;
					hero.coefficient_critical_damage = 1.5;
					break;
				}
				else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '3') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 4) / 2, "�����");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "���������� �����������");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 40) / 2, "���� �������� ���������� ��� ����� �� 10%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "��������������");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "15 - ���� ��������");
			mvprintw(21, (cols - 8) / 2, "7 - �����");
			mvprintw(22, (cols - 19) / 2, "0 - ���������� �����");
			mvprintw(23, (cols - 19) / 2, "3 - ���������� �����");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "�� ������ ������� ��� ����?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ��");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - ���");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
					strcpy(hero.race, "devil");
					hero.hp = 15;
					hero.damage = 7;
					hero.physical_armor = 0;
					hero.magic_armor = 3;
					hero.fright_chance = 10;
					hero.coefficient_experience = 1;
					hero.coefficient_critical_damage = 1.5;
					break;
				}
				else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '4') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 2) / 2, "���");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "���������� �����������");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 40) / 2, "���������� ���� ������������ ����� �� 15%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "��������������");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "25 - ���� ��������");
			mvprintw(21, (cols - 8) / 2, "6 - �����");
			mvprintw(22, (cols - 19) / 2, "0 - ���������� �����");
			mvprintw(23, (cols - 19) / 2, "0 - ���������� �����");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "�� ������ ������� ��� ����?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ��");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - ���");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == '�' || v == 'Z' || v == '�') {
					strcpy(hero.race, "orc");
					hero.hp = 25;
					hero.damage = 6;
					hero.physical_armor = 0;
					hero.magic_armor = 0;
					hero.critical_chance = 15;
					hero.coefficient_experience = 1;
					hero.coefficient_critical_damage = 1.5;
					break;
				}
				else if (v == 'x' || v == '�' || v == 'X' || v == '�') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
	}
	int tmp_strength, tmp_agility, tmp_intellect;
	DrawMenu�haracteristics();
	curs_set(1);
	echo();
	attron(COLOR_PAIR(1));
	attroff(A_UNDERLINE | A_BOLD);
	mvprintw(23, (cols / 2) - 17, "����:");
	scanw("%d", &tmp_strength);
	while (tmp_strength < 0 || tmp_strength > 15) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
		getch();
		curs_set(1);
		DrawMenu�haracteristics();
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
	while (tmp_agility < 0 || tmp_agility > (15 - tmp_strength)) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
		getch();
		curs_set(1);
		DrawMenu�haracteristics();
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
	while (tmp_intellect < 0 || tmp_intellect > (15 - tmp_strength - tmp_agility)) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
		getch();
		curs_set(1);
		DrawMenu�haracteristics();
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
	hero.strenhgt = tmp_strength;
	hero.agility = tmp_agility;
	hero.intellect = tmp_intellect;
	hero.level = 1;
	hero.experience_for_levelup = 20 + (hero.level * 5);
	DrawSpell();
	c = getch();
	while (c < '1' || c > '5') {
		c = getch();
	}
	hero.spells[c - 49] = 1;
	return hero;
}

void DrawMenuCharacterRace() {
	clear();
	attron(COLOR_PAIR(7));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 22) / 2, "���� �������� ���������");
	attron(COLOR_PAIR(4) | A_BOLD | A_UNDERLINE);
	mvprintw(6, (cols - 3) / 2, "����");
	attron(COLOR_PAIR(4));
	mvprintw(7, (cols - 34) / 2, "��������, ����� ��������� ���������");
	attron(COLOR_PAIR(2));
	attroff(A_UNDERLINE | A_BOLD);
	mvprintw(10, (cols - 10) / 2, "1 - �������");
	mvprintw(11, (cols - 7) / 2, "2 - ����");
	mvprintw(12, (cols - 8) / 2, "3 - �����");
	mvprintw(13, (cols - 6) / 2, "4 - ���");
}

void DrawMenu�haracteristics() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 22) / 2, "���� �������� ���������");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 32) / 2, "������������� ����� �������������");
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
	mvprintw(21, (cols - 13) / 2, "� ��� 15 �����");
}

void DrawSpell() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 22) / 2, "���� �������� ���������");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 15) / 2, "����� ����������");
	attron(COLOR_PAIR(2));
	attroff(A_UNDERLINE);
	mvprintw(9, (cols - 13) / 2, "1 - ����������");
	mvprintw(10, (cols - 40) / 2, "��������� ����� ������������ � ������ 50%%");
	mvprintw(11, (cols - 8) / 2, "�� 2 ����");
	mvprintw(13, (cols - 13) / 2, "2 - ����������");
	mvprintw(14, (cols - 45) / 2, "�������� ����� ��������� �� 3(+�������� * 0.2)");
	mvprintw(15, (cols - 10) / 2, "�� ��� ����");
	mvprintw(17, (cols - 10) / 2, "3 - �������");
	mvprintw(18, (cols - 48) / 2, "��������������� ���� 10(+��������) ����� ��������");
	mvprintw(20, (cols - 7) / 2, "4 - ����");
	mvprintw(21, (cols - 57) / 2, "�������� ���� ������ � ����� �� 2 (+�������� * 0.5) ������");
	mvprintw(22, (cols - 9) / 2, "�� 5 �����");
	mvprintw(24, (cols - 9) / 2, "5 - ������");
	mvprintw(25, (cols - 50) / 2, "�������� ���� ������ �� 3, �� �������� ����� �� 50%%");
	mvprintw(27, (cols - 61) / 2, "�� �� ������ ������������ ���� ���������� ��������� ��� �� ���");
}