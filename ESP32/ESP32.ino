/*************************************************************************************************
  ESP32 Web Server
  Ejemplo de creación de Web server 
  Basándose en los ejemplos de: 
  https://lastminuteengineers.com/creating-esp32-web-server-arduino-ide/
  https://electropeak.com/learn
**************************************************************************************************/
//************************************************************************************************
// Librerías
//************************************************************************************************
#include <WiFi.h>
#include <SPIFFS.h>
#include <WebServer.h>
//************************************************************************************************
// Variables globales
//************************************************************************************************
// SSID & Password
const char* ssid = "YHLQMDLG";  // Enter your SSID here
const char* password = "12345678";  //Enter your Password here

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

//************************************************************************************************
//Variables
//************************************************************************************************
uint8_t bandera = 0;
uint8_t bandera2 = 0;
uint8_t parqueo_1 = 0;
uint8_t parqueo_2 = 0;
uint8_t parqueo_3 = 0;
uint8_t parqueo_4 = 0;
uint8_t parqueo_5 = 0;
uint8_t parqueo_6 = 0;
uint8_t parqueo_7 = 0;
uint8_t parqueo_8 = 0;
uint8_t parq_disp = 0;
int status1, status2, status3;
int go;

//************************************************************************************************
// Configuración
//************************************************************************************************
void setup() {
  #define RXD2 16 
  #define TXD2 17
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  if (!SPIFFS.begin()) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("password: ");
  Serial.println(password);

  //server.on("/", handle_OnConnected); // página de inicio
  server.on("/s1", handle_s1); // handler al haber uno ocupado
  server.on("/s2", handle_s2); //
  server.on("/s3", handle_s3); //
  server.on("/s4", handle_s4); //
  server.on("/s5", handle_s5); //
  server.on("/s6", handle_s6); //
  server.on("/s7", handle_s7); //
  server.on("/s8", handle_s8); //
  server.onNotFound([]() {                  // si el cliente solicita una uri desconocida
    //if (!HandleFileRead(server.uri()))      // enviar archivo desde SPIFF, si existe
      //handleNotFound();             // sino responder con un error 404 (no existe)
  });
  //server.onNotFound(handle_NotFound); //si no se encuentra el uri, responder con error 404 (no existe)

  server.begin(); // iniciar servidor
  Serial.println("HTTP server started");
  delay(100);
}
//************************************************************************************************
// loop principal
//************************************************************************************************
void loop() {
  server.handleClient(); //looks for clients request.
  while(Serial.available()) {
    if (Serial2.available()) {
    
  
    status2 = Serial2.read();
    //status3 = 0;
    if(status2 == '0'){
      Serial.print("0");
      go = 0;
      server.send(200, "text/html", SendHTML(go));
    }
    if(status2 == '1'){
      Serial.print("1");
      go = 1;
      server.send(200, "text/html", SendHTML(go));
    }
    if(status2 == '2'){
      Serial.print("2");
      go = 2;
      server.send(200, "text/html", SendHTML(go));
    }
    if(status2 == '3'){
      Serial.print("3");
      go = 3;
      server.send(200, "text/html", SendHTML(go));
    }
    if(status2 == '4'){
      Serial.print("4");
      go = 4;
      server.send(200, "text/html", SendHTML(go));
    }
    bandera =Serial.read();
    bandera2 = Serial2.read();
    Serial.println(bandera);
    Serial.println(bandera2);
    //here we ceck the data that we recibe from the tivas
    if (bandera & 0x01){
      parqueo_1 = 1;
    }
    else {
      parqueo_1 = 0;
    }
    if (bandera & 0x02){
      parqueo_2 = 1;
    }
    else {
      parqueo_2 = 0;
    }
    if (bandera & 0x04){
      parqueo_3 = 1;
    }
    else {
      parqueo_3 = 0;
    }
    if (bandera & 0x08){
      parqueo_4 = 1;
    }
    else {
      parqueo_4 = 0;
    }
        if (bandera2 & 0x01){
      parqueo_5 = 1;
    }
    else {
      parqueo_5 = 0;
    }
    if (bandera2 & 0x02){
      parqueo_6 = 1;
    }
    else {
      parqueo_6 = 0;
    }
    if (bandera2 & 0x04){
      parqueo_7 = 1;
    }
    else {
      parqueo_7 = 0;
    }
    if (bandera2 & 0x08){
      parqueo_8 = 1;
    }
    else {
      parqueo_8 = 0;
    }
    Serial.println(parqueo_1);
  }
}
}
//************************************************************************************************
// Handler de Inicio página
//************************************************************************************************
void handle_OnConnect() {
  Serial.println("GPIO2 Status: OFF");
  parq_disp = -(parqueo_1 + parqueo_2 + parqueo_3 + parqueo_4 + parqueo_5 + parqueo_6 + parqueo_7 + parqueo_8) + 8 ;
  server.send(200, "text/html", SendHTML2(parqueo_1, parqueo_2, parqueo_3, parqueo_4, parqueo_5, parqueo_6, parqueo_7, parqueo_8, parq_disp));
  digitalWrite(33, HIGH); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(25, HIGH); //
  digitalWrite(26, HIGH); //
  status1 = 0; // inicia todo libre, por defecto
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}

