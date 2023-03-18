//Goal:Driving motors on the smart car
//Theme:class and function

#define Aa 7 //motor pins
#define Ab 5
#define Ba 8
#define Bb 6

class Motor { // to move motors
  public:
    void forward() { // like presets, is called on
      move(1, 100, 1, 100);
    }

    void backward() {
      move(0, 100, 0, 100);
    }

    void left() {
      move(0, 100, 1, 100);
    }

    void right() {
      move(1, 100, 0, 100);
    }

    void init(){
      for (int i = 6; i < 9; i++){//assigns pins as outputs
      pinMode(i, OUTPUT);
        
      }
    }

  private:
  
    void move(bool a, int b, bool c, int d) {//function to actually move the car
      digitalWrite(Aa, a);
      digitalWrite(Ba, c);

      analogWrite(Ab, b);
      analogWrite(Bb, d);
    }
};



Motor move;

void setup() {

move.init();
   
}

void loop() {
 
  move.forward();//moves the car forward
}
