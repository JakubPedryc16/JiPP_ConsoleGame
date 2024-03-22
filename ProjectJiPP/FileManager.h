#pragma once
#include "Character.h"
#include "fstream"

/**
 * @brief Save to or Read from file
*/
class FileManager : public Character {
private:
	double manaPoints;
	int killCount;
public:

	/**
	 * @brief Constructor that creates information about data to save/read
	 * @param character - who's statistics will be copied to FileManager
	 * @param _killCount - amount of enemies killed
	*/
	FileManager(Character& character, int _killCount);

	/**
	 * @brief Constructor that creates empty information about data to save/read
	*/
	FileManager();

	~FileManager();

	/**
	 * @brief save data to file
	*/
	void saveToFile();

	/**
	 * @brief read data from file and print it on screen
	*/
	void readFromFile();
};

