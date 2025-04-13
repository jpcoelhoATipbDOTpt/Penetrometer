#include "HX711.h"
#include <list>
HX711 myScale;

//  adjust pins if needed.
uint8_t dataPin = 26;
uint8_t clockPin = 27;



std::list<long> lista_cdc_b; // create a list for the raw values from load cell
std::list<long> lista_cdc_m; // create a list for the average of 10 values from each second 

long rawValue = 0; // variable for the raw value
long media = 0; // variable for the average of 10 values
long somadosdez = 0; // variable for the sum of 10 values

void setup(){

  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("HX711_LIB_VERSION: ");
  Serial.println(HX711_LIB_VERSION);
  Serial.println();

  myScale.begin(dataPin, clockPin);
}

void loop()
{

  if (Serial.available() > 0) {
    char inByte = Serial.read();
    // Click "Enter" button to read value
    if (inByte == '\n') {
      
      lista_cdc_b.clear();
      lista_cdc_m.clear();
      for (int i = 0 ; i <60; i++){ // Read 10 values in 1 second and returns the average value SIXTY TIMES

        for (int j = 0; j < 10; j++) {// Read 10 values in 1 second and returns the average value
          rawValue = myScale.read();
          somadosdez += rawValue;
          lista_cdc_b.push_back(rawValue);
//          Serial.print("Valor bruto: ");
//          Serial.println(rawValue);  
          delay(100); // 100ms x 10 readings = 1s
          
        }
        long media = somadosdez / 10;
        somadosdez = 0; // Reset the value to perform the average of the data from the next second

        lista_cdc_m.push_back(media);
//        Serial.print("Valor Médio: ");
//        Serial.println(media);
      }

      Serial.println("\nValores Brutos Armazenados:");
      for (long i_value : lista_cdc_b) {
        Serial.print(i_value);
        Serial.print(", ");
      }

      Serial.println("\n\nValores Médios Armazenados:");
      for (long j_value : lista_cdc_m) {
        Serial.print(j_value);
        Serial.print(", ");
      }

      }
    }
  }
}