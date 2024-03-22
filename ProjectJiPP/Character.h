#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/**
 * @brief Basic life being
*/
class Character {
protected:
	string name;
	double health;
	double maxHealth;
	double damage;
	double shield;
public:

	/**
	 * @brief Default constructor 
	*/
	Character();
	
	/**
	 * @brief Constructor with parameters
	 * @param _name - name of character
	 * @param _maxHealth - max Health of character
	 * @param _damage - damage of character
	 * @param _shield - shield (armour) of character
	*/
	Character(string _name, double _maxHealth, double _damage, double  _shield = 0);

	/**
	 * @brief Copying constructor
	 * @param character - character who's statistics you want to copy
	*/
	Character(Character& character);

	/**
	 * @brief Destructor
	*/
	virtual ~Character();

	/**
	 * @brief use special ability
	 * @param target - target on which the ability will be used
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	virtual bool useAbility(Character& target);

	/**
	 * @brief prints the informations about this object on screen
	*/
	virtual void printInfo();

	/**
	 * @brief attacks its target (with certain damage)
	 * @param target - target that will be attacked
	 * @param _damage - damage of this attack
	*/
	virtual void attack(Character& target, double _damage);

	/**
	 * @brief attacks its target
	 * @param target - target that will be attacked
	*/
	virtual void attack(Character& target);

	/**
	 * @brief Adds mana points
	 * @param value - value of mana points to add
	*/
	virtual void addMana(double value);

	/**
	 * @brief Upgrades one of the main statistics
	 * @param index - index of statistic to upgrade
	 * @param percentage - percentage of the upgrade (for example 20% will upgrade your stat to 120%)
	 * @return string - the statistic that was upgraded
	*/
	virtual string upgradeStat(int index, double percentage);

	/**
	 * @brief get current health points
	 * @return current health points
	*/
	double getHealth();

	/**
	 * @brief get max health points
	 * @return max health points
	*/
	double getMaxHealth();

	/**
	 * @brief get shield (armour) points
	 * @return shield (armour) points
	*/
	double getShield();

	/**
	 * @brief get damage points
	 * @return damage points
	*/
	double getDamage();

	/**
	 * @brief get name string
	 * @return name string
	*/
	string getName();

	/**
	 * @brief get max mana points
	 * @return max mana points
	*/
	virtual double getMaxMP();

	/**
	 * @brief loose health points
	 * @param _damage - amount of health points to loose
	*/
	void getHurt(double _damage);

	/**
	 * @brief Add shield (armour) points
	 * @param value - amount of shield points to add
	*/
	void addShield(int value);

	/**
	 * @brief Add health points
	 * @param value - amount of health points to add
	*/
	void healHP(double value);

	/**
	 * @brief shows status of both character after a certain action
	 * @param target - target on which an action will be performed
	 * @param action - name of action that will be performed
	 * @param points - points that will be added or subtracted
	*/
	void printBattleLog(Character& target, string action, double points);

	/**
	 * @brief sets health to zero to end game
	*/
	void surrenderFight();

	/**
	 * @brief operator overloading
	 * @param lh - left hand of operator (ostream)
	 * @param rh - right hand of operator (Character)
	 * @return - ostream for information cout
	*/
	friend ostream& operator<<(ostream& lh, Character& rh);

};
