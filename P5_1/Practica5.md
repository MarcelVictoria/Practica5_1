#PRACTICA 5 : Buses de comunicación I (introducción y I2c) 
<div align=right>
Victòria Blanco Bosch 
<div>
<div align=right>
Marcel Farelo de la Orden
<div> 
<div align="justify">

***

# Ejercicio practico 1 - ESCÀNER I2C

## **Introducción**
El objetivo de esta práctica es comprender el funcionamiento de los buses/sistemas de comunicación entre periféricos, estos elementos pueden ser internos o externos al procesador.


## **Funcionamiento**
El funcionamiento de este ejercicio consiste en comprobar la temperatura y humead del laboratorio. Utilizando el dispositivo AHT10 y un sensor de temperatura y humedad. Finalmente podremos observar el resultado en el dispositivo I2C.

## **Material**
* ESP32-Wroom-32.
* AHT10 Sensor de Temperatura y Humedad I2C.
* Sensor I2C BMP280.

#### **INFORMACIÓN AHT10**
AHT10 es un sensor de temperatura y humedad altamente preciso y de bajo consumo de energía. Es fabricado por la compañía Ambient Micro. A continuación, te proporcionaré información relevante sobre este sensor:

1. Funcionalidad: El AHT10 es capaz de medir tanto la temperatura como la humedad relativa del entorno en el que se encuentra. Proporciona lecturas precisas y confiables en una amplia gama de condiciones ambientales.

2. Precisión: El sensor tiene una precisión de ±0.3°C en la medición de la temperatura y ±2% en la medición de la humedad relativa. Estos valores lo convierten en una opción adecuada para aplicaciones que requieren mediciones precisas.

3. Interfaz de comunicación: El AHT10 utiliza una interfaz digital I2C para la comunicación con otros dispositivos electrónicos, lo que facilita su integración en proyectos de electrónica y sistemas embebidos.

4. Rango de medición: En cuanto a la temperatura, el AHT10 puede medir en un rango de -40°C a 85°C, lo que lo hace adecuado para aplicaciones en entornos amplios. Para la humedad relativa, puede medir en un rango del 0 al 100%.

5. Consumo de energía: Este sensor es conocido por su bajo consumo de energía, lo que lo hace ideal para dispositivos alimentados por batería o con requisitos de eficiencia energética.

6. Calibración: El AHT10 viene calibrado de fábrica, lo que significa que no requiere una calibración adicional para proporcionar mediciones precisas. Sin embargo, si se desea una mayor precisión, es posible realizar una calibración personalizada.

7. Aplicaciones: El AHT10 se utiliza en una amplia gama de aplicaciones, como sistemas de climatización, estaciones meteorológicas, monitoreo ambiental, sistemas de control de procesos y dispositivos portátiles que requieren mediciones precisas de temperatura y humedad.


# Código del programa
***
### Librerias
Incluimos las librerías **"Arduino.h"**, **"Wire.h"** (para poder establecer la comunicación con el I2C) **"AHT10.h"** (para poder usar el el sensor AHT10).
```cpp

//librerías 
#include <Arduino.h>
#include <Wire.h> // Librería para establecer comunicación I2C
#include <AHT10.h> // Librería para utilizar el sensor AHT10


AHT10 myAHT10(0x38);
```
### Estructura del Setup

1. Se inicializa la libreria **"Wire"** y la comunicación serial.
2. Se imprime el nombre del sensor (AHT10)
3. Se imprime un mensaje de *error* si la comunicación con el sensor falla.


```cpp

void setup() {
Wire.begin(); // Función que inicializa la librería Wire
Serial.begin(9600); //comunicación serial 
Serial.println("AHT10"); //imprime nombre sensor
if (!myAHT10.begin()) { //mensaje de error si falla
Serial.println("Error no se el sensor!");
while (1);
}
}
```
### **Estructura del Loop**
En la estructura del Loop se lee la temperatura y se asigna "tem" y también lee la humedad se le asigna "hum".
Posteriormente se imprime el valor de la temperatura y 
con esta función "Serial.print("tt");" se imprimen dos pestañas para acomodar los valores de temperatura y humedad. Por último se imprime el valor de humedad y finaliza el loop.

1. Se lee la temperatura y se asigna **"temp"** y también lee la humedad a la que se le asigna **"hum"**.
2. Se imprime el valor de la temperatura y con "Serial.print("tt")" se imprimen dos pestañas para acomodar los valores de temperatura y humedad.
3. Se imprime el valor de la humedad y finaliza el loop.

```cpp
void loop() {
float temp = myAHT10.readTemperature(); //Se lee la temperatura y se asigna "tem"
float hum = myAHT10.readHumidity(); //Se lee humedad y se asigna "hum" 
Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C"); // el valor de tempertura 
Serial.print("tt"); // Imprime dos pestañas para acomodar los valores de temperatura y humedad
Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %"); // el valor de humedad
delay(1000);
}
```

## **Código completo**
```cpp
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
```