// AC temp fan using temperature sensor

int reading;
float voltage , temp;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT); // Analog output line
  Serial.begin(9500); // baud rate in serial communication
}

void loop()
{
  reading = analogRead(A0); // Voltage reading from temperature sensor
  
  // Analog to digital voltage conversion
  
  voltage = float(reading)*5.0;
  voltage /= 1024.0;
  
  // Voltage to Temp conversion
  
  temp = (voltage - 0.5)*100;
  Serial.print(temp); //Prints the value in serial monitor
  
  if (temp > 40) {
    
    analogWrite(9,255);
    Serial.println(temp);
  } 
  else{
    
    if(temp > 20 && temp < 40)
    {  
    analogWrite(9,100);
    Serial.println(temp);
    }
  else {
     
    analogWrite(9,10);
    Serial.println(temp);
  }
  } 
  delay(10);
}
