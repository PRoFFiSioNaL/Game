#pragma once
//#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <stdint.h>
#include <stdbool.h>

struct Character {
    char race[10];
    int strenhgt;
    int agility;
    int intellect;
    int damage;
    int physical_armor;
    int magic_armor;
    int critical_chance;
    int dodge_chance;
    int fright_chance;
    int experience;
    int hp;
    int money;
    int level;
    int experience_for_levelup;
    float coefficient_experience;
    float coefficient_critical_damage;
    int equipment[11];
    int spells[5];
};

struct CharacterBattle {
    int current_hp;
    int intellect;
    int damage_melee;
    int damage_range;
    int damage_magic;
    int physical_armor;
    int magic_armor;
    int critical_chance; //ğåàëèçîâàòü ÷åğåç ğàíäîì äî 100, åñëè âûïàäåò äî øàíñà òî âûïîëíÿåòñÿ
    int dodge_chance;
    int fright_chance;
    int max_hp;
    float coefficient_critical_damage;
    int spells[5];
};

struct Enemy {
    char types[10];
    int damage_physical;
    int damage_magic;
    int physical_armor;
    int magic_armor;
    int critical_chance; 
    int dodge_chance;
    int magic_chance;
    int hp;
    float coefficient_critical_damage;
    int experience_for_killing;
    int money_for_killing;
};

int kLocationLength, kTraiderChance, kCaveChance, kTreasureChance;
float kGain;
int rows, cols;


void DrawBorder();
void DrawMenu();
void DrawSettings();
void DrawMenuCharacterRace();
void DrawMenuÑharacteristics();
void DrawSpell();
void DrawMenuMoney(struct Character* hero);
void DrawMenuDay(int i);
void DrawDistribution();
void DrawStatistics(struct Character hero);
void DrawMenuBattle(struct CharacterBattle hero, struct Enemy enemy);
void DrawMenuAction(struct CharacterBattle hero, struct Enemy enemy);
void ClearRow(int j);
void Setting(int choose_extend);
struct Character CreateCharacter();
int MiddlePhase(struct Character hero, int num_loc);
void Traid(struct Character* hero, int number_location);
struct Enemy CreateEnemy(int number_location);
struct CharacterBattle CalculationÑharacteristics(struct Character* hero);
int Battle(struct Character* hero, struct Enemy enemy);
int Load(int* num_loc, struct Character* hero);
void Save(int* num_loc, struct Character* hero);