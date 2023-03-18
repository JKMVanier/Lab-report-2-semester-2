//Goal: Displaying state of pb with serial monitor
//theme input pullup to serial print
class PushButton {
  
  private:
    int buttonPin; // Pin number for the button

  public:
    PushButton(int pin) { // Constructor
      buttonPin = pin; // Store the pin number
    }

    void init() {
      pinMode(buttonPin, INPUT_PULLUP); // Set the pin as an input with pullup
      Serial.begin(9600); // Initialize the serial 
    }

    void checkState() {
      int buttonState = digitalRead(buttonPin); // read the state of the button

      if (buttonState == LOW) { // Check if button is pressed 
        Serial.println("Button is pressed"); //prints message
      }
    }
};

PushButton button(2); 
void setup() {
  button.init(); 
}

void loop() {
  button.checkState(); 
}
