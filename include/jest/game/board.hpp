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

#ifndef BOARD_H
#define BOARD_H 1

#include <cstdint>

namespace jest {
namespace game {
    class Board {
        public:
            uint64_t pieces = wPieces | bPieces;

            uint64_t wPieces = wPawn | wRook | wKnight | wBishop | wQueen | wKing;
            uint64_t wPawn;
            uint64_t wRook;
            uint64_t wKnight;
            uint64_t wBishop;
            uint64_t wQueen;
            uint64_t wKing;

            uint64_t bPieces = bPawn | bRook | bKnight | bBishop | bQueen | bKing;
            uint64_t bPawn;
            uint64_t bRook;
            uint64_t bKnight;
            uint64_t bBishop;
            uint64_t bQueen;
            uint64_t bKing;

            uint64_t ep;

            uint8_t castle;

            // true = w, false = b
            bool move;

        private:
            const uint64_t empty = 0;
            const uint64_t universe = 18446744073709551615ULL;
    };
} // namespace game
} // namespace jest

#endif