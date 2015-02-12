int tiltDown = 4;
int tiltUp = 5;
int tiltLeft = 2;
int tiltRight = 3;

int left_counter = 0;
int right_counter = 0;
int up_counter = 0;
int down_counter = 0;

const int TARGET_COUNT = 5000;

const int CENTER = 0;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

int state = CENTER;

const boolean KEYBOARD_OUT = true;
const boolean SERIAL_OUT = true;

void setup() {
  if( SERIAL_OUT )
    Serial.begin(9600);

  if( KEYBOARD_OUT )
    Keyboard.begin();

  pinMode(tiltDown, INPUT);
  pinMode(tiltUp, INPUT);
  pinMode(tiltLeft, INPUT);
  pinMode(tiltRight, INPUT);
}

void loop() {
  updateValues();

  switch( state ) {
  case CENTER:
    if ( right_counter == TARGET_COUNT ) {
      makeStateRight();
    }
    else if ( up_counter == TARGET_COUNT ) {
      makeStateUp();
    }
    else if ( down_counter == TARGET_COUNT ) {
      makeStateDown();
    }
    else if ( left_counter == TARGET_COUNT ) {
      makeStateLeft();
    }
    break;
  default:
    if ( left_counter == 0 && right_counter == 0 && up_counter == 0 && down_counter == 0) {
      makeStateCenter();
    }
    break;
  }
}

void updateValues() { 
  if( digitalRead(tiltDown) == HIGH ) 
    down_counter = min( TARGET_COUNT, down_counter + 1);
  else if( digitalRead(tiltUp) == HIGH ) 
    up_counter = min( TARGET_COUNT, up_counter + 1);
  else if( digitalRead(tiltLeft) == HIGH ) 
    left_counter = min( TARGET_COUNT, left_counter + 1);
  else if( digitalRead(tiltRight) == HIGH ) 
    right_counter = min( TARGET_COUNT, right_counter + 1);
 else {
   up_counter = max(0, up_counter - 1);
   down_counter = max(0, down_counter - 1);
   left_counter = max(0, left_counter - 1);
   right_counter = max(0, right_counter - 1);
 }

}

void makeStateUp() {
  if( SERIAL_OUT )
    Serial.println("Up!");
  state = UP;
  if( KEYBOARD_OUT )
    Keyboard.write(0xDA);
}

void makeStateDown() {
  if( SERIAL_OUT )
    Serial.println("Down!");
  state = DOWN;
  if( KEYBOARD_OUT )
    Keyboard.write(0xD9);
}

void makeStateLeft() {
  if( SERIAL_OUT )
    Serial.println("Left!");
  state = LEFT;
  if( KEYBOARD_OUT )
    Keyboard.write(0xD8);
}

void makeStateRight() {
  if( SERIAL_OUT )
    Serial.println("Right!");
  state = RIGHT;
  if( KEYBOARD_OUT )
    Keyboard.write(0xD7);
}

void makeStateCenter() {
  if( SERIAL_OUT )
    Serial.println("Center");
  state = CENTER;
}








