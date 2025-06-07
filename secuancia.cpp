
// Configuración de pines

const int buttonPin = 10;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numSteps = sizeof(ledPins) / sizeof(ledPins[0]);


// Variables para el botón

bool currentButtonState = LOW;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;


// Variables de secuencia

int modoSecuencia = 0; 
int paso = 0;          
unsigned long lastStepTime = 0;
const unsigned long stepInterval = 400; // Tiempo entre pasos en ms


// setup()

void setup() {
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < numSteps; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}


// loop()

void loop() {
  manejarBoton();
  ejecutarSecuencia();
}



void manejarBoton() {
  bool lectura = digitalRead(buttonPin);

  if (lectura != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (lectura != currentButtonState) {
      currentButtonState = lectura;

      if (currentButtonState == HIGH) {
        modoSecuencia = 1 - modoSecuencia; 
        paso = 0; // reiniciar paso cuando se cambia de modo
      }
    }
  }

  lastButtonState = lectura;
}




void ejecutarSecuencia() {
  if (millis() - lastStepTime >= stepInterval) {
    apagarTodosLosLEDs();

    if (modoSecuencia == 0) {
      
      digitalWrite(ledPins[paso], HIGH);
      paso = (paso + 1) % numSteps;

    } else {
      // Secuencia B: pares -> impares -> pares...
      int grupo = paso % 2; // 0 para pares, 1 para impares
      for (int i = grupo; i < numSteps; i += 2) {
        digitalWrite(ledPins[i], HIGH);
      }
      paso = (paso + 1) % 2; 
    }

    lastStepTime = millis();
  }
}


// Apagar todos los LEDs

void apagarTodosLosLEDs() {
  for (int i = 0; i < numSteps; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
