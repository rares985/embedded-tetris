#ifndef TETRIS_H_
#define TETRIS_H_

#include "nokia5110.h"

#define BOARD_HEIGHT 21
#define BOARD_WIDTH 12

#define SIZE 4


void draw_block(uint8_t x, uint8_t y, uint8_t size);
void draw_tetromino(char type, int rotation, uint8_t x, uint8_t y);


#endif