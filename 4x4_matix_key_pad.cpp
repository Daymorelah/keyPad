/*
 * _4x4_matix_key_pad.cpp
 *
 * Created: 3/21/2016 6:44:29 PM
 *  Author: LENOVO PC
 */ 


# include <avr/io.h>
# include "lcd-/LCD2.h"
# define F_CPU 16000000UL
# include <util/delay.h>

int main(void)
{
	controlDDR = 0x0F; // declare data port of LCD as output
	PORTC |= 0xF0 ; // enable internal pull-up for pin1 to pin7 and high impedance for pin0 to pin3
	commmand(0x38) ;
	_delay_ms(500) ;
	commmand(0x01) ;
	_delay_ms(500) ;
    commmand(0x0E) ;
    _delay_ms(300) ;
	send_string(" Welcome ! ");
	_delay_ms(500);
	commmand(0x01);
	_delay_ms(500);
	send_string(" Enter a key: ");
	_delay_ms(500);
	commmand(0x01);
	_delay_ms(500);
	static uint8_t key_num, t =0;
	while(1)
    {
		for (uint8_t y=0; y<4; y++)
		{
			DDRC &= ~(0xFF) ; // declare all portB pins as inputs
			DDRC |= (0x01<<y);
			for (uint8_t w=0; w<=3; w++)
			{
				if (!(PINC & (0x10<<w)))
				{
					 t = ( ( (3 - w ) * 4 ) + ( 4 - y ) ) ;
				switch (t)
					{
						case 1:
						send_variable(t);
						_delay_ms(500);key_num++;
						break;
						case 2:
						send_variable(t);
						_delay_ms(500);key_num++;
						break;
						case 3:
						send_variable(t);
						_delay_ms(500);key_num++;
						break;
						case 4:
						character('A');
						_delay_ms(500);key_num++;
						break;
						case 5:
						send_variable(4);
						_delay_ms(500);key_num++;
						break;
						case 6:
						send_variable(5);
						_delay_ms(500);key_num++;
						break;
						case 7:
						send_variable(6);
						_delay_ms(500);key_num++;
						break;
						case 8:
						character('B');
						_delay_ms(500);key_num++;
						break;
						case 9:
						send_variable(7);
						_delay_ms(500);key_num++;
						break;
						case 10:
						send_variable(8);
						_delay_ms(500);key_num++;
						break;
						case 11:
						send_variable(9);
						_delay_ms(500);key_num++;
						break;
						case 12:
						character('C');
						_delay_ms(500);key_num++;
						break;
						} // end of switch statement
						if (t==13)
						{
							character('*');
							_delay_ms(500);
							key_num++;
						} // end of if statement
						if (t==14)
						{
							send_variable(0);
							_delay_ms(500);
							key_num++;
						} // end of if statement
						if (t==15)
						{
						character('#');
						_delay_ms(500);
						key_num++;
						} // end of if statement
						if (t==16)
						{
							character('D');
							_delay_ms(500);
							key_num++;
						} //end of if statement
					t=0; // set t back to 0
			if (key_num==16)
			{
				key_num=0;
				commmand(0x01);
		} // end of key_num if statement
    } // end of button_pressed if statement
    } // end of Row for loop
    } // end of Column for loop
	} // end of while loop
} // end of function main