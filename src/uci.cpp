/*
    Jest is a UCI chess playing engine.
    Copyright (C) 2022-2023 Jake Senne

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

#include <algorithm>
#include <iostream>
#include <sstream>

#include "jest/uci.hpp"

namespace jest {
    Uci::Uci(int argc, char* argv[]) {
        std::cout << "jest 0.0.1 by Jake Senne" << std::endl;
        Loop(argc, argv);
    }

    void Uci::Loop(int argc, char* argv[]) {
        std::string cmd, input;

        for(int i = 1; i < argc; i++) {
            cmd += std::string(argv[i]) + " ";
        }

        while(true) {
            if(argc == 1 && !getline(std::cin, cmd)) {
                cmd = "quit";
            }

            std::istringstream is(cmd);

            input.clear();

            is >> std::skipws >> input;

            if(input == "quit") {
                return;
            } else if(input == "uci") {
                std::cout << "id name jest 0.0.1\nid author Jake Senne\n" << std::endl;
                std::cout << "option name Threads type spin default 2 min 2 max 1024" << std::endl;
                std::cout << "uciok" << std::endl;
            } else if(input.find("setoption") != std::string::npos) {
                std::transform(input.begin(), input.end(), input.begin(), ::tolower);
                std::cout << input << std::endl;
            } else if(input == "isready") {
                std::cout << "readyok" << std::endl;
            } else if(input == "ucinewgame") {
                // clear move cache at some point
                std::cout << "isready" << std::endl;
            } else if(input == "go" || input == "stop") {
                const std::string bestMove = "e2e4 ponder c7c5";
                std::cout << "bestmove e2e4" << std::endl;
            } else {
                std::cout << "Unknown command: " << input << std::endl;
            }
        }
    }
} // namspace jest