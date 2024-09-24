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
        int moves = 0;
        string turn;            // needed for knowing which symbol to use
        Board board;            // Is this correct to use? 
        

    public:
        std::string starter;
    
        void introGame() {
            cout << "---------------------------------------------------------\n";
            cout << "WELCOME TO THE TIC-TAC-TOE GAME MADE BY IDA SU OZDEMIR :>\n";
            cout << "---------------------------------------------------------\n";

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

                turn = player1;
                
            } else {
                player1Symbol = 'O';
                player2Symbol = 'X';

                cout << player1 << " you will get O as your symbol.\n";
                cout << player2 << " you will get X as your symbol.\n";

                turn = player2;
            }

            cout << "\n";

            starter = (player1Symbol == 'X' ? player1 : player2);
            cout << "Whoever has the X will start first, so " << starter << "\n";
        }


        void playerMove() {          // when player move is called, after another function must switch the turn of the players
            vector<int> tileChosenL (2);                // In order to save the tile in a sort of list where the indexes can be accessed
            int tile;

            cout << turn << " what is your move (enter board tile rowcolumn): \n";
            cin >> tile;
            tileChosenL[0] = tile / 10;
            tileChosenL[1] = tile % 10;

            if (turn == player1) {
                moveOnBoard(tileChosenL, board, player1Symbol);
            } else {
                moveOnBoard(tileChosenL, board, player2Symbol);
            }
        }

        void moveOnBoard(vector<int> move, Board& board, char value) { // we're passing board as a reference
            // Should display the board when moved
            moves += 1;
            board.setTile(move[0], move[1], value);
            board.boardDisplay();
        }

        void swapPlayer() {
            if (turn == player1) {
                turn = player2;
            } else {
                turn  = player1;
            }
        }


        void gameLogic() {
            while (moves < 5) {
                playerMove();
                swapPlayer();
                }
        }       // NOW ADD THE REAL LOGIC WHERE YOU CHECK IF ANYONES WINNING OR TIE
            // while (checkBoardFull == false) {
            //     //play (1st), play, play, play (4th), play (5th), check 
                
            // }
            // when its out of the loop without any wins then automatic tie
};



int main(){
    Board board;
    gamePlay game;
    game.introGame();
    game.randomChooser();
    board.boardDisplay();
    game.gameLogic();
    return 0;
}


