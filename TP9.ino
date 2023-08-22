#define LED1 PB4
#define LED2 PB5
#define LED3 PB6
#define LED4 PB7
#define LED5 PB8
#define LED6 PB9

#define BOTON1 PB12
#define BOTON2 PB13
#define SWITCH2 PB14
#define SWITCH1 PB15

#define POT PA0
#define LDR PA1

#define PRESS LOW
#define UNPRESS HIGH

int button1State;
int button2State;
int switch1State;
int switch2State;

int potState;
int ldrState;

int estado = 1;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);

  pinMode(BOTON1, INPUT_PULLUP);
  pinMode(BOTON2, INPUT_PULLUP);
  pinMode(SWITCH1, INPUT);
  pinMode(SWITCH2, INPUT);

  pinMode(POT, INPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  button1State = digitalRead(BOTON1);
  button2State = digitalRead(BOTON2);
  switch1State = digitalRead(SWITCH1);
  switch2State = digitalRead(SWITCH2);
  potState = analogRead(POT);
  ldrState = analogRead(LDR);

  if (button1State == PRESS && button2State == PRESS) {
    estado += 1;

    if (estado > 4) {
      estado = 1;
    }

    delay (500);
    
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
  }
  
   switch (estado) {
    case 1:  
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      break;
      
    case 2:
      if (button1State == PRESS){
      delay (40);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      }
      else if (button2State == PRESS){
        delay (40);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED6, HIGH);
      }
      else if (button1State == PRESS){
        delay (40);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED6, HIGH);
      }
      else if (button1State == UNPRESS && button2State == UNPRESS) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
      }
      break;

    case 3:
      if (switch1State == HIGH && switch2State == LOW) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
      }
      else if (switch2State == HIGH && switch1State == LOW) {
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
      }
      else if (switch1State == LOW && switch2State == LOW || switch1State == HIGH && switch2State == HIGH) {
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
      }
      break;

    case 4:
    analogWrite (LED5, analogRead (POT));
    if (switch1State == HIGH && switch2State == LOW) {
      analogWrite (LED5, analogRead (POT))
    }
    break;

    case 5:
       
    //a
    break;
 
 } 
}
