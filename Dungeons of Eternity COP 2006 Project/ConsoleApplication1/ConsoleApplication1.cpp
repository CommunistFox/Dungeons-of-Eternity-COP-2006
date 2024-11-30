#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int titleScreen() {
    cout << "\n" << R"(/$$$$$$$  /$$   /$$ /$$   /$$  /$$$$$$  /$$$$$$$$  /$$$$$$  /$$   /$$  /$$$$$$         /$$$$$$  /$$$$$$$$)";
    cout << "\n" << R"(| $$__  $$| $$  | $$| $$$ | $$ /$$__  $$| $$_____/ /$$__  $$| $$$ | $$ /$$__  $$       /$$__  $$| $$_____/)";
    cout << "\n" << R"(| $$  \ $$| $$  | $$| $$$$| $$| $$  \__/| $$      | $$  \ $$| $$$$| $$| $$  \__/      | $$  \ $$| $$      )";
    cout << "\n" << R"(| $$  | $$| $$  | $$| $$ $$ $$| $$ /$$$$| $$$$$   | $$  | $$| $$ $$ $$|  $$$$$$       | $$  | $$| $$$$$   )";
    cout << "\n" << R"(| $$  | $$| $$  | $$| $$  $$$$| $$|_  $$| $$__/   | $$  | $$| $$  $$$$ \____  $$      | $$  | $$| $$__/   )";
    cout << "\n" << R"(| $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$      | $$  | $$| $$\  $$$ /$$  \ $$      | $$  | $$| $$      )";
    cout << "\n" << R"(| $$$$$$$/|  $$$$$$/| $$ \  $$|  $$$$$$/| $$$$$$$$|  $$$$$$/| $$ \  $$|  $$$$$$/      |  $$$$$$/| $$      )";
    cout << "\n" << R"(|_______/  \______/ |__/  \__/ \______/ |________/ \______/ |__/  \__/ \______/        \______/ |__/      )";

    cout << "\n\n\n" << R"( /$$$$$$$$/$$$$$$$$/$$$$$$$$ /$$$$$$$  /$$   /$$ /$$$$$$/$$$$$$$$/$$     /$$)";
    cout << "\n" << R"(| $$_____/__  $$__/ $$_____/| $$__  $$| $$$ | $$|_  $$_/__  $$__/  $$   /$$/)";
    cout << "\n" << R"(| $$        | $$  | $$      | $$  \ $$| $$$$| $$  | $$    | $$   \  $$ /$$/ )";
    cout << "\n" << R"(| $$$$$     | $$  | $$$$$   | $$$$$$$/| $$ $$ $$  | $$    | $$    \  $$$$/  )";
    cout << "\n" << R"(| $$__/     | $$  | $$__/   | $$__  $$| $$  $$$$  | $$    | $$     \  $$/   )";
    cout << "\n" << R"(| $$        | $$  | $$      | $$  \ $$| $$\  $$$  | $$    | $$      | $$   )";
    cout << "\n" << R"(| $$$$$$$$  | $$  | $$$$$$$$| $$  | $$| $$ \  $$ /$$$$$$  | $$      | $$    )";
    cout << "\n" << R"(|________/  |__/  |________/|__/  |__/|__/  \__/|______/  |__/      |__/    )";
    cout << "\n\n" << R"(________________________________________________________________________________________________________)";

    cout << "\n\nPRESS ENTER TO BEGIN";
    cin.get();
    system("cls");

    return(0);
}

class Room
{
public:
    int roomDifficulty; /* 0 = Start area or area with no monsters. 1 = easy. 2 = medium. 3 = hard. 4 = mini-boss (if any). 5 = Boss. 9 = Room does not exist */
    string roomDescription;

    void generateRoomDesc()
    {   
        string line;
        ifstream file("DungeonDescriptions.txt");
        int targetLine = rand() % 10 + 1;
        int currentLine = 1;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                if (currentLine == targetLine)
                {
                    roomDescription = line;
                }
                currentLine++;
            }
            
        }
    }

    Room(int roomDifficulty): roomDifficulty(roomDifficulty){}

    Room():roomDifficulty(0){}

};

class Monster
{
public:

    int difficulty; /* 0 = no monsters. 1 = easy. 2 = medium. 3 = hard. 4 = mini-boss (if any). 5 = Boss. 9 = Monster does not exist */
    int monsterHealth=0;
    int monsterStrength=0;
    int monsterAgility=0;
    int monsterRoll=0;
    int monsterChoice=0;

    void createMonster()
    {
        switch (difficulty)
        {
        case 1:
            monsterHealth = rand() % 5 + 5;
            monsterStrength = rand() % 5 + 5;
            monsterAgility = rand() % 5 + 5;
            break;
        case 2:
            monsterHealth = rand() % 5 + 15;
            monsterStrength = rand() % 5 + 15;
            monsterAgility = rand() % 5 + 15;
            break;
        case 3:
            monsterHealth = rand() % 5 + 25;
            monsterStrength = rand() % 5 + 25;
            monsterAgility = rand() % 5 + 25;
            break;
        case 5:
            monsterHealth = 60;
            monsterStrength = 40;
            monsterAgility = 45;
            break;
        
            
        }
    }


