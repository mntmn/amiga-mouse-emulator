
static int pin_xa = 2;
static int pin_xb = 3;
static int pin_ya = 4;
static int pin_yb = 5;
static int pin_lb = 6;
static int pin_rb = 7;

void setup() {
  Serial.begin(57600);
  
  pinMode(pin_xa, OUTPUT);
  pinMode(pin_xb, OUTPUT);
  pinMode(pin_ya, OUTPUT);
  pinMode(pin_yb, OUTPUT);
  pinMode(pin_lb, OUTPUT);
  pinMode(pin_rb, OUTPUT);
  
  digitalWrite(pin_lb, HIGH);
  digitalWrite(pin_rb, HIGH);
}

static int xspeed = 1;
static int yspeed = 1;

void send_down() {  
  digitalWrite(pin_yb, HIGH);
  delay(yspeed);
  digitalWrite(pin_ya, HIGH);
  delay(yspeed);
  digitalWrite(pin_yb, LOW);
  delay(yspeed);
  digitalWrite(pin_ya, LOW);
  delay(yspeed);
}

void send_up() {
  digitalWrite(pin_ya, HIGH);
  delay(yspeed);
  digitalWrite(pin_yb, HIGH);
  delay(yspeed);
  digitalWrite(pin_ya, LOW);
  delay(yspeed);
  digitalWrite(pin_yb, LOW);
  delay(yspeed);
}

void send_left() {
  digitalWrite(pin_xa, HIGH);
  delay(yspeed);
  digitalWrite(pin_xb, HIGH);
  delay(yspeed);
  digitalWrite(pin_xa, LOW);
  delay(yspeed);
  digitalWrite(pin_xb, LOW);
  delay(yspeed);
}

void send_right() {
  digitalWrite(pin_xb, HIGH);
  delay(yspeed);
  digitalWrite(pin_xa, HIGH);
  delay(yspeed);
  digitalWrite(pin_xb, LOW);
  delay(yspeed);
  digitalWrite(pin_xa, LOW);
  delay(yspeed);
}

#define CMD_LMDOWN 1
#define CMD_LMUP 2
#define CMD_RMDOWN 3
#define CMD_RMUP 4
#define CMD_LEFT 5
#define CMD_RIGHT 6
#define CMD_UP 7
#define CMD_DOWN 8

void loop() {
  if (Serial.available() > 0) {
    int cmd = Serial.parseInt();
    Serial.println(cmd);
    switch (cmd) {
      case CMD_LMDOWN: {
        digitalWrite(pin_lb, LOW);
        break;
      }
      case CMD_LMUP: {
        digitalWrite(pin_lb, HIGH);
        break;
      }
      case CMD_RMDOWN: {
        digitalWrite(pin_rb, LOW);
        break;
      }
      case CMD_RMUP: {
        digitalWrite(pin_rb, HIGH);
        break;
      }
      case CMD_LEFT: {
        send_left();
        break;
      }
      case CMD_RIGHT: {
        send_right();
        break;
      }
      case CMD_UP: {
        send_up();
        break;
      }
      case CMD_DOWN: {
        send_down();
        break;
      }
      default: {
      }
    } 
  }
}
