//Name: Ananya Garg
//Roll No: 101903548
//Batch: 2CO21

//Accident Avoidance System
//The same system can be applied at front and back side of the vehicles
const int trigPin = 7;
const int echoPin = 4;
const int LED=2;
const int BuzzerLED=13;
int buzz = 10;
float duration;
float distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);  //Using the pulseIn function to find out the time duration
  
  distance= duration*0.034/2;         //Distace is being calculated using duration
  Serial.print("Distance: ");         //Prints the statement on the Serial Monitor
  Serial.println(distance);           //Prints the distance on the Serial Monitor
  
                                       //************** ZONE 1 **************
                                       //This zone warns the driver to drive carefully through a Red LED
  if(distance <= 200 && distance >= 50)//If the other vehicle/Obstacle is in between the range of 50-200 cm 
  {
    digitalWrite(LED, HIGH);           //Turn the Red LED On to warn the driver
  }
  else                                 //If the other vehicle is at a safe distance
  {
    digitalWrite(LED, LOW);            //Keep the Red LED OFF
  } 
  
                                   //************** ZONE 2 **************
                                   //This zone is a critical zone and warns the driver to slow down
                                   //It warns through the blue LEd and a Buzzer

  if(distance < 50)                //If the other vehicle is less than 50 cm from our vehicle 
  {
    digitalWrite(BuzzerLED, HIGH); //Turn the Blue LED ON
    
    tone(buzz, 2000);              //The buzzer starts buzzing
    delay(100);                    //Wait for 100 milliseconds
    noTone(buzz);                  //Stop the buzzer
    delay(100);                    //Wait for 100 milliseconds
    
    tone(buzz, 2000);              //This piece of code is repeated to make buzzing sound
    delay(100);
    noTone(buzz);
    delay(100);
    
    tone(buzz, 2000);
    delay(100);
    noTone(buzz);
        
    tone(buzz, 2000);
    delay(100);
    noTone(buzz);
    delay(100);
   }
   else                            //If the vehicle is at a distance greater than 50 cms
   {
     digitalWrite(BuzzerLED, LOW); //Keep the blue LED OFF
   }
}
