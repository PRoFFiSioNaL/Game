#include "main.h"

typedef struct Character Character;
typedef struct CharacterBattle CharacterBattle;
typedef struct Enemy Enemy;

enum Action {
	hit_melee,
	hit_range,
	hit_magic,
	cast_spell,
	health_potion,
	run_away
} action;

CharacterBattle CalculationСharacteristics(Character* hero) {
	CharacterBattle character_battle = { 0 };
	character_battle.max_hp = hero->hp + (hero->strenhgt * 2);
	character_battle.physical_armor = hero->physical_armor + (hero->agility * 0.5);
	character_battle.magic_armor = hero->magic_armor + (hero->intellect * 0.5);
	character_battle.damage_melee = hero->damage + hero->strenhgt;
	character_battle.damage_range = hero->damage + hero->agility;
	character_battle.damage_magic = hero->damage + hero->intellect;
	character_battle.intellect = hero->intellect;
	character_battle.dodge_chance = hero->dodge_chance;
	character_battle.critical_chance = hero->critical_chance;
	character_battle.fright_chance = hero->fright_chance;
    for (int item = 0; item < 10; ++item) {
		int rarity_item = hero->equipment[item];
		switch (item)
		{
		case(0):
			if (rarity_item == 1) character_battle.damage_melee += 5;
			else if (rarity_item == 2) character_battle.damage_melee += 10;
			else if (rarity_item == 3) character_battle.damage_melee += 20;
			break;
		case(1):
			if (rarity_item == 1) character_battle.damage_range += 5;
			else if (rarity_item == 2) character_battle.damage_range += 10;
			else if (rarity_item == 3) character_battle.damage_range += 20;
			break;
		case(2):
			if (rarity_item == 1) character_battle.damage_magic += 5;
			else if (rarity_item == 2) character_battle.damage_magic += 10;
			else if (rarity_item == 3) character_battle.damage_magic += 20;
			break;
		case(3):
			if (rarity_item == 1) character_battle.damage_range += 4, character_battle.physical_armor += 2;
			else if (rarity_item == 2) character_battle.damage_range += 8, character_battle.physical_armor += 4;
			else if (rarity_item == 3) character_battle.damage_range += 12, character_battle.physical_armor += 6;
			break;
		case(4):
			if (rarity_item == 1) character_battle.damage_melee += 4, character_battle.max_hp += 8;
			else if (rarity_item == 2) character_battle.damage_melee += 8, character_battle.max_hp += 16;
			else if (rarity_item == 3) character_battle.damage_melee += 12, character_battle.max_hp += 24;
			break;
		case(5):
			if (rarity_item == 1) character_battle.physical_armor += 3, character_battle.max_hp += 5;
			else if (rarity_item == 2) character_battle.physical_armor += 5, character_battle.max_hp += 7;
			else if (rarity_item == 3) character_battle.physical_armor += 7, character_battle.max_hp += 10;
			break;
		case(6):
			if (rarity_item == 1) character_battle.dodge_chance += 5;
			else if (rarity_item == 2) character_battle.dodge_chance += 15;
			else if (rarity_item == 3) character_battle.dodge_chance += 25;
			break;
		case(7):
			if (rarity_item == 1) character_battle.critical_chance += 5;
			else if (rarity_item == 2) character_battle.critical_chance += 15;
			else if (rarity_item == 3) character_battle.critical_chance += 25;
			break;
		case(8):
			if (rarity_item == 1) character_battle.damage_magic += 4, character_battle.magic_armor += 2;
			else if (rarity_item == 2) character_battle.damage_magic += 8, character_battle.magic_armor += 4;
			else if (rarity_item == 3) character_battle.damage_magic += 12, character_battle.magic_armor += 6;
			break;
		case(9):
			if (rarity_item == 1) character_battle.magic_armor += 3, character_battle.max_hp += 5;
			else if (rarity_item == 2) character_battle.magic_armor += 5, character_battle.max_hp += 7;
			else if (rarity_item == 3) character_battle.magic_armor += 7, character_battle.max_hp += 10;
			break;
		default:
			break;
		}
    }
	character_battle.current_hp = character_battle.max_hp;
	return character_battle;
}

