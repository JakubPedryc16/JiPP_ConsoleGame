#include "Enemy.h"
using namespace std;

Enemy::Enemy() : Character() {
	abilityNum = 0;
}

Enemy::Enemy(
	string _name,
	double _maxHealth,
	double _damage,
	int _abilityNum,
	double _shield
) : Character(_name, _maxHealth, _damage, _shield)
{
	abilityNum = _abilityNum;
}

Enemy::~Enemy() {
}
/*
void Enemy::printInfo() {
	cout << endl
		<< "Name: " << name << endl
		<< "Health: " << health << endl
		<< "Shield: " << shield << endl
		<< "Damage: " << damage << endl;
}
*/
void Enemy::attack(Character& target) {
	if (getHealth() <= 0) return;
	//srand((unsigned)time(NULL));
	unsigned random = (rand() % 11);
	if (random <= 8) {
		target.getHurt(damage);
		printBattleLog(target, "deals", damage);
	}
	else {
		useAbility(target);
	}
}

void Enemy::attack(Character& target, double _damage) {
	if (getHealth() <= 0) return;
	target.getHurt(_damage);
	printBattleLog(target, "deals", _damage);
}

bool Enemy::useAbility(Character& target) {
	switch (abilityNum) {
	case 0:
		return doubleAttack(target);
		break;
	case 1:
		return shieldUp();
		break;
	case 2:
		return bloodyBite(target);
		break;
	default:
		cout << "Ability Error";
		return false;
	}
	return false;
}
bool Enemy::doubleAttack(Character& target) {
	attack(target, 1.5 * damage);
	//target.getHurt(1.5 * damage);

	//printBattleLog(target, "deals", 1.5 * damage);
	return true;
}

bool Enemy::shieldUp() {

	addShield(25);
	//printBattleLog(*this, "gets shield", shield);
	return true;
}
bool Enemy::bloodyBite(Character& target) {
	attack(target, 0.7 * damage);
	//target.getHurt(0.7 * damage);
	healHP(0.7 * damage);
	//printBattleLog(target, "deals", 0.7 * damage);
	//printBattleLog(*this, "heals", 0.7 * damage);
	return true;
}