    Monster(int difficulty): difficulty(difficulty){}

    Monster():difficulty(9){}
};


// Function to display the stats
void displayStats(int strength, int perception, int vitality, int agility) {
    cout << "\nCurrent Stats:\n";
    cout << "1. Strength: " << strength << endl;
    cout << "2. Perception: " << perception << endl;
    cout << "3. Vitality: " << vitality << endl;
    cout << "4. Agility: " << agility << endl;
    cout << endl;
}

// Function to roll a dice
int rollDice(int sides) {
    return rand() % sides + 1;
}


void combatTutorial(int strength, int agility, int vitality) {
    int playerHealth = 20 + (vitality - 10); // Player's health based on vitality
    int ratHealth = 10;                     // Rat's health
    int ratStrength = 11;                   // Rat's strength
    int ratAgility = 13;                    // Rat's agility
    bool heavyAttackUsed = false;           // Track if heavy attack was just used
    int playerRoll = 0;                     // Declare playerRoll outside of the switch-case

    cout << "\n=== Combat Tutorial: You vs. Rat ===\n";
    cout << "Player Health: " << playerHealth << endl;
    cout << "Rat Health: " << ratHealth << endl;

    // Combat loop
    while (playerHealth > 0 && ratHealth > 0) {
        if (!heavyAttackUsed) { // Allow player action if heavy attack was not just used
            cout << "\nYour turn! Choose an action:\n";
            cout << "1. Attack\n2. Dodge\n3. Heavy Attack\n";
            int choice;
            cin >> choice;

            // Roll for player's action
            int playerDamage = 0;
            switch (choice) {
            case 1: // Regular attack
                playerRoll = rollDice(20) + (strength - 10) / 2;
                cout << "You rolled: " << playerRoll << " (attack roll)\n";
                if (playerRoll >= rollDice(20) + (ratAgility - 10) / 2) {
                    playerDamage = rollDice(6) + (strength - 10) / 2;
                    ratHealth -= playerDamage;
                    cout << "You hit the rat for " << playerDamage << " damage!\n";
                }
                else {
                    cout << "You missed the rat!\n";
                }
                break;

            case 2: // Dodge
                playerRoll = rollDice(20) + (agility - 10) / 2;
                cout << "You prepare to dodge with a roll of " << playerRoll << ".\n";
                break;

            case 3: // Heavy attack
                playerRoll = rollDice(20) + ((strength - 10) / 2) * 2 + 1; // Double modifier or +1
                cout << "You rolled: " << playerRoll << " (heavy attack roll)\n";
                if (playerRoll >= rollDice(20) + (ratAgility - 10) / 2) {
                    playerDamage = rollDice(6) + ((strength - 10) / 2) * 2 + 1;
                    ratHealth -= playerDamage;
                    cout << "You hit the rat with a heavy blow for " << playerDamage << " damage!\n";
                }
                else {
                    cout << "You missed the rat with your heavy attack!\n";
                }
                heavyAttackUsed = true; // Set flag to skip next player turn
                break;

            default:
                cout << "Invalid choice. Turn skipped.\n";
                break;
            }
        }
        else {
            cout << "You are recovering from your heavy attack and skip this turn.\n";
            heavyAttackUsed = false; // Reset heavy attack flag
        }

        if (ratHealth <= 0) {
            cout << "\nThe rat has been defeated! You emerge victorious!\n";
            break;
        }

        // Rat's turn
        for (int i = 0; i < (heavyAttackUsed ? 2 : 1); i++) { // Rat gets 2 turns if heavy attack used
            cout << "\nThe rat's turn!\n";
            int ratChoice = rollDice(2); // 1 for attack, 2 for heavy attack
            int ratRoll = rollDice(20) + (ratStrength - 10) / 2;

            if (ratChoice == 1) { // Regular attack
                cout << "The rat rolls " << ratRoll << " for its attack.\n";
                if (playerRoll >= ratRoll) { // Player dodges
                    cout << "You dodged the rat's attack!\n";
                }
                else {
                    int ratDamage = rollDice(6) + (ratStrength - 10) / 2;
                    playerHealth -= ratDamage;
                    cout << "The rat hits you for " << ratDamage << " damage!\n";
                }
            }
            else { // Heavy attack
                cout << "The rat charges up for a heavy attack!\n";
                ratRoll += (ratStrength - 10) / 2; // Double modifier or +1
                cout << "The rat rolls " << ratRoll << " for its heavy attack.\n";
                if (playerRoll >= ratRoll) { // Player dodges
                    cout << "You dodged the rat's heavy attack!\n";
                }
                else {
                    int ratDamage = rollDice(6) + ((ratStrength - 10) / 2) * 2;
                    playerHealth -= ratDamage;
                    cout << "The rat lands a heavy blow for " << ratDamage << " damage!\n";
                }
            }

            cout << "\nPlayer Health: " << playerHealth << endl;
            cout << "Rat Health: " << ratHealth << endl;

            if (playerHealth <= 0) {
                cout << "\nYou have been defeated. The dungeon claims another victim...\n";
                break;
            }
        }
    }
}

