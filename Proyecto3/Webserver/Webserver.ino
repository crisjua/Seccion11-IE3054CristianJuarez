#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>

uint8_t datos_rx[9];
const char* ssid = "cristian";
const char* password = "CRISTIAN";

WebServer server(80);

// 1 = Libre
// 0 = Ocupado
bool parqueo[8] = {1,1,1,1,1,1,1,1};
void receiveEvent(int howMany)
{
  int i = 0;

  while(Wire.available() && i < 9)
  {
    datos_rx[i] = Wire.read();
    i++;
  }

  Serial.print("Recibidos: ");

  for(int j = 0; j < 9; j++)
  {
    Serial.print(datos_rx[j]);
    Serial.print(" ");
  }

  Serial.println();

  for(int j = 0; j < 8; j++)
  {
    parqueo[j] = datos_rx[j];
  }
}
String generarPagina()
{
  int disponibles = 0;

  for(int i = 0; i < 8; i++)
  {
    if(parqueo[i]) disponibles++;
  }

  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="refresh" content="1">
<title>Parqueo-Cristian</title>

<style>

body{
    font-family:Arial, sans-serif;
    background:#e5e5e5;
    text-align:center;
    margin:0;
    padding:20px;
}

h1{
    color:#0d3b66;
    font-size:50px;
}

.contador{
    font-size:40px;
    font-weight:bold;
    color:#0d3b66;
    margin-bottom:25px;
}

.parqueo{
    width:900px;
    margin:auto;
    background:white;
    border-radius:20px;
    padding:25px;
    box-shadow:0px 0px 15px rgba(0,0,0,0.2);
}

.fila{
    display:flex;
    justify-content:center;
    gap:25px;
    margin:20px 0;
}

.espacio{
    width:130px;
    height:100px;
    border:4px solid black;
    border-radius:10px;
    display:flex;
    flex-direction:column;
    justify-content:center;
    align-items:center;
    color:white;
    font-weight:bold;
    font-size:22px;
}

.libre{
    background:#00c853;
}

.ocupado{
    background:#e53935;
}

.jardin{
    height:90px;
    background:#2e7d32;
    color:white;
    font-size:30px;
    font-weight:bold;
    display:flex;
    justify-content:center;
    align-items:center;
    border-radius:10px;
    border:4px solid #1b5e20;
    margin:25px 0;
}

</style>

</head>
<body>

<h1>🚗 Parqueo Cristian</h1>

<div class="contador">
Espacios Disponibles:
)rawliteral";

  html += disponibles;

  html += R"rawliteral(
</div>

<div class="parqueo">

<div class="fila">
)rawliteral";

  for(int i=0;i<4;i++)
  {
    html += "<div class='espacio ";
    html += parqueo[i] ? "libre" : "ocupado";
    html += "'>";

    if(parqueo[i])
    {
      html += "P";
      html += String(i+1);
      html += "<br>LIBRE";
    }
    else
    {
      html += "🚗<br>P";
      html += String(i+1);
    }

    html += "</div>";
  }

  html += R"rawliteral(
</div>

<div class="jardin">
 ÁREA CENTRAL 
</div>

<div class="fila">
)rawliteral";

  for(int i=4;i<8;i++)
  {
    html += "<div class='espacio ";
    html += parqueo[i] ? "libre" : "ocupado";
    html += "'>";

    if(parqueo[i])
    {
      html += "P";
      html += String(i+1);
      html += "<br>LIBRE";
    }
    else
    {
      html += "🚗<br>P";
      html += String(i+1);
    }

    html += "</div>";
  }

  html += R"rawliteral(
</div>

</div>

</body>
</html>
)rawliteral";

  return html;
}

void handleRoot()
{
  server.send(200, "text/html", generarPagina());
}

void setup()
{
  
  Wire.begin(21,22);
  Wire.requestFrom(0x20,9)
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);

  IPAddress local_IP(172,20,10,2);
  IPAddress gateway(172,20,10,1);
  IPAddress subnet(255,255,255,0);

  WiFi.config(local_IP, gateway, subnet);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
}

void loop()
{
  server.handleClient();

  // PRUEBA
  // Cambia estos estados para probar colores

  /*
  parqueo[0] = 1;
  parqueo[1] = 0;
  parqueo[2] = 1;
  parqueo[3] = 1;
  parqueo[4] = 0;
  parqueo[5] = 1;
  parqueo[6] = 1;
  parqueo[7] = 0;
  */
  static unsigned long tiempo = 0;

if(millis() - tiempo > 2000)
{
    tiempo = millis();

    Serial.print("P1=");
    Serial.print(parqueo[0]);
    Serial.print(" P2=");
    Serial.print(parqueo[1]);
    Serial.print(" P3=");
    Serial.print(parqueo[2]);
    Serial.print(" P4=");
    Serial.println(parqueo[3]);
}
}