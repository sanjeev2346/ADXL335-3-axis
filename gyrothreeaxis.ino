const int xpin = 34;                
const int ypin = 35;                
 const int zpin = 32;
 const int xpini = 33;                
const int ypini = 25;                
 const int zpini = 26;
 const int xpine = 27;                
const int ypine = 14;                
 const int zpine = 12;
 

 

void setup()
{
   Serial.begin(9600);          // initialize the serial communications:
}


void loop()
{
  Serial.println("1");

   wroom(xpin,ypin,zpin);
   
  Serial.println("2");
   wroom(xpini,ypini,zpini);
   
  Serial.println("3");
   wroom(xpine,ypine,zpine);
   delay(5000);
 
}

float wroom(int x,int y,int z)
{
  int xvalue;
 int yvalue;
 int zvalue;
  double x_g_value, y_g_value, z_g_value;
  double roll, pitch, yaw;
  xvalue = analogRead(x);                              //reads values from x-pin & measures acceleration in X direction 
  int a = map(xvalue, 267, 400, -100, 100);               //maps the extreme ends analog values from -100 to 100 for our understanding
// you need to replace the 267 & 400 value with your values from calibration
  float xg = (float)a/(-100.00);                          //converts the mapped value into acceleration in terms of "g"
  Serial.print(xg);                                       //prints value of acceleration in X direction
  Serial.print("g   ");                                   //prints "g"
   
  yvalue = analogRead(y);
  int b = map(yvalue, 272, 406, -100, 100);
  float yg = (float)b/(-100.00);
  Serial.print("\t");
  Serial.print(yg);
  Serial.print("g   "); 
 
  zvalue = analogRead(z);
  int c = map(zvalue, 277, 410, -100, 100);
  float zg = (float)c/(100.00);
  Serial.print("\t"); 
  Serial.print(zg);
  Serial.println("g   ");
  delay(100);
   x_g_value = ( ( ( (double)(xg * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in x-direction in g units */ 
  y_g_value = ( ( ( (double)(yg * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in y-direction in g units */ 
  z_g_value = ( ( ( (double)(zg* 5)/1024) - 1.80 ) / 0.330 ); /* Acceleration in z-direction in g units */ 

  roll = ( ( (atan2(y_g_value,z_g_value) * 180) / 3.14 ) + 180 ); /* Formula for roll */
  pitch = ( ( (atan2(z_g_value,x_g_value) * 180) / 3.14 ) + 180 ); /* Formula for pitch */
  yaw = ( ( (atan2(x_g_value,y_g_value) * 180) / 3.14 ) + 180 ); /* Formula for yaw */
  /* Not possible to measure yaw using accelerometer. Gyroscope must be used if yaw is also required */

  Serial.print("Roll = ");
  Serial.print(roll);
  Serial.print("\t");
  Serial.print("Pitch = ");
  Serial.print(pitch);
  Serial.print("\n\n");
  Serial.print("yaw = ");
  Serial.print(yaw);
  Serial.print("\n\n");
  delay(1000);
  return xvalue;
  
}
