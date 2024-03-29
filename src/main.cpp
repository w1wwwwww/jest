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

#include <iostream>
#include <string>

#include "chess.hpp"
#include "search.hpp"

int main()
{
    Board board = Board();

    std::string input;
    while(true)
    {
        std::cin >> input;
        Move move = uci::uciToMove(board, input);
        board.makeMove(move);
        move = RSearch(board, 5);
        board.makeMove(move);
        std::cout << move << std::endl;
    }

    return 0;
}