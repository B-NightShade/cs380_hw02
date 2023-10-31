// C++ code
//
void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(57600);
}

//function to turn on a number of lights
//takes in one value that is the number of lights/volume level
void turnOnLight(int lightNumber){
  digitalWrite(lightNumber, HIGH);
}

//function to turn off a number of lights
//takes in one value that is the number of lights/volume level
void turnOffLight(int lightNumber){
  digitalWrite(lightNumber, LOW); 
}

void loop()
{
  Serial.println("ENTER VOLUME level (0-10): ");

  String userInput;
  int integerInput;
  while(Serial.available() == 0){
  }
  
  userInput = Serial.readStringUntil('\n');
  userInput.trim();
  integerInput = userInput.toInt();

  //check if input is only digits
  bool fullDigit = true;
  for(int i = 0; i < userInput.length(); i++){
    if(!isdigit(userInput[i])){
     fullDigit = false; 
    }
  }

  //check if it converted completly
  if(((userInput.compareTo("0") != 0) && (integerInput == 0)) || fullDigit == false){
    Serial.println("invalid try again");
    //string input
  }else{
   
    if(integerInput < 0 || integerInput > 10){
      Serial.println("invalid try again");
      //invalid input 
    }
     else{
      Serial.println("volume chosen " + userInput);
       for (int i= 2; i < 2+integerInput; i++){
       	turnOnLight(i);
       }
       //wait five seconds
       if(integerInput != 0){
        delay(5000);
       }
       for (int i= 2; i < 2+integerInput; i++){
       	turnOffLight(i);
       }
    }
  }
}
      
      
      
      
