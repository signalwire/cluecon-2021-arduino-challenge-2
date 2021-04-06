/*
Ohm Meter Sample Code
Calculates value of unknown resistor, by utilizing a known value.
*/


// declare variables
int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float knownResistor = 1000;
float unkownResistor = 0;
float buffer = 0;

void setup(){
  // prepare serial port 
  Serial.begin(9600);
}

void loop(){
  
  // read analog input from specified pin
  raw = analogRead(analogPin);
  
  // if data has been input
  if(raw){
    buffer = raw * Vin;
    Vout = (buffer)/1024.0;
    buffer = (Vin/Vout) - 1;
    unknownResistor = knownResistor * buffer;
    
    // Output to serial port
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("unknownResistor: ");
    Serial.println(unknownResistor);
    
    // poll every 1000ms (1 second)
    delay(1000);
  }
}