int Battle(Character* hero, Enemy enemy) {
	char c, v;
	srand(time(NULL));
	CharacterBattle character_battle = CalculationСharacteristics(hero);
	clear();
	DrawMenuBattle(character_battle, enemy);
	int choose_action, choose_spell, is_enemy_dead = 0, is_hero_dead = 0, critical_hit, dodge_hit, hit, magic_hit, fright_hit;
	int possible_spell[5] = { -1, -1, -1, -1, -1 };
	int use_spell[5] = { -1, -1, -1, -1, -1 };
	int status[5] = { -1, -1, -1, -1, -1 };
	while (1) {
		for (int i = 0; i < 5; ++i) {
			status[i]--;
			if (use_spell[i] != -1) {
				switch (use_spell[i])
				{
				case (0):
					if (status == 0) character_battle.dodge_chance -= 50;
					break;
				case (1):
					if (status == 0) enemy.physical_armor -= 3 + character_battle.intellect * 0.2, enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
					break;
				case (3):
					if (status == 0) {
						character_battle.damage_melee -= 2 + character_battle.intellect * 0.5;
						character_battle.damage_range -= 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic -= 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor -= 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor -= 2 + character_battle.intellect * 0.5;
					}
					break;
				default:
					break;
				}
			}
		}
		DrawMenuBattle(character_battle, enemy);
		DrawMenuAction(character_battle, enemy);
		c = getch();
		while ((c < 49) || (c > 54)) c = getch();
		choose_action = c - 48;
		bool repeat_action = false;
		if (choose_action == 1) action = hit_melee;
		else if (choose_action == 2) action = hit_range;
		else if (choose_action == 3) action = hit_magic;
		else if (choose_action == 4) action = cast_spell;
		else if (choose_action == 5) action = health_potion;
		else action = run_away;
		switch (action)
		{
		case hit_melee:;
			dodge_hit = 1 + (rand() % 100);
			if (dodge_hit <= enemy.dodge_chance) {
				attroff(A_BOLD);
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(13, (cols - 21) / 2, "Вы промахнулись атакой");
				attroff(A_UNDERLINE);
			}
			else {
				critical_hit = 1 + (rand() % 100);
				if (critical_hit <= character_battle.critical_chance) hit = (character_battle.damage_melee - enemy.physical_armor) * character_battle.coefficient_critical_damage;
				else hit = character_battle.damage_melee - enemy.physical_armor;
				if (hit < 0) hit = 0;
				attroff(A_BOLD);
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(4) | A_UNDERLINE);
				mvprintw(13, (cols - 26) / 2, "Вы наносите удар в %d урона", hit);
				attroff(A_UNDERLINE);
				enemy.hp = (enemy.hp > hit) ? enemy.hp - hit : 0;
				if (enemy.hp == 0) {
					attroff(A_BOLD);
					ClearRow(15);
					attron(COLOR_PAIR(1) | A_UNDERLINE);
					mvprintw(15, (cols - 9) / 2, "Враг мертв", hit);
					attroff(A_UNDERLINE);
					is_enemy_dead = 1;
				}
			}
			break;
		case hit_range:;
			dodge_hit = 1 + (rand() % 100);
			if (dodge_hit <= enemy.dodge_chance) {
				attroff(A_BOLD);
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(13, (cols - 21) / 2, "Вы промахнулись атакой");
				attroff(A_UNDERLINE);
			}
			else {
				critical_hit = 1 + (rand() % 100);
				if (critical_hit <= character_battle.critical_chance) hit = (character_battle.damage_range - enemy.physical_armor) * character_battle.coefficient_critical_damage;
				else hit = character_battle.damage_range - enemy.physical_armor;
				if (hit < 0) hit = 0;
				attroff(A_BOLD);
				ClearRow(13);
				attron(COLOR_PAIR(4) | A_UNDERLINE);
				mvprintw(13, (cols - 26) / 2, "Вы наносите удар в %d урона", hit);
				attroff(A_UNDERLINE);
				enemy.hp = (enemy.hp > hit) ? enemy.hp - hit : 0;
				if (enemy.hp == 0) {
					attroff(A_BOLD);
					ClearRow(15);
					ClearRow(15);
					attron(COLOR_PAIR(1) | A_UNDERLINE);
					mvprintw(15, (cols - 9) / 2, "Враг мертв", hit);
					attroff(A_UNDERLINE);
					is_enemy_dead = 1;
				}
			}
			break;
		case hit_magic:;
			dodge_hit = 1 + (rand() % 100);
			if (dodge_hit <= enemy.dodge_chance) {
				attroff(A_BOLD);
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(22) | A_UNDERLINE);
				mvprintw(13, (cols - 21) / 2, "Вы промахнулись атакой");
				attroff(A_UNDERLINE);
			}
			else {
				critical_hit = 1 + (rand() % 100);
				if (critical_hit <= character_battle.critical_chance) hit = (character_battle.damage_magic - enemy.physical_armor) * character_battle.coefficient_critical_damage;
				else hit = character_battle.damage_magic - enemy.physical_armor;
				if (hit < 0) hit = 0;
				attroff(A_BOLD);
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(4) | A_UNDERLINE);
				mvprintw(13, (cols - 26) / 2, "Вы наносите удар в %d урона", hit);
				attroff(A_UNDERLINE);
				enemy.hp = (enemy.hp > hit) ? enemy.hp - hit : 0;
				if (enemy.hp == 0) {
					attroff(A_BOLD);
					ClearRow(15);
					attron(COLOR_PAIR(1) | A_UNDERLINE);
					mvprintw(15, (cols - 9) / 2, "Враг мертв", hit);
					attroff(A_UNDERLINE);
					is_enemy_dead = 1;
				}
			}
			break;
		case cast_spell:;
			int j = 0;
			clear();
			DrawMenuBattle(character_battle, enemy);
			for (int i = 0; i < 5; ++i) {
				if (hero->spells[i] == 1) {
					switch (i)
					{
					case(0):
						attroff(A_UNDERLINE);
						attron(COLOR_PAIR(2) | A_BOLD);
						possible_spell[j] = 0;
						mvprintw(9 + ((++j) * 2), (cols - 13) / 2, "%d - Ослепление", j);
						mvprintw(10 + (j * 2), (cols - 58) / 2, "Противник будет промахиватся с шансом 50%% в течении 2 ходов");
						break;
					case(1):
						attroff(A_UNDERLINE);
						attron(COLOR_PAIR(2) | A_BOLD);
						possible_spell[j] = 1;
						mvprintw(9 + ((++j) * 2), (cols - 13) / 2, "%d - Разрушение", j);
						mvprintw(10 + (j * 2), (cols - 41) / 2, "Понижает броню противнка на%2.0f на три хода", 3 + (character_battle.intellect * 0.2));
						break;
					case(2):
						attroff(A_UNDERLINE);
						attron(COLOR_PAIR(2) | A_BOLD);
						possible_spell[j] = 2;
						mvprintw(9 + ((++j) * 2), (cols - 10) / 2, "%d - Лечение", j);
						mvprintw(10 + (j * 2), (cols - 37) / 2, "Восстанавливает себе %d очков здоровья", 3 + character_battle.intellect);
						break;
					case(3):
						attroff(A_UNDERLINE);
						attron(COLOR_PAIR(2) | A_BOLD);
						possible_spell[j] = 3;
						mvprintw(9 + ((++j) * 2), (cols - 10) / 2, "%d - Клич", j);
						mvprintw(10 + (j * 2), (cols - 45) / 2, "Повышает свою защиту и атаку на%2.0f на 5 ходов", 2 + (character_battle.intellect * 0.5));
						break;
					case(4):
						attroff(A_UNDERLINE);
						attron(COLOR_PAIR(2) | A_BOLD);
						possible_spell[j] = 4;
						mvprintw(9 + ((++j) * 2), (cols - 10) / 2, "%d - Ярость", j);
						mvprintw(10 + (j * 2), (cols - 45) / 2, "Понижает свою защиту на 3, но повышает атаку на 50%%");
						break;
					default:
						break;
					}
				}
			}
			v = getch();
			while ((v < 49) || (v > (j + 48))) v = getch();
			int choose_spell = v - 48;
			if (choose_spell == 1) { //если выбрали 1
				switch (possible_spell[0])  //в этом массиве лежат выведенные спелы, под 0 индексом - 1 выведенный
				{
				case(0): //если это 1 - это ослепление
					if (use_spell[0] == -1) {//если ослепление не кастовалось
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Ослепление использовано!");
						attroff(A_UNDERLINE);
						status[0] = 2;
						character_battle.dodge_chance += 50;
						use_spell[0] = 0;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);

					}
					break;
				case(1):
					if (use_spell[1] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Разрушение использовано!");
						attroff(A_UNDERLINE);
						status[1] = 3;
						enemy.physical_armor -= 3 + character_battle.intellect * 0.2;
						enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
						use_spell[1] = 1;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(2):
					if (use_spell[2] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 20) / 2, "Лечение использовано!");
						attroff(A_UNDERLINE);
						status[2] = 0;
						character_battle.current_hp = ((character_battle.current_hp + 10 + character_battle.intellect) < character_battle.max_hp) ? character_battle.current_hp + 10 + character_battle.intellect : character_battle.max_hp;
						use_spell[2] = 2;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(3):
					if (use_spell[3] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 16) / 2, "Клич использован!");
						attroff(A_UNDERLINE);
						status[3] = 5;
						character_battle.damage_melee += 2 + character_battle.intellect * 0.5;
						character_battle.damage_range += 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic += 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor += 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor += 2 + character_battle.intellect * 0.5;
						use_spell[3] = 3;								use_spell[3] = 3;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(4):
					if (use_spell[4] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 19) / 2, "Ярость использована!");
						attroff(A_UNDERLINE);
						status[4] = 0;
						character_battle.damage_melee *= 1.5;
						character_battle.damage_range *= 1.5;
						character_battle.damage_magic *= 1.5;
						character_battle.physical_armor -= 3;
						character_battle.magic_armor -= 3;	
						use_spell[4] = 4;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				default:
					break;
				}
			}
			else if (choose_spell == 2) { //если выбрали 2
				switch (possible_spell[1])  //в этом массиве лежат выведенные спелы, под 1 индексом - 2 выведенный
				{
				case(0): //если это 1 - это ослепление
					if (use_spell[0] == -1) {//если ослепление не кастовалось
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Ослепление использовано!");
						attroff(A_UNDERLINE);
						status[0] = 2;
						character_battle.dodge_chance += 50;
						use_spell[0] = 0;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);

					}
					break;
				case(1):
					if (use_spell[1] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Разрушение использовано!");
						attroff(A_UNDERLINE);
						status[1] = 3;
						enemy.physical_armor -= 3 + character_battle.intellect * 0.2;
						enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
						use_spell[1] = 1;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(2):
					if (use_spell[2] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 20) / 2, "Лечение использовано!");
						attroff(A_UNDERLINE);
						status[2] = 0;
						character_battle.current_hp = ((character_battle.current_hp + 10 + character_battle.intellect) < character_battle.max_hp) ? character_battle.current_hp + 10 + character_battle.intellect : character_battle.max_hp;
						use_spell[2] = 2;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(3):
					if (use_spell[3] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 16) / 2, "Клич использован!");
						attroff(A_UNDERLINE);
						status[3] = 5;
						character_battle.damage_melee += 2 + character_battle.intellect * 0.5;
						character_battle.damage_range += 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic += 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor += 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor += 2 + character_battle.intellect * 0.5;
						use_spell[3] = 3;								use_spell[3] = 3;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(4):
					if (use_spell[4] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 19) / 2, "Ярость использована!");
						attroff(A_UNDERLINE);
						status[4] = 0;
						character_battle.damage_melee *= 1.5;
						character_battle.damage_range *= 1.5;
						character_battle.damage_magic *= 1.5;
						character_battle.physical_armor -= 3;
						character_battle.magic_armor -= 3;	
						use_spell[4] = 4;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				default:
					break;
				}
			}
			else if (choose_spell == 3) {
				switch (possible_spell[2])
				{
				case(0): //если это 1 - это ослепление
					if (use_spell[0] == -1) {//если ослепление не кастовалось
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Ослепление использовано!");
						attroff(A_UNDERLINE);
						status[0] = 2;
						character_battle.dodge_chance += 50;
						use_spell[0] = 0;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);

					}
					break;
				case(1):
					if (use_spell[1] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Разрушение использовано!");
						attroff(A_UNDERLINE);
						status[1] = 3;
						enemy.physical_armor -= 3 + character_battle.intellect * 0.2;
						enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
						use_spell[1] = 1;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(2):
					if (use_spell[2] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 20) / 2, "Лечение использовано!");
						attroff(A_UNDERLINE);
						status[2] = 0;
						character_battle.current_hp = ((character_battle.current_hp + 10 + character_battle.intellect) < character_battle.max_hp) ? character_battle.current_hp + 10 + character_battle.intellect : character_battle.max_hp;
						use_spell[2] = 2;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(3):
					if (use_spell[3] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 16) / 2, "Клич использован!");
						attroff(A_UNDERLINE);
						status[3] = 5;
						character_battle.damage_melee += 2 + character_battle.intellect * 0.5;
						character_battle.damage_range += 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic += 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor += 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor += 2 + character_battle.intellect * 0.5;
						use_spell[3] = 3;								use_spell[3] = 3;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(4):
					if (use_spell[4] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 19) / 2, "Ярость использована!");
						attroff(A_UNDERLINE);
						status[4] = 0;
						character_battle.damage_melee *= 1.5;
						character_battle.damage_range *= 1.5;
						character_battle.damage_magic *= 1.5;
						character_battle.physical_armor -= 3;
						character_battle.magic_armor -= 3;	
						use_spell[4] = 4;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				default:
					break;
				}
			}
			else if (choose_spell == 4) {
				switch (possible_spell[5])
				{
				case(0): //если это 1 - это ослепление
					if (use_spell[0] == -1) {//если ослепление не кастовалось
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Ослепление использовано!");
						attroff(A_UNDERLINE);
						status[0] = 2;
						character_battle.dodge_chance += 50;
						use_spell[0] = 0;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);

					}
					break;
				case(1):
					if (use_spell[1] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Разрушение использовано!");
						attroff(A_UNDERLINE);
						status[1] = 3;
						enemy.physical_armor -= 3 + character_battle.intellect * 0.2;
						enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
						use_spell[1] = 1;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(2):
					if (use_spell[2] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 20) / 2, "Лечение использовано!");
						attroff(A_UNDERLINE);
						status[2] = 0;
						character_battle.current_hp = ((character_battle.current_hp + 10 + character_battle.intellect) < character_battle.max_hp) ? character_battle.current_hp + 10 + character_battle.intellect : character_battle.max_hp;
						use_spell[2] = 2;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(3):
					if (use_spell[3] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 16) / 2, "Клич использован!");
						attroff(A_UNDERLINE);
						status[3] = 5;
						character_battle.damage_melee += 2 + character_battle.intellect * 0.5;
						character_battle.damage_range += 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic += 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor += 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor += 2 + character_battle.intellect * 0.5;
						use_spell[3] = 3;								use_spell[3] = 3;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(4):
					if (use_spell[4] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 19) / 2, "Ярость использована!");
						attroff(A_UNDERLINE);
						status[4] = 0;
						character_battle.damage_melee *= 1.5;
						character_battle.damage_range *= 1.5;
						character_battle.damage_magic *= 1.5;
						character_battle.physical_armor -= 3;
						character_battle.magic_armor -= 3;	
						use_spell[4] = 4;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				default:
					break;
				}
			}
			else if (choose_spell == 5) {
				switch (possible_spell[4])
				{
				case(0): //если это 1 - это ослепление
					if (use_spell[0] == -1) {//если ослепление не кастовалось
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Ослепление использовано!");
						attroff(A_UNDERLINE);
						status[0] = 2;
						character_battle.dodge_chance += 50;
						use_spell[0] = 0;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);

					}
					break;
				case(1):
					if (use_spell[1] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 23) / 2, "Разрушение использовано!");
						attroff(A_UNDERLINE);
						status[1] = 3;
						enemy.physical_armor -= 3 + character_battle.intellect * 0.2;
						enemy.magic_armor -= 3 + character_battle.intellect * 0.2;
						use_spell[1] = 1;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(2):
					if (use_spell[2] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 20) / 2, "Лечение использовано!");
						attroff(A_UNDERLINE);
						status[2] = 0;
						character_battle.current_hp = ((character_battle.current_hp + 10 + character_battle.intellect) < character_battle.max_hp) ? character_battle.current_hp + 10 + character_battle.intellect : character_battle.max_hp;
						use_spell[2] = 2;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(3):
					if (use_spell[3] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 16) / 2, "Клич использован!");
						attroff(A_UNDERLINE);
						status[3] = 5;
						character_battle.damage_melee += 2 + character_battle.intellect * 0.5;
						character_battle.damage_range += 2 + character_battle.intellect * 0.5;
						character_battle.damage_magic += 2 + character_battle.intellect * 0.5;
						character_battle.physical_armor += 2 + character_battle.intellect * 0.5;
						character_battle.magic_armor += 2 + character_battle.intellect * 0.5;
						use_spell[3] = 3;								use_spell[3] = 3;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				case(4):
					if (use_spell[4] == -1) {
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(4) | A_UNDERLINE);
						mvprintw(13, (cols - 19) / 2, "Ярость использована!");
						attroff(A_UNDERLINE);
						status[4] = 0;
						character_battle.damage_melee *= 1.5;
						character_battle.damage_range *= 1.5;
						character_battle.damage_magic *= 1.5;
						character_battle.physical_armor -= 3;
						character_battle.magic_armor -= 3;	
						use_spell[4] = 4;
					}
					else {
						repeat_action = true;
						for (int i = 0; i < j; ++i) {
							ClearRow(11 + (i * 2));
							ClearRow(11 + (i * 2) + 1);
						}
						ClearRow(13);
						ClearRow(15);
						attron(COLOR_PAIR(1) | A_UNDERLINE);
						mvprintw(13, (cols - 65) / 2, "Вы уже использовали это заклинание в бою, выберите другое действие");
						attroff(A_UNDERLINE);
					}
					break;
				default:
					break;
				}
			}
			break;
		case health_potion:
			if (hero->equipment[10] > 0) {
				character_battle.current_hp = ((character_battle.current_hp + 15) < character_battle.max_hp) ? character_battle.current_hp + 15 : character_battle.max_hp;
				ClearRow(13);
				attron(COLOR_PAIR(4) | A_UNDERLINE);
				mvprintw(13, (cols - 65) / 2, "Вы выпили зелье здоровья!");
				attroff(A_UNDERLINE);
				hero->equipment[10]--;
			}
			else {
				repeat_action = true;
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(1) | A_UNDERLINE);
				mvprintw(13, (cols - 49) / 2, "У вас нет зелья здоровья, выберите другое действие");
				attroff(A_UNDERLINE);
			}
			break;
		case run_away:
			if (strcmp(enemy.types, "энт") == 0) {
				ClearRow(13);
				ClearRow(15);
				attron(COLOR_PAIR(1) | A_UNDERLINE);
				mvprintw(13, (cols - 65) / 2, "Вы не можете убежать от главного босса");
				attroff(A_UNDERLINE);
				repeat_action = true;
			}
			int lost_money = rand() % 50;
			clear();
			attron(COLOR_PAIR(8));
			DrawBorder();
			attron(COLOR_PAIR(1) | A_UNDERLINE);
			mvprintw(rows / 2, (cols - 34) / 2, "Во время бегства вы выронили - %d", (hero->money > lost_money) ? lost_money : hero->money);
			attroff(A_UNDERLINE);
			hero->money = (hero->money > lost_money) ? hero->money - lost_money : 0;
			getch();
			return;
			break;
		default:
			break;
		}
		if (repeat_action == true) continue;
		if (is_enemy_dead == 1) {
			getch();
			clear();
			attron(COLOR_PAIR(7));
			DrawBorder();
			attron(COLOR_PAIR(2) | A_UNDERLINE);
			mvprintw(rows / 2, (cols - 44) / 2, "Вы победили и получаете %d золота и %d опыта", enemy.money_for_killing, enemy.experience_for_killing);
			attroff(A_UNDERLINE);
			getch();
			hero->money += enemy.money_for_killing;
			hero->experience += enemy.experience_for_killing * hero->coefficient_experience;
			if (strcmp(enemy.types, "энт") == 0) return 2;
			return 1;
		}

		fright_hit = 1 + (rand() % 100);
		if (fright_hit <= character_battle.fright_chance) {
			ClearRow(15);
			attron(COLOR_PAIR(4) | A_UNDERLINE);
			mvprintw(15, (cols - 33) / 2, "Противник напуган и пропускает ход");
			attroff(A_UNDERLINE);
			continue;
		}
		//-------------------------------------УДАР ВРАГА---------------------------------------

		dodge_hit = 1 + (rand() % 100);
		if (dodge_hit <= character_battle.dodge_chance) {
			ClearRow(15);
			attron(COLOR_PAIR(4) | A_UNDERLINE);
			mvprintw(15, (cols - 24) / 2, "Враг промахивается атакой");
			attroff(A_UNDERLINE);
		}
		else {
			critical_hit = 1 + (rand() % 100);
			magic_hit = 1 + (rand() % 100);
			if (magic_hit <= enemy.magic_chance) {
				if (critical_hit <= character_battle.critical_chance) hit = (enemy.damage_magic - character_battle.magic_armor) * enemy.coefficient_critical_damage;
				else hit = enemy.damage_magic - character_battle.magic_armor;
			}
			else {
				if (critical_hit <= character_battle.critical_chance) hit = (enemy.damage_physical - character_battle.physical_armor) * enemy.coefficient_critical_damage;
				else hit = enemy.damage_physical - character_battle.physical_armor;
			}
			if (hit < 0) hit = 0;
			ClearRow(15);
			attron(COLOR_PAIR(1) | A_UNDERLINE);
			mvprintw(15, (cols - 26) / 2, "Вам наносят удар в %d урона", hit);
			attroff(A_UNDERLINE);
			character_battle.current_hp = (character_battle.current_hp > hit) ? character_battle.current_hp - hit : 0;
			if (character_battle.current_hp == 0) {
				is_hero_dead = 1;
			}
		}

		if (is_hero_dead == 1) {
			attron(COLOR_PAIR(8));
			DrawBorder();
			attron(COLOR_PAIR(1) | A_UNDERLINE);
			mvprintw(rows / 2, (cols - 38) / 2, "Вы погибли", hit);
			attroff(A_UNDERLINE);
			return 0;
		}
	}
}

