#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
using namespace std;



int getChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

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
    int xpValue=0;
    string monsterName;

    void createMonster()
    {
        switch (difficulty)
        {
        case 1:
            monsterHealth = rand() % 5 + 5;
            monsterStrength = rand() % 5 + 5;
            monsterAgility = rand() % 5 + 5;
            xpValue = rand() % 20 + 21;
            break;
        case 2:
            monsterHealth = rand() % 5 + 15;
            monsterStrength = rand() % 5 + 15;
            monsterAgility = rand() % 5 + 15;
            xpValue = rand() % 20 + 41;
            break;
        case 3:
            monsterHealth = rand() % 5 + 25;
            monsterStrength = rand() % 5 + 25;
            monsterAgility = rand() % 5 + 25;
            xpValue = rand() % 20 + 61;
            break;
        case 5:
            monsterHealth = 60;
            monsterStrength = 40;
            monsterAgility = 45;
            xpValue = rand() % 20 + 101;
            break;
        
            
        }
        ///xpValue = rand() % 10*difficulty + ((difficulty * 5) + 1);
        if (difficulty == 1)
        {
            string line;
            ifstream names("LowLevelMonsters.txt");
            int targetLine = rand() % 10 + 1;
            int currentLine = 1;
            if (names.is_open())
            {
                while (getline(names, line)&&currentLine<11)
                {
                    if (currentLine == targetLine)
                    {
                        monsterName = line;
                    }
                    currentLine++;
                }

            }
        }
        else if (difficulty == 2)
        {
            string line;
            ifstream names("MidLevelMonsters.txt");
            int targetLine = rand() % 10 + 1;
            int currentLine = 1;
            if (names.is_open())
            {
                while (getline(names, line) && currentLine < 11)
                {
                    if (currentLine == targetLine)
                    {
                        monsterName = line;
                    }
                    currentLine++;
                }

            }
        }
        else if (difficulty == 3)
        {
            string line;
            ifstream names("HighLevelMonsters.txt");
            int targetLine = rand() % 10 + 1;
            int currentLine = 1;
            if (names.is_open())
            {
                while (getline(names, line) && currentLine < 11)
                {
                    if (currentLine == targetLine)
                    {
                        monsterName = line;
                    }
                    currentLine++;
                }

            }
        }
        else if (difficulty == 5)
        {
            string line;
            ifstream names("Bosses.txt");
            int targetLine = rand() % 5 + 1;
            int currentLine = 1;
            if (names.is_open())
            {
                while (getline(names, line) && currentLine < 6)
                {
                    if (currentLine == targetLine)
                    {
                        monsterName = line;
                    }
                    currentLine++;
                }

            }
        }





    }


    Monster(int difficulty): difficulty(difficulty){}

    Monster():difficulty(9){}
};

class Hero
{
public:
    int heroHealth = 10;
    int heroVitality = 10;
    int heroStrength = 10;
    int heroAgility = 10;
    int lvl = 1;
    int xp = 0;
    int skillPoints = 5;



    // Function to display the stats
    void displayStats() {
        cout << "Stats:\n";
        cout << "Level: " << lvl << endl;
        cout << "XP: " << xp << endl;
        cout << "Strength: " << heroStrength << endl;
      ///  cout << "2. Perception: " << perception << endl;
        cout << "Agility: " << heroAgility << endl;
        cout << "Vitality: " << heroVitality << endl;
        cout << endl;
    }
    
    void applyStats()
    {
        heroHealth = 20 + (heroVitality - 10); // Player's health based on vitality
    }

    void levelCheck(int xpReceived)
    {
        xp += xpReceived;
        if (xp > ((lvl * 0.5) * 100))
        {
            xp -= (lvl * 0.5) * 100;
            lvl += 1;
            skillPoints += 7;
            system("cls");
            cout << "You leveled up!\n\n";
            displayStats();
            this_thread::sleep_for(chrono::seconds(2));
        }
    }






    void setSkills()
    {
        while (skillPoints > 0)
        {
            system("cls");
            displayStats();
            cout << "\nYou have " << skillPoints << " skill points to spend." << endl << "What will you spend it on?:\n1. Strength\n2. Agility\n3. Vitality\n";
            choice = getChoice();
            switch (choice)
            {
            case 1:
                skillPoints -= 1;
                heroStrength += 1;
                break;
            case 2:
                skillPoints -= 1;
                heroAgility += 1;
                break;
            case 3:
                skillPoints -= 1;
                heroVitality += 1;
                break;
            default:
                cout << "Wrong Choice";
            }
            system("cls");
        }
    }


private:
    int choice = 0;
};




// Function to roll a dice
int rollDice(int sides) {
    return rand() % sides + 1;
}


