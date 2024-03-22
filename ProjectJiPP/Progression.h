#pragma once
#include <iostream>
#include <ostream>
using namespace std;

/**
 * @brief Manager of killed enemies names and count 
*/
class Progression {
private:
	int killCount;
	string* killNames;
	int killNamesSize;
public:

	/**
	 * @brief Default constructor 
	*/
	Progression();

	/**
	 * @brief Constructor with parameters
	 * @param _killCount - amount of killed enemies
	 * @param _killNames - names of killed enemies (dynamic string array)
	 * @param _killNameSize - size of _killNames
	*/
	Progression(int _killCount, string* _killNames, int _killNameSize);

	~Progression();

	/**
	 * @brief add killed enemy
	 * @param name - name of killed enemy
	*/
	void addEnemy(string name);

	/**
	 * @brief get count of killed enemies
	 * @return count of killed enemies
	*/
	int getKillCount();

	/**
	 * @brief operator overloading << 
	 * @param lh - left hand (ostream)
	 * @param rh - right hand (Progression)
	 * @return ostream - informations of game progression
	*/
	friend ostream& operator<<(ostream& lh, Progression& rh);
};

