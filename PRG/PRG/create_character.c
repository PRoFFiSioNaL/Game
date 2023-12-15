#include "main.h"

typedef struct Character Character;

Character CreateCharacter() {
	Character hero = {0};
	char c, v = 'x';
	clear();
	DrawMenuCharacterRace();
	while (v != 'z' && v != 'я' && v != 'Z' && v != 'Я') {
		c = getch();
		if (c == '1') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 6) / 2, "ЧЕЛОВЕК");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "Врожденная способность");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 34) / 2, "Повышенный коэффициент опыта на 25%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "Характеристики");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "20 - Очки здоровья");
			mvprintw(21, (cols - 8) / 2, "5 - Атака");
			mvprintw(22, (cols - 19) / 2, "1 - Физическая броня");
			mvprintw(23, (cols - 19) / 2, "1 - Магическая броня");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "Вы хотите выбрать эту расу?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ДА");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - НЕТ");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
					strcpy(hero.race, "human");
					hero.hp = 20;
					hero.damage = 5;
					hero.physical_armor = 1;
					hero.magic_armor = 1;
					hero.coefficient_experience = 1.25;
					hero.coefficient_critical_damage = 1.5;
					break;
				}
				else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '2') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 4) / 2, "ЭЛЬФ");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "Врожденная способность");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 46) / 2, "Повышешнное уклонение от физических атак на 20%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "Характеристики");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "10 - Очки здоровья");
			mvprintw(21, (cols - 8) / 2, "7 - Атака");
			mvprintw(22, (cols - 19) / 2, "2 - Физическая броня");
			mvprintw(23, (cols - 19) / 2, "2 - Магическая броня");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "Вы хотите выбрать эту расу?");
			attroff(A_BOLD | A_UNDERLINE);
			attron( COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ДА");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - НЕТ");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
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
				else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '3') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 4) / 2, "ДЕМОН");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "Врожденная способность");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 40) / 2, "Шанс напугать противника при атаке на 10%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "Характеристики");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "15 - Очки здоровья");
			mvprintw(21, (cols - 8) / 2, "7 - Атака");
			mvprintw(22, (cols - 19) / 2, "0 - Физическая броня");
			mvprintw(23, (cols - 19) / 2, "3 - Магическая броня");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "Вы хотите выбрать эту расу?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ДА");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - НЕТ");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
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
				else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
		else if (c == '4') {
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(15, (cols - 2) / 2, "ОРК");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(16, (cols - 21) / 2, "Врожденная способность");
			attron(COLOR_PAIR(2) | A_NORMAL);
			mvprintw(17, (cols - 40) / 2, "Повышенный шанс критического удара на 15%%");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(3));
			mvprintw(19, (cols - 13) / 2, "Характеристики");
			attron(COLOR_PAIR(2));
			attroff(A_UNDERLINE | A_BOLD);
			mvprintw(20, (cols - 17) / 2, "25 - Очки здоровья");
			mvprintw(21, (cols - 8) / 2, "6 - Атака");
			mvprintw(22, (cols - 19) / 2, "0 - Физическая броня");
			mvprintw(23, (cols - 19) / 2, "0 - Магическая броня");
			attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(5));
			mvprintw(25, (cols - 24) / 2, "Вы хотите выбрать эту расу?");
			attroff(A_BOLD | A_UNDERLINE);
			attron(COLOR_PAIR(4));
			mvprintw(27, (cols / 2) - 10, "z - ДА");
			attron(COLOR_PAIR(1));
			mvprintw(27, (cols / 2) + 3, "x - НЕТ");
			while ((v = getch()) != 27) {
				if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
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
				else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
					clear();
					DrawMenuCharacterRace();
					break;
				}
			}
		}
	}
	int tmp_strength, tmp_agility, tmp_intellect;
	DrawMenuСharacteristics();
	curs_set(1);
	echo();
	attron(COLOR_PAIR(1));
	attroff(A_UNDERLINE | A_BOLD);
	mvprintw(23, (cols / 2) - 17, "СИЛА:");
	scanw("%d", &tmp_strength);
	while (tmp_strength < 0 || tmp_strength > 15) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
		getch();
		curs_set(1);
		DrawMenuСharacteristics();
		attron(COLOR_PAIR(1));
		attroff(A_UNDERLINE | A_BOLD);
		mvprintw(23, (cols / 2) - 17, "СИЛА:");
		scanw("%d", &tmp_strength);
	}
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(4));
	mvprintw(23, (cols / 2) - 7, "ЛОВКОСТЬ:");
	scanw("%d", &tmp_agility);
	while (tmp_agility < 0 || tmp_agility > (15 - tmp_strength)) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
		getch();
		curs_set(1);
		DrawMenuСharacteristics();
		attron(COLOR_PAIR(1));
		attroff(A_UNDERLINE | A_BOLD);
		mvprintw(23, (cols / 2) - 17, "СИЛА:%d", tmp_strength);
		attron(COLOR_PAIR(4));
		mvprintw(23, (cols / 2) - 7, "ЛОВКОСТЬ:");
		scanw("%d", &tmp_agility);
	}
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(3));
	mvprintw(23, (cols / 2) + 7, "ИНТЕЛЛЕКТ:");
	scanw("%d", &tmp_intellect);
	while (tmp_intellect < 0 || tmp_intellect > (15 - tmp_strength - tmp_agility)) {
		curs_set(0);
		clear();
		attron(A_UNDERLINE | COLOR_PAIR(8));
		attroff(A_BOLD);
		DrawBorder();
		attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
		mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
		getch();
		curs_set(1);
		DrawMenuСharacteristics();
		attron(COLOR_PAIR(1));
		attroff(A_UNDERLINE | A_BOLD);
		mvprintw(23, (cols / 2) - 17, "СИЛА:%d", tmp_strength);
		attron(COLOR_PAIR(4));
		mvprintw(23, (cols / 2) - 7, "ЛОВКОСТЬ:%d", tmp_agility);
		attron(COLOR_PAIR(3));
		mvprintw(23, (cols / 2) + 7, "ИНТЕЛЛЕКТ:");
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
	mvprintw(4, (cols - 22) / 2, "МЕНЮ СОЗДАНИЯ ПЕРСОНАЖА");
	attron(COLOR_PAIR(4) | A_BOLD | A_UNDERLINE);
	mvprintw(6, (cols - 3) / 2, "Раса");
	attron(COLOR_PAIR(4));
	mvprintw(7, (cols - 34) / 2, "Выберите, чтобы прочитать подробнее");
	attron(COLOR_PAIR(2));
	attroff(A_UNDERLINE | A_BOLD);
	mvprintw(10, (cols - 10) / 2, "1 - Человек");
	mvprintw(11, (cols - 7) / 2, "2 - Эльф");
	mvprintw(12, (cols - 8) / 2, "3 - Демон");
	mvprintw(13, (cols - 6) / 2, "4 - Орк");
}

