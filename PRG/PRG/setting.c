#include "main.h"

void Setting(int choose_extend) {
	srand(time(NULL));
	extern int kLocationLength, kTraiderChance, kCaveChance, kTreasureChance;
	kLocationLength = 7 + rand() % 13;
	kTraiderChance = 15;
	kCaveChance = 20;
	kTreasureChance = 15;
	kGain = 1.2;
	clear();
	DrawSettings();
	if (choose_extend == 1) {
		char c;
		while ((c = getch()) != 27) {
			if (c == '1') {
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 33) / 2, "������� ����� ������� �� ����� 5");
				move(22, cols / 2);
				curs_set(1);
				echo();
				scanw("%d", &kLocationLength);
				while (kLocationLength < 5) {
					clear();
					attron(A_UNDERLINE | COLOR_PAIR(8));
					attroff(A_BOLD);
					DrawBorder();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
					move(22, cols / 2);
					scanw("%d", &kLocationLength);
				}
				curs_set(0);
				noecho();
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 25) / 2, "������ ������� ������ %d", kLocationLength);
			}
			else if (c == '2') {
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(19, (cols - 44) / 2, "������� ���� ��������� �������� �� ����� %d", 100 - kCaveChance - kTreasureChance);
				mvprintw(20, (cols - 31) / 2, "��� ���� ���� ��������� ������");
				mvprintw(21, (cols - 42) / 2, "������� ��������� ����� �� ������ �������");
				move(23, cols / 2);
				curs_set(1);
				echo();
				scanw("%d", &kTraiderChance);
				while ((kTraiderChance < 0) || (kTraiderChance > (100 - kCaveChance - kTreasureChance))) {
					clear();
					attron(A_UNDERLINE | COLOR_PAIR(8));
					attroff(A_BOLD);
					DrawBorder();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
					move(23, cols / 2);
					scanw("%d", &kTraiderChance);
				}
				curs_set(0);
				noecho();
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 34) / 2, "���� ��������� �������� ������ %d%%", kTraiderChance);
			}
			else if (c == '3') {
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(19, (cols - 42) / 2, "������� ���� ���������� ������ �� ����� %d", 100 - kTraiderChance - kTreasureChance);
				mvprintw(20, (cols - 31) / 2, "��� ���� ���� ��������� ������");
				mvprintw(21, (cols - 42) / 2, "������� ��������� ����� �� ������ �������");
				move(23, cols / 2);
				curs_set(1);
				echo();
				scanw("%d", &kCaveChance);
				while ((kCaveChance < 0) || (kCaveChance > (100 - kTraiderChance - kTreasureChance))) {
					clear();
					attron(A_UNDERLINE | COLOR_PAIR(8));
					attroff(A_BOLD);
					DrawBorder();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
					move(23, cols / 2);
					scanw("%d", &kCaveChance);
				}
				curs_set(0);
				noecho();
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 34) / 2, "���� ���������� ������ ������ %d%%", kCaveChance);
			}
			else if (c == '4') {
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(19, (cols - 42) / 2, "������� ���� ���������� ��������� �� ����� %d", 100 - kTraiderChance - kCaveChance);
				mvprintw(20, (cols - 31) / 2, "��� ���� ���� ��������� ������");
				mvprintw(21, (cols - 42) / 2, "������� ��������� ����� �� ������ �������");
				move(23, cols / 2);
				curs_set(1);
				echo();
				scanw("%d", &kTreasureChance);
				while ((kTreasureChance < 0) || (kTreasureChance > (100 - kTraiderChance - kCaveChance))) {
					clear();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(8));
					attroff(A_BOLD);
					DrawBorder();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
					move(23, cols / 2);
					scanw("%d", &kTreasureChance);
				}
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 36) / 2, "���� ���������� ��������� ������ %d%%", kTreasureChance);
			}
			else if (c == '5') {
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 46) / 2, "������� ����������� �������� ����������� �� 1");
				move(22, cols / 2);
				curs_set(1);
				echo();
				scanw("%f", &kGain);
				while (kGain < 1) {
					clear();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(8));
					attroff(A_BOLD);
					DrawBorder();
					attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(12, (cols - 28) / 2, "�� ����� ������������ �����");
					move(22, cols / 2);
					scanw("%f", &kGain);
				}
				curs_set(0);
				noecho();
				clear();
				DrawSettings();
				attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
				mvprintw(20, (cols - 43) / 2, "����������� �������� ����������� ������ %.2f", kGain);
			}
		}
	}
}

void DrawSettings() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 21) / 2, "��������� ����� ����");
	attron(COLOR_PAIR(2));
	mvprintw(7, (cols - 18) / 2, "1 - ����� �������");
	mvprintw(8, (cols - 26) / 2, "2 - ���� ������� ��������");
	mvprintw(9, (cols - 28) / 2, "3 - ���� ����������� ������");
	mvprintw(10, (cols - 29) / 2, "4 - ���� ���������� ��������");
	mvprintw(11, (cols - 37) / 2, "5 - ����������� �������� �����������");
}