/*
Akıllı Ev Projesi
github.com/BedirDemir
09.04.2018
*/

#include <LiquidCrystal.h> // LCD Kütüphanesi
#include <Servo.h> //Servo Kütüphanesi
#include <math.h> // Matematiksel İşlem Kütüphanesi

// Değişkenlerim
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
Servo myservo;
char veri;
int lamba = 13;
int dis_lamba = 3;
int dis_lamba_durum = 0;
int buzzer = 10;
int fan = 2;
int derece = 0;
int ldr_deger = 0;

void setup() {
  // Kurulum
  lcd.begin(16, 2);
  lcd.print("HOSGELDINIZ");
  pinMode(buzzer, OUTPUT);
  pinMode(lamba, OUTPUT);
  pinMode(dis_lamba, OUTPUT);
  pinMode(fan, OUTPUT);
  tone(buzzer, 294);
  delay(500);
  noTone(buzzer);
  delay(3000);
  lcd.clear();
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  lcd.setCursor(3, 0);
  lcd.print("AKILLI EV");
}

// Sıcaklık Okuma Fonksiyonu
double Termistor(int analogOkuma){
  double sicaklik;
  sicaklik = log(((10240000 / analogOkuma) - 10000));
  sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik )) * sicaklik );
  sicaklik = sicaklik - 273.15;
  return sicaklik;
}

// LCD Ekranın Alt Satırını Temizlemek İçin Fonksiyon (16 tane boşluk at)
void LCDTemizle(){
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
}

// Buzzer Çalma Fonksiyonu
void BuzzerCal(){
  tone(buzzer, 294);
  delay(400);
  noTone(buzzer);
}

void loop() {
  // Sonsuz Döngü...
  veri = Serial.read(); // Bluetooth'dan Gelen Değeri Veri Değişkenine Ata
  
  // Dış Aydınlatma LDR
  ldr_deger = analogRead(A1);
  if(dis_lamba_durum == 0 && ldr_deger <= 400){
    dis_lamba_durum = 1;
    digitalWrite(dis_lamba, HIGH);
    LCDTemizle();
    lcd.print("On Lamba Acik");
    BuzzerCal();
  }
  
  if(dis_lamba_durum == 1 && ldr_deger >= 700){
    dis_lamba_durum = 0;
    digitalWrite(dis_lamba, LOW);
    LCDTemizle();
    lcd.print("On Lamba Kapali");
    BuzzerCal();
  }
  
  // Termistor Fonksiyonunu Kullanarak Sıcaklığı Hesapla
  int deger;
  double sicaklik;
  deger = analogRead(A0);
  sicaklik = Termistor(deger);

  // Gelen Değer 0 İse Kapıyı Kapat
  if(veri=='0'){
    LCDTemizle();
    lcd.print("Kapi Kapaniyor..");
    BuzzerCal();
    for(derece = 180; derece >= 0; derece -= 1){
      myservo.write(derece);//Motor Döner..
    }
    delay(1000);
    LCDTemizle();
    lcd.print("Kapi Kapandi");
    delay(1000);
  }
  
  // Gelen Değer 1 İse Kapıyı Aç
  if(veri=='1'){
    LCDTemizle();
    lcd.print("Kapi Aciliyor..");
    BuzzerCal();
    for(derece = 0; derece <= 180; derece += 1){
      myservo.write(derece); //Motor Döner..
    }
    delay(1000);
    LCDTemizle();
    lcd.print("Kapi Acildi");
    delay(1000);
  }
  
  // Gelen Değer 2 İse Sıcaklığı Yaz
  if(veri=='2'){
    BuzzerCal();
    Serial.print(sicaklik);
    LCDTemizle();
    lcd.print("Sicaklik:");
    lcd.print(sicaklik);
    delay(1000);
  }
  
  // Gelen Değer 3 İse Lambayı Yak
  if(veri=='3'){
    BuzzerCal();
    LCDTemizle();
    lcd.print("Lamba Yandi");
    digitalWrite(lamba, HIGH);
    delay(1000);
  }
  
  //Gelen Değer 4 İse Lambayı Söndür
  if(veri=='4'){
    BuzzerCal();
    LCDTemizle();
    lcd.print("Lamba Sondu");
    digitalWrite(lamba, LOW);
    delay(1000);
  }

  // Gelen Değer 5 İse Fanı Çalıştır
  if(veri=='5'){
    BuzzerCal();
    LCDTemizle();
    lcd.print("Klima Devrede");
    digitalWrite(fan, HIGH);
    delay(1000);
  }

  //Gelen Değer 6 İse Fanı Kapat
  if(veri=='6'){
    BuzzerCal();
    LCDTemizle();
    lcd.print("Klima Kapali");
    digitalWrite(fan, LOW);
    delay(1000);
  }
  
  delay(100);
}
