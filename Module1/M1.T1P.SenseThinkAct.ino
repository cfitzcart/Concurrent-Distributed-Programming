  /*
  # Date       : 26.07.2021
  # Version    : 1.0
  # Details    :
  # Measure moisture in potplant soil
  # Trigger warning LED when soil is too dry 
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
  */


uint8_t ledState = LOW;

void setup() {
  // initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // open serial port
  Serial.begin(9600); 
}

void loop() {
  
  int reading;
  reading = analogRead(0);
  Serial.print("Moisture reading: ");
  Serial.println(reading); //print the input value to serial port

  digitalWrite(LED_BUILTIN, ledState); //update LED

  if(reading <= 300) //300 or less indicates dry soil
  {
    ledState = HIGH; //turn on warning LED
    Serial.print("Plant needs water!");
    Serial.println("");
  }
  else {
    ledState = LOW; //turn off LED if plant isn't dry
  }
  
  
  delay(2000); //delay 2 sec

}
