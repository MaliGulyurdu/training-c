#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void powerofheroes();
void calculate();
void hero_information();

struct heroes {
	int hp;
	int ad;
	int armor;
	int attack_speed;
	int dps;
	int reduce_dmg;
	int true_dmg;
}truza, veykun; // Truza: 1 , Veykun:2

int main() {
	srand(time(0));

	int tt, vt;
	powerofheroes();
	calculate();
	// True damage calculating
	truza.true_dmg = (truza.dps) - (truza.dps) * (truza.reduce_dmg) / 100;
	veykun.true_dmg = (veykun.dps) - (veykun.dps) * (veykun.reduce_dmg) / 100;

	tt = truza.true_dmg;
	vt = veykun.true_dmg;
	hero_information();

	printf("Control");

	return 0;
}


void powerofheroes() {

	truza.hp = rand() % 2000 + 1000;
	truza.ad = rand() % 200 + 100;
	truza.armor = rand() % 40 + 20;
	truza.attack_speed = rand() % 5 + 1;
	veykun.hp = rand() % 2000 + 1000;
	veykun.ad = rand() % 200 + 100;
	veykun.armor = rand() % 40 + 20;
	veykun.attack_speed = rand() % 5 + 1;
}

void calculate() {
	truza.reduce_dmg = log(truza.armor);
	veykun.reduce_dmg = log(veykun.armor);
	truza.dps = (truza.attack_speed) * (truza.ad);
	veykun.dps = (veykun.attack_speed) * (veykun.ad);
}

void hero_information() {
	FILE* truzaf;
	FILE* veykunf;
	truzaf = fopen("truza_info.txt", "w");
	fprintf(truzaf, "Health Points:%d\nDPS:%d\nStrenght:%d\nDamage Dealt:%d", truza.hp, truza.dps, truza.reduce_dmg, truza.true_dmg);
	fclose(truzaf);
	veykunf = fopen("veykun_info.txt", "w");
	fprintf(veykunf, "Health Points:%d\nDPS:%d\nStrenght:%d\nDamage Dealt:%d", veykun.hp, veykun.dps, veykun.reduce_dmg, veykun.true_dmg);
	fclose(veykunf);
}
