


void setup() {
  //Selecting PWM output pins.
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  Serial.begin(9600);
}

enum Color //This is used to indicate which color is coming next.
{
  RED,
  BLUE,
  GREEN,
  NONE
};

Color color = GREEN;
float redValue = 0.0;
float greenValue = 0.0;
float blueValue = 1.0;
float maxVal = 255;
float stepSize = 0.001;

void loop() 
{

   
  if(color == GREEN)
  {
    redValue -=stepSize;
    greenValue = 1.0 - redValue;
  }
  else if(color == BLUE)
  {
    greenValue -=stepSize;
    blueValue = 1.0 - greenValue;
  }
  else if(color == RED)
  {
    blueValue -=stepSize;
    redValue = 1.0 - blueValue;
  }



  
  
  if(blueValue >= 1)
  {
    color = RED;
    greenValue = 0.0;
  }
  else if(greenValue >= 1)
  {
    color = BLUE;
    redValue = 0.0;
  }
  else if(redValue >= 1)
  {
    color = GREEN;
    blueValue = 0.0;
  }
  
  
  analogWrite(3, redValue * maxVal);
  analogWrite(5, greenValue * maxVal);
  analogWrite(6, blueValue * maxVal);
  
  //String values = "RED: "+ String(redValue) + " GREEN: "+ String(greenValue) + " BLUE: "+ String(blueValue);
  //Serial.println(values);
  delay(10);

}



