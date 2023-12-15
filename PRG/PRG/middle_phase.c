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
		mvprintw(4, (cols - 22) / 2, "Добро пожаловать в мир!");
		attroff(A_UNDERLINE);
		attron(COLOR_PAIR(2));
		mvprintw(6, (cols - 53) / 2, "Вы находитесь в небольшом городе и жаждете приключений");
		mvprintw(7, (cols - 42) / 2, "но перед этим нужно хорошенько подготовится");
		mvprintw(8, (cols - 29) / 2, "Будете заглядывать к торговцу?");
		attron(COLOR_PAIR(4));
		mvprintw(10, (cols / 2) - 10, "z - ДА");
		attron(COLOR_PAIR(1));
		mvprintw(10, (cols / 2) + 3, "x - НЕТ");
		while ((v = getch()) != 27) {
			if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
				Traid(&hero, 0);
				break;
			}
			else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
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
				while (rarity_item == 3) { //Рандомим пока не найдем у героя предмета не миф качества
					int item = rand() % 11;
					int rarity_item = hero.equipment[item];
				}
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(6, (cols - 43) / 2, "Проходя вперед вы обнаруживаете скоровищницу");
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8 , (cols - 19) / 2, "Вы хотите осмотреть?");
				attroff(A_BOLD | A_UNDERLINE);
				attron(COLOR_PAIR(4));
				mvprintw(9, (cols / 2) - 10, "z - ДА");
				attron(COLOR_PAIR(1));
				mvprintw(9, (cols / 2) + 3, "x - НЕТ");
				while (v = getch()) {
					if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(2));
						mvprintw(8 , (cols - 10) / 2, "Вы находите");
						switch (item)
						{
						case(0):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 46) / 2, "меч обычного качества - атака в ближнем бою +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 46) / 2, "меч редкого качества - атака в ближнем бою +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 46) / 2, "меч мифического качества - атака в ближнем бою +20");
							}
							break;
						case(1):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 46) / 2, "лук обычного качества - атака в дальнем бою +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 46) / 2, "лук редкого качества - атака в дальнем бою +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 46) / 2, "лук мифического качества - атака в дальнем бою +20");
							}
							break;
						case(2):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 54) / 2, "посох обычного качества - атака в дальнем бою магией +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 54) / 2, "посох редкого качества - атака в дальнем бою магией +10");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 54) / 2, "посох мифического качества - атака в дальнем бою магией +20");
							}
							break;
						case(3):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 38) / 2, "сапоги обычного качества - ловкость +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 38) / 2, "сапоги редкого качества - ловкость +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 38) / 2, "сапоги мифического качества - ловкость +12");
							}
							break;
						case(4):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 36) / 2, "нагрудник обычного качества - сила +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 36) / 2, "нагрудник редкого качества - сила +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 36) / 2, "нагрудник мифического качества - сила +12");
							}
							break;
						case(5):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 56) / 2, "шлем обычного качества - физическая броня +3, здоровье +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 56) / 2, "шлем редкого качества - физическая броня +5, здоровье +7");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 56) / 2, "шлем мифического качества - физическая броня +7, здоровье +10");
							}
							break;
						case(6):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 38) / 2, "штаны обычного качества - уклонение +5%%");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 38) / 2, "штаны редкого качества - уклонение +15%%");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 38) / 2, "штаны мифического качества - уклонение +25%%");
							}
							break;
						case(7):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 55) / 2, "перчатки обычного качества - шанс критического удара +5%%");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 55) / 2, "перчатки редкого качества - шанс критического удара +15%%");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 55) / 2, "перчатки мифического качества - шанс критического удара +25%%");
							}
							break;
						case(8):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 37) / 2, "амулет обычного качества - интелект +4");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 37) / 2, "амулет редкого качества - интелект +8");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 37) / 2, "амулет мифического качества - интелект +12");
							}
							break;
						case(9):
							if (rarity_item == 0) {
								attron(COLOR_PAIR(20));
								mvprintw(9, (cols - 58) / 2, "кольцо обычного качества - магическая броня +3, здоровье +5");
							}
							else if (rarity_item == 1) {
								attron(COLOR_PAIR(3));
								mvprintw(9, (cols - 58) / 2, "кольцо редкого качества - магическая броня +5, здоровье +7");
							}
							else {
								attron(COLOR_PAIR(5));
								mvprintw(9, (cols - 58) / 2, "кольцо мифического качества - магическая броня +7, здоровье +10");
							}
							break;
						case(10):
							attroff(A_UNDERLINE | A_BOLD);
							attron(COLOR_PAIR(1));
							mvprintw(9, (cols - 49) / 2, "зелье здоровья - восстанавливает 15 очков здоровья");
							break;
						default:
							break;
						}
						hero.equipment[item]++;
						attron(COLOR_PAIR(4) | A_UNDERLINE | A_BOLD);
						mvprintw(13, (cols - 39) / 2, "Обрадованные находкой вы продолжате путь");
						attroff(A_UNDERLINE | A_BOLD);
						getch();
						break;
					}
					else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 31) / 2, "Вы прошли мимо не заглянув в неё");
						break;
					}
				}
				break;
			case cave:
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(6, (cols - 37) / 2, "Проходя вперед вы обнаруживаете пещеру");
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8 , (cols - 25) / 2, "Вы хотите заглянуть в нее?");
				attroff(A_BOLD | A_UNDERLINE);
				attron(COLOR_PAIR(4));
				mvprintw(9, (cols / 2) - 10, "z - ДА");
				attron(COLOR_PAIR(1));
				mvprintw(9, (cols / 2) + 3, "x - НЕТ");
				while (v = getch()) {
					if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
						ClearRow(8);
						ClearRow(9);
						int cave_rand = rand() % 100;
						if (cave_rand < 80) {
							attron(COLOR_PAIR(1));
							mvprintw(13, (cols - 26) / 2, "Вы обнаруживаете противника");
							Enemy enemy = CreateEnemy(i);
							getch();
							int is_win = Battle(&hero, enemy);
							if (is_win == 0) return 0;
						}
						else if (cave_rand < 95) {
							ClearRow(8);
							ClearRow(9);
							attron(COLOR_PAIR(20));
							mvprintw(13, (cols - 42) / 2, "Абсолютно пустая и не примечательная пещера");
							getch();
							
						}
						else {
							ClearRow(8);
							ClearRow(9);
							attron(COLOR_PAIR(2));
							mvprintw(8, (cols - 28) / 2, "Вы находите свиток заклинания");
							int spell = rand() % 5;
							while (hero.spells[spell] != 0) spell = rand() % 5;
							attron(COLOR_PAIR(2) | A_BOLD);
							attroff(A_UNDERLINE);
							switch (spell)
							{
							case(1):
								mvprintw(9, (cols - 13) / 2, "1 - Ослепление");
								mvprintw(10, (cols - 40) / 2, "Противник будет промахиватся с шансом 50%%");
								mvprintw(11, (cols - 8) / 2, "на 2 хода");
								break;
							case(2):
								mvprintw(9, (cols - 13) / 2, "2 - Разрушение");
								mvprintw(10, (cols - 45) / 2, "Понижает броню противнка на 3(+интелект * 0.2)");
								mvprintw(11, (cols - 10) / 2, "на три хода");
								break;
							case(3):
								mvprintw(9, (cols - 10) / 2, "3 - Лечение");
								mvprintw(10, (cols - 48) / 2, "Восстанавливает себе 10(+интелект) очков здоровья");
								break;
							case(4):
								mvprintw(9, (cols - 7) / 2, "4 - Клич");
								mvprintw(10, (cols - 57) / 2, "Повышает свою защиту и атаку на 2 (+интелект * 0.5) единиц");
								break;
							case(5):
								mvprintw(9, (cols - 9) / 2, "5 - Ярость");
								mvprintw(10, (cols - 50) / 2, "Понижает свою защиту на 3, но повышает атаку на 50%%");
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
					else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 33) / 2, "Вы обошли странную пещеру стороной");
						break;
					}
				}
				break;
			case traid:
				attroff(A_UNDERLINE);
				attron(COLOR_PAIR(2));
				mvprintw(8, (cols - 52) / 2, "Вы встречаете торговца, хотите узнать что он продает?");
				attron(COLOR_PAIR(4));
				mvprintw(10, (cols / 2) - 10, "z - ДА");
				attron(COLOR_PAIR(1));
				mvprintw(10, (cols / 2) + 3, "x - НЕТ");
				while (v = getch()) {
					if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
						Traid(&hero, i);
						break;
					}
					else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
						ClearRow(8);
						ClearRow(9);
						attron(COLOR_PAIR(1));
						mvprintw(13, (cols - 55) / 2, "Вы прошли мимо торговца, так и не взглянув на его товары");
						break;
					}
				}
				break;
			case foe:
				attron(COLOR_PAIR(1));
				mvprintw(13, (cols - 26) / 2, "Вы обнаруживаете противника");
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
					mvprintw(23, (cols / 2) - 17, "СИЛА:");
					scanw("%d", &tmp_strength);
					while (tmp_strength < 0 || tmp_strength > 5) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
						getch();
						curs_set(1);
						DrawDistribution();
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
					while (tmp_agility < 0 || tmp_agility > (5 - tmp_strength)) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
						getch();
						curs_set(1);
						DrawDistribution();
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
					while (tmp_intellect < 0 || tmp_intellect > (5 - tmp_strength - tmp_agility)) {
						curs_set(0);
						clear();
						attron(A_UNDERLINE | COLOR_PAIR(8));
						attroff(A_BOLD);
						DrawBorder();
						attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(1));
						mvprintw(12, (cols - 28) / 2, "Вы ввели некорректное число");
						getch();
						curs_set(1);
						DrawDistribution();
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
			mvprintw(rows / 2, (cols - 19) / 2, "Вы отдыхаете у костра");
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
	mvprintw(2, (cols - 9) / 2, "СТАТИСТИКА");
	attroff(A_UNDERLINE);
	attron(COLOR_PAIR(2) | A_BOLD);
	mvprintw(4, (cols - 74) / 2, "Раса - %s", hero.race);
	mvprintw(8, (cols - 74) / 2, "Здоровье - %d", hero.hp);
	mvprintw(5, (cols - 74) / 2, "Деньги - %d", hero.money);
	mvprintw(6, (cols - 74) / 2, "Сила - %d", hero.strenhgt);
	mvprintw(7, (cols - 74) / 2, "Ловкость - %d", hero.agility);
	mvprintw(8, (cols - 74) / 2, "Интелект - %d ", hero.intellect);
	mvprintw(9, (cols - 74) / 2, "Чистый урон - %d", hero.damage);
	mvprintw(10, (cols - 74) / 2, "Физическая броня - %d", hero.physical_armor);
	mvprintw(11, (cols - 74) / 2, "Магическая броня - %d", hero.magic_armor);
	mvprintw(12, (cols - 74) / 2, "Процент крит удара - %d", hero.critical_chance);
	mvprintw(13, (cols - 74) / 2, "Процент уклонения - %d", hero.dodge_chance);
	mvprintw(14, (cols - 74) / 2, "Процент испуга - %d", hero.fright_chance);
	mvprintw(15, (cols - 74) / 2, "Опыт - %d/%d", hero.experience, hero.experience_for_levelup);
	mvprintw(16, (cols - 74) / 2, "Уровень - %d", hero.level);
	int lot = 0;
	attron(COLOR_PAIR(20));
	for (int item = 0; item < 11; ++item) {
		int rarity_item = hero.equipment[item];
		switch (item)
		{
		case(0):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Меч обычного качества, атака в ближнем бою +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Меч редкого качества, атака в ближнем бою +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Меч мифического качества, атака в ближнем бою +20");
			break;
		case(1):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Лук обычного качества, атака в дальнем бою +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Лук редкого качества, атака в дальнем бою +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Лук мифического качества, атака в дальнем бою +20");
			break;
		case(2):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Посох обычного качества, атака в дальнем бою магией +5");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Посох редкого качества, атака в дальнем бою магией +10");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Посох мифического качества, атака в дальнем бою магией +20");
			break;
		case(3):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Сапоги обычного качества, ловкость +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Сапоги редкого качества, ловкость +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Сапоги мифического качества, ловкость +12");
			break;
		case(4):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Нагрудник обычного качества, сила +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Нагрудник редкого качества, сила +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Нагрудник мифического качества, сила +12");
			break;
		case(5):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Шлем обычного качества, физическая броня +3");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Шлем редкого качества, физическая броня +5");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Шлем мифического качества, физическая броня +7");
			break;
		case(6):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Штаны обычного качества, уклонение +5%%");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Штаны редкого качества, уклонение +15%%");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Штаны мифического качества, уклонение +25%%");
			break;
		case(7):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Перчатки обычного качества, шанс критического удара +5%%");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Перчатки редкого качества, шанс критического удара +15%%");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Перчатки мифического качества, шанс критического удара +25%%");
			break;
		case(8):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Амулет обычного качества, интелект +4");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Амулет редкого качества, интелект +8");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Амулет мифического качества, интелект +12");
			break;
		case(9):
			if (rarity_item == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Кольцо обычного качества, магическая броня +3");
			else if (rarity_item == 2) mvprintw(16 + (lot++), (cols - 74) / 2, "Кольцо редкого качества, магическая броня +5");
			else if (rarity_item == 3) mvprintw(16 + (lot++), (cols - 74) / 2, "Кольцо мифического качества, магическая броня +7");
			break;
		case(10):
			mvprintw(16 + (lot++), (cols - 74) / 2, "Зелья здоровья: %d", rarity_item);
			break;
		default:
			break;
		}
	}
	for (int spell = 0; spell < 5; ++spell) {
		switch (spell)
		{
		case(0):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Ослепление: противник будет промахиватся с шансом 50%% на 2 ходов");
			break;
		case(1):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Разрушение: понижает броню противнка на 3(+интелект * 20%) на 3 ходов");
			break;
		case(2):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Лечение: восстанавливает себе 10(+интелект) очков здоровья");
			break;
		case(3):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Клич: повышает свою защиту и атаку на 2 (+интелект * 0.5) единиц на 5 ходов");
			break;
		case(4):
			if (hero.spells[spell] == 1) mvprintw(16 + (lot++), (cols - 74) / 2, "Ярость: понижает свою защиту на 3, но повышает атаку на 50%%");
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
	mvprintw(4, (cols - 15) / 2, "ПОВЫШЕНИЕ УРОВНЯ");
	attron(COLOR_PAIR(5));
	mvprintw(6, (cols - 30) / 2, "Распределите очки характеристик");
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
	mvprintw(21, (cols - 12) / 2, "У вас 5 очков");
}

void DrawMenuDay(int i) {
	attron(COLOR_PAIR(6));
	attroff(A_BOLD | A_UNDERLINE);
	DrawBorder();
	attron(A_BOLD | COLOR_PAIR(2));
	mvprintw(6, (cols - 64) / 2, "День %d", i);
	mvprintw(8, (cols - 64) / 2, "1 - Продолжить путь");
	mvprintw(9, (cols - 64) / 2, "2 - Остановаться на привал(Сохраниться)");
	mvprintw(10, (cols - 64) / 2, "3 - Осмотреть персонажа");
	mvprintw(11, (cols - 64) / 2, "4 - Выйти");
	attroff(A_BOLD);
}