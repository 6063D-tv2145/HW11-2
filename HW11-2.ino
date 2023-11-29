bool passwordCorrect;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0); 
  int button2 = digitalRead(2);
  int button3 = digitalRead(3);

  digitalWrite(5, LOW); // turn off green LED
  digitalWrite(6, LOW); // turn off red LED

 Serial.print("Potentiometer value: ");
  Serial.println(potValue);
  Serial.print("Button 2: ");
  Serial.println(button2 == HIGH ? "Pressed" : "Not Pressed");
  Serial.print("Button 3: ");
  Serial.println(button3 == HIGH ? "Pressed" : "Not Pressed");

  if (potValue == 4095 && button2 == HIGH && button3 == HIGH) { // correct password
    passwordCorrect = true;
  } else {
    passwordCorrect = false;
  }

  if (passwordCorrect) {
    digitalWrite(5, HIGH); // turn on green LED
    delay(500);
    digitalWrite(5, LOW); // turn off green LED
    Serial.println("Correct password entered, door is unlocked.");

  } else { 
    digitalWrite(6, HIGH); // turn on red LED
    delay(500);
    Serial.println("Door is locked.");
  }
  delay(10);
}

