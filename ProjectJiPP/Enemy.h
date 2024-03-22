#pragma once
#include <iostream>
#include "Character.h"

using namespace std;

/**
 * @brief Enemy life being
*/
class Enemy : public Character {
protected:
	int abilityNum;
public:

	/**
	 * @brief Default constructor
	*/
	Enemy();

	/**
	 * @brief Constuctor with parameters
	 * @param _name - name of enemy
	 * @param _maxHealth - max Health of enemy
	 * @param _damage - damage of enemy
	 * @param _ability - ability type of enemy
	 * @param _shield - shield (armour) of enemy
	*/
	Enemy(string _name, double _maxHealth, double _damage, int _abilityNum, double _shield = 0);

	~Enemy();
	
	/**
	 * @brief use special ability
	 * @param target - target on which the ability will be used
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	bool useAbility(Character& target) override;

	/**
	 * @brief prints the informations about this object on screen
	*/
	//void printInfo() override;

	/**
	 * @brief attacks its target
	 * @param target - target that will be attacked
	*/
	void attack(Character& target) override;

	/**
	 * @brief attacks its target (with certain damage)
	 * @param target - target that will be attacked
	 * @param _damage - damage of this attack
	*/
	void attack(Character& target, double _damage) override;

	/**
	 * @brief special ability that deals increased damage (1.5x modifier)
	 * @param target - target that will be attacked 
	 * @return bool - true if the ability was succesfully used, false if not
	*/
	bool doubleAttack(Character& target);

	/**
	 * @brief special ability that gives shield 
	 * @return bool - true if the ability was succesfully used, false if not 
	*/
	bool shieldUp();

	/**
	 * @brief special ability that deals damage and heals 
	 * @param target - target that will be attacked 
	 * @return bool - true if the attack was succesful, false if not
	*/
	bool bloodyBite(Character& target);

};

