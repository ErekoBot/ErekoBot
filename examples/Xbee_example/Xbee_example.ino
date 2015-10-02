char estado;
void setup() {
  Serial.begin(9600);    	//initialize serial
  pinMode(13, OUTPUT);   	//set pin 13 as output
  Serial.println("Escreva a, para ligar o LED e b, para desligar ");
}

void loop() {

  if(Serial.available()>0){  //há algo para ler?
    estado = Serial.read(); //Se tem, leia-a  
    if(estado == 'a' ){
      Serial.println(" Ligado ");
      digitalWrite(13, HIGH);

    }
    else if(estado == 'b'){
      Serial.println(" Desligado ");
      digitalWrite(13,LOW);    
    }
  }
}

