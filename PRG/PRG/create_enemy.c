#include "main.h"

typedef struct Enemy Enemy;

enum Opponent { 
	wolf, 
	goblin, 
	robber, 
	khajiit
} opponent;

Enemy CreateEnemy(int number_location) {
	srand(time(NULL));
	Enemy enemy = { 0 };
	if (number_location >= kLocationLength) {
		strcpy(enemy.types, "энт");
		enemy.damage_physical = 10 + (number_location * kGain * 1.25);
		enemy.damage_magic = 12 + (number_location * kGain);
		enemy.physical_armor = 1 + (number_location * kGain * 1.25);
		enemy.magic_armor = 1 + (number_location * kGain * 0.85);
		enemy.critical_chance = 15; 
		enemy.dodge_chance = 15;
		enemy.magic_chance = 80;
		enemy.hp = 20 + (number_location * kGain * 2.5);
		enemy.coefficient_critical_damage = 2.5;
		enemy.experience_for_killing = 100 + (number_location * kGain * 0.85);
		enemy.money_for_killing = 500 + (number_location * kGain * 5);
	}
	else {
		int choose_opponent = rand() % 4;
		if (choose_opponent == 0) opponent = wolf;
		else if (choose_opponent == 1) opponent = goblin;
		else if (choose_opponent == 2) opponent = robber;
		else if (choose_opponent == 3) opponent = khajiit;
		switch (opponent)
		{
		case wolf:
			strcpy(enemy.types, "волк");
			enemy.damage_physical = 7 + (number_location * kGain);
			enemy.physical_armor = 0 + (number_location * kGain * 0.5);
			enemy.magic_armor = 0 + (number_location * kGain * 0.3);
			enemy.critical_chance = 15; 
			enemy.dodge_chance = 5;
			enemy.magic_chance = 0;
			enemy.hp = 20 + (number_location * kGain * 1.65);
			enemy.coefficient_critical_damage = 1.7;
			enemy.experience_for_killing = 5 + (number_location * kGain * 0.85);
			enemy.money_for_killing = 30 + (number_location * kGain * 5);
			break;
		case goblin:
			strcpy(enemy.types, "гоблин");
			enemy.damage_physical = 4 + (number_location * kGain);
			enemy.damage_magic = 6 + (number_location * kGain);
			enemy.physical_armor = 3 + (number_location * kGain * 0.85);
			enemy.magic_armor = 1 + (number_location * kGain * 0.5);
			enemy.critical_chance = 20; 
			enemy.dodge_chance = 5;
			enemy.magic_chance = 20;
			enemy.hp = 25 + (number_location * kGain * 1.65);
			enemy.coefficient_critical_damage = 1.5;
			enemy.experience_for_killing = 7 + (number_location * kGain * 0.85);
			enemy.money_for_killing = 70 + (number_location * kGain * 5);
			break;
		case robber:
			strcpy(enemy.types, "бандит");
			enemy.damage_physical = 10 + (number_location * kGain);
			enemy.damage_magic = 7 + (number_location * kGain);
			enemy.physical_armor = 3 + (number_location * kGain);
			enemy.magic_armor = 2 + (number_location * kGain * 0.5);
			enemy.critical_chance = 20; 
			enemy.dodge_chance = 10;
			enemy.magic_chance = 30;
			enemy.hp = 30 + (number_location * kGain * 2.5);
			enemy.coefficient_critical_damage = 1.5;
			enemy.experience_for_killing = 15 + (number_location * kGain * 0.85);
			enemy.money_for_killing = 150 + (number_location * kGain * 5);
			break;
		case khajiit:
			strcpy(enemy.types, "каджит");
			enemy.damage_physical = 6 + (number_location * kGain);
			enemy.damage_magic = 9 + (number_location * kGain);
			enemy.physical_armor = 3 + (number_location * kGain * 0.85);
			enemy.magic_armor = 5 + (number_location * kGain);
			enemy.critical_chance = 30 + (number_location * kGain * 0.85);
			enemy.dodge_chance = 20;
			enemy.magic_chance = 60;
			enemy.hp = 20 + (number_location * kGain * 0.85);
			enemy.coefficient_critical_damage = 2;
			enemy.experience_for_killing = 15 + (number_location * kGain * 0.85);
			enemy.money_for_killing = 150 + (number_location * kGain * 10);
			break;
		default:
			break;
		}
	}
	return enemy;
}