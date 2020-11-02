
#include <SPI.h>
#include <ESP8266WiFi.h> 
#include <Servo.h> 

Servo servo1; //axe central
Servo servo2; //axe gauche
Servo servo3; //axe droite

char ssid[] = "XXXXXXXX"; //SSID de votre Wi-Fi 
char pass[] = "YYYYYYY"; //Password de votre Wi-Fi 
int keyIndex = 0;     // key Index number de votre rÃ©seau (seulement requis pour WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
 while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  } 
  server.begin();
  // you're connected now, so print out the status:
   printWifiStatus();
  servo1.attach(4);
  servo2.attach(3);
  servo3.attach(5);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
   

}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // read first line of request
  String req = client.readStringUntil('\r');
  ////////////////////////////////////////////
  // read request
  String phrase = "";
  // If phrase parameter found
  if (req.indexOf("phrase=") != -1){
  // phrase is included between name of the variable and the HTTP text
    phrase = req.substring(req.indexOf("phrase=")+7,req.indexOf("HTTP")-1);
    phrase.toUpperCase();
  }
  Serial.println("Phrase:");
  Serial.println(phrase);

  String uneLettre = "";
for (int indiceLettre=0; indiceLettre <= phrase.length(); indiceLettre++){
      uneLettre = phrase.substring(indiceLettre, indiceLettre+1);
      Serial.println(uneLettre);
  if (uneLettre == "A" )   {servo1.write(90); servo2.write(0); servo3.write(179);delay(1000);}
  if (uneLettre == "B" )   {servo1.write(45); servo2.write(0); servo3.write(179);delay(1000);}
  if (uneLettre == "C" )   {servo1.write(0); servo2.write(0); servo3.write(179);delay(1000);}
  if (uneLettre == "D" )   {servo1.write(135); servo2.write(179); servo3.write(0);delay(1000);}
  if (uneLettre == "E" )   {servo1.write(90); servo2.write(179); servo3.write(0);delay(1000);}
  if (uneLettre == "F" )   {servo1.write(45); servo2.write(179); servo3.write(0);delay(1000);}
  if (uneLettre == "G" )   {servo1.write(0); servo2.write(179); servo3.write(0);delay(1000);}
  if (uneLettre == "H" )   {servo1.write(135); servo2.write(0); servo3.write(179);delay(1000);}
  if (uneLettre == "I" )   {servo1.write(90); servo2.write(0); servo3.write(0);delay(1000);}
  if (uneLettre == "J" )   {servo1.write(90); servo2.write(0); servo3.write(0);delay(1000);}
  if (uneLettre == "K" )   {servo1.write(45); servo2.write(0); servo3.write(0);delay(1000);}
  if (uneLettre == "L" )   {servo1.write(0); servo2.write(0); servo3.write(0);delay(1000);}
  if (uneLettre == "M" )   {servo1.write(135); servo2.write(0); servo3.write(0);delay(1000);}
  if (uneLettre == "N" )   {servo1.write(90); servo2.write(179); servo3.write(179);delay(1000);}
  if (uneLettre == "O" )   {servo1.write(45); servo2.write(179); servo3.write(179);delay(1000);}
  if (uneLettre == "P" )   {servo1.write(0); servo2.write(179); servo3.write(179);delay(1000);}
  if (uneLettre == "Q" )   {servo1.write(135); servo2.write(179); servo3.write(179);delay(1000);}
  if (uneLettre == "R" )   {servo1.write(90); servo2.write(90); servo3.write(179);delay(1000);}
  if (uneLettre == "S" )   {servo1.write(45); servo2.write(90); servo3.write(179);delay(1000);}
  if (uneLettre == "T" )   {servo1.write(0); servo2.write(90); servo3.write(179);delay(1000);}
  if (uneLettre == "U" )   {servo1.write(135); servo2.write(179); servo3.write(90);delay(1000);}
  if (uneLettre == "V" )   {servo1.write(90); servo2.write(179); servo3.write(90);delay(1000);}
  if (uneLettre == "W" )   {servo1.write(45); servo2.write(179); servo3.write(90);delay(1000);}
  if (uneLettre == "X" )   {servo1.write(0); servo2.write(179); servo3.write(90);delay(1000);}
  if (uneLettre == "Y" )   {servo1.write(135); servo2.write(90); servo3.write(179);delay(1000);}
  if (uneLettre == "Z" )   {servo1.write(90); servo2.write(0); servo3.write(90);delay(1000);}
  if (uneLettre == "&" )   {servo1.write(45); servo2.write(0); servo3.write(90);delay(1000);}
  if (uneLettre == "1" )   {servo1.write(0); servo2.write(0); servo3.write(90);delay(1000);}
  if (uneLettre == "2" )   {servo1.write(135); servo2.write(90); servo3.write(0);delay(1000);}
  if (uneLettre == "3" )   {servo1.write(90); servo2.write(90); servo3.write(0);delay(1000);}
  if (uneLettre == "4" )   {servo1.write(45); servo2.write(90); servo3.write(0);delay(1000);}
  if (uneLettre == "5" )   {servo1.write(0); servo2.write(90); servo3.write(0);delay(1000);}
  if (uneLettre == "6" )   {servo1.write(135); servo2.write(0); servo3.write(90);delay(1000);}
  if (uneLettre == "7" )   {servo1.write(90); servo2.write(90); servo3.write(90);delay(1000);}
  if (uneLettre == "8" )   {servo1.write(45); servo2.write(90); servo3.write(90);delay(1000);}
  if (uneLettre == "9" )   {servo1.write(0); servo2.write(90); servo3.write(90);delay(1000);}
  if (uneLettre == "10" )   {servo1.write(135); servo2.write(90); servo3.write(90);delay(1000);}   }
  // end of request reading
  
  client.flush();

  // assigns a value to "val" following request 
  int val = -1; 

  if (req.indexOf("/A") != -1)
    val = 1; 
 else if (req.indexOf("/B") != -1)  val = 2;
 else if (req.indexOf("/C") != -1)  val = 3;
 else if (req.indexOf("/D") != -1)  val = 4;
 else if (req.indexOf("/E") != -1)  val = 5;
 else if (req.indexOf("/F") != -1)  val = 6;
 else if (req.indexOf("/G") != -1)  val = 7;
 else if (req.indexOf("/H") != -1)  val = 8;
 else if (req.indexOf("/I") != -1)  val = 9;
 else if (req.indexOf("/J") != -1)  val = 10;
 else if (req.indexOf("/K") != -1)  val = 11;
 else if (req.indexOf("/L") != -1)  val = 12;
 else if (req.indexOf("/M") != -1)  val = 13;
 else if (req.indexOf("/N") != -1)  val = 14;
 else if (req.indexOf("/O") != -1)  val = 15;
 else if (req.indexOf("/P") != -1)  val = 16;
 else if (req.indexOf("/Q") != -1)  val = 17;
 else if (req.indexOf("/R") != -1)  val = 18;
 else if (req.indexOf("/S") != -1)  val = 19;
 else if (req.indexOf("/T") != -1)  val = 20;
 else if (req.indexOf("/U") != -1)  val = 21;
 else if (req.indexOf("/V") != -1)  val = 22;
 else if (req.indexOf("/W") != -1)  val = 23;
 else if (req.indexOf("/X") != -1)  val = 24;
 else if (req.indexOf("/Y") != -1)  val = 25;
 else if (req.indexOf("/Z") != -1)  val = 26;
 else if (req.indexOf("/&") != -1)  val = 27;
 else if (req.indexOf("/1") != -1)  val = 28;
 else if (req.indexOf("/2") != -1)  val = 29;
 else if (req.indexOf("/3") != -1)  val = 30;
 else if (req.indexOf("/4") != -1)  val = 31;
 else if (req.indexOf("/5") != -1)  val = 32;
 else if (req.indexOf("/6") != -1)  val = 33;
 else if (req.indexOf("/7") != -1)  val = 34;
 else if (req.indexOf("/8") != -1)  val = 35;
 else if (req.indexOf("/9") != -1)  val = 36;
 else if (req.indexOf("/10") != -1)  val = 37;

  // Prepare the response web page. Start with common "header" ; (HTML code will be written in the character string s).
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n";
  s += "<html>\r\n";
  
  s += "<center>";
  s += "<h1 style=\"font-size:300%;\"\> Le Chappeduino by Toysfab";

  // let's finalise the character string and send instructions
