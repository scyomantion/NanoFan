void setupTimer1() {
    cli();

    TCCR1A = (1<<COM1A1) | (1<<COM1B1) | (1<<WGM11); // Toggle OC1A and OC1B
    TCCR1B = (1<<WGM12) + (1<<WGM13) + (1<<CS11) + (1<<CS10); // prescaler = 64;
    //ICR1 = 2500; // 3000 RPM, 16000000 / 64 / ( RPM / 60 * 2) - 1
    //ICR1 = 1500; // 5000 RPM, 16000000 / 64 / ( RPM / 60 * 2) - 1
    ICR1 = 1250; // 6000 RPM, 16000000 / 64 / ( RPM / 60 * 2) - 1
    OCR1A = 100; // pulse length from simulated fan, not realy important
    OCR1B = 100; // pulse length from simulated fan, not realy important
    DDRB |= (1<<PB1) | (1<<PB2);

    sei();
}


void setup() {
    // setup fake rpm signal for original controller
    setupTimer1();

    // fan 1 speed output
    pinMode(3, OUTPUT);
    analogWrite(3, 80);

    // fan 2 speed output
    pinMode(11, OUTPUT);
    analogWrite(11, 80);

    // rpm input, if you need to monitor the real fan speed
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
}

void loop() {
}