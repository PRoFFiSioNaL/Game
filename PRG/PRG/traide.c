#include "main.h"
typedef struct Character Character;

void Traid(Character* hero, int number_location) {
	srand(time(NULL));
	clear();
	DrawMenuMoney(hero);
	char c, v;
	int coefficient_usual, coefficient_rare, coefficient_mythical = 0;
	if (number_location < 6) { //расчет кэфоф в зависимост и от номера локации
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
	int number_items = 4 + (rand() % 5); //кол-о айтемов у торговца
	int* items = (int*)malloc(2 * number_items * sizeof(int)); //массив айтемов торговца
	for (int i = 0; i < number_items; ++i) {
		int item = rand() % 10; //рандом айтема
		int rarity = rand() % 100; //рандом качества айтема
		int rarity_item;
		if (rarity < coefficient_usual) rarity_item = 0;
		else if (rarity < (coefficient_usual + coefficient_rare)) rarity_item = 1;
		else rarity_item = 2;
		int is_repeat = 0;
		for (int j = 0; j < i; ++j) {
			if ((item == items[j * 2]) && (rarity_item == items[j * 2 + 1])) { //проверка на повтор
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
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - меч обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в ближнем бою +5, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - меч редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в ближнем бою +10, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - меч мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в ближнем бою +20, стоимость - 1000 монет");
			}
			break;
		case(1):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - лук обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою +5, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - лук редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою +10, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - лук мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою +20, стоимость - 1000 монет");
			}
			break;
		case(2):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - посох обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою магией +5, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - посох редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою магией +10, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - посох мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "атака в дальнем бою магией +20, стоимость - 1000 монет");
			}
			break;
		case(3):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - сапоги обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "ловкость +4, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - сапоги редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "ловкость +8, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - сапоги мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "ловкость +12, стоимость - 1000 монет");
			}
			break;
		case(4):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - нагрудник обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "сила +4, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - нагрудник редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "сила +8, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - нагрудник мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "сила +12, стоимость - 1000 монет");
			}
			break;
		case(5):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - шлем обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "физическая броня +3, здоровье +5, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - шлем редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "физическая броня +5, здоровье +7, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - шлем мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "физическая броня +7, здоровье +10, стоимость - 1000 монет");
			}
			break;
		case(6):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - штаны обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "уклонение +5%%, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - штаны редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "уклонение +15%%, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - штаны мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "уклонение +25%%, стоимость - 1000 монет");
			}
			break;
		case(7):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - перчатки обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "шанс критического удара +5%%, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - перчатки редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "шанс критического удара +15%%, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - перчатки мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "шанс критического удара +25%%, стоимость - 1000 монет");
			}
			break;
		case(8):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - амулет обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "интелект +4, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - амулет редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "интелект +8, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - амулет мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "интелект +12, стоимость - 1000 монет");
			}
			break;
		case(9):
			if (rarity_item == 0) {
				attron(COLOR_PAIR(20));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - кольцо обычного качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "магическая броня +3, здоровье +5, стоимость - 100 монет");
			}
			else if (rarity_item == 1) {
				attron(COLOR_PAIR(3));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - кольцо редкого качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "магическая броня +5, здоровье +7, стоимость - 300 монет");
			}
			else {
				attron(COLOR_PAIR(5));
				mvprintw(6 + (i * 2), (cols - 74) / 2, "%d предмет - кольцо мифического качества", i + 1);
				mvprintw(6 + (i * 2) + 1, (cols - 74) / 2, "магическая броня +7, здоровье +10, стоимость - 1000 монет");
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
	mvprintw(6 + (number_items * 2), (cols - 74) / 2, "%d предмет - зелье здоровья", number_items + 1);
	mvprintw(6 + (number_items * 2) + 1, (cols - 74) / 2, "восстанавливает 15 очков здоровья, стоимость - 100 монет");
	while ((c = getch()) != 27) { //цикл покупки айтемов
		if ((c > '0') && (c <= (number_items + 49))) {
			ClearRow(rows - 4);
			int number = c - 48;
			if (number == number_items + 1) { //зелька
				if (hero->money >= 100) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "Вы точно хотите приобрести?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ДА");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - НЕТ");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
							hero->equipment[10]++;
							hero->money -= 100;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "Спасибо за покупку, что то еще?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 40) / 2, "У вас недостаточно золота для приобретения");
					attroff(A_UNDERLINE);
				}
			}
			else { //остальные айтемы
				number--;
				int item, rarity_item;
				item = items[number * 2];
				rarity_item = items[(number * 2) + 1];
				if (rarity_item == -1) {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 25) / 2, "Вы уже купили этот предмет");
					attroff(A_UNDERLINE);
				}
				else if (rarity_item == 0 && hero->money >= 100) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "Вы точно хотите приобрести?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ДА");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - НЕТ");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 100;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "Спасибо за покупку, что то еще?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else if (rarity_item == 1 && hero->money >= 300) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "Вы точно хотите приобрести?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ДА");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - НЕТ");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 300;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "Спасибо за покупку, что то еще?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else if (rarity_item == 2 && hero->money >= 1000) {
					attron(COLOR_PAIR(2));
					mvprintw(6 + ((number_items + 1) * 2) + 1, (cols - 26) / 2, "Вы точно хотите приобрести?");
					attroff(A_BOLD | A_UNDERLINE);
					attron(COLOR_PAIR(4));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) - 10, "z - ДА");
					attron(COLOR_PAIR(1));
					mvprintw(6 + (((number_items + 1) * 2) + 2), (cols / 2) + 3, "x - НЕТ");
					while ((v = getch()) != 27) {
						if (v == 'z' || v == 'я' || v == 'Z' || v == 'Я') {
							hero->equipment[item] = rarity_item + 1;
							items[(number * 2) + 1] = -1;
							hero->money -= 1000;
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							attron(COLOR_PAIR(4));
							mvprintw(rows - 4, (cols - 30) / 2, "Спасибо за покупку, что то еще?");
							DrawMenuMoney(hero);
							break;
						}
						else if (v == 'x' || v == 'ч' || v == 'X' || v == 'Ч') {
							ClearRow(6 + ((number_items + 1) * 2) + 1);
							ClearRow(6 + (((number_items + 1) * 2) + 2));
							break;
						}
					}
				}
				else {
					attron(A_UNDERLINE | COLOR_PAIR(1));
					mvprintw(rows - 4, (cols - 40) / 2, "У вас недостаточно золота для приобретения");
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
	mvprintw(4, (cols - 7) / 2, "ТОРГОВЕЦ");
	mvprintw(rows - 3, (cols - 15) / 2, "Ваши деньги - %d", hero->money);
}

