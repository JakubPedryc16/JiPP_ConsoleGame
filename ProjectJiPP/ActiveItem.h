#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
using namespace std;

/**
 * @brief Type of potion (HEALING, MANA, SHIELD)
*/
enum class ItemType {
	HEALING,
	MANA,
	SHIELD
};

/**
 * @brief Potions Handler
*/
class ActiveItem {
private:
	vector<ItemType> itemList;
public:

	/**
	 * @brief Default constructor
	*/
	ActiveItem();

	/**
	 * @brief Use random potion
	 * @param target - character that is supposed to perform this action
	 * @return bool - true if potion was used, false if wasn't
	*/
	bool useItem(Character& target);

	/**
	 * @brief Adds random potion 
	 * @param type - type of potion (enum class ItemType)
	*/
	void addItem(ItemType type);
};

