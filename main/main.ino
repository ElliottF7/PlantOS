void setup() {
  Serial.begin(9600);//Begin serial via COMM
  
  //Digital Pins
  pinMode(22, OUTPUT);//D Out for moisture detect const power
  pinMode(LED_BUILTIN, OUTPUT);

  //Analog Pins
  pinMode(A0, INPUT);//A In for moisture detect 
}

void loop() {
  // Serial.println("Loop Iter");
  digitalWrite(22, HIGH);//out max signal

  double state = getSoilMoisture(A0, 'P');//read moisture

  if(state < 40){
    digitalWrite(LED_BUILTIN, LOW);
  }else{
    digitalWrite(LED_BUILTIN, HIGH);
  }

  Serial.println(state);
  delay(500);
}




//params: uint8_t pinToRead, formatOfOutput (RAW, Percentage)
//returns RAW: 0 (wet) - 1023 (dry) , Percentage: 0.00 (dry) - 100.00 (wet)| no error returnable ENSURE PIN IN USE
double getSoilMoisture(uint8_t readPin, char outputFormat){

  //Add regexcheck for valid pin argument

  if(outputFormat == 'R'){
    return (double)analogRead(readPin);//read moisture in raw analog form
  }else if(outputFormat == 'P'){
    return ((1023.0 - (double)analogRead(readPin)) / 1023.0) * 100.0;//read moisture in raw analog, invert read numeral, convert to percentage
  }else{
    return -1.0;//unexpected input
  }

  return -1.0;//other error
}

//args: pinToRead,
//returns -1, function stubbed for later impl
double getHumidity(uint8_t readPin){
  return -1;
}

//args: N/A
//returns -1, function stubbed for later impl
//proposed impl: for plant, get seconds of sunlight since midnight (or over course past few days)
//better idea of need for water or need for artificial lighting
double getTotalSunlight(){
  return -1;
}