// Function to display the game over screen with restart option
bool gameOver() {
    cout << "\n=== GAME OVER ===\n";
    cout << "I knew you would die MORTAl\n";
    cout << "You could just restart.....oh wait your dead.\n";
    cout << "Press 1 to restart or any other key to exit: ";

    int restartChoice;
    cin >> restartChoice;
    return restartChoice == 1; // Restart only if the user presses 1
}


void generateMenu(int health, int level, int money) 
{
    system("cls");

    cout << "HP: " << health << "\t\tLevel" << level << "\t\tMoney: " << money;
    cout << "\n===============================================\nYOUR OPTIONS\n";
    cout << "\n1: Shop";
    cout << "\n2: Continue";
    cout << "// Add more options below as needed";

    
}










int main()
{
    srand(time(0));
    Room allRooms[10][7] = { {Room(9)   , Room(5)   , Room(1)   , Room(1)   ,Room(9)   ,Room(9)   ,Room(9)},{Room(9)   , Room(3)   ,Room(9)   , Room(2)   , Room(3)   , Room(3)   , Room(3)},{Room(9)   , Room(3)   ,Room(9)   , Room(3)   ,Room(9)   , Room(3)   ,Room(9)},{ Room(2)   , Room(2)   ,Room(9)   , Room(2)   ,Room(9)   , Room(2)   ,Room(9)},{ Room(2)   ,Room(9)   ,Room(9)   , Room(2)   ,Room(9)   , Room(2)   , Room(2)},{ Room(2)   , Room(2)   ,Room(9)   , Room(2)   ,Room(9)   ,Room(9)   , Room(2)},{Room(9)   , Room(1)   , Room(1)   , Room(1)   , Room(1)   ,Room(9)   , Room(1)},{Room(9)   ,Room(9)   , Room(1)   ,Room(9)   , Room(1)   , Room(1)   , Room(1)},{Room(9)   ,Room(9)   , Room(1)   ,Room(9)   , Room(1)   ,Room(9)   ,Room(9)},{Room(9)   ,Room(9)   ,Room(0)   ,Room(9)   ,Room(9)   ,Room(9)   ,Room(9)} };

    Monster allMonsters[10][7];

    titleScreen();


    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 7; y++)
        {
            allMonsters[x][y] = Monster(allRooms[x][y].roomDifficulty);
            allMonsters[x][y].createMonster();
            allRooms[x][y].generateRoomDesc();
        }
    }

    




    cout << allMonsters[0][1].monsterAgility;
    
    
    cout << allRooms[0][1].roomDifficulty;
    
    cout << allRooms[0][1].roomDescription;


    

    
    return 0;
}

// ==================
// Tyler 11/20/24
// ==================

// Concepts of a generate menu function


/*

To Do List:

- 8 more dungeon templates + random picking of template
- Text for each room and its description (example: Text1: The room is dark and something etc. Text2: There is a pathway forward, left , or right, or back.)
- Determine health of main character
- Make classes for monsters
- Determine balancing for monsters
- Create a Boss, who should also be randomly picked
- Items and their effects
- Main character attributes (Strength, Perception, Vitality, Agility)
- Text for fights
- Fight sequence
- Figure out how to take input
- Organize code, so it doesn't cause brain tumour
- Comments should be placed in important parts of the code
- To be determined: Shopes and the items + currency
- To be determined: Inventory and inventory interaction
- Check for errors, try to break the game
- Fix the errors
- Math that goes along with attributes
- Level up system(concept: level up every three rooms each level up you can increase two stats by 2)
- To be determined: Secret rooms with random things


In progress: (Task + Name of who does it)
- Assign attriutes to each room when dungeon generates (Tim)
-Text for each room and its description (cole)
-Main character attributes (cole)
- Math that goes along with attributes(cole)
- Items and their effects(cole)
Finished: (Task + Name of who finished it)







*/

/* Test
    for (int r = 0; r <=9; r++)
    {
        cout << "###";
        for (int c = 0; c <=6; c++)
        {
            cout << dungeonTemplate[r][c];
            if (dungeonTemplate[r][c] > 0 && dungeonTemplate[r][c+1] > 0 && c < 6)
            {
                cout << "===";
            }
            else
            {
                cout << "###";
            }
        }
        cout << endl;
        if (r < 9)
        {
            cout << "###";
            for (int w = 0; w <= 6; w++)
            {

                if (dungeonTemplate[r][w] > 0 && dungeonTemplate[r+1][w] > 0)
                {
                    cout << "I";
                }
                else
                {
                    cout << "#";
                }
                cout << "###";
            }
        }
        cout << endl;
    }
    This was just template test*/