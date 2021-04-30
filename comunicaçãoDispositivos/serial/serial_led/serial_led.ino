#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C // 0x3C device address of I2C OLED
Adafruit_SSD1306 oled(128, 64);
int ledPin = 11;    // nomeia o pino11 do arduino como ledPin 

void setup() {
  pinMode(ledPin, OUTPUT);            //Pino11 como saida 
  Serial.begin(9600);
oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);				   //Inicialica a comunicação serial
}


void loop() {		// antigo, o templast

  char dado;	
int valor;						    // Declara dado como variavel local do tipo char

  if(Serial.available() > 0){				// Se tem alguma coisa no buffer da serial
    dado = Serial.read();					// Entao salva em dado
    Serial.print(dado);

    if (dado == 'A'){   					// Se dado igual a 'L'
        valor = Serial.parseInt();   // salva em valor o valor do pot1 recebido na serial​
		
		oled.clearDisplay();
		
		oled.setCursor(0,0);			// seta o cursor no inicio
	  	oled.setTextColor(WHITE);	// 
	    oled.println("port1:");
	    oled.println(valor);
	    oled.display();
	    delay(100);                           // delay de 0,5 seg.
    }//end if dado == 'L'

    if (dado == 'B'){ 
		valor = Serial.parseInt();   // salva em valor o valor do pot1 recebido na serial​
		oled.clearDisplay();
	
		oled.setCursor(0,0);			// seta o cursor no inicio
  		oled.setTextColor(WHITE);	// 
  		oled.println("port2:");
		oled.println(valor);
  		oled.display();
  		delay(100);                            // delay de 0,5 seg.
    }

  }//end if Serial.available

}//end loop