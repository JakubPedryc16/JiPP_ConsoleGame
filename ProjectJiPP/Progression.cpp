#include "Progression.h"

Progression::Progression() {
	killCount = 0;
	killNames = new string[5];
	killNamesSize = 5;
}

Progression::Progression(int _killCount, string* _killNames, int _killNameSize) {
	killCount = _killCount;
	killNames = _killNames;
	killNamesSize = _killNameSize;
}

Progression::~Progression() {
	delete[] killNames;
}

void Progression::addEnemy(string name) {
	killCount++;
	if (killNamesSize < killCount) {
		killNamesSize *= 2;
		string* _killNames = new string[killNamesSize];
		for (int i = 0; i < killCount - 1; i++) {
			_killNames[i] = killNames[i];
		}
		delete[] killNames;
		killNames = _killNames;
	}
	killNames[killCount - 1] = name + " |";
}

int Progression::getKillCount()
{
	return killCount;
}


ostream& operator<<(ostream& lh, Progression& rh)
{
	string ret;
	for (int i = 0; i < rh.killCount; i++) {
		ret = ret + rh.killNames[i] + " ";
	}
	return lh << endl << endl << "Game Over" << endl << "You have killed " << rh.killCount 
			  << " enemies" << endl << "Enemies killed:" << endl << ret;
}
