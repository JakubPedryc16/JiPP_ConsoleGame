#pragma once
#include "Character.h"

using namespace std;

/**
 * @brief Type of special ability
*/
enum class AbilityType {
	TRIPLE_ATTACK,
	SHIELD_UP,
	STEALTH_ATTACK
};

/**
 * @brief hero life being
*/
class Hero : public Character{
protected:
	double mana;
	double maxMP;
	AbilityType attackType;
public:

	/**
	 * @brief Default constructor
	*/
	Hero();

	/**
	 * @brief Constructor with parameters
	 * @param _name - name of Hero
	 * @param _maxHealth - max Health of hero
	 * @param _damage - damage of hero
	 * @param maxMP - max mana points of hero
	 * @param _attackType - type of hero ability (enum AbilityType)
	 * @param _shield - shield (armour) of hero
	*/
	Hero(string _name, double _maxHealth, double _damage, double maxMP, int _attackType,double _shield = 0 );

	~Hero();

	/**
	 * @brief Get max mana points value
	 * @return max mana points value
	*/
	double getMaxMP();

	/**
	 * @brief Use special ability
	 * @param target - target on which the ability will be used
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	bool useAbility(Character& target) override;

	/**
	 * @brief Prints the informations about this object on screen
	*/
	void printInfo() override;

	/**
	 * @brief Adds mana points
	 * @param value - value of mana points to add
	*/
	void addMana(double value) override;

	/**
	 * @brief Upgrades one of the main statistics
	 * @param index - index of statistic to upgrade
	 * @param percentage - percentage of the upgrade (for example 20% will upgrade your stat to 120%)
	 * @return string - the statistic that was upgraded
	*/
	string upgradeStat(int index, double percentage) override;
	
	/**
	 * @brief special ability that deals increased damage (3x modifier)
	 * @param target - target that will be attacked
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	bool tripleAttack(Character& target);

	/**
	 * @brief special ability that gives shield
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	bool shieldUp();

	/**
	 * @brief special ability that deals damage, heals and gives additional turn
	 * @param target - target that will be attacked 
	 * @return bool - true if the attack was succesful, false if not
	*/
	bool stealthAttack(Character& target);

};

