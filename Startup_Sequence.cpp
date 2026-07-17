#include "Startup_Sequence.hpp"

HardwareTimer *TSAL_Timer = new HardwareTimer(TIM2);

volatile bool startState = false;
volatile bool ledState = false;
volatile bool neutral_state = false;
volatile bool accel_state = false;
volatile bool brake_state = false;
volatile unsigned long lastDebounceTime = 0;

void handleButtonPress() {
    unsigned long currentTime = millis();
    if ((currentTime - lastDebounceTime) > DEBOUNCE_DELAY) 
    {
        Serial.println("Button pressed!");

        neutral_state = digitalRead(NEUTRAL_PIN);
        Serial.print("Neutral State: ");
        Serial.println(neutral_state);

        accel_state = digitalRead(ACCEL_PIN);
        Serial.print("Accelerator State: ");
        Serial.println(accel_state);

        brake_state = digitalRead(BRAKE_PIN);
        Serial.print("Brake State: ");
        Serial.println(brake_state);

        if(startState == false)
        {
            if (neutral_state) {
            Serial.println("Neutral");
                if (!accel_state) {
                    Serial.println("Accelerator Not Pressed");
                    if (brake_state) {
                        Serial.println("Brake Pressed");
                        ledState = !ledState;
                        startState = true;
                        digitalWrite(LED_PIN, ledState ? LOW : HIGH); // Toggle LED state
                        Serial.print("LED state changed to: ");
                        Serial.println(ledState ? "ON" : "OFF");
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("Vehicle Started!");
                        digitalWrite(TSAL_PIN,LOW);
                        digitalWrite(RTDS,LOW);
                        delay(990);
                        digitalWrite(RTDS,HIGH);
                    }
                    else {
                        Serial.println("Brake Not Pressed");
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("BRK not pressed!");
                    }
                }
                else {
                    Serial.println("Accelerator Pressed");
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print("ACCEL pressed!");
                }
            }
            else{
            Serial.println("Not in neutral state");
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Not in Neutral!");
            }
        }
        else{
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Vehicle already");
        lcd.setCursor(8, 1);
        lcd.print("started!");
        }
        lastDebounceTime = currentTime;
    }   
}

void blink_TSAL(void)
{
    if(startState == true)
    {
        digitalWrite(TSAL_INDICATOR_PIN,!digitalRead(TSAL_INDICATOR_PIN));
    }
}

void setup_Startup() {
    pinMode(NEUTRAL_PIN, INPUT_PULLDOWN);
    pinMode(ACCEL_PIN, INPUT_PULLDOWN);
    pinMode(BRAKE_PIN, INPUT_PULLDOWN);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    pinMode(TSAL_INDICATOR_PIN, OUTPUT);
    pinMode(TSAL_PIN, OUTPUT);
    pinMode(RTDS, OUTPUT);
    digitalWrite(RTDS,HIGH);
    digitalWrite(TSAL_PIN,HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(TSAL_INDICATOR_PIN, LOW);

    startState = false;

    // Enable SYSCFG clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // Attach interrupt to the button pin, triggered on falling edge
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);

    //Serial.println("Setup complete. Waiting for button press...");

    TSAL_Timer->setOverflow(500000, MICROSEC_FORMAT);  // Set frequency to 0.5 kHz
    TSAL_Timer->attachInterrupt(blink_TSAL); // Attach the ISR
    TSAL_Timer->resume(); // Start the timer
}
