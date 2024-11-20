# Projeto De Extensão IoT
Este repositório tem como finalidade armazenar o projeto IoT para que possa ser analizado pelo docente (Wilton) da disciplina (Aplic. de Cloud, IoT e Indústri 4.0 em Python).


Bibliotecas usadas foram: IOXhop_FirebaseESP32 [Versão 5.13.5] (https://github.com/ArtronShop/IOXhop_FirebaseESP32), WiFi (do próprio arduino).

#define WIFI_SSID "Nome_Da_Sua_Rede"  (Aqui você coloca o nome da sua rede, caso não saiba, descomente o código comentado e de run, para achar a sua);

#define WIFI_PASSWORD "soumuitofeliz" (Aqui você vai colocar a senha de sua rede);

#define FIREBASE_HOST "https://arduino-98100-default-rtdb.firebaseio.com/" (Aqui você vai colocar o link do seu Database disponibilizado no Firebase);

#define FIREBASE_AUTH  "1JROD3Y8FhKGDd7l3hr3PdSebK0TCae0m36PSrs4" (Aqui você pega a senha, que está nas configurações do Database);


Foram usados a placa ESP32, para poder realizar a comunicação com o Firebase. Para poder acender a lâmpada, foi utilizado um relé (https://www.eletrogate.com/modulo-rele-1-canal-5v), onde recebia 3 pinagens DC, uma negativa, outra de alimentação 5V e outra de sinal (conectada no pino de saída).

## CUIDADO AO UTILIZAR O RELÉ, CASO NÃO TENHA CONHECIMENTO EVITE, POIS PODE GERAR UM ACIDENTE MORTAL DEVIVO AO ENVOLVIMENTO COM CORRENTE ELÉTRICA QUE ALIMENTA A LÂMPADA!!


Vídeo usado como referência para entender o funcionamento do relé: https://www.youtube.com/watch?v=0JLc3o6sTMY;

Vídeo usado como referência para entender o funcionamento da conexão do Arduino com o Firebase: https://www.youtube.com/watch?v=_ADdFH2K7SI&t=142s;


## #WIP