//************************************************************************************************
// Procesador de HTML
//************************************************************************************************
//Pagina web y funcionamiento del parqueo disponible y ocupado 
String SendHTML2(uint8_t parq_1, uint8_t parq_2, uint8_t parq_3, uint8_t parq_4, uint8_t parqueo_5, uint8_t parqueo_6, uint8_t parqueo_7, uint8_t  parqueo_8, uint8_t parq_disp) {
  String pagina = "<html>\n";
pagina +="<!doctype html>\n";
pagina +="<html lang=\"en\">\n";
pagina +="  <head>\n";
pagina +="    <meta charset=\"utf-8\">\n"; //with this function we refresh the 
pagina +="    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
pagina +="    <!--\n";
pagina +="    function timedRefresh(timeoutPeriod) {\n";
pagina +="    \tsetTimeout(\"location.reload(true);\",timeoutPeriod);\n";
pagina +="    }\n";
pagina +="    \n";
pagina +="    window.onload = timedRefresh(1000);\n";
pagina +="    \n";
pagina +="    //   -->\n";
pagina +="    <link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-+0n0xVW2eSR5OomGNYDnhzAbDsOXxcvSN1TPprVMTNDbiYZCxYbOOl7+AMvyTG2x\" crossorigin=\"anonymous\">\n";
pagina +="    <title>Parqueos</title>\n";
pagina +="  </head>\n";
pagina +="  <body>\n";
pagina +="    <h1>YHLQMDLG parKing</h1>    \n";
pagina +="    <table class=\"table table-hover\">\n";
pagina +="  <thead class=\"table table-hover\">\"\n";
pagina +="    <tr class=\"table-active\">\n";
pagina +="      <th scope=\"col\">Parqueo #</th>\n";
pagina +="      <th scope=\"col\">Estado</th>\n";
pagina +="    </tr>\n";
pagina +="  </thead>\n";
pagina +="  <tbody>\n";
pagina +="    <tr>\n";

if (parqueo_1 == 1){
  pagina +="    <th scope=\"row\">Espacio #1</th>\n";
  pagina +="    <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="    <th scope=\"row\">Espacio #1</th>\n";
  pagina +="    <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_2 == 1){
  pagina +="    <th scope=\"row\">Espacio #2</th>\n";
  pagina +="    <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="    <th scope=\"row\">Espacio #2</th>\n";
  pagina +="    <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_3 == 1){
  pagina +="      <th scope=\"row\">Espacio #3</th>\n";
  pagina +="      <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="      <th scope=\"row\">Espacio #3</th>\n";
  pagina +="      <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_4 == 1){
  pagina +="      <th scope=\"row\">Espacio #4</th>\n";
  pagina +="      <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="      <th scope=\"row\">Espacio #4</th>\n";
  pagina +="      <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_5 == 1){
  pagina +="    <th scope=\"row\">Espacio #5</th>\n";
  pagina +="    <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="    <th scope=\"row\">Espacio #5</th>\n";
  pagina +="    <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_6 == 1){
  pagina +="    <th scope=\"row\">Espacio #6</th>\n";
  pagina +="    <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="    <th scope=\"row\">Espacio #6</th>\n";
  pagina +="    <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_7 == 1){
  pagina +="      <th scope=\"row\">Espacio #7</th>\n";
  pagina +="      <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="      <th scope=\"row\">Espacio #7</th>\n";
  pagina +="      <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
if (parqueo_8 == 1){
  pagina +="      <th scope=\"row\">Espacio #8</th>\n";
  pagina +="      <td class=\"table table-hover\">Ocupado</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}
else {
  pagina +="      <th scope=\"row\">Espacio #8</th>\n";
  pagina +="      <td class=\"table table-hover\">Disponible</td>\n";
  pagina +="    </tr>\n";
  pagina +="    <tr>\n";
}

pagina +="  </tbody>\n";
pagina +="  </tfoot>\n";
pagina +="  \t<tr>\n";
pagina += "<th class=table-active scope=row>Parqueos Disponible</th>\n";
pagina += "<td class=table-info>";
pagina += (int) parq_disp; //Variable de la operacion para mostrar el resultado. 
pagina += "</td>\n";
pagina +="    </tr>\n";
pagina +="  </tfoot>\n";
pagina +="</table>\n";
pagina +="<script>\n";
pagina +="function timedRefresh(timeoutPeriod) {\n";
pagina +="\tsetTimeout(\"location.reload(true);\",timeoutPeriod);}\n";
pagina +="window.onload = timedRefresh(1000);\n";
pagina +="</script>\n";
pagina +="    <script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-gtEjrD/SeCtmISkJkNUaaKMoLD0//ElJ19smozuHV6z3Iehds+3Ulb9Bn9Plx0x4\" crossorigin=\"anonymous\"></script>\n";
pagina +="    <script src=\"https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js\" integrity=\"sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p\" crossorigin=\"anonymous\"></script>\n";
pagina +="    <script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.min.js\" integrity=\"sha384-Atwg2Pkwv9vp0ygtn1JAojH0nYbwNJLPhwyoVbhoPwBhjQPR5VtM2+xf0Uwh9KtT\" crossorigin=\"anonymous\"></script>\n";
pagina +="  </body>\n";
pagina +="</html>";
return pagina;
}


String SendHTML(uint8_t led1stat) {  
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server &#128664</h1>\n";
  ptr += "<h3>Ejemplo de Web Server</h3>\n";

  if (led1stat)
  {
    ptr += "<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  }
  else
  {
    ptr += "<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
//************************************************************************************************
// Handler de not found
//************************************************************************************************
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
//************************************************************************************************
// 7 segment modes
//************************************************************************************************
//void handle_OnConnected() {
//  //8
//  digitalWrite(33, HIGH); //
//  digitalWrite(32, HIGH); //
//  digitalWrite(27, HIGH); //
//  digitalWrite(14, HIGH); //
//  digitalWrite(12, HIGH); //
//  digitalWrite(25, HIGH); //
//  digitalWrite(26, HIGH); //
//  status1 = 0; // inicia todo libre, por defecto
//  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
//}
//************************************************************************************************
// Handler de 1 ocupado
//************************************************************************************************
void handle_s1() {
  //7
  digitalWrite(33, HIGH); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, LOW); //
  digitalWrite(12, LOW); //
  digitalWrite(25, LOW); //
  digitalWrite(26, LOW); //
  status1 = 1;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML

}
//************************************************************************************************
// Handler de 2 ocupados
//************************************************************************************************
void handle_s2() {
  //6
  digitalWrite(33, LOW); //
  digitalWrite(32, LOW); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(25, HIGH); //
  digitalWrite(26, HIGH); //
  status1 = 2;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}

//************************************************************************************************
// Handler de 3 ocupado
//************************************************************************************************
void handle_s3() {
  //5
  digitalWrite(33, HIGH); //
  digitalWrite(32, LOW); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, LOW); //
  digitalWrite(25, HIGH); //
  digitalWrite(26, HIGH); //
  status1 = 3;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}
//************************************************************************************************
// Handler de 4 ocupados
//************************************************************************************************
void handle_s4() {
  //4
  digitalWrite(33, LOW); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, LOW); //
  digitalWrite(12, LOW); //
  digitalWrite(25, HIGH); //
  digitalWrite(26, HIGH); //
  status1 = 4;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}

//************************************************************************************************
// Handler de 5 ocupado
//************************************************************************************************
void handle_s5() {
  //3
  digitalWrite(33, HIGH); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, LOW); //
  digitalWrite(25, LOW); //
  digitalWrite(26, HIGH); //
  status1 = 5;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}
//************************************************************************************************
// Handler de 6 ocupados
//************************************************************************************************
void handle_s6() {
  //2
  digitalWrite(33, HIGH); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, LOW); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(25, LOW); //
  digitalWrite(26, HIGH); //
  status1 = 6;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}

//************************************************************************************************
// Handler de 7 ocupado
//************************************************************************************************
void handle_s7() {
  //1
  digitalWrite(33, LOW); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, LOW); //
  digitalWrite(12, LOW); //
  digitalWrite(25, LOW); //
  digitalWrite(26, LOW); //
  status1 = 7;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}
//************************************************************************************************
// Handler de 8 ocupados
//************************************************************************************************
void handle_s8() {
  //0
  digitalWrite(33, HIGH); //
  digitalWrite(32, HIGH); //
  digitalWrite(27, HIGH); //
  digitalWrite(14, HIGH); //
  digitalWrite(12, HIGH); //
  digitalWrite(25, HIGH); //
  digitalWrite(26, LOW); //
  status1 = 8;
  server.send(200, "text/html", SendHTML(status1)); //responde con un OK (200) y envía HTML
}
