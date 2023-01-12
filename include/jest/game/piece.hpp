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

#ifndef PIECE_H
#define PIECE_H 1

#include <cstdint>

namespace jest {
namespace game {
    class Piece {
        public:
            // Position as a bitboard

            uint64_t pos;

            /*
                Piece type key:
                0: Pawn
                1: Knight
                2: Bishop
                3: Rook
                4: Queen
                5: King
            */

            const uint8_t type;

            /*
                Piece value key (if black make negative):

                1: Pawn
                3: Knight or Bishop
                5: Rook
                9: Queen
                127: King
            */

            int8_t value;

            /* 
                Piece color key:

                True: White
                False: Black
            */

            const bool color;

            Piece(uint64_t pos, uint8_t type, bool color);
    };
} // namespace game
} // namespace jest

#endif