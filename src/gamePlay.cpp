#include <iostream>
#include <ctime> 
#include <random>
#include "board.cpp"
using namespace std;

class gamePlay: public Board  {

    private:
        std::string player1;
        std::string player2;
        char turn;

    public:
    
        void introGame() {
            cout << "-------------------------------------------";
            cout << "WELCOME TO THE TIC-TAC-TOE GAME MADE BY IDA SU OZDEMIR :>";
            cout << "-------------------------------------------\n";

            cout << "You are player1, please enter your name: ";
            cin >> player1;
            cout << "Hi " << player1 << "\n";

            cout << "You are player2, please enter your name: ";
            cin >> player2;
            cout << "Hi " << player2 << "\n";
        }

        void randomChooser() {
            cout << "-------------------------------------\n";
            cout << "The symbols will be chosen randomly!\n";
            cout << "-------------------------------------\n";

            srand(time(NULL));
            int num = rand() % 2;       // to choose between who gets X (1) and O (0)

            if (num == 1) {
                cout << player1 << " you will get X as your symbol.\n";
                cout << player2 << " you will get O as your symbol.\n";
            } else {
                cout << player1 << " you will get O as your symbol.\n";
                cout << player2 << " you will get X as your symbol.\n";
            }
        }

        void playerMoves() {
            


        }



};



int main(){
    Board board;
    gamePlay game;
    game.introGame();
    game.randomChooser();
    return 0;
}


