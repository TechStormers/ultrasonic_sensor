#define trigger D1 //connecting trig to D1
#define echo D2 //connecting echo to D2

void setup() {
  // Beginning the serial monitor
  Serial.begin(115200); //115200 is the baud rate 
  //declaring pinmode
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // making the trigger pin low for 2 microseconds
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  // making the trigger pin high for 10 microseconds
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  // making trigger pin low
  digitalWrite(trigger,LOW);
  
  double t = pulseIn(echo,HIGH); // calculating the time in which reflected waves are received by receiver
  long d = t*0.034/2; //formula to calculate the distance between object and sensor, storing the value in variable d
  Serial.println(d); //printing value of d in serial monitor
  delay(1000); //delay of 1 second

}
