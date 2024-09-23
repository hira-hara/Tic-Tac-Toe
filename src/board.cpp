#include <iostream>
using namespace std;

class Board {

    private:
        char board[3][3];

    public: 
        Board() {                               // constructor to initialize board
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    board[j][i] = ' ';
                }
            }
        }

        void boardDisplay() {
            cout << "-------------------------\n";
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    cout << board[j][i] << "|\t";
                }
                cout << "|\n";
                cout << "-------------------------\n";
            }
        }

        char getTile(int row, int col) {
            return board[row][col];
        }


        void setTile(int row, int col, char value) {
            board[row][col] = value;
        }
};


