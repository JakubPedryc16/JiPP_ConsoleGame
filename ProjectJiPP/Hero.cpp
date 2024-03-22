#include "Hero.h"

using namespace std;

Hero::Hero() : Character() {
	maxMP = 20;
	mana = 20;
	attackType = AbilityType::TRIPLE_ATTACK;
}

Hero::Hero(
	string _name,
	double _maxHealth,
	double _damage,
	double _maxMP,
	int _attackType,
	double _shield
	) : Character(_name, _maxHealth, _damage, _shield) {
	maxMP = _maxMP;
	mana = _maxMP;
	attackType = (AbilityType)_attackType;
}

Hero::~Hero() {
}

double Hero::getMaxMP()
{
	return maxMP;
}

bool Hero::useAbility(Character& target) {
	switch (attackType) {
	case AbilityType::TRIPLE_ATTACK:
		return tripleAttack(target);
		break;
	case AbilityType::SHIELD_UP:
		return shieldUp();
		break;
	case AbilityType::STEALTH_ATTACK:
		return stealthAttack(target);
		break;
	default:
		cout << "Ability Index out of range";
		return false;
	}
	return false;
}

void Hero::printInfo() {
	cout << endl
		<< "Name: " << name << endl
		<< "\33[31m" << "Health: " << health << "\33[0m" << endl
		<< "\33[94m" << "Shield: " << shield << "\33[0m" << endl
		<< "Damage: " << damage << endl
		<< "Mana: " << mana << " / " << maxMP << endl;
}

void Hero::addMana(double value) {
	if (mana += value > maxMP) {
		mana = maxMP;
	}
	cout << name << " restored " << value << " mana" << endl;
}

string Hero::upgradeStat(int index, double percentage) {
	string ret = "";
	double value;
	switch (index) {
	case 0:
		value = maxHealth * (1.0 + percentage);
		health += value - maxHealth;
		maxHealth = value;
		ret = "Health";
		break;
	case 1:
		damage *= (1.0 + percentage);
		ret = "Damage";
		break;
	case 2:
		value = maxMP * (1.0 + percentage);
		mana += value - maxMP;
		maxMP = value;
		ret = "Mana";
		break;
	default:
		ret = "Index out of range";
		break;
	}
	return ret;
}

bool Hero::tripleAttack(Character& target) {
	if (mana < 8) {
		cout << "Not Enough Mana" << endl;
		return false;
	}
	mana -= 8;

	target.getHurt(3*damage);

	printBattleLog(target, "deals", 3 * damage);
	return true;
}

bool Hero::shieldUp() {
	if (mana < 10) {
		cout << "Not Enough Mana" << endl;
		return false;
	}
	mana -= 10;
	addShield(50);
	return true;
}
bool Hero::stealthAttack(Character & target) {
	if (mana < 8) {
		cout << "Not Enough Mana" << endl;
		return false;
	}
	mana -= 8;

	target.getHurt(0.7 * damage);
	healHP(15); 
	printBattleLog(target, "deals", 0.7 * damage);

	return false;
}


