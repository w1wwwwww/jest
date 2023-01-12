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

#include "jest/game/piece.hpp"

namespace jest {
namespace game {
    Piece::Piece(uint64_t pos, uint8_t type, bool color):pos(pos), type(type), color(color) {
        switch(type) {
            case 0:
                value = 1;
                break;
            
            case 1 || 2:
                value = 3;
                break;

            case 3:
                value = 5;
                break;
            
            case 4:
                value = 9;
                break;
            
            case 5:
                value = 127;
                break;
        }

        if(!color) {
            value = -value;
        }
    }
} // namespace game
} // namespace jest