void DrawMenuBattle(CharacterBattle hero, Enemy enemy) {
	ClearRow(rows - 3);
	attroff(A_UNDERLINE | A_BOLD);
	attron(COLOR_PAIR(9));
	DrawBorder();
	attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
	mvprintw(4, (cols - 7) / 2, "%s", enemy.types);
	mvprintw(rows - 3, (cols - 40) / 2, "Ваше здоровье %d | Здоровье противника %d", hero.current_hp, enemy.hp);
}

void DrawMenuAction(CharacterBattle hero, Enemy enemy) {
	attron(COLOR_PAIR(20) | A_BOLD | A_UNDERLINE);
	mvprintw(6, (cols - 74) / 2, "Ваш ход");
	attron(COLOR_PAIR(2));
	attroff(A_UNDERLINE);
	mvprintw(6, (cols - 74) / 2, "1 - Удар мечом %d урона", hero.damage_melee);
	mvprintw(7, (cols - 74) / 2, "2 - Выстрел из лука %d урона", hero.damage_range);
	mvprintw(8, (cols - 74) / 2, "3 - Выстрел из посоха %d урона", hero.damage_magic);
	mvprintw(9, (cols - 74) / 2, "4 - Использовать заклинание");
	mvprintw(10, (cols - 74) / 2, "5 - Выпить зелье здоровья");
	mvprintw(11, (cols - 74) / 2, "6 - Сбежать с поля битвы");
	attroff(A_BOLD);
}