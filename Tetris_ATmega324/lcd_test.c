#include <avr/io.h>
#include <util/delay.h>
#include "nokia5110.h"
#include "tetris.h"

int main(void) {

	nokia_lcd_init();
	nokia_lcd_power(1);
	nokia_lcd_clear();
	draw_block(10,10,5);
	nokia_lcd_render();
	while(1) {
		_delay_ms(1000);
	}
	return 0;
}