if (val == 1 )   {    s +=  "A" ;  servo1.write(90); servo2.write(0); servo3.write(179);}
if (val == 2 )   {    s +=  "B" ;  servo1.write(45); servo2.write(0); servo3.write(179);}
if (val == 3 )   {    s +=  "C" ;  servo1.write(0); servo2.write(0); servo3.write(179);}
if (val == 4 )   {    s +=  "D" ;  servo1.write(135); servo2.write(179); servo3.write(0);}
if (val == 5 )   {    s +=  "E" ;  servo1.write(90); servo2.write(179); servo3.write(0);}
if (val == 6 )   {    s +=  "F" ;  servo1.write(45); servo2.write(179); servo3.write(0);}
if (val == 7 )   {    s +=  "G" ;  servo1.write(0); servo2.write(179); servo3.write(0);}
if (val == 8 )   {    s +=  "H" ;  servo1.write(135); servo2.write(0); servo3.write(179);}
if (val == 9 )   {    s +=  "I" ;  servo1.write(90); servo2.write(0); servo3.write(0);}
if (val == 10 )   {    s +=  "J" ;  servo1.write(90); servo2.write(0); servo3.write(0);}
if (val == 11 )   {    s +=  "K" ;  servo1.write(45); servo2.write(0); servo3.write(0);}
if (val == 12 )   {    s +=  "L" ;  servo1.write(0); servo2.write(0); servo3.write(0);}
if (val == 13 )   {    s +=  "M" ;  servo1.write(135); servo2.write(0); servo3.write(0);}
if (val == 14 )   {    s +=  "N" ;  servo1.write(90); servo2.write(179); servo3.write(179);}
if (val == 15 )   {    s +=  "O" ;  servo1.write(45); servo2.write(179); servo3.write(179);}
if (val == 16 )   {    s +=  "P" ;  servo1.write(0); servo2.write(179); servo3.write(179);}
if (val == 17 )   {    s +=  "Q" ;  servo1.write(135); servo2.write(179); servo3.write(179);}
if (val == 18 )   {    s +=  "R" ;  servo1.write(90); servo2.write(90); servo3.write(179);}
if (val == 19 )   {    s +=  "S" ;  servo1.write(45); servo2.write(90); servo3.write(179);}
if (val == 20 )   {    s +=  "T" ;  servo1.write(0); servo2.write(90); servo3.write(179);}
if (val == 21 )   {    s +=  "U" ;  servo1.write(135); servo2.write(179); servo3.write(90);}
if (val == 22 )   {    s +=  "V" ;  servo1.write(90); servo2.write(179); servo3.write(90);}
if (val == 23 )   {    s +=  "W" ;  servo1.write(45); servo2.write(179); servo3.write(90);}
if (val == 24 )   {    s +=  "X" ;  servo1.write(0); servo2.write(179); servo3.write(90);}
if (val == 25 )   {    s +=  "Y" ;  servo1.write(135); servo2.write(90); servo3.write(179);}
if (val == 26 )   {    s +=  "Z" ;  servo1.write(90); servo2.write(0); servo3.write(90);}
if (val == 27 )   {    s +=  "&" ;  servo1.write(45); servo2.write(0); servo3.write(90);}
if (val == 28 )   {    s +=  "1" ;  servo1.write(0); servo2.write(0); servo3.write(90);}
if (val == 29 )   {    s +=  "2" ;  servo1.write(135); servo2.write(90); servo3.write(0);}
if (val == 30 )   {    s +=  "3" ;  servo1.write(90); servo2.write(90); servo3.write(0);}
if (val == 31 )   {    s +=  "4" ;  servo1.write(45); servo2.write(90); servo3.write(0);}
if (val == 32 )   {    s +=  "5" ;  servo1.write(0); servo2.write(90); servo3.write(0);}
if (val == 33 )   {    s +=  "6" ;  servo1.write(135); servo2.write(0); servo3.write(90);}
if (val == 34 )   {    s +=  "7" ;  servo1.write(90); servo2.write(90); servo3.write(90);}
if (val == 35 )   {    s +=  "8" ;  servo1.write(45); servo2.write(90); servo3.write(90);}
if (val == 36 )   {    s +=  "9" ;  servo1.write(0); servo2.write(90); servo3.write(90);}
if (val == 37 )   {    s +=  "10" ;  servo1.write(135); servo2.write(90); servo3.write(90);}

  s += "</h1>";
  s += "<br>"; 
  s += "<br>";
  s += "<center><form method=\"get\">Mon texte: <input type=\"text\" name=\"phrase\"><input type=\"submit\" value=\"Submit\"></form></center>\r\n";
  s += "<br>"; 
 s += "<a href=\"/A\"\"><button style=\"font-size:200%; width: 18%\"\>A</button></a>\r\n";// creer un boutton "A"
 s += "<a href=\"/B\"\"><button style=\"font-size:200%; width: 18%\"\>B</button></a>\r\n";// creer un boutton "B"
 s += "<a href=\"/C\"\"><button style=\"font-size:200%; width: 18%\"\>C</button></a>\r\n";// creer un boutton "C"
 s += "<a href=\"/D\"\"><button style=\"font-size:200%; width: 18%\"\>D</button></a>\r\n";// creer un boutton "D"
 s += "<a href=\"/E\"\"><button style=\"font-size:200%; width: 18%\"\>E</button></a>\r\n";// creer un boutton "E"
 s += "<a href=\"/F\"\"><button style=\"font-size:200%; width: 18%\"\>F</button></a>\r\n";// creer un boutton "F"
 s += "<a href=\"/G\"\"><button style=\"font-size:200%; width: 18%\"\>G</button></a>\r\n";// creer un boutton "G"
 s += "<a href=\"/H\"\"><button style=\"font-size:200%; width: 18%\"\>H</button></a>\r\n";// creer un boutton "H"
 s += "<a href=\"/I\"\"><button style=\"font-size:200%; width: 18%\"\>I</button></a>\r\n";// creer un boutton "I"
 s += "<a href=\"/J\"\"><button style=\"font-size:200%; width: 18%\"\>J</button></a>\r\n";// creer un boutton "J"
 s += "<a href=\"/K\"\"><button style=\"font-size:200%; width: 18%\"\>K</button></a>\r\n";// creer un boutton "K"
 s += "<a href=\"/L\"\"><button style=\"font-size:200%; width: 18%\"\>L</button></a>\r\n";// creer un boutton "L"
 s += "<a href=\"/M\"\"><button style=\"font-size:200%; width: 18%\"\>M</button></a>\r\n";// creer un boutton "M"
 s += "<a href=\"/N\"\"><button style=\"font-size:200%; width: 18%\"\>N</button></a>\r\n";// creer un boutton "N"
 s += "<a href=\"/O\"\"><button style=\"font-size:200%; width: 18%\"\>O</button></a>\r\n";// creer un boutton "O"
 s += "<a href=\"/P\"\"><button style=\"font-size:200%; width: 18%\"\>P</button></a>\r\n";// creer un boutton "P"
 s += "<a href=\"/Q\"\"><button style=\"font-size:200%; width: 18%\"\>Q</button></a>\r\n";// creer un boutton "Q"
 s += "<a href=\"/R\"\"><button style=\"font-size:200%; width: 18%\"\>R</button></a>\r\n";// creer un boutton "R"
 s += "<a href=\"/S\"\"><button style=\"font-size:200%; width: 18%\"\>S</button></a>\r\n";// creer un boutton "S"
 s += "<a href=\"/T\"\"><button style=\"font-size:200%; width: 18%\"\>T</button></a>\r\n";// creer un boutton "T"
 s += "<a href=\"/U\"\"><button style=\"font-size:200%; width: 18%\"\>U</button></a>\r\n";// creer un boutton "U"
 s += "<a href=\"/V\"\"><button style=\"font-size:200%; width: 18%\"\>V</button></a>\r\n";// creer un boutton "V"
 s += "<a href=\"/W\"\"><button style=\"font-size:200%; width: 18%\"\>W</button></a>\r\n";// creer un boutton "W"
 s += "<a href=\"/X\"\"><button style=\"font-size:200%; width: 18%\"\>X</button></a>\r\n";// creer un boutton "X"
 s += "<a href=\"/Y\"\"><button style=\"font-size:200%; width: 18%\"\>Y</button></a>\r\n";// creer un boutton "Y"
 s += "<a href=\"/Z\"\"><button style=\"font-size:200%; width: 18%\"\>Z</button></a>\r\n";// creer un boutton "Z"
 s += "<a href=\"/&\"\"><button style=\"font-size:200%; width: 18%\"\>&</button></a>\r\n";// creer un boutton "&"
 s += "<a href=\"/1\"\"><button style=\"font-size:200%; width: 18%\"\>1</button></a>\r\n";// creer un boutton "1"
 s += "<a href=\"/2\"\"><button style=\"font-size:200%; width: 18%\"\>2</button></a>\r\n";// creer un boutton "2"
 s += "<a href=\"/3\"\"><button style=\"font-size:200%; width: 18%\"\>3</button></a>\r\n";// creer un boutton "3"
 s += "<a href=\"/4\"\"><button style=\"font-size:200%; width: 18%\"\>4</button></a>\r\n";// creer un boutton "4"
 s += "<a href=\"/5\"\"><button style=\"font-size:200%; width: 18%\"\>5</button></a>\r\n";// creer un boutton "5"
 s += "<a href=\"/6\"\"><button style=\"font-size:200%; width: 18%\"\>6</button></a>\r\n";// creer un boutton "6"
 s += "<a href=\"/7\"\"><button style=\"font-size:200%; width: 18%\"\>7</button></a>\r\n";// creer un boutton "7"
 s += "<a href=\"/8\"\"><button style=\"font-size:200%; width: 18%\"\>8</button></a>\r\n";// creer un boutton "8"
 s += "<a href=\"/9\"\"><button style=\"font-size:200%; width: 18%\"\>9</button></a>\r\n";// creer un boutton "9"
 s += "<a href=\"/10\"\"><button style=\"font-size:200%; width: 18%\"\>10</button></a><br />\r\n";// creer un boutton "10"
  s += "</center>";
  s += "</html>\n"; //end of Web page

  // send response to browser
  client.print(s);
  delay(10);
  Serial.println("Client disconnected");
  client.flush();

}



void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}