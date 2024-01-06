/*
    jest - a chess engine
    Copyright (C) 2024  Jake Senne

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "search.hpp"

#include "chess.hpp"
#include "eval.hpp"

int Search(Board& pos, int alpha, int beta, int depth, int dist);
int QSearch(Board& pos, int alpha, int beta, int dist);

Move RSearch(Board& pos, int depth)
{
    int max = -10001;
    int best = 0;
    int score;
    Movelist moves;
    movegen::legalmoves(moves, pos);

    int i = 0;
    for(const Move& move : moves)
    {
        pos.makeMove(move);
        score = -Search(pos, max, 10001, depth - 1, 1);
        pos.unmakeMove(move);

        if(score > max)
        {
            max = score;
            best = i;
        }

        i++;
    }

    return moves[best];
}

int Search(Board& pos, int alpha, int beta, int depth, int dist)
{
    if(depth == 0)
        return QSearch(pos, alpha, beta, dist);

    int score = -10001;
    Movelist moves;
    movegen::legalmoves(moves, pos);

    for(const Move& move : moves)
    {
        pos.makeMove(move);
        score = -Search(pos, -beta, -alpha, depth - 1, dist + 1);
        pos.unmakeMove(move);

        if(score >= beta)
            return beta;

        if(score > alpha)
            alpha = score;
    }

    return alpha;
}

int QSearch(Board& pos, int alpha, int beta, int dist)
{
    int standPat = Eval(pos, dist);

    if(standPat >= beta)
        return beta;
    
    if(standPat > alpha)
        alpha = standPat;
    
    int score;
    Movelist moves;
    movegen::legalmoves<movegen::MoveGenType::CAPTURE>(moves, pos);

    for(const Move& move : moves)
    {
        pos.makeMove(move);
        score = -QSearch(pos, -beta, -alpha, dist + 1);
        pos.unmakeMove(move);

        if(score >= beta)
            return beta;
        
        if(score > alpha)
            alpha = score;
    }

    return alpha;
}