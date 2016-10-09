
/*
 * RGB-LED Chroma scroller by OhjelmointiTuuba
 */


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
float maxVal = 255; //You could decrease brightness by decreasing this value but then you are going to have smaller amount of different colors and changes will be more noticeable. 
float stepSize = 0.001;

void loop() 
{

  /*We check which color will be next and begin reducing current color while increasing
   *next color by reducing current color from next color.
   */
   
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


  /*Then we need to check if current color has reached maximum value and turn old color completely off because
   *it's value might be little bit over or less than zero depending on stepSize.
   *We also pick next color.
   */
  
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



