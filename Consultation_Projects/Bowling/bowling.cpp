#include <iostream>
#include <fstream>
#include <cstring>
#include <random>

using namespace std;

const int MAX_PLAYERS = 10;
const int MAX_NAME_LEN = 50;
const int MAX_ROLLS = 21;
const int MAX_GAMES = 100;
const int MAX_GAME_NAME = 50;

int playersCount;
char playerNames[MAX_PLAYERS][MAX_NAME_LEN];

int rolls[MAX_PLAYERS][MAX_ROLLS];
int rollsCount[MAX_PLAYERS];

int currentFrame;    // 0...9
int currentPlayer;   // 0...playersCount-1
char currentGameName[MAX_GAME_NAME];

void buildFilename(char* dest, const char* gameName) {
    strcpy(dest, gameName);
    strcat(dest, ".txt");
}

std::mt19937 rng(std::random_device{}());

int randomPins(int maxPins) {
    std::uniform_int_distribution<int> dist(0, maxPins);
    return dist(rng);
}

// old way for generating random numbers in range, use the new approach instead
// int randomPins(int maxPins) {
//     return rand() % (maxPins + 1);
// }

void resetGame() {
    currentFrame = 0;
    currentPlayer = 0;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        rollsCount[i] = 0;
        playerNames[i][0] = '\0';
        for (int j = 0; j < MAX_ROLLS; j++)
            rolls[i][j] = 0;
    }
}

void addRoll(int player, int pins) {
    rolls[player][rollsCount[player]++] = pins;
}

void playFrame(int player, int frame) {
    int pinsLeft = 10;

    int first = randomPins(pinsLeft);
    addRoll(player, first);
    pinsLeft -= first;

    if (first == 10 && frame < 9) {
        return;
    }

    int second = randomPins(pinsLeft);
    addRoll(player, second);

    if (frame == 9 && (first == 10 || first + second == 10)) {
        addRoll(player, randomPins(10));
    }
}

int calculateScore(int player) {
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; frame++) {
        if (rolls[player][rollIndex] == 10) {
            score += 10 + rolls[player][rollIndex + 1] + rolls[player][rollIndex + 2];
            rollIndex++;
        } else if (rolls[player][rollIndex] + rolls[player][rollIndex + 1] == 10) {
            score += 10 + rolls[player][rollIndex + 2];
            rollIndex += 2;
        } else {
            score += rolls[player][rollIndex] + rolls[player][rollIndex + 1];
            rollIndex += 2;
        }
    }
    return score;
}

void printBoard(int player) {
    int rollIndex = 0;
    cout << endl << playerNames[player] << " | ";

    for (int frame = 0; frame < 10; frame++) {
        if (rolls[player][rollIndex] == 10) {
            cout << "X ";
            rollIndex++;
        } else {
            int a = rolls[player][rollIndex];
            int b = rolls[player][rollIndex + 1];

            cout << a;
            if (a + b == 10) {
                cout << "/";
            } else {
                cout << b;
            }
            cout << " ";
            rollIndex += 2;
        }
    }

    cout << "| Score: " << calculateScore(player) << endl;
}

void printAllBoards() {
    for (int i = 0; i < playersCount; i++) {
        printBoard(i);
    }
}

void saveGame() {
    char filename[60];
    buildFilename(filename, currentGameName);

    ofstream out(filename);
    if (!out) {
        cout << "Error opening file!" << endl;
        return;
    }

    out << playersCount << endl;
    out << currentFrame << endl;
    out << currentPlayer << endl;
    for (int i = 0; i < playersCount; i++) {
        out << playerNames[i] << endl;
        out << rollsCount[i] << endl;
        for (int r = 0; r < rollsCount[i]; r++) {
            out << rolls[i][r] << ' ';
        }
        out << endl;
    }
    out.close();
}

bool loadGame(const char* gameName) {
    char filename[60];
    buildFilename(filename, gameName);

    ifstream in(filename);
    if (!in) {
        cout << "Error opening file!" << endl;
        return false;
    }

    in >> playersCount >> currentFrame >> currentPlayer;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < playersCount; i++) {
        in.getline(playerNames[i], MAX_NAME_LEN);
        in >> rollsCount[i];
        for (int r = 0; r < rollsCount[i]; r++) {
            in >> rolls[i][r];
        }
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    in.close();
    return true;
}

bool loadGamesList(char games[][MAX_GAME_NAME], int& count) {
    ifstream in("games.txt");
    if (!in) {
        cout << "Error opening games.txt" << endl;
        return false;
    }

    count = 0;
    while (in.getline(games[count], MAX_GAME_NAME)) {
        if (strlen(games[count]) > 0) {
            count++;
        }
    }
    in.close();
    return count > 0;
}

void registerGame() {
    ofstream out("games.txt", std::ios::app); // with std::ios::app we append to the current file,
                                                      // instead of overwriting it
    if (!out) {
        cout << "Error opening file" << endl;
        return;
    }

    out << currentGameName << endl;
    out.close();
}

void gameLoop() {
    while (currentFrame < 10) {
        printAllBoards();

        cout << "\nNext player: " << playerNames[currentPlayer] << endl;
        cout << "\n1. Next throw\n2. Save game\n3. Exit to menu\nChoice: ";
        int c;
        cin >> c;
        cin.ignore();

        if (c == 1) {
            playFrame(currentPlayer, currentFrame);
            currentPlayer++;

            if (currentPlayer == playersCount) {
                currentPlayer = 0;
                currentFrame++;
            }
        } else if (c == 2) {
            saveGame();
            cout << "Game saved.\n";
        } else {
            return;
        }
    }

    printAllBoards();
    saveGame();
    cout << "\nGame finished!\n";
}

int main() {
    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. New Game\n2. Load Game\n3. Exit\nChoice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            resetGame();

            cout << "Game name: ";
            cin.getline(currentGameName, MAX_GAME_NAME);
            registerGame();

            cout << "Players count: ";
            cin >> playersCount;
            cin.ignore();

            for (int i = 0; i < playersCount; i++) {
                cout << "Player " << i + 1 << " name: ";
                cin.getline(playerNames[i], MAX_NAME_LEN);
            }
            saveGame();
            gameLoop();
        } else if (choice == 2) {
            char games[MAX_GAMES][MAX_GAME_NAME];
            int gamesCount;

            if (!loadGamesList(games, gamesCount)) {
                cout << "No saved games.\n";
                continue;
            }

            cout << "\nSaved games:\n";
            for (int i = 0; i < gamesCount; i++) {
                cout << i + 1 << ". " << games[i] << endl;
            }

            cout << "Choose game: ";
            int gameNumber;
            cin >> gameNumber;
            cin.ignore();

            if (gameNumber < 1 || gameNumber > gamesCount) {
                cout << "Invalid choice.\n";
                continue;
            }

            if (loadGame(games[gameNumber - 1])) {
                gameLoop();
            } else {
                cout << "Failed to load game.\n";
            }
        }
        else {
            break;
        }
    }

    return 0;
}
