#define pulsador 2 
#define led1 13
#define led2 12

void setup() {
  pinMode(pulsador, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
}

void loop() {
  int valor = digitalRead(pulsador);

  if (valor) {
    // Encender led1 y apagar led2
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);


    digitalWrite(led1, LOW);
  } else {
    // Encender led2 y apagar led1
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }


}