void combat(int playerHealth, int strength, int agility, int monsterHealth, int monsterStrength, int monsterAgility, string monsterName, bool &gameOver) {
    bool heavyAttackUsed = false;           // Track if heavy attack was just used
    bool monsterHeavyAttackUsed = false;
    int playerRoll = 0;                     // Declare playerRoll outside of the switch-case

    cout << "You have encountered a " << monsterName;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
    cout << "Player Health: " << playerHealth << endl;
    cout << monsterName <<" Health: " << monsterHealth << endl;

    // Combat loop
    while (playerHealth > 0 && monsterHealth > 0) {
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
                system("cls");
                cout << "You rolled: " << playerRoll << " (attack roll)\n";
                if (playerRoll >= rollDice(20) + (monsterAgility - 10) / 2) {
                    playerDamage = rollDice(6) + (strength - 10) / 2;
                    monsterHealth -= playerDamage;
                    cout << "You hit the "<< monsterName <<" for " << playerDamage << " damage!\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                else {
                    cout << "You missed the "<< monsterName << "!\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                break;

            case 2: // Dodge
                playerRoll = rollDice(20) + (agility - 10) / 2;
                system("cls");
                cout << "You prepare to dodge with a roll of " << playerRoll << ".\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;

            case 3: // Heavy attack
                playerRoll = rollDice(20) + ((strength - 10) / 2) * 2 + 1; // Double modifier or +1
                system("cls");
                cout << "You rolled: " << playerRoll << " (heavy attack roll)\n";
                if (playerRoll >= rollDice(20) + (monsterAgility - 10) / 2) {
                    playerDamage = rollDice(6) + ((strength - 10) / 2) * 2 + 1;
                    monsterHealth -= playerDamage;
                    cout << "You hit the " << monsterName << " with a heavy blow for " << playerDamage << " damage!\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                else {
                    system("cls");
                    cout << "You missed the " << monsterName << " with your heavy attack!\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                heavyAttackUsed = true; // Set flag to skip next player turn
                break;

            default:
                system("cls");
                cout << "Invalid choice. Turn skipped.\n";
                this_thread::sleep_for(chrono::seconds(2));
                break;
            }
        }
        else {
            cout << "You are recovering from your heavy attack and skip this turn.\n";
            this_thread::sleep_for(chrono::seconds(2));
            heavyAttackUsed = false; // Reset heavy attack flag
        }

        if (monsterHealth <= 0) {
            system("cls");
            cout << "The " << monsterName << " has been defeated! You emerge victorious!\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            break;
        }

        // Rat's turn
        ///for (int i = 0; i < (heavyAttackUsed ? 2 : 1); i++) { // Rat gets 2 turns if heavy attack used
            system("cls");
            cout << "The " << monsterName << "'s turn!\n";
            this_thread::sleep_for(chrono::seconds(1));
            system("cls");
            int monsterChoice = rollDice(2); // 1 for attack, 2 for heavy attack
            int monsterRoll = rollDice(20) + (monsterStrength - 10) / 2;

            if (monsterChoice == 1 && !monsterHeavyAttackUsed) { // Regular attack
                cout << "The " << monsterName << " rolls " << monsterRoll << " for its attack.\n";
                if (playerRoll >= monsterRoll) { // Player dodges
                    cout << "You dodged the " << monsterName << "'s attack!\n";
                }
                else {
                    int monsterDamage = rollDice(6) + (monsterStrength - 10) / 2;
                    playerHealth -= monsterDamage;
                    cout << "The " << monsterName << " hits you for " << monsterDamage << " damage!\n";
                }
            }
            else { // Heavy attack
                if (!monsterHeavyAttackUsed)
                {
                    cout << "The " << monsterName << " charges up for a heavy attack!\n";
                    monsterRoll = rollDice(6) + ((monsterStrength - 10) / 2) * 2 + 1; // Double modifier or +1
                    cout << "The " << monsterName << " rolls " << monsterRoll << " for its heavy attack.\n";
                    if (playerRoll >= monsterRoll) { // Player dodges
                        cout << "You dodged the " << monsterName << "'s heavy attack!\n";
                    }
                    else {
                        int monsterDamage = rollDice(6) + ((monsterStrength - 10) / 2) * 2;
                        playerHealth -= monsterDamage;
                        cout << "The " << monsterName << " lands a heavy blow for " << monsterDamage << " damage!\n";
                    }
                    monsterHeavyAttackUsed = true;
                }
                else
                {
                    cout << monsterName << " skips this turn";
                    monsterHeavyAttackUsed = false;
                }
            }

            this_thread::sleep_for(chrono::seconds(3));
            system("cls");

            cout << "Player Health: " << playerHealth << endl;
            cout << monsterName << " Health: " << monsterHealth << endl;

            if (playerHealth <= 0) {
                system("cls");
                cout << "You have been defeated. The dungeon claims another victim...\n";
                this_thread::sleep_for(chrono::seconds(5));
                gameOver = true;
                break;
            }
        ///}
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

    Hero player;

    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 7; y++)
        {
            allMonsters[x][y] = Monster(allRooms[x][y].roomDifficulty);
            allMonsters[x][y].createMonster();
            allRooms[x][y].generateRoomDesc();
        }
    }

    bool gameOver = false;

    titleScreen();


    //player.heroAgility = 60;
    //player.heroStrength = 60;
    //player.heroVitality = 60;



    player.setSkills();
    player.applyStats();
 


