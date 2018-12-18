const int ledPin = 13; 
int incomingByte; 
String stringTemperatura = ""; 
int contador = 5; 
const int intervalo = 5; 

void setup() { 
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
} 
void loop() { 
  //int temperatura = analogRead(A0); 
  // SI NO TIENE CONECTADO UN POTENCIOMETRO AL PUERTO A0 (ANALOGO 0) 
  // COMENTARIE LA LINEA 013 Y DESCOMENTARIE LA 016 
  int temperatura = random(0, 1024); 
  float fTemperatura = ((float)temperatura / 1024.0) * 50;
  float y = ((float)temperatura / 1024.0) * 50;
  float xx = random(2, 7); 
  float xxx = (((float)temperatura / 1024) * 4) +2;
  
  int SL = analogRead(A0); 
 float inicioSL = 2.0;
 float finSL = 6.0;
 float rangoSL = finSL - inicioSL;
  //int intSL = random(0, 1024);
  float sl = (((float)SL / 1024.0 * rangoSL) + inicioSL);
 //  Serial.println(sl);
  String stringSL = String(sl, 1);

  int SW = analogRead(A1); 
  float inicioSW = 3.0;
  float finSW = 7.0;
  float rangoSW = finSW - inicioSW;
  //int intSL = random(0, 1024);
  float sw = (((float) SW / 1024.0 * rangoSW) + inicioSW);
 // Serial.println(sw);
  String stringSW = String(sw, 1);

   int PL = analogRead(A2); 
 float inicioPL = 2.0;
 float finPL = 7.0;
 float rangoPL = finPL - inicioPL;
  //int intPL = random(0, 1024);
 float pl = (((float)PL / 1024.0 * rangoPL) + inicioPL);
 // Serial.println(pl);
  String stringPL = String(pl, 1);

   int PW = analogRead(A3); 
  float inicioPW = 0.0;
  float finPW = 5.0;
  float rangoPW = finPW - inicioPW;
  //int intSL = random(0, 1024);
  float pw = (((float) PW / 1024.0 * rangoPW) + inicioPW);
  //Serial.println(pw);
  String stringPW = String(pw, 1);
  
 // float x = constrain (); 
  stringTemperatura = String(fTemperatura, 2); 

      String json = "{'nodo':'nodo01'";
      json = json + ", 'sl':" + stringSL;
      json = json + ",'sw':" + stringSW;
      json = json + ",'pl':" + stringPL;
      json = json + ",'pw':" + stringPW + "}";
  
  if (Serial.available() > 0) { 
    incomingByte = Serial.read(); 
    if (incomingByte == 'H') { 
      digitalWrite(ledPin, HIGH); 
      Serial.println("{'nodo':'nodo01','led':'PRENDIDO'}"); 
    } 
    if (incomingByte == 'L') { 
      digitalWrite(ledPin, LOW); 
      Serial.println("{'nodo':'nodo01','led':'APAGADO'}"); 
    } 
    if (incomingByte == 'R') { 
     //Serial.println("{'nodo':'nodo01','temperatura':" + stringTemperatura + "}");
      
        Serial.println(json);
    } 
  }

  
  if(contador % intervalo == 0){ 
    //Serial.println("{'nodo':'nodo01','temperatura':" + stringTemperatura + "}"); 
    Serial.println(json);
    
    contador = 0; 
    
  } 
  delay(1000); 
  contador = contador + 1; 
}
