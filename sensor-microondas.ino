int ledPin = 5;               // Pin donde está conectado el LED
int inputPin = 9;             // Pin donde está conectado el sensor de radar
int motion = 0;               // Estado de movimiento
unsigned long tiempoSinMovimiento = 0;  // Variable para rastrear el tiempo sin movimiento
bool flag_Mov = false;        // Bandera de movimiento

void setup() {
  pinMode(ledPin, OUTPUT);    // Declarar el pin LED como salida
  pinMode(inputPin, INPUT);   // Declarar el pin del sensor como entrada
  Serial.begin(9600);
}

void loop() {
  motion = digitalRead(inputPin);  // Leer el pin de entrada

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);    // Encender el LED
    flag_Mov = true;
    Serial.println("¡Movimiento detectado!");
    tiempoSinMovimiento = millis(); // Restablecer el temporizador si hay movimiento
    delay(4000);
  } else if (flag_Mov && millis() - tiempoSinMovimiento > 600000) { // 600000 ms = 10 minutos
    digitalWrite(ledPin, LOW);     // Apagar el LED después de 10 minutos sin movimiento
    Serial.println("No se detectó movimiento durante 10 minutos.");
    Serial.println(tiempoSinMovimiento);
    flag_Mov = false;
    tiempoSinMovimiento = 0;  // Reiniciar el tiempo de inactividad
    delay(4000);
  }

  delay(1000);
}
