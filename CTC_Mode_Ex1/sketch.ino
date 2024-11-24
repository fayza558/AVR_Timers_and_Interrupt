void timer1_init(){
TCNT1 = 0;
// prescaler 1024
TCCR1B |= (1 << CS12) | (1 << CS10);
TCCR1B &= ~(1 << CS11);
// Enable Overflow Interrupt
TIMSK1 |= (1 << TOIE1);
// enable global interrupt
sei();
TCNT1 = 3036;
}
void timer2_init(){
// clear timer
TCNT2 = 0;
// select CTC Mode
TCCR2A |= (1<< WGM21);
// Select Prescaler 32
TCCR2B |= (1 << CS21) | (1 << CS20);
// Output Compare Mode = Toggle
TCCR2A |= (1<< COM2A0);
// Output compare register
OCR2A = 124;
// pin 11 is output OC2A
DDRB |= (1 << PB3);
}
void setup() {
timer1_init();
// Setting PB0 as output
DDRB |= (1 << PB0);
}
void loop() {
// nothing to do here
while(1);
}
ISR(TIMER1_OVF_vect){
TCCR1B = 0;
PORTB |= (1 << PB0);
timer2_init();
}
