volatile uint8_t overflow_counter = 0;
void timer2_init(){
// prescaler 1024
TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
// Enable Overflow Interrupt
TIMSK2 |= (1 << TOIE2);
// enable global interrupt
sei();
}
void setup() {
timer2_init();
// Setting PB0 as output
DDRB |= (1 << PB0);
}
void loop() {
// nothing to do here
while(1);
}
ISR(TIMER2_OVF_vect){
overflow_counter ++;
if(overflow_counter == 122){
overflow_counter = 0;
PORTB ^= (1 << PB0);
}
}