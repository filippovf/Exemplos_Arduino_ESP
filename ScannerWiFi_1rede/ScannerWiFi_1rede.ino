// Elaborado por Prof. Filippo Valiante Filho
// Fontes:
//     Material Prof. Rodrigo Assirati
//     Github da Espressif: https://github.com/espressif/arduino-esp32/blob/master/libraries/WiFi/examples/

#include "WiFi.h"

//nome da rede a ser buscada:
String redeSSID = "DFMV2";
int intensidadeSinal = -9999;
int i = 0;
bool redeEncontrada = false;

void setup()
{
    // Instrução para inicializar o Serial para o log no monitor.
    Serial.begin(115200);

    // configurando o modo de operação do WiFi como estação
    WiFi.mode(WIFI_STA);

    // desconecta do access point caso ele já esteja conectado
    WiFi.disconnect();
}

void loop()
{
    //realiza o escaneamento das redes disponíveis
    int n = WiFi.scanNetworks();
    Serial.println("Escaneamento realizado");

    //verifica se encontrou alguma rede
    if (n == 0) {
        Serial.println("Nenhuma rede encontrada");
    }
    else
    {
        for (i = 0; i < n; i++)
        {            
            if (WiFi.SSID(i) == redeSSID) 
            {
                Serial.print("SSID: ");
                Serial.print(WiFi.SSID(i)); //nome da rede
                Serial.print("\t\tSINAL: ");
                Serial.print(WiFi.RSSI(i)); //intensidade do sinal
                Serial.print("\t\tcanal: ");
                Serial.print((int)WiFi.channel(i));
                Serial.print("\t\tSegurança: ");
                switch (WiFi.encryptionType(i)) 
                {
                    case WIFI_AUTH_OPEN:            Serial.print("open"); break;
                    case WIFI_AUTH_WEP:             Serial.print("WEP"); break;
                    case WIFI_AUTH_WPA_PSK:         Serial.print("WPA"); break;
                    case WIFI_AUTH_WPA2_PSK:        Serial.print("WPA2"); break;
                    case WIFI_AUTH_WPA_WPA2_PSK:    Serial.print("WPA+WPA2"); break;
                    case WIFI_AUTH_WPA2_ENTERPRISE: Serial.print("WPA2-EAP"); break;
                    case WIFI_AUTH_WPA3_PSK:        Serial.print("WPA3"); break;
                    case WIFI_AUTH_WPA2_WPA3_PSK:   Serial.print("WPA2+WPA3"); break;
                    case WIFI_AUTH_WAPI_PSK:        Serial.print("WAPI"); break;
                    default:                        Serial.print("unknown");
                }
                Serial.print("\t\tMAC do AP: ");
                Serial.println(WiFi.BSSIDstr(i));//MAC Address do ponto de acesso
                redeEncontrada = true;
            }
        }
    }
    if (!redeEncontrada)
        {
            Serial.print("A rede ");
            Serial.print(redeSSID);
            Serial.println(" não foi encontrada");
        }

    Serial.println("\n------------------------------------------------------------------------------------------------------------------------------\n");

    // deixa um intervalo para um novo escaneamento
    delay(1000);
}
