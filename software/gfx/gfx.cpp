#include <string>
#include <iostream>
#include "font.hpp"

// basically just swaps the two so that a is smaller than b.
#define GFX_SWAP(a, b) if (a > b) { std::swap(a, b); };

// used to draw things to the screen
class Gfx {
  public:
    // stores the colour that it is currently drawing with.
    int color;

    // draws a pixel on the screen
    void pixel(int x, int y) {
      // code here to paint one dot to the screen.
      std::cout << "(";
      std::cout << x;
      std::cout << ", ";
      std::cout << y;
      std::cout << ") \n";
    };

    // draws a horizontal line connecting the two x points at the y position specified
    void fastHLine(int y, int x1, int x2) {
      GFX_SWAP(x1, x2);
      for (int x = x1; x <= x2; x++) {
        pixel(x, y);
      };
    };

    // draws a vertical line connecting the two y points at the x position specified
    void fastVLine(int x, int y1, int y2) {
      GFX_SWAP(y1, y2);
      for (int y = y1; y <= y2; y++) {
        pixel(x, y);
      };
    };

    // draws an empty rectangle given the two points.
    void rectangle(int x1, int y1, int x2, int y2) {
      // top and bottom
      fastHLine(y1, x1, x2);
      fastHLine(y2, x1, x2);
      // left and right;
      fastVLine(x1, y1, y2);
      fastVLine(x2, y1, y2);
      // NOTE: this does result in duplicate points on the corners where the lines overlap.
      // TODO: investigate whether it is quicker to leave the duplicates there, or to do the maths to remove them here.
    };

    // draws a filled rectangle given the two points.
    void rectangleF(int x1, int y1, int x2, int y2) {
      GFX_SWAP(y1, y2);
      for (int y = y1; y <= y2; y++) {
        fastHLine(y, x1, x2);
      };
    };

    // draws the letter to the screen, at the specified position.
    void letter(char l, int x, int y) {
      // get the pixels of the font via font.hpp
      // offset them by x and y.
      std::cout << "drawing letter ";
      std::cout << l;
      std::cout << "\n";
    };

    // draws the string to the screen, at the specified position
    void str(std::string str, int x, int y) {
      // the offset is there because it places spacing before the character
      int currWidth = -LETTER_SPACING;
      for (int i = 0; i < str.length(); i++) {
        letter(str[i], currWidth + LETTER_SPACING, y);
        currWidth += (LETTER_WIDTH + LETTER_SPACING);
      };
    };
};

int main() {
  Gfx gfx;
  gfx.color = 0xffffff;
  gfx.str("hello", 2, 5);
  gfx.line(1, 1, 2, 4);
  
  return 0;
}
