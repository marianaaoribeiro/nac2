int potUm = A0;
int potDois = A1;

int buttonPin2 = 2; // nomeia o pino2 do arduino como buttonPin2
int buttonPin3 = 3; // nomeia o pino3 do arduino como buttonPin3
int ledPin = 13;    // nomeia o pino13 do arduino como ledPin 

int buttonStatus2;  // Variavel de estado do buttonPin2
int buttonStatus3;  // Variavel de estado do buttonPin2

int var1;
int var2;
void setup() {
pinMode(ledPin, OUTPUT);            //Pino13 como saida 
  pinMode(buttonPin2, INPUT_PULLUP);  //Pino2 como entrada com resistor de pullup interno
  pinMode(buttonPin3, INPUT_PULLUP);  //Pino3 como entrada com resistor de pullup interno
  Serial.begin(9600);				   //Inicialica a comunicação serial
}

void loop() {
   buttonStatus2 = digitalRead(buttonPin2);
   buttonStatus3 = digitalRead(buttonPin3);
 	var1 = analogRead(potUm);
	var2 = analogRead(potDois);
  if (buttonStatus2 == LOW){
	Serial.print("A");                        // Então acenda o led
    Serial.print(var1);
    delay(500);                                         // delay de 0,5 seg.
  }
if (buttonStatus3 == LOW){                            // Então acenda o led
    Serial.print("B");
    Serial.print(var2);
    delay(500);                                          // delay de 0,5 seg.
  }
}