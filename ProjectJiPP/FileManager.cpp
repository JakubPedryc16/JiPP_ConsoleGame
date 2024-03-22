#include "FileManager.h"

FileManager::FileManager(Character& character, int _killCount) : Character(character) {
	manaPoints = character.getMaxMP();
    killCount = _killCount;
}

FileManager::FileManager() : Character() {
    manaPoints = 0;
    killCount = 0;
}

FileManager::~FileManager() { }

void FileManager::saveToFile() {
    ofstream ostream{ "file.bin", ios::binary };
    if (ostream.good() == 1) {
        size_t nameLength = name.size();
        //string name = name;
        ostream.write(reinterpret_cast<char*>(&nameLength), sizeof(int));
        ostream.write(&name[0], nameLength);

        //double maxHealth = maxHealth;
        ostream.write(reinterpret_cast<char*>(&maxHealth), sizeof(double));

        //double damage = damage;
        ostream.write(reinterpret_cast<char*>(&damage), sizeof(double));

        //double maxMP = manaPoints;
        ostream.write(reinterpret_cast<char*>(&manaPoints), sizeof(double));

        //double shield = shield;
        ostream.write(reinterpret_cast<char*>(&shield), sizeof(double));

        //int killedEnemiesCount = killCount;
        ostream.write(reinterpret_cast<char*>(&killCount), sizeof(double));

        ostream.close();
    }
    else {
        cout << "Error, can't save the data" << endl;
    }
}

void FileManager::readFromFile() {
    ifstream istream{ "file.bin", ios::binary };
    if (istream.good() == 1) {
        int nameLength;
        //string name;

        istream.read(reinterpret_cast<char*>(&nameLength), sizeof(int));
        name.resize(nameLength);
        istream.read(&name[0], nameLength);

        //double maxHealth;
        istream.read(reinterpret_cast<char*>(&maxHealth), sizeof(double));

        //double damage;
        istream.read(reinterpret_cast<char*>(&damage), sizeof(double));

        //double maxMP;
        istream.read(reinterpret_cast<char*>(&manaPoints), sizeof(double));

        //double shield;
        istream.read(reinterpret_cast<char*>(&shield), sizeof(double));

        //int killedEnemiesCount;
        istream.read(reinterpret_cast<char*>(&killCount), sizeof(double));

        cout << endl
            << "Name: " << name << endl
            << "Max Health: " << maxHealth << endl
            << "Shield: " << shield << endl
            << "Damage: " << damage << endl
            << "Max Mana: " << manaPoints << endl
            << "Killed Enemies: " << killCount << endl << endl;

        istream.close();
    }
    else {
        cout << "Error, can't read the data or file doesn't exist" << endl << endl;
    }
}
