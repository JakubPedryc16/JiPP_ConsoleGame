
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <limits>
#include <fstream>

#include "Hero.h"
#include "Enemy.h"
#include "Progression.h"
#include "ActiveItem.h"
#include "FileManager.h"

using namespace std;

int getChar();
Hero* createHero();
Enemy* createEnemy();
string getEnemyName();
string getBossName();
void manageUpgrades();
bool performAction(char button);

void displayMenu();

string abilityTexts[3] = {
"Deals triple Damage to enemy, at cost of 8 mana points",
"Gains 50 points of Shield, at cost of 10 mana points",
"Deals normal Damage to enemy, gains 15 Health Points and gets one additional turn at cost of 8 mana cost"
};

ActiveItem activeItem;
Progression progression;

Character* hero;
Character* enemy;

string* names;
int length;

template<typename T, typename T1>
T add(T firstValue, T1 secondValue);

int main(int argc, char* argv[]) {
    srand((unsigned)time(NULL));
    int round = 1;
    int floor = 1;
    length = argc - 1;

    if (argc > 1) {
        names = new string[length];
        for (int i = 0; i < length; i++) {
            names[i] = argv[i + 1];
        }
    }
    else {
        names =  NULL;
        length = 0;
    }

    displayMenu();
    hero = createHero();

    while (hero->getHealth() != 0) {
        char button = NULL;

        enemy = createEnemy();
        enemy->printInfo();
        cout << "Health + Shield = " << add(enemy->getHealth(), enemy->getShield()) << endl;

        hero->printInfo();
        cout << "Health + Shield = " << add(hero->getHealth(), hero->getShield()) << endl;

        while (hero->getHealth() != 0 && enemy->getHealth() != 0) {
            cout << "Perform action to continue..." << endl;
            button = getChar();
            if (button != 'c') {
                cout << endl << "------------------------------------" << endl
                    << floor << endl
                    << "Round: " << round << endl << endl;
            }

            if (performAction(button) == true) {
                round++;
            }
        }
        if (enemy->getHealth() <= 0) {
            cout << "You killed a " << enemy->getName() << endl;
            progression.addEnemy(enemy->getName());
            manageUpgrades();
            floor++;

            cout << "Press 'f' to see next enemy..." << endl;
            fflush(stdin);

            char temp = getChar();
            while (temp != 'f') temp = getChar();
        }

    }
    cout << "You died" << endl;

    cout << progression;
    cout << endl << "Press Enter to exit" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    FileManager fileManager(*hero, progression.getKillCount());
    fileManager.saveToFile();

    delete hero;
    delete[] names;
	return 0;
}

