#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

string FindPlayerName(string players[], bool playerTurn);
void getUserData(string names[]);
int askMove(string names[], int chipsInPile, bool player1Turn);


int main() {

    bool player1Turn = true;

    bool gameOver = false;

    int chipsInPile = 0;
    int chipsTaken;
    int MaxChipsTakenPerTurn;
    string playerNames[2];
    char userChoice;

    // seed the random number generator
    srand(time(0));

    // Get the names of the players and store them in array
    getUserData(playerNames);

    //start the game with a random number of chips in pile
    
    // cout << "You can take upto " << MaxChipsTakenPerTurn << endl;
    do {
        chipsInPile = (rand() % MAX_CHIPS) + 1;
    
        cout << "This round will start with " << chipsInPile << " chips in pile" << endl;
        gameOver = false;

        while (gameOver == false) {
            chipsTaken = askMove(playerNames, chipsInPile, player1Turn);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in the bag" << endl;
            player1Turn = !player1Turn;
            if (chipsInPile == 0) {
                gameOver = true;
                cout << FindPlayerName(playerNames, player1Turn) << ", Congratulations!! You are the winner" << endl;
            }

        }

        cout << "Do you wish to play again (Y/N)?" << endl;
        cin >> userChoice;
    }while((userChoice == 'Y') || (userChoice == 'y'));

   // chipsTaken = (rand() % MaxChipsTakenPerTurn) + 1;

   // cout << "Number Taken: " << chipsTaken << endl;


    return 0;



}

void getUserData(string players[]) {
    cout << "Player 1, Please enter your name" << endl;
    cin >> players[0];
    cout << "Thanks and Good Luck!!" << endl; 
    cout << "Player 2, Please enter your name" << endl << "If you wish to play againt the computer, type AI" << endl;
    cin >> players[1];
    cout << "Thanks and Good Luck!!";
}

int askMove(string names[], int chipsInPile, bool player1Turn) {
    
    int chipsTaken = 0;
    int MaxChipsTakenPerTurn = MAX_TURN * chipsInPile;

    do {
        
        cout << FindPlayerName(names, player1Turn) << ", How many chips would you like?" << endl;

        cout << "You can take upto ";
        if (MaxChipsTakenPerTurn == 0) {
            cout << "1" << endl;
        }
        else {
            cout << MaxChipsTakenPerTurn << endl;
        }

        if (FindPlayerName(names, player1Turn) == "AI") {
            if (MaxChipsTakenPerTurn == 0) {
                chipsTaken = 1;
            }
            else {
                chipsTaken = (rand() % MaxChipsTakenPerTurn) + 1;
            }
        }
        else {
            cin >> chipsTaken;
        }
    }while((chipsTaken > MaxChipsTakenPerTurn) && chipsInPile !=1);
    return chipsTaken;
}

string FindPlayerName(string names[], bool playerTurn) {
    if (playerTurn == true) 
        return names[0];
    else {
        return names[1];
    }
}