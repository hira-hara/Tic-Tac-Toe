#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include "board.cpp"
using namespace std;

class gamePlay: public Board  {

    private:
        string player1;
        string player2;
        char player1Symbol;
        char player2Symbol;
        Board board;            // Is this correct to use? 
        

    public:
        std::string starter;
    
        void introGame() {
            cout << "-------------------------------------------";
            cout << "WELCOME TO THE TIC-TAC-TOE GAME MADE BY IDA SU OZDEMIR :>";
            cout << "-------------------------------------------\n";

            cout << "You are player1, please enter your name: ";
            cin >> player1;
            cout << "Hi " << player1 << "!\n";

            cout << "You are player2, please enter your name: ";
            cin >> player2;
            cout << "Hi " << player2 << "!\n";
        }

        void randomChooser() {
            cout << "-------------------------------------\n";
            cout << "The symbols will be chosen randomly!\n";
            cout << "-------------------------------------\n";

            cout << "\n";

            srand(time(NULL));
            int num = rand() % 2;       // to choose between who gets X (1) and O (0)

            if (num == 1) {
                player1Symbol = 'X';
                player2Symbol = 'O';

                cout << player1 << " you will get X as your symbol.\n";
                cout << player2 << " you will get O as your symbol.\n";
                
            } else {
                player1Symbol = 'O';
                player2Symbol = 'X';

                cout << player1 << " you will get O as your symbol.\n";
                cout << player2 << " you will get X as your symbol.\n";
            }

            cout << "\n";

            starter = (player1Symbol == 'X' ? player1 : player2);
            cout << "Whoever has the X will start first, so " << starter << "\n";
        }

        void playerMoves() {
            vector<int> tileChosenL (2);
            int tile;
            

            cout << starter << " what is your move (enter board tile rowcolumn): \n";
            cin >> tile;
            tileChosenL[0] = tile / 10;
            tileChosenL[1] = tile % 10;
        }
};



int main(){
    Board board;
    gamePlay game;
    game.introGame();
    game.randomChooser();
    board.boardDisplay();
    game.playerMoves();
    return 0;
}


