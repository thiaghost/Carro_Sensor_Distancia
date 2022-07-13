
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

volatile float limite = 1176.6;

void init_IO(){
	DDRB = (1<<3);
	DDRD = (1<<2) + (1<<4) + (1<<6) + (1<<7);
}

void frente(){
	PORTD |= (1<<7);
	PORTD &= ~(1<<6);
	OCR2A = 200;
}

void ligar_timer(){
	TCCR1B = 0x03;
	TCNT1 = 0;
}

int32_t sensor_distancia(){
	int32_t tempo;
	PORTD &= ~(1<<4); //deixar em low
	_delay_us(5);
	PORTD |= (1<<4); //deixar em high
	_delay_us(10);
	PORTD &= ~(1<<4); //deixar em low
	ligar_timer();
	while(!(PIND & (1<<2)));
	tempo = TCNT1 * 4L;
	
}

void tras(){
	PORTD |= (1<<6);
	PORTD &= ~(1<<7);
	OCR2A = 255;
}

void parar(){
	PORTD |= (1<<6);
	PORTD |= (1<<7);
}

void init_pwm(){
	OCR2A = 200;
	TCCR2A = (1<<COM2A1) | (1<<WGM21) | (1<<WGM20);
	TCCR2B = (1<<CS21);	
}

int main(void)
{	
	int32_t x;
	init_IO();
	init_pwm();
    /* Replace with your application code */
    while (1) 
    {
		frente();
		if( sensor_distancia() <= limite)
		{
			tras();
			_delay_ms(300);
			parar();
			_delay_ms(100);
		}			
    }
}

