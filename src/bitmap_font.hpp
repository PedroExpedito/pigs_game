#ifndef __BITMAP_FONT_HPP
#define __BITMAP_FONT_HPP

#include <Vector2D.hpp>
#include <map>

class MonogramFont {
public:
    static auto const charmap()
    {
        return std::map<char, Vector2D<int>> {
            { ' ', { 10, 6 } },

            { '+', { 14, 0 } },
            { '-', { 15, 0 } },
            { '=', { 16, 0 } },
            { '/', { 17, 0 } },
            { '\\', { 18, 0 } },
            { '*', { 19, 0 } },
            { ':', { 20, 0 } },
            { ';', { 21, 0 } },
            { '(', { 14, 1 } },
            { ')', { 15, 1 } },
            { '[', { 16, 1 } },
            { ']', { 17, 1 } },
            { '{', { 18, 1 } },
            { '}', { 19, 1 } },
            { '<', { 20, 1 } },
            { '>', { 21, 1 } },
            { '!', { 14, 2 } },
            { '?', { 15, 2 } },
            { '.', { 16, 2 } },
            { ',', { 17, 2 } },
            { '\'', { 18, 2 } },
            { '"', { 19, 2 } },
            { '&', { 20, 2 } },
            { '#', { 14, 3 } },
            { '%', { 15, 3 } },

            { '1', { 0, 6 } },
            { '2', { 1, 6 } },
            { '3', { 2, 6 } },
            { '4', { 3, 6 } },
            { '5', { 4, 6 } },
            { '6', { 5, 6 } },
            { '7', { 6, 6 } },
            { '8', { 7, 6 } },
            { '9', { 8, 6 } },
            { '0', { 9, 6 } },

            { 'A', { 0, 0 } },
            { 'B', { 1, 0 } },
            { 'C', { 2, 0 } },
            { 'D', { 3, 0 } },
            { 'E', { 4, 0 } },
            { 'F', { 5, 0 } },
            { 'G', { 6, 0 } },
            { 'H', { 7, 0 } },
            { 'I', { 8, 0 } },
            { 'J', { 9, 0 } },
            { 'K', { 10, 0 } },
            { 'L', { 11, 0 } },
            { 'M', { 12, 0 } },
            { 'N', { 0, 1 } },
            { 'O', { 1, 1 } },
            { 'P', { 2, 1 } },
            { 'Q', { 3, 1 } },
            { 'R', { 4, 1 } },
            { 'S', { 5, 1 } },
            { 'T', { 6, 1 } },
            { 'U', { 7, 1 } },
            { 'V', { 8, 1 } },
            { 'W', { 9, 1 } },
            { 'X', { 10, 1 } },
            { 'Y', { 11, 1 } },
            { 'Z', { 12, 1 } },

            { 'a', { 0, 3 } },
            { 'b', { 1, 3 } },
            { 'c', { 2, 3 } },
            { 'd', { 3, 3 } },
            { 'e', { 4, 3 } },
            { 'f', { 5, 3 } },
            { 'g', { 6, 3 } },
            { 'h', { 7, 3 } },
            { 'i', { 8, 3 } },
            { 'j', { 9, 3 } },
            { 'k', { 10, 3 } },
            { 'l', { 11, 3 } },
            { 'm', { 12, 3 } },
            { 'n', { 0, 4 } },
            { 'o', { 1, 4 } },
            { 'p', { 2, 4 } },
            { 'q', { 3, 4 } },
            { 'r', { 4, 4 } },
            { 's', { 5, 4 } },
            { 't', { 6, 4 } },
            { 'u', { 7, 4 } },
            { 'v', { 8, 4 } },
            { 'w', { 9, 4 } },
            { 'x', { 10, 4 } },
            { 'y', { 11, 4 } },
            { 'z', { 12, 4 } },
        };
    }
};

#endif
