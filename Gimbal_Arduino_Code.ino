/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.
'
  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>


Servo ServoX;
Servo ServoY;

static const int ServoXGPIO = 12;
static const int ServoYGPIO = 13;

int XAng = 100;
int YAng = 170;

int PrevXAng = 100;
int PrevYAng = 170;

int Ypos = 170;
int Xpos = 100;

long T = 0;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "DreD-WxpiqEtr5B2HOX4635wf2YYDGrx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Beazues 1";
char pass[] = "D33pC0v3r0y@ls";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  ServoX.attach(ServoXGPIO);
  ServoY.attach(ServoYGPIO);

  ServoX.write(XAng);
  ServoY.write(YAng);
  
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  YAng = param.asInt();

  if (YAng > PrevYAng)
  {

  for (Ypos = PrevYAng; Ypos <= YAng; Ypos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoY.write(Ypos);
  }
  }
  
  if (YAng < PrevYAng)
  {

  
  for (Ypos = PrevYAng; Ypos >= YAng; Ypos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoY.write(Ypos);
  }
  }

PrevYAng = Ypos;


}

BLYNK_WRITE(V2)
{
XAng = param.asInt();
  
  if (XAng > PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos <= XAng; Xpos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoX.write(Xpos);
  }    

  }
  
  if (XAng < PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos >= XAng; Xpos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoX.write(Xpos);
  }
  }

  PrevXAng = Xpos;
}



//Kitchen
BLYNK_WRITE(V11)
{
YAng = 122;
XAng = 110;

/// X angle Adjustment
  if (XAng > PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos <= XAng; Xpos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoX.write(Xpos);
  }    

  }
  
  if (XAng < PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos >= XAng; Xpos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoX.write(Xpos);
  }
  }

  PrevXAng = Xpos;

  //// Y angle adjustment

  if (YAng > PrevYAng)
  {

  for (Ypos = PrevYAng; Ypos <= YAng; Ypos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoY.write(Ypos);
  }
  }
  
  if (YAng < PrevYAng)
  {

  
  for (Ypos = PrevYAng; Ypos >= YAng; Ypos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoY.write(Ypos);
  }
  }

PrevYAng = Ypos;


}


//Front Door
BLYNK_WRITE(V12)
{
YAng = 109;
XAng = 75;

/// X angle Adjustment
  if (XAng > PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos <= XAng; Xpos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoX.write(Xpos);
  }    

  }
  
  if (XAng < PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos >= XAng; Xpos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoX.write(Xpos);
  }
  }

  PrevXAng = Xpos;

  //// Y angle adjustment

  if (YAng > PrevYAng)
  {

  for (Ypos = PrevYAng; Ypos <= YAng; Ypos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoY.write(Ypos);
  }
  }
  
  if (YAng < PrevYAng)
  {

  
  for (Ypos = PrevYAng; Ypos >= YAng; Ypos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoY.write(Ypos);
  }
  }

PrevYAng = Ypos;

  
}

//Living Room
BLYNK_WRITE(V13)
{
 YAng = 107;
 XAng = 33;

/// X angle Adjustment
  if (XAng > PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos <= XAng; Xpos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoX.write(Xpos);
  }    

  }
  
  if (XAng < PrevXAng)
  {
  for (Xpos = PrevXAng; Xpos >= XAng; Xpos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoX.write(Xpos);
  }
  }

  PrevXAng = Xpos;

  //// Y angle adjustment

  if (YAng > PrevYAng)
  {

  for (Ypos = PrevYAng; Ypos <= YAng; Ypos += 1) 
  { 
  T = millis();
  while (millis() - T <15);
  {
  }  
    ServoY.write(Ypos);
  }
  }
  
  if (YAng < PrevYAng)
  {

  
  for (Ypos = PrevYAng; Ypos >= YAng; Ypos -= 1) 
  { 
  T = millis();
  while (millis()-T < 15);
  {
  }    
    ServoY.write(Ypos);
  }
  }

PrevYAng = Ypos;


 
}
