  /*
  # Date       : 29.07.2021
  # Version    : 1.0
  # Details    :
  # Uses Pin Change Interrupts PCINT library to implement more interrupts than the 2 default
  # Uses 3 pushbuttons: counter+1, counter-1, counter+2
  # Also implements internal interrupt timer that fires every 10 seconds, flashing LED and resetting counter
  */

//Initialise variables - match pins to gates on display 
const uint8_t a = 11;
const uint8_t b = 12;
const uint8_t c = 6;
const uint8_t d = 7;
const uint8_t e = 8;
const uint8_t f = 9;
const uint8_t g = 10;

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
  pinMode(13, OUTPUT);
  
  noInterrupts();
  
  // Clear registers 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  //compare match register = [ 16,000,000Hz/ (prescaler * desired interrupt frequency) ] - 1
  // 156,249 = [16,000,000/(1024*0.1)]-1 (once every 10 seconds)
  
  //Set timer compare match register for o.1hz increments 
  OCR1A = 156249;
  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Output Compare Match A Interrupt Enable 
  TIMSK1 |= (1 << OCIE1A);
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  
  interrupts();
  
  PCICR |= 0b00000100; // turn on port d interrupts
  
  PCMSK2 |= 0b000011100; // enable pins PD0 & PD7, PCINT16 & PCINT23 to be used for interrupts
  
  //establish serial communication protocol
  Serial.begin(9600);
  
}

void loop(){     
  
  delay(500); //pause program (simulates processor performing tasks)
    
}

//implements internal interrupt function
ISR(TIMER1_COMPA_vect){
    counter = 0;
  	display(counter);
  	Serial.println("Reset!");
  	digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
}


// implements external interrupt function
ISR(PCINT2_vect){
  
  //from left to right on board
  //button 1 - increases counter (pink)
  if(PIND & B00010000){
      counter++;
      if(counter >= 10){
        counter = 9;
      	}
      display(counter);
      Serial.print("+ 1 : ");
      Serial.println(counter);
  	}
  
  //button 2 - decreases counter (purple)
  if (PIND & B00001000){
      counter--;
      if(counter < 0){
        counter = 0;
      	}
      display(counter);
      Serial.print("- 1 : ");
      Serial.println(counter);
  }
  
  //button 3 - increases counter by 2 (blue)
  if(PIND & B00000100){
    if(counter == 8 || counter == 9){
      counter+=0;
    }
    else{
      counter+=2;
    }
    display(counter);
    Serial.print("+ 2 : ");
     Serial.println(counter);
  }
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



