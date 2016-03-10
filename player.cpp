#include "player.h"

/* TESTING TO SEE IF GIT WORKS!!!! */

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    board = new Board();
    color = side;
}

/*
 * Destructor for the player.
 */
Player::~Player() {
    delete board;
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    if(color == WHITE)
    {
        board->doMove(opponentsMove, BLACK);
    }
    else
    {
        board->doMove(opponentsMove, WHITE);
    }
    Move m(0,0);
    int maxScore = -100;
    Move best(0,0);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            m.setX(i);
            m.setY(j);
            if (board->checkMove(&m, color))
            {
                Board* temp = board->copy();
                temp->doMove(&m, color);
                int score;
                if(color==BLACK)
                {
                    score = temp->countBlack()-temp->countWhite();
                }
                else
                {
                    score = temp->countWhite()-temp->countBlack();
                }
                score = multiplier(i, j, score);
                if (score > maxScore)
                {
                    best = m;
                    maxScore = score;
                }
            }
        }
    }
    if (!(board->checkMove(&best, color)))
    {
        return NULL;
    }
    board->doMove(&best, color);
    Move* previous = new Move(best.getX(), best.getY());
    return previous;
}

int multiplier(int x, int y, int score)
{
    if(x==0 || x==7)
    {
        if(y==0 || y==7)
        {
            return score+5;
        }
        else if(y==1 || y==6)
        {
            return score-2;
        }
        else
        {
            return score+3;
        }
    }
    else if(y==0 || y==7)
    {
        if(x==1 || x==6)
        {
            return score-2;
        }
        else
        {
            return score+3;
        }
    }
    else if(x==1 || x==6)
    {
        if(y==1 || y==6)
        {
            return score-3;
        }
        else
        {
            return score-1;
        }
    }
    else if(y==1 || y==6)
    {
        return score-1;
    }
    else
    {
        return score;
    }
}
