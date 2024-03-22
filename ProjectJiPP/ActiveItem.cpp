#include "ActiveItem.h"

ActiveItem::ActiveItem() {

}

bool ActiveItem::useItem(Character& target) {
	if (itemList.size() <= 0) {
		cout << "You have no items" << endl << endl;
		return false;
	}
	switch (itemList.at(0)) {
	case ItemType::HEALING:
		cout << "You use Healing Potion" << endl;
		target.healHP(50);
		itemList.erase(itemList.begin());
		break;
	case ItemType::MANA:
		cout << "You use Mana Potion" << endl;
		target.addMana(20);
		itemList.erase(itemList.begin());
		break;
	case ItemType::SHIELD:
		cout << "You use Shield Potion" << endl;
		target.addShield(40);
		itemList.erase(itemList.begin());
		break;
	default:
		cout << "useItem error" << endl;
		return false;
	}
	cout << endl;
	return true;
}

void ActiveItem::addItem(ItemType type) {
	itemList.push_back(type);
}

