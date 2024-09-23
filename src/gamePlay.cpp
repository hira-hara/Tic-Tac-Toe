#include <iostream>
#include "board.cpp"
using namespace std;

class gamePlay: public Board  {



int main(){
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } };

    boardDisplay();
    return 0;
}

};


