  /*
  # Date       : 27.07.2021
  # Version    : 2.0
  # Details    :
  # Implements interrupt triggered by button push
  # Increments and displays counter value
  */


//Initialise variables - match pins to gates on display 
const uint8_t a = 11;
const uint8_t b = 12;
const uint8_t c = 6;
const uint8_t d = 7;
const uint8_t e = 8;
const uint8_t f = 9;
const uint8_t g = 10;

const uint8_t B1_PIN=2;

uint8_t counter = 0;

void setup(){
    
  //configure pin 2 and input and others as output
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(B1_PIN, INPUT_PULLUP);
  
  //initialise interrupt for button push
  attachInterrupt(digitalPinToInterrupt(B1_PIN), increaseCounter, FALLING);
  
  //establish serial communication protocol
  Serial.begin(9600);
}


void loop(){     

  delay(500); //pause program (simulates processor performing tasks)
    
}

//function performed on interrupt
// increases counter and writes value to 7-segment display
void increaseCounter(){
  
  counter++;
  
  if(counter >= 10 || counter < 0){
    counter = 0;
  }
  
  Serial.print("Counter: ");
  Serial.println(counter);
  
  display(counter); 
}

void display(int number){
  switch(number){
    case 0: write0();
         break;
    case 1: write1();
      break;
    case 2: write2(); 
      break;
    case 3: write3();
      break;
    case 4: write4();
      break;
    case 5: write5();
      break;
    case 6: write6();
      break;
    case 7: write7();
      break;
    case 8 : write8();
      break;
    case 9 : write9();
      break;
    default : write0();
        break;   
  }
}
    
    
//functions to display digits 0 to 9
void write0(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,1);
    delay(1);
}
void write1(){
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    delay(1);
}
void write2(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,0);
    delay(1);
}
void write3(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
    delay(1);
}
void write4(){
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,f);
    digitalWrite(f,0);
    digitalWrite(g,0);
    delay(1);
}
void write5(){
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,0);
    delay(1);
}
void write6(){
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
    delay(1);
}
void write7(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    delay(1);
}
void write8(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
    delay(1);
}
void write9(){
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,0);
    delay(1);
}
