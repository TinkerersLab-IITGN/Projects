#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"                                                                 //Firebase Library (FirebaseJson Version should be 5, not 6) 
#include <Wire.h>
#include <SoftwareSerial.h>

#define FIREBASE_HOST "<Enter Firebase HOST address here>"                                   //Firebase HOST
#define FIREBASE_AUTH "<Enter Firebase SecretKey here>"                                      //Firebase SecretKey
#define WIFI_SSID "Vivo 1902"
#define WIFI_PASSWORD "123456789"
String str;
String t="Time0";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(2,OUTPUT);
  pinMode(0,INPUT);
  digitalWrite(2,LOW);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                              //Begin Firebase
  delay(5000);
}

int result;

void loop() {
 String str = "";
 boolean StringReady = false;
 while (Serial.available()){
  str=Serial.readString();
  StringReady=true;
  delay(1);
 }

 if (StringReady){
  // put your main code here, to run repeatedly:

searchnumber();
if (result==0){
  digitalWrite(2,LOW);
}
else{
  digitalWrite(2,HIGH);
}
 }
 delay(10);
}


void searchnumber()                                                                          //Define function for checking Authorized status
{

String s;                                                                                    //String s to store path to get Authorized status from Firebase Datbase
char firstnum = str.charAt(0);                                                               //To get first digit of Roll No.
char secondnum = str.charAt(1);                                                              //To get second digit of Roll No.
char thirdnum = str.charAt(2);                                                               //To get Third digit of Roll No.

if (firstnum=='1')                                                                           //If Roll No. starts with '1'
{
  if (secondnum=='6')                                                                        //If it is of 2016 Batch
  {
    if (thirdnum=='1')                                                                       //If it is of 2016 Btech batch
    {
      s = "Database/2016/Btech/" + str.substring(0,8);                                       //Save path in s as "Dtabase/2016/Btech/Roll No.
      result = Firebase.getInt(s);                                                           //Get the Authorized status of that Roll No.
      if (Firebase.failed())                                                                 //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
      {
        result = 0;
      }
    }
    else if (thirdnum=='2')                                                                  //If it is of 2016 Mtech batch
    {
       s = "Database/2016/Mtech/" + str.substring(0,8);                                      //Save path in s as "Dtabase/2016/Mtech/Roll No.
       result = Firebase.getInt(s);                                                          //Get the Authorized status of that Roll No.
       if (Firebase.failed())                                                                //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
        {
          result = 0;
        }
    }
    else
    {
      result = 0;                                                                            //If third digit is not '1' or '2', then return unauthorized status
    }

  }
  else if (secondnum=='7')                                                                   //If it is of 2017 batch
  {
    if (thirdnum=='1')                                                                       //If it is of 2017 Btech batch
    {
      s = "Database/2017/Btech/" + str.substring(0,8);                                       //Save path in s as "Dtabase/2017/Btech/Roll No.
      result = Firebase.getInt(s);                                                           //Get the Authorized status of that Roll No.
      if (Firebase.failed())                                                                 //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
      {
        result = 0;
      }
    }
    else if (thirdnum=='2')                                                                  //If it is of 2017 Mtech batch
    {
      s = "Database/2017/Mtech/" + str.substring(0,8);                                       //Save path in s as "Dtabase/2017/Mtech/Roll No.
      result = Firebase.getInt(s);                                                           //Get the Authorized status of that Roll No.
      if (Firebase.failed())                                                                 //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
      {
        result = 0;
      }
    }
    else
    {
      result = 0;                                                                            //If third digit is not '1' or '2', then return unauthorized status
    }

  }
  else if (secondnum=='8')                                                                   //If it is of 2018 batch
  {
    if (thirdnum=='1')                                                                       //If it is of 2018 Btech batch
    {
      s = "Database/2018/Btech/" + str.substring(0,8);                                       //Save path in s as "Dtabase/2018/Btech/Roll No.
      result = Firebase.getInt(s);                                                           //Get the Authorized status of that Roll No.
      if (Firebase.failed())                                                                 //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
      {
        result = 0;
      }
    }
    else if (thirdnum=='2')                                                                  //If it is of 2018 Mtech batch
    {
      s = "Database/2018/Mtech/" + str.substring(0,8);                                       //Save path in s as "Dtabase/2018/Mtech/Roll No.
      result = Firebase.getInt(s);                                                           //Get the Authorized status of that Roll No.
      if (Firebase.failed())                                                                 //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
      {
        result = 0;
      }
    }
    else
    {
      result = 0;                                                                            //If third digit is not '1' or '2', then return unauthorized status
    }
  
  }
  else if (secondnum=='9')                                                                   //If it is of 2019 batch
  {
  if (thirdnum=='1')                                                                         //If it is of 2019 Btech batch
  {
    s = "Database/2019/Btech/" + str.substring(0,8);                                         //Save path in s as "Dtabase/2019/Btech/Roll No.
    result = Firebase.getInt(s);                                                             //Get the Authorized status of that Roll No.
    if (Firebase.failed())                                                                   //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
    {
      result = 0;
    }
  }
  else if (thirdnum=='2')                                                                    //If it is of 2019 Mtech batch
  {
    s = "Database/2019/Mtech/" + str.substring(0,8);                                         //Save path in s as "Dtabase/2019/Mtech/Roll No.
    result = Firebase.getInt(s);                                                             //Get the Authorized status of that Roll No.
    if (Firebase.failed())                                                                   //If no Roll No. in Dtabase match with that Roll No., then return unauthorized status
    {
      result = 0;
    }
  }
  else
  {
    result = 0;                                                                              //If third digit is not '1' or '2', then return unauthorized status
  }

  }
}
else
{
  result = 0;                                                                                //If first digit is not '1' then return unaythorized status
}

if (result==1){
  digitalWrite(2,HIGH);
  authorized();
}
else{
  digitalWrite(2,LOW);
  unauthorized();
}
}



void authorized()                                                                            //Define function authorized
{
  String s = "Users/" + t + " Open";                                                         
  Firebase.setString(s,str+" :1");                                                           //Writes Date & Time of access and Roll No. in Firebase/Users
  open();                                                                                    //Call function open
  delay(1);
}


void unauthorized()                                                                          //Define function unauthorized
{
  unauthoclose();
  delay(1);
}

void authoclose()                                                                            //Define function authoclose
{
    String s = "Users/" + t + " Close";                                                          
    Firebase.setString(s,str+" :1");                                                         //Writes Date & Time of access and Roll No. in Firebase/Users
                           //Initialize LCD again
    str="";                                                           
    delay(1);
}

void unauthoclose()                                                                          //Define function unauthoclose
{
    String s = "Users/" + t + " Close";
    Firebase.setString(s,str+" :0");                                                         //Writes Date & Time of access and Roll No. in Firebase/Users
    digitalWrite(2,LOW);                                                                         //Initialize LCD again                                                                  
    str="";
    delay(1);
}

void open()                                                                                  //Define function open
{
  while(digitalRead(0)==0){
    int e;
  }
    authoclose();                                                                            //Call function authoclose
    delay(1);
}
