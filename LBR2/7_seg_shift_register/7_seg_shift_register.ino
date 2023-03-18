//Goal: Display a number on a 4 digit 7 seg display connected to a shift register
//Theme: functions and shiftout

int i;
int latch = 12; //latch
int cs = 11; //clock
int data = 10; //sends information
int dPins[4] = {8, 7, 6, 5};// on 4 digit - 4321
const byte digits[10] = { // pin combinations do display a number
B00111111,//0
B00000110,//1
B01011011,//2
B01001111,//3
B01100110,//4
B01101101,//5
B01111101,//6
B0000111,//7
B01111111,//8
B01101111,//9
};

void setup() {
  
  pinMode(latch, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(data, OUTPUT);

 for (int i = 5; i < 9; i++){
 pinMode(i, OUTPUT);

}
}




//lines are as such 4321
                 // abcd
void dis1(int x){ // each function calls on a digit on the 7 seg 

 digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);

  digitalWrite(latch,LOW);
shiftOut(data, cs, MSBFIRST, digits[x]);
 digitalWrite(latch,HIGH);
}

void dis2(int x){

 digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);

  digitalWrite(latch,LOW);
shiftOut(data, cs, MSBFIRST, digits[x]);
 digitalWrite(latch,HIGH);
}

void dis3(int x){

 digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);

  digitalWrite(latch,LOW);
shiftOut(data, cs, MSBFIRST, digits[x]);
 digitalWrite(latch,HIGH);
}

void dis4(int x){

 digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);

  digitalWrite(latch,LOW);
shiftOut(data, cs, MSBFIRST, digits[x]);
 digitalWrite(latch,HIGH);
}

void display(int a, int b, int c, int d){ // displays the numbers as typed

dis4(a);
dis3(b);
dis2(c);  
dis1(d); 

}
void loop() {

display(5,7,2,1); // displayed to 7 seg

}



  
  
 



/*
 delay(1000);

 digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);

  digitalWrite(latch,LOW);
shiftOut(data, cs, MSBFIRST, digits[2]);
 digitalWrite(latch,HIGH);

 delay(1000);
    */
