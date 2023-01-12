# Jest is a UCI chess playing engine.
# Copyright (C) 2022-2023 Jake Senne

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

SDIR = src
IDIR = include

SOURCES = \
$(SDIR)/main.cpp \
$(SDIR)/uci.cpp \
$(SDIR)/game/piece.cpp

bin_PROGRAMS = jest
jest_SOURCES = $(SOURCES)

AM_CPPFLAGS = -Wall -Werror -Wextra -I $(IDIR)