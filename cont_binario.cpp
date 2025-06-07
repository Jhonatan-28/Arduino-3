const int buttonPin = 10;         
const int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; 
int counter = 0;
bool lastButtonState = LOW;
bool currentButtonState = LOW;

void setup() {
  
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT);  
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    counter++;
    if (counter > 255) counter = 0;  

    displayBinary(counter);  
    delay(100);  
  }

  lastButtonState = currentButtonState;
}

void displayBinary(int value) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], bitRead(value, i));
  }
}
