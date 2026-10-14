#include <Bluepad32.h>

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

void onConnectedController(ControllerPtr ctl) {
    Serial.println("Conectado exitosamente al mando PS4!");
    myControllers[ctl->index()] = ctl;
}

void onDisconnectedController(ControllerPtr ctl) {
    Serial.println("Mando desconectado");
    myControllers[ctl->index()] = nullptr;
}

void processGamepad(ControllerPtr ctl) {
    // Joystick izquierdo: movimiento
    int lx = ctl->axisX();  // -511 (izquierda) a +512 (derecha)
    if (lx < -200) {
        Serial2.println("L");
        Serial.println("Joystick → Izquierda");
        delay(100);
    }
    if (lx > 200) {
        Serial2.println("R");
        Serial.println("Joystick → Derecha");
        delay(100);
    }

    // Botón X (Cross) → salto
    if (ctl->a()) {
        Serial2.println("A");
        Serial.println("PS4 → Salto (Botón X)");
        delay(100);
    }

// Botón Cuadrado para ataque
    if (ctl->x()) {
    Serial2.println("X");
    Serial.println("PS4 → Ataque (Cuadrado)");
    delay(100);
    }
}

void processControllers() {
    for (auto ctl : myControllers) {
        if (ctl && ctl->isConnected() && ctl->hasData()) {
            if (ctl->isGamepad()) {
                processGamepad(ctl);
            }
        }
    }
}

void setup() {
    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, 16, 17); // UART2 hacia STM32

    Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
    const uint8_t* addr = BP32.localBdAddress();
    Serial.printf("ESP32 BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n",
                  addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    BP32.setup(&onConnectedController, &onDisconnectedController);
    BP32.forgetBluetoothKeys(); // Limpia claves previas para evitar conflictos
}

void loop() {
    bool dataUpdated = BP32.update();
    if (dataUpdated) {
        processControllers();
    }
    delay(150);
}
