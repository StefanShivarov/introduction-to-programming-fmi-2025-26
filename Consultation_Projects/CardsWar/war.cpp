#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

const int DECK_SIZE = 52;
const char* SAVE_FILE = "war_game.txt";

int deck1[DECK_SIZE], deck2[DECK_SIZE];
int deck1Top = 0, deck1End = 0;
int deck2Top = 0, deck2End = 0;

mt19937 randomGenerator(std::random_device{}()); // random generator

void cardToString(int card, char* out) {
    int value = card % 13 + 2; // 0->2, 12->14 (A)

    if (value <= 10) {
        if (value == 10) {
            out[0] = '1';
            out[1] = '0';
            out[2] = '\0';
            return;
        } else {
            out[0] = '0' + value;
        }
    } else if (value == 11) {
        out[0]='J';
    }
    else if (value == 12) {
        out[0]='Q';
    }
    else if (value == 13) {
        out[0]='K';
    }
    else {
        out[0]='A';
    }
    out[1]='\0';
}

int cardsLeft(int top, int end) {
    return (end - top + DECK_SIZE) % DECK_SIZE;
}

int drawCard(const int* deck, int &top) {
    int card = deck[top];
    top = (top + 1) % DECK_SIZE;
    return card;
}

void addCards(int* deck, int &end, int card1, int card2) {
    deck[end] = card1;
    end = (end + 1) % DECK_SIZE;
    deck[end] = card2;
    end = (end + 1) % DECK_SIZE;
}

void playRound() {
    if (cardsLeft(deck1Top, deck1End) == 0 || cardsLeft(deck2Top, deck2End) == 0) {
        return;
    }

    int card1 = drawCard(deck1, deck1Top);
    int card2 = drawCard(deck2, deck2Top);

    char c1[3], c2[3];
    cardToString(card1, c1);
    cardToString(card2, c2);
    cout << "Player 1 plays " << c1 << " | Player 2 plays " << c2 << endl;

    if (card1 > card2) {
        addCards(deck1, deck1End, card1, card2);
        cout << "Player 1 wins the round." << endl;
    } else if (card2 > card1) {
        addCards(deck2, deck2End, card1, card2);
        cout << "Player 2 wins the round." << endl;
    } else {
        cout << "Tie! Cards remain on table." << endl;
    }
}

void saveGame() {
    ofstream out(SAVE_FILE);
    if (!out) {
        cout << "Failed to save game" << endl;
        return;
    }

    out << deck1Top << ' ' << deck1End << endl;
    for (int i = 0; i < DECK_SIZE; i++) {
        out << deck1[i] << ' ';
    }
    out << endl;
    out << deck2Top << ' ' << deck2End << endl;
    for (int i = 0; i < DECK_SIZE; i++) {
        out << deck2[i] << ' ';
    }
    out << endl;

    out.close();
    cout << "Game saved." << endl;
}

bool loadGame() {
    ifstream in(SAVE_FILE);
    if (!in) {
        cout << "Failed to open file!";
        return false;
    }

    in >> deck1Top >> deck1End;
    for (int i = 0; i < DECK_SIZE; i++) {
        in >> deck1[i];
    }

    in >> deck2Top >> deck2End;
    for (int i = 0; i < DECK_SIZE; i++) {
        in >> deck2[i];
    }

    in.close();
    return true;
}

void newGame() {
    if (cardsLeft(deck1Top, deck1End) > 0 || cardsLeft(deck2Top, deck2End) > 0) {
        cout << "A game is already in progress. Finish or save it first.\n";
        return;
    }

    int fullDeck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        fullDeck[i] = i % 13;
    }
    shuffle(fullDeck, fullDeck + DECK_SIZE, randomGenerator);

    deck1Top = deck2Top = 0;
    deck1End = deck2End = 0;

    for (int i = 0; i < DECK_SIZE; i++) {
        if (i % 2 == 0) {
            deck1[deck1End++] = fullDeck[i];
        }
        else {
            deck2[deck2End++] = fullDeck[i];
        }
        deck1End %= DECK_SIZE;
        deck2End %= DECK_SIZE;
    }

    cout << "New game started!\n";
}

void gameLoop() {
    while (cardsLeft(deck1Top, deck1End) > 0 && cardsLeft(deck2Top, deck2End) > 0) {
        cout << "\n1. Play next round\n2. Save game\n3. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            playRound();
        }
        else if (choice == 2) {
            saveGame();
        }
        else {
            return;
        }

        cout << "Player1 cards left: " << cardsLeft(deck1Top, deck1End)
             << " | Player2 cards left: " << cardsLeft(deck2Top, deck2End) << "\n\n";
    }

    if (cardsLeft(deck1Top, deck1End) == 0) {
        cout << "Player 2 wins the game!\n";
    } else if (cardsLeft(deck2Top, deck2End) == 0) {
        cout << "Player 1 wins the game!\n";
    }

    deck1Top = deck1End = deck2Top = deck2End = 0;
}

int main() {
    while (true) {
        cout << "\n--- WAR GAME MENU ---\n";
        cout << "1. Start / Continue Game\n";
        cout << "2. Save Game\n";
        cout << "3. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (!loadGame()) {
                newGame();
            }
            else {
                cout << "Loaded saved game.\n";
            }
            gameLoop();
        }
        else if (choice == 2) {
            saveGame();
        }
        else {
            break;
        }
    }

    return 0;
}
