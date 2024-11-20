#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#define WIFI_SSID "URSINHO 2.4G"
#define WIFI_PASSWORD "soumuitofeliz"
#define FIREBASE_HOST "https://arduino-98100-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH  "1JROD3Y8FhKGDd7l3hr3PdSebK0TCae0m36PSrs4"

// Biblioteca ArduinoJson (Benoit Blanchon) precisa estar na versão 5.13.5 pra baixo

const int pinoControle = 2;
bool verificacao = false;

void setup() {

  pinMode(pinoControle, OUTPUT);
  Serial.begin(9600);
  int d = 0;

  // Conexão com o Wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Conectando ao Wifi");

  // Loop para checar se conectou ao wifi
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(". ");
    delay(1000);
    d++;
    if (d == 15)
    {
      break;
    }
  }

  // Conexão com Banco de Dados
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Conectado ao Firebase");
}

void loop() {
  bool verificacao = Firebase.getBool("/Culto");


    // Se a veriricação estiver false, desliga lâmpada;
    if (verificacao == 0)
    {
      digitalWrite(pinoControle, LOW);
    } else // Se estiver true, liga durante 2 minutos depois apaga
    {
      for(int j = 0; j < 1; j++){
        for(int i = 0; i < 10;i++)
        {
          digitalWrite(pinoControle, HIGH);
          delay(1000);
        }
      digitalWrite(pinoControle, LOW);
      delay(2000);
      Firebase.setBool("/Culto", false);
    }
    }
}

// Código para mostrar as redes Wifi Disponíveis
// #include <WiFi.h>

// void setup() {
//   Serial.begin(9600);
//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect(); // Desconecta de qualquer rede previamente conectada
//   delay(1000);

//   Serial.println("Escaneando redes WiFi...");
//   int n = WiFi.scanNetworks();
//   Serial.println("Redes encontradas:");
//   for (int i = 0; i < n; ++i) {
//     // Mostra o SSID de cada rede
//     Serial.print(i + 1);
//     Serial.print(": ");
//     Serial.print(WiFi.SSID(i));
//     Serial.print(" (");
//     Serial.print(WiFi.RSSI(i)); // Mostra a intensidade do sinal
//     Serial.println(" dBm)");
//   }
// }

// void loop() {
//   // Nada aqui
// }

