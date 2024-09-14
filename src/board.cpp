#include <iostream>
using namespace std;

void boardDisplay(char board[3][3]) {
    cout << "-------------------------\n";
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            cout << board[j][i] << "|\t";
        }
        cout << "|";
        cout << "\n";
        cout << "-------------------------\n";
    }
}


int main(){
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } };

    boardDisplay(board);
    return 0;
}

