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

#include "eval.hpp"

#include <utility>

#include "chess.hpp"

constexpr int PVals[5] = { 100, 320, 330, 500, 900 };
constexpr PieceType pt[5] = { PieceType("p"), PieceType("n"), PieceType("b"), PieceType("r"), PieceType("q") }; // TODO: make this better

int Eval(Board& pos, int depth)
{
    std::pair<GameResultReason, GameResult> result = pos.isGameOver();
    if(result.first == GameResultReason::CHECKMATE)
        return -1000 - depth;
    else if(result.second == GameResult::DRAW)
        return 0;

    int eval = 0;
    for(int i = 0; i < 5; i++)
    {
        eval += (pos.us(pos.sideToMove()) & pos.pieces(pt[i])).count() * PVals[i];
        eval -= (pos.us(~pos.sideToMove()) & pos.pieces(pt[i])).count() * PVals[i];
    }

    // mobility bonus
    Movelist moves;
    movegen::legalmoves(moves, pos);
    eval += moves.size() * 10;
    pos.makeNullMove();
    movegen::legalmoves(moves, pos);
    eval -= moves.size() * 10;
    pos.unmakeNullMove();

    return eval;
}