Hero* createHero() {
    int num;
    string name;
    double random = (rand() % 20) / 100.0;
    int ability = 0;

    double stats[4] = { 100, 15, 40, 100 };
    cout << "Choose you name: " << endl;
    getline(cin, name);

    cout << "Choose you class [1,2,3]" << endl
        << "1: Warrior" << endl
        << "2: Assasin" << endl
        << "3: Mage" << endl;
    try {
        cin >> num;
        if (num > 3 || num < 1 || cin.fail() == 1) {
            throw out_of_range("Invalid Value: Index Out Of Range, value was set to 1");
        }
    }
    catch (out_of_range &err) {
        cerr << err.what() << endl;
        num = 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    stats[num - 1] *= (1.1 + random);
    
    cout << "Choose your attribute [1,2,3]" << endl
        << "1: Strength" << endl
        << "2: Dextrity" << endl
        << "3: Inteligence" << endl;
    try {
        cin >> num;
        if (num > 3 || num < 1 || cin.fail() == 1) {
            throw out_of_range("Invalid Value: Index Out Of Range, value was set to 1");
        }
    }
    catch (out_of_range& err) {
        cerr << err.what() << endl;
        num = 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    stats[num - 1] *= (1.05 + (random / 3.0));
    stats[num] *= (1.05 + (random / 3.0));

    cout << "Choose your ability [1,2,3]" << endl
        << "1: Triple Attack" << endl
        << "2: Shield Up" << endl
        << "3: Stealth Attack" << endl;
    try {
        cin >> num;
        if (num > 3 || num < 1 || cin.fail() == 1) {
            throw out_of_range("Invalid Value: Index Out Of Range, value was set to 1");
        }
    }
    catch (out_of_range& err) {
        cerr << err.what() << endl;
        num = 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ability = (num - 1);
    cout << "Your Hero ability is: " << endl << abilityTexts[num - 1] << endl << endl;
    cout << "Press any button to continue..." << endl;
    char temp = getChar();

    return new Hero(name, stats[0], stats[1], stats[2], ability, (stats[3] - 100));
}
Enemy* createEnemy() {

    string name;
    int killCount = progression.getKillCount();
    int maxRand = killCount * 2 + 1;
    int minRand = killCount;
    double random = ( (double)(rand() % maxRand) + minRand) / 100.0;
    unsigned randomAbility = rand() % 3;

    double stats[3] = { 30 + killCount * 8.0 , 5 + killCount * 0.5, 0};
    int ability = 0;
    if ((killCount+1) % 5 == 0) {
        stats[0] *= (2 * random + 1.0);
        stats[1] *= (2 * random + 1.0);
        stats[2] += (2 * random * 100);
        name = getBossName();
    }
    else {
        stats[0] *= (random + 1.0);
        stats[1] *= (random + 1.0);
        name = getEnemyName();
    }

    if (random < (maxRand / 100) * 0.70) {
        stats[2] += (random * 100);
    }
    
    ability = randomAbility;
    cout << endl << "------------------------------------" << endl;

    delete enemy;
    return new Enemy(name, stats[0], stats[1], ability, stats[2]);
}
string getEnemyName() {
    if (length <= 0) {
        unsigned random = rand() % 5;
        string names[5] = { "Slime", "Berserk", "Skeleton", "Zombie", "Ghost" };
        return names[random];
    }
    unsigned random = rand() % length;
    return (names[random]);
}

string getBossName() {
    unsigned random = rand() % 5;
    if (length <= 0) {
        string _names[5] = { "Slime God", "Berserk King", "Dark Skeleton", "Huge Zombie", "Ghost Summoner" };
        return _names[random];
    }
    string _names[5] = { "The Godness ", "King ", "Dark ", "Huge ", "The Ancient " };
    unsigned _random = rand() % length;
    return (_names[random] + names[_random]);
}

void manageUpgrades() {
    string upgradeText = "";
    unsigned randomNum = (rand() % 3);
    double randomValue = ((double)(rand() % 20) + 1) / 100.0;

    upgradeText = hero->upgradeStat(randomNum, randomValue);

    cout << "Rewards: +" << (int)(randomValue * 100) << "% " << upgradeText << endl;
    if (randomValue < 0.1) {
        activeItem.addItem((ItemType)randomNum);
        cout << "You get a random potion" << endl;
    }
}

bool performAction(char button) {
    switch (button) {

    case 'w':

        if (hero->useAbility(*enemy) == false) return false;
        enemy->attack(*hero);
        break;

    case 'q':
        if (activeItem.useItem(*hero) == false) return false;
        enemy->attack(*hero);
        break;

    case 'e':
        hero->attack(*enemy);
        enemy->attack(*hero);
        break;
    case 'c':
        system("cls");
        return false;
        break;

    case 's':
        cout << "Exit the game ? (y/n)" << endl;
        button = getChar();
        if (button == 'y') {
            hero->surrenderFight();
        }
        else if (button == 'n') {
            return false;
        }
        else {
            cout << "unknown button" << endl;
            return false;
        }
        break;

    default:
        cout << endl << "unknown button" << endl; 
        return false;
        break;
    }
    return true;
}

int getChar() {
    char button = _getch();

    return button;
}

void displayMenu() {
    char temp = 0;
    cout << "Welcome in The Deep Dungeon" << endl
         << "To skip the Tutorial Menu press 'f' , to show it press 'i' " << endl << endl;
    temp = getChar();
    while (temp != 'i' && temp != 'f') temp = getChar();;
    if (temp == 'i') {
        cout << "You will explore floors, on each you will find one enemy" << endl
            << "The fight will go in turns, every turn you can choose one of three options" << endl
            << "Option 1 - 'e' button - normal attack" << endl
            << "Option 2 - 'w' button - special ability (uses mana points)" << endl
            << "Option 3 - 'q' button - use random potion (heal / shield / mana)" << endl
            << "Option 4 - 's' button - surrender and exit current game" << endl << endl;

        cout << "If you kill enemy you will get random upgrade to one of you statistics (health / damage / mana points)" << endl
            << "But remember the deeper you go the stronger the enemy will be..." << endl << endl;

        cout << "Press 'f' to continue..." << endl << endl;
        temp = getChar();
        while (temp != 'f') temp = getChar();
    }
    cout << "To start new game press 'f' , to see last game results press 'i' " << endl << endl;
    temp = getChar();
    while (temp != 'i' && temp != 'f') temp = getChar();
    if (temp == 'i') {
        FileManager fileManager;
        fileManager.readFromFile();
        cout << "Press 'f' to continue..." << endl << endl;
        temp = getChar();
        while (temp != 'f') temp = getChar();
    }

}

template<typename T, typename T1>
T add(T firstValue, T1 secondValue){
    return firstValue + secondValue;
}
