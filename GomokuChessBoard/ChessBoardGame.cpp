//
//  ChessBoardGame.cpp
//  GomokuChessBoard
//
//  Created by Suu on 15/01/2016.
//  Copyright © 2016 suu. All rights reserved.
//

#include "ChessBoardGame.hpp"

using namespace std;

ChessBoardGame::ChessBoardGame()
{
    this->started = 0;
}

int ChessBoardGame::P1()
{
    //Add AI here
    //this->myBoard->getChessBoard(int board[15][15]);
    //this->LastStep
    
    int x;
    int y;
    printf("P1: ");
    scanf("%d, %d", &x, &y);
    return this->play(1, x, y);
}

int ChessBoardGame::P2()
{
    //Add AI here
    //this->myBoard->getChessBoard(int board[15][15]);
    //this->LastStep
    
    int x;
    int y;
    printf("P2: ");
    scanf("%d, %d", &x, &y);
    return this->play(2, x, y);
}

int ChessBoardGame::play(int player, int x, int y)
{
    if (this->myBoard.setOnChess(player, x, y))
    {
        gameover(player);
        return 1;
    }
    else
    {
        if (int win = this->myBoard.checkWin())
        {
            gameover(3 ^ win);
            return 1;
        }
        else
        {
            myBoard.printBoard();
            this->lastStep[0] = x;
            this->lastStep[1] = y;
        }
    }
 
    return 0;
}

void ChessBoardGame::startGame(int first)
{
    this->started = 1;
    this->myBoard.printBoard();
    if (first == 2)
    {
        if (P2())
        {
            gameover(2);
            return;
        }
    }
    
    while (this->started)
    {
        if (P1() || P2()) return;
    }
}

void ChessBoardGame::gameover(int lose)
{
    this->started = 0;
    this->myBoard.printBoard();
    int win = 3 ^ lose;
    cout << "Player " << win << " Wins" << endl;
}