/// normal settings
    int xPosition = 9;
    int yPosition = 2;


///Boss for test
    ///int xPosition = 1;
    ///int yPosition = 1;

    bool leftSide;
    bool rightSide;
    bool forwardSide;
    bool backwardSide;
    int choice;

    while (!gameOver&&allRooms[0][1].roomDifficulty == 5)
    {
        player.setSkills();
        player.applyStats();

        if (allRooms[xPosition][yPosition - 1].roomDifficulty == 9 && (yPosition - 1) > -1)
        {
            leftSide = false;
        }
        else if (allRooms[xPosition][yPosition - 1].roomDifficulty != 9 && (yPosition - 1) > -1)
        {
            leftSide = true;
        }
        else
        {
            leftSide = false;
        }
        if (allRooms[xPosition][yPosition + 1].roomDifficulty == 9 && (yPosition + 1) < 7)
        {
            rightSide = false;
        }
        else if (allRooms[xPosition][yPosition + 1].roomDifficulty != 9 && (yPosition + 1) < 7)
        {
            rightSide = true;
        }
        else
        {
            rightSide = false;
        }
        if (allRooms[xPosition - 1][yPosition].roomDifficulty == 9 && (xPosition - 1) > -1)
        {
            forwardSide = false;
        }
        else if (allRooms[xPosition - 1][yPosition].roomDifficulty != 9 && (xPosition - 1) > -1)
        {
            forwardSide = true;
        }
        else
        {
            forwardSide = false;
        }
        if (allRooms[xPosition + 1][yPosition].roomDifficulty == 9 && (xPosition + 1) < 10)
        {
            backwardSide = false;
        }
        else if (allRooms[xPosition + 1][yPosition].roomDifficulty != 9 && (xPosition + 1) < 10)
        {
            backwardSide = true;
        }
        else
        {
            backwardSide = false;
        }

        while (true)
        {


            cout << "Please choose direction you want to go:" << endl;

            if (leftSide)
            {
                cout << "1. Left" << endl;
            }
            if (rightSide)
            {
                cout << "2. Right" << endl;
            }
            if (forwardSide)
            {
                cout << "3. Forward" << endl;
            }
            if (backwardSide)
            {
                cout << "4. Backward" << endl;
            }

            choice = getChoice();
            

            if (choice == 1 && leftSide)
            {
                yPosition -= 1;
                system("cls");
                break;
            }
            else if (choice == 2 && rightSide)
            {
                yPosition += 1;
                system("cls");
                break;
            }
            else if (choice == 3 && forwardSide)
            {
                xPosition -= 1;
                system("cls");
                break;
            }
            else if (choice == 4 && backwardSide)
            {
                xPosition += 1;
                system("cls");
                break;
            }
            else
            {
                system("cls");
                cout << "Wrong Choice" << endl;
            }


        }




        if (allRooms[xPosition][yPosition].roomDifficulty != 9&& allRooms[xPosition][yPosition].roomDifficulty != 0)
        {
            system("cls");
            combat(player.heroHealth, player.heroStrength, player.heroAgility, allMonsters[xPosition][yPosition].monsterHealth, allMonsters[xPosition][yPosition].monsterStrength, allMonsters[xPosition][yPosition].monsterAgility, allMonsters[xPosition][yPosition].monsterName, gameOver);
            if (!gameOver)
            {
                player.levelCheck(allMonsters[xPosition][yPosition].xpValue);
                allRooms[xPosition][yPosition].roomDifficulty = 0;
            }
        }
        
    }  




    

    if (!gameOver)
    {
        system("cls");
        cout << "You have conquered the dungeon! Than you very much for playing!";
        this_thread::sleep_for(chrono::seconds(5));
    }
    

    
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
- Determine balancing for monsters
- Items and their effects
- Organize code, so it doesn't cause brain tumour
- Comments should be placed in important parts of the code
- To be determined: Shopes and the items + currency
- To be determined: Inventory and inventory interaction
- Check for errors, try to break the game
- Fix the errors
- Math that goes along with attributes
- Level up system(concept: level up every three rooms each level up you can increase two stats by 2)
- To be determined: Secret rooms with random things








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