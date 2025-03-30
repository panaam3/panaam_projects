// transpoCredit final Skecth
// @author: Phiwumusa Ngidi
int balance;
int deposit;
int fee;
int numt = 5000;
int choice;
int red=4;
int green=3;
int blue=2;
int swt=0;
int buzzer=5;
int shortnumt=100;
int OEincome;
int bridge;
boolean when=false;

#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

int rfidCard;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd.init();       // initialize the lcd
  lcd.init();
  //card setup
  
  SPI.begin();
  rfid.init();
  
  // begin 
  
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("    PA INC.");
  lcd.setCursor(0, 1);
  lcd.print(" TranspoCredit");
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  delay(numt);
    digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  lcd.clear();
  
}
void loop() {
  // put your main code here, to run repeatedly: 
  
  lcd.clear();
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Deposit: ");
   if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  
  while (Serial.available() == 0) {
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
  }
  
  while(rfidCard!=411){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Card");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }

  if (rfidCard==411){
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  deposit = Serial.parseInt();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Deposit :R");
  lcd.print(deposit);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Balanced Updated");
  lcd.setCursor(0, 1);
  lcd.print("balance :R");
  balance = deposit;
  lcd.print(balance);
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  lcd.clear();
  }
  rfidCard=0;

  while(choice!=6) {

    delay(500);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(500);
  while (Serial.available() == 0) {
    lcd.setCursor(0, 0);
    lcd.print("1-Check balance");
    lcd.setCursor(0, 1);
    lcd.print("2-Make a deposit");
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
        digitalWrite(green, LOW);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("3-Transaction");
    lcd.setCursor(0,1);
    lcd.print("4-Check Income");
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("5-Get Income");
    lcd.setCursor(0,1);
    lcd.print("6-Exit");
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    lcd.clear();
    

  }
 choice = Serial.parseInt();
 
  if (choice==1){
 rfidCard=0;    
  while(rfidCard!=411){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Card");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }
  if (rfidCard==411){
  lcd.clear();
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  lcd.setCursor(0,0);
  lcd.print("Balance :R");
  lcd.print(balance);
  digitalWrite(blue, HIGH);
  delay(5000);
  digitalWrite(blue, LOW);
  lcd.clear();
  }
  }
  
 if (choice==2){
  rfidCard=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Deposit: ");
  
  while (Serial.available() == 0) {}
    
    while(rfidCard!=411){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Card");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }

  if (rfidCard==411){
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  deposit = Serial.parseInt();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Deposit :R");
  lcd.print(deposit);
  digitalWrite(green, HIGH);
  delay(5000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Balanced Updated");
  lcd.setCursor(0, 1);
  lcd.print("balance :R");
  
  balance = balance + deposit;
  
  lcd.print(balance);
  
  delay(5000);
  lcd.clear();
  digitalWrite(green, LOW);
  } 
 }
 
 if (choice==3){
  rfidCard=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter fee: ");
  
  while (Serial.available() == 0) {}

  while(rfidCard!=411){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Card");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }

  if (rfidCard==411){
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  fee = Serial.parseInt();
  if (balance>fee){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("fee :R");
  lcd.print(fee);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Balanced Updated");
  lcd.setCursor(0, 1);
  lcd.print("balance :R");
  
  balance = balance - fee;
  
  lcd.print(balance);
  
  delay(5000);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  lcd.clear();
  
  }
  else{
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("INSUFFICIENT");
  lcd.setCursor(0,1);
  lcd.print("***FUNDS***");
  digitalWrite(red, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(5000);
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("Please deposit");
  lcd.setCursor(0,1);
  lcd.print("cash 2 Continue");
  delay(5000);
  digitalWrite(red,LOW);
  digitalWrite(buzzer, LOW);
  lcd.clear();
  }
 
  }
}
 if (choice==4){
 rfidCard=0;    
  while(rfidCard!=483){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Driver's Tag");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }
  if (rfidCard==483){
  lcd.clear();
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  lcd.setCursor(0,0);
  OEincome =OEincome + fee;
  lcd.print("Income :R");
  lcd.print(OEincome);
  digitalWrite(blue, HIGH);
  delay(5000);
  digitalWrite(blue, LOW);
  lcd.clear();
  when = true;
  }
  }
 if (choice==5 & when==true){
  rfidCard=0;
  lcd.clear();
  lcd.setCursor(0, 0);    
    while(rfidCard!=483){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Driver's Tag");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }

  if (rfidCard==483){
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cash :R");
  lcd.print(OEincome);
  digitalWrite(green, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Cash Transferred");
  delay(5000);
  lcd.clear();
  digitalWrite(green, LOW);
  OEincome=0;
  fee=0;
  when=false;
  } 
 }else{
 if (choice==5 & when==false){
  rfidCard=0;
  lcd.clear();
  lcd.setCursor(0, 0);    
    while(rfidCard!=483){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please Tap Your");
    lcd.setCursor(0,1);
    lcd.print("Driver's Tag");
       if (rfid.isCard()) {
  if (rfid.readCardSerial()) {
    rfidCard = int(rfid.serNum[0]) + int(rfid.serNum[1]) + int(rfid.serNum[2]) + int(rfid.serNum[3]);
    }
    rfid.halt();
    }
  }

  if (rfidCard==483){
  digitalWrite(buzzer, HIGH);
  delay(shortnumt);
  digitalWrite(buzzer, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cash :R");
  bridge=OEincome + fee;
  lcd.print(bridge);
  digitalWrite(green, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Cash Transferred");
  delay(5000);
  lcd.clear();
  digitalWrite(green, LOW);
  OEincome=0;
  fee=0;
  } 
 }
  
  }
  
}
}
