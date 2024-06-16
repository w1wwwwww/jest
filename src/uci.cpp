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

#include "uci.hpp"

#include <iostream>
#include <sstream>
#include <string>

#include "chess.hpp"
#include "search.hpp"

// TODO: finish uci implementation
void Uci(void)
{
    Board board;
    std::string input = " ";

    while(input != "quit")
    {
        std::cin >> input;
        std::istringstream inputStream(input);

        if(input == "uci")
        {
            std::cout << "option name Hash type spin default 1 min 1 max 1" << std::endl;
            std::cout << "option name Threads type spin default 1 min 1 max 1" << std::endl;
            std::cout << "uciok" << std::endl;
        } else if(input == "isready")
        {
            std::cout << "readyok" << std::endl;
        } else if(input == "position")
        {
            inputStream >> input;

            if(input == "startpos")
            {
                board = Board();
            } else if(input == "fen")
            {
                inputStream >> input;
                board = Board(input);
            }
        } else if(input == "go")
        {
            Move move = RSearch(board, 5);
            board.makeMove(move);
            std::cout << move << std::endl;
        }
    }
}