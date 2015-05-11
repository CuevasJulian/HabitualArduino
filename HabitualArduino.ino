long tiempo = 0;
int espera = 500;

int humedad = 0;
int luz = 0;
int temperatura = 0;

int pinRelee = 13;

void setup(){
 Serial.begin(9600);
 tiempo = millis();
 pinMode(pinRelee,OUTPUT);
 digitalWrite(pinRelee,LOW);
 
}

void loop(){
  lecturaTemp();
  lecturaHum();
  lecturaLuz();
  recibirDatos();
  enviarDatos();
}

void lecturaTemp(){
 temperatura = analogRead(A0); 
 temperatura = (5.0 * temperatura * 100.0) / 1024;
}
void lecturaHum(){
 humedad = analogRead(A1); 
 humedad = (int) map(humedad,1024,0,0,100);
}
void lecturaLuz(){
 luz = analogRead(A2); 
 luz = (int) map(luz,0,1024,0,100);
}

void enviarDatos(){
  if(millis() - tiempo > espera){
    tiempo = millis();
    Serial.print(temperatura);
    Serial.print("/");
    Serial.print(luz);
    Serial.print("/");
    Serial.print(humedad);
    Serial.print("/");
    Serial.print('\n'); 
  }  
}
void recibirDatos(){
 if(Serial.available() > 0){
    int d = Serial.read();
    if(d == 1){
      digitalWrite(pinRelee,HIGH);
    }else{
      digitalWrite(pinRelee,LOW);
    }
 } 
}
