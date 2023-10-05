#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "nokia5110.h"
#include "tetris.h"


#define RESET PD7
#define BTN PD6

#define LEFT PD5
#define RIGHT PD4
#define DOWN PD3
#define UP PD2

int game_over = 0;
int score = 0;

ISR(PCINT3_vect)
{
	if ((PIND & (1 << BTN)) == 0) {
		game_over = 1;
		nokia_lcd_clear();
	}
	// else if ((PIND & (1 << UP)) == 0) {

	// }
	// else if ((PIND & (1 << DOWN)) == 0) {

	// }
	// else if ((PIND & (1 << LEFT)) == 0) {

	// }
	// else if ((PIND & (1 << RIGHT)) == 0) {

	// }
}


int main(void) {

	int i,j;

	sei(); /* enable global interrupts */
	
	PCICR |= (1 << PCIE3);

	/* Setam pinii ca intrare */
	DDRD &= ~(1 << BTN);

	// DDRD &= ~(1 << UP);
	// DDRD &= ~(1 << DOWN);
	// DDRD &= ~(1 << LEFT);
	// DDRD &= ~(1 << RIGHT);

	/* Activam rezistentele de pull-up pentru butoane */
	PORTD |= (1 << BTN);

	// PORTD |= (1 << UP);
	// PORTD |= (1 << DOWN);
	// PORTD |= (1 << LEFT);
	// PORTD |= (1 << RIGHT);


	PCMSK3 |= (1 << PCINT30); /* BTN */
	// PCMSK3 |= (1 << PCINT29); /* UP */ 
	// PCMSK3 |= (1 << PCINT28); /* DOWN */
	// PCMSK3 |= (1 << PCINT27); /* LEFT */
	// PCMSK3 |= (1 << PCINT26); /* RIGHT */


	/* Pornim LCD-ul */

	nokia_lcd_init();
	nokia_lcd_power(1);
	nokia_lcd_clear();

	char **blocks = (char**)calloc(BOARD_HEIGHT,sizeof(char*));
	for(i = 0; i < BOARD_HEIGHT; i++) {
		blocks[i] = (char*)calloc(BOARD_WIDTH,sizeof(char));
	}

	while(!game_over) {
		nokia_lcd_clear();
		nokia_lcd_render();
		_delay_ms(200);
	}
	free(blocks);


	char end[21][12] = {{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{0,1,1,0, 0,0,0,0,0,0,0,0},
						{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,0,0,0, 0,0,0,0,0,0,0,0},
						{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,0,0,0, 0,0,0,0,0,0,0,0},
						{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,1,1,1, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{1,1,1,0, 0,0,0,0,0,0,0,0},
						{1,0,1,0, 0,0,0,0,0,0,0,0},
						{1,0,0,1, 0,0,0,0,0,0,0,0},
						{0,0,0,0, 0,0,0,0,0,0,0,0}};

	for(i = 0; i < BOARD_HEIGHT; i++) {
		for(j = 0; j < BOARD_WIDTH; j++) {
			if (end[i][j])
				draw_block(i*SIZE,j*SIZE,SIZE);
		}
	}


	return 0;
}