void DrawMenuСharacteristics() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 22) / 2, "МЕНЮ СОЗДАНИЯ ПЕРСОНАЖА");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 32) / 2, "Распределение очков характеристик");
	attron(COLOR_PAIR(1));
	attroff(A_BOLD);
	mvprintw(8, (cols - 3) / 2, "СИЛА");
	attroff(A_UNDERLINE);
	mvprintw(9, (cols - 34) / 2, "Увеличивает урон в ближнем бою на 1");
	mvprintw(10, (cols - 30) / 2, "Увеличивает здоровье героя на 2");
	attron(COLOR_PAIR(4) | A_UNDERLINE);
	mvprintw(12, (cols - 7) / 2, "ЛОВКОСТЬ");
	attroff(A_UNDERLINE);
	mvprintw(13, (cols - 34) / 2, "Увеличивает урон в дальнем бою на 1");
	mvprintw(14, (cols - 40) / 2, "Увеличивает физическую броню героя на 0.5");
	attron(COLOR_PAIR(3) | A_UNDERLINE);
	mvprintw(16, (cols - 8) / 2, "ИНТЕЛЛЕКТ");
	attroff(A_UNDERLINE);
	mvprintw(17, (cols - 26) / 2, "Увелчивает урон магией на 1");
	mvprintw(18, (cols - 41) / 2, "Увеличивает магичесскую броню героя на 0.5");
	attron(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
	mvprintw(21, (cols - 13) / 2, "У вас 15 очков");
}

void DrawSpell() {
	clear();
	attron(COLOR_PAIR(9));
	attroff(A_BOLD);
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 22) / 2, "МЕНЮ СОЗДАНИЯ ПЕРСОНАЖА");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 15) / 2, "Выбор заклинания");
	attron(COLOR_PAIR(2));
	attroff(A_UNDERLINE);
	mvprintw(9, (cols - 13) / 2, "1 - Ослепление");
	mvprintw(10, (cols - 40) / 2, "Противник будет промахиватся с шансом 50%%");
	mvprintw(11, (cols - 8) / 2, "на 2 хода");
	mvprintw(13, (cols - 13) / 2, "2 - Разрушение");
	mvprintw(14, (cols - 45) / 2, "Понижает броню противнка на 3(+интелект * 0.2)");
	mvprintw(15, (cols - 10) / 2, "на три хода");
	mvprintw(17, (cols - 10) / 2, "3 - Лечение");
	mvprintw(18, (cols - 48) / 2, "Восстанавливает себе 10(+интелект) очков здоровья");
	mvprintw(20, (cols - 7) / 2, "4 - Клич");
	mvprintw(21, (cols - 57) / 2, "Повышает свою защиту и атаку на 2 (+интелект * 0.5) единиц");
	mvprintw(22, (cols - 9) / 2, "на 5 ходов");
	mvprintw(24, (cols - 9) / 2, "5 - Ярость");
	mvprintw(25, (cols - 50) / 2, "Понижает свою защиту на 3, но повышает атаку на 50%%");
	mvprintw(27, (cols - 61) / 2, "Вы не можете использовать одно заклинание несколько раз за бой");
}