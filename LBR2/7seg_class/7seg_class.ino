//Goal: counting on 7 seg with class
// theme: class and functions
class SevenSegmentCounter {

  private:
      int ledPins[8];
    int digits[10][8] = {
      {1, 1, 1, 0, 0, 1, 1, 1}, // 0
      {0, 0, 1, 0, 0, 0, 0, 1}, // 1
      {1, 1, 0, 0, 1, 0, 1, 1}, // 2
      {0, 1, 1, 0, 1, 0, 1, 1}, // 3
      {0, 0, 1, 0, 1, 1, 0, 1}, // 4
      {0, 1, 1, 0, 1, 1, 1, 0}, // 5
      {1, 1, 1, 0, 1, 1, 1, 0}, // 6
      {0, 0, 1, 0, 0, 0, 1, 1}, // 7
      {1, 1, 1, 0, 1, 1, 1, 1}, // 8
      {0, 0, 1, 0, 1, 1, 1, 1}  // 9
    };

  public:
    SevenSegmentCounter(int pins[]) { // constructor
      for (int i = 0; i < 8; i++) {
        ledPins[i] = pins[i];
      }
    }

    void init() {
      for (int i = 0; i < 8; i++) {
        pinMode(ledPins[i], OUTPUT);
      }
    }

    void displayDigit(int digit) {
      
      int* digitArray = digits[digit]; // get the segment pattern for the digit
      for (int i = 0; i < 8; i++) {
        digitalWrite(ledPins[i], digitArray[i]); //sets each LED to the corresponding segment pattern
      }
    }

    void countToNine() { // basically like previous functions used, counts from 0-9, i is actually number on 7 seg
      for (int i = 0; i <= 9; i++) {
       displayDigit(i);
      delay(1000);
      }
    }
};



int pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 7 seg pins

SevenSegmentCounter counter(pins);

void setup() {
  counter.init(); // enables pins as outputs
}

void loop() {
  counter.countToNine(); //counts 
}
