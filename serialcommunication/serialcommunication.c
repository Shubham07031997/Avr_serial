#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>
#include<serial.h>

unsigned char v;
void main()
{
DDRB=0XFF;
lcd_init();
usart_init();

while(1)

{
lcd_command(0x80);
lcd_string("WELCOME");
usart_string("WELCOME TO SERIAL");

for(int x=0XC0;x<=0XCF;x++)
{
v=usart_rec();
lcd_command(x);
lcd_data(v);
lcd_command(0x06);
_delay_ms(10);
}
}
}
