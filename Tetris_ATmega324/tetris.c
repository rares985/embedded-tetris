#include "tetris.h"



void draw_block(uint8_t x, uint8_t y, uint8_t size)
{
	int i,j;

	for(i = x; i < x + size; i++) {
		for(j = y; j < y + size; j++) {
			nokia_lcd_set_pixel(i,j,1);
		}
	}
}
void draw_tetromino(char type, int rotation, uint8_t x, uint8_t y)
{
	switch(type)
	{
		case 'I':
			break;
		case 'O':
			break;
		case 'L':
			break;
		case 'T':
			break;
		case 'Z':
			break;
		default:
			break;
	}
}


