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


#ifndef UCI_H
#define UCI_H 1

#include <string>

#include "jest/game/board.hpp"

namespace jest {
    class Uci {
        public:
            Uci(int argc, char* argv[]);

        private:
            std::string input;
            
            const std::string startFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

            game::Board mainBoard;

            void Loop(int argc, char* argv[]);
    };
} // namespace jest

#endif