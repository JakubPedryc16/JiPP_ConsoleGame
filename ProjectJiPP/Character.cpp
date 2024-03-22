#include "Character.h"

Character::Character() {
	name = "Unknown";
	health = 100;
	damage = 20;
	shield = 0;
}

Character::Character(string _name, double _maxHealth, double _damage, double _shield) {
	name = _name;
	maxHealth = _maxHealth;
	health = _maxHealth;
	damage = _damage;
	shield = _shield;
}
Character::Character(Character & character) {
	name = character.name;
	maxHealth = character.maxHealth;
	health = character.health;
	damage = character.damage;
	shield = character.shield;
}
Character::~Character() { }

bool Character::useAbility(Character& target) { return false; }

void Character::attack(Character& target, double _damage) {
	if (getHealth() <= 0) return;
	target.getHurt(_damage);
	printBattleLog(target, "deals", _damage);
}

void Character::attack(Character& target) {
	if (getHealth() <= 0) return;
	target.getHurt(damage);
	printBattleLog(target, "deals", damage);
}

void Character::addMana(double value) { }


void Character::getHurt(double _damage) {
	double damageTemp = _damage;
	if (shield > 0) {
		if ((shield -= _damage) < 0) {
			damageTemp = -(shield);
			shield = 0;
			if ((health -= damageTemp) < 0) {
				health = 0;
			}
		}
	}
	else if ( (health -= _damage) < 0) {
		health = 0;
	}
}
void Character::printInfo() {
	cout << endl
		<< "Name: " << name << endl
		<< "\33[31m" << "Health: " << health << "\33[0m" << endl
		<< "\33[94m" << "Shield: " << shield << "\33[0m" << endl
		<< "Damage: " << damage << endl;
}
double Character::getHealth() {
	return health;
}
double Character::getMaxHealth() {
	return maxHealth;
}
string Character::getName() {
	return name;
}
double Character::getMaxMP() { return 0; }
double Character::getShield() {
	return shield;
}
double Character::getDamage() {
	return damage;
}

void Character::addShield(int value) {
	shield += value;
	cout << name << " got " << value << " shield" << endl << endl;
}

void Character::healHP(double value) {
	if ((health += value ) > maxHealth) {
		health = maxHealth;
	}
	cout << name << " restored " << value << " health" << endl
		 << getName() << " HP: " << getHealth() << endl << endl;
}

void Character::printBattleLog(Character& target, string action, double points) {
	cout << name << " " << action << " " << points << " points to " << target.getName() << endl;
	if ( target.getShield() <= 0) {
		cout << "\33[31m" << target.getName() <<  " HP: " << target.getHealth() << "\33[0m" << endl;
	}
	if ( target.getShield() > 0) {
		cout << "\33[94m" << target.getName() << " SHIELD: " <<  target.getShield() << "\33[0m" << endl;
	}
	cout << endl;
}

void Character::surrenderFight() {
	health = 0;
}

string Character::upgradeStat(int index, double percentage) { return ""; }

ostream& operator<<(ostream& lh, Character& rh)
{
	return lh << "Name: " << rh.name << endl
				<< "Health: " << rh.health << endl
				<< "Shield: " << rh.shield << endl
				<< "Damage: " << rh.damage << endl;
}
