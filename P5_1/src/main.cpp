//librerías 
#include <Wire.h> // Librería para establecer comunicación I2C
#include <AHT10.h> // Librería para utilizar el sensor AHT10

AHT10 myAHT10(0x38);

void setup() {
Wire.begin(); // Función que inicializa la librería Wire
Serial.begin(9600); //Se inicia la comunicación serial 
Serial.println("AHT10"); // Se imprime el nombre de sensor
if (!myAHT10.begin()) { // Si la comunicación con el sensor falla se imprime el un mensaje de error 
Serial.println("Error no se el sensor!");
while (1);
}
}

void loop() {
float temp = myAHT10.readTemperature(); //Se lee la temperatura y se asigna "temp"
float hum = myAHT10.readHumidity(); //Se lee humedad y se asigna "hum" 
Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C"); //Se imprime el valor de tempertura 
Serial.print("tt"); // Imprime dos pestañas para acomodar los valores de temperatura y humedad
Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %"); //Se imprime el valor de humedad
delay(1000);
}