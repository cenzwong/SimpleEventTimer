#define led_pin 13

typedef struct EventRegister{
  unsigned long previous_millis;
  bool check_flag;
  unsigned long duration;
};

EventRegister ledToggle{0, false, 1000};

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
}

void loop() {
  //variable declaration
  unsigned long current_millis = millis();

  //=========checkFlag()======
  if(current_millis - ledToggle.previous_millis >= ledToggle.duration){
    //toggle LED function flag on
    ledToggle.check_flag = true;
  }

  //===========do()===========
  if(ledToggle.check_flag){
    led_toggle(led_pin);
    //reset the flag and timer
    ledToggle.check_flag = false;
    ledToggle.previous_millis = current_millis;
  }
}

void led_toggle(unsigned char pin){
  digitalWrite(pin, !digitalRead(pin));
}
