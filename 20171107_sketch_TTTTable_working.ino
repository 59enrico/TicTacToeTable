//Connect to NeoPixels

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN A1 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 9 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//storage for LED 1-9 (RGB_x), whether off(0), blue(1) or red(2)

int RGB_1 = 0;
int RGB_2 = 0;
int RGB_3 = 0;
int RGB_4 = 0;
int RGB_5 = 0;
int RGB_6 = 0;
int RGB_7 = 0;
int RGB_8 = 0;
int RGB_9 = 0;

//ir sensors 1-9 (irs_number), and their value saved in dis_number

int irs_1 ; float dis_1 = 1200;
int irs_2 ; float dis_2 = 1200;
int irs_3 ; float dis_3 = 1200;
int irs_4 ; float dis_4 = 1200;
int irs_5 ; float dis_5 = 1200;
int irs_6 ; float dis_6 = 1200;
int irs_7 ; float dis_7 = 1200;
int irs_8 ; float dis_8 = 1200;
int irs_9 ; float dis_9 = 1200;

//variable to check whose turn it is, blue (1) beginns, then red (2)

int turn = 1;

//variable to check who won, no one (0), blue (1). red (2)

int win = 0;

//variable to reset the game after a person won
int reset = 0;


//___________________________________________________________________________


void setup() {

// set LEDs as OUTPUT and Sensors as INPUT

pixels.begin(); //Start NeoPixels

pinMode(irs_1,INPUT);
pinMode(irs_2,INPUT);
pinMode(irs_3,INPUT);
pinMode(irs_4,INPUT);
pinMode(irs_5,INPUT);
pinMode(irs_6,INPUT);
pinMode(irs_7,INPUT);
pinMode(irs_8,INPUT);
pinMode(irs_9,INPUT);

Serial.begin(9600);
}


//___________________________________________________________________________


void loop() {

  //check sensors, to turn light on and switch players turn
  
  if((RGB_1 == 0) && (analogRead(irs_1) < 1000)){RGB_1 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_2 == 0) && (analogRead(irs_2) < 1000)){RGB_2 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_3 == 0) && (analogRead(irs_3) < 1000)){RGB_3 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_4 == 0) && (analogRead(irs_4) < 1000)){RGB_4 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_5 == 0) && (analogRead(irs_5) < 1000)){RGB_5 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_6 == 0) && (analogRead(irs_6) < 1000)){RGB_6 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_7 == 0) && (analogRead(irs_7) < 1000)){RGB_7 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_8 == 0) && (analogRead(irs_8) < 1000)){RGB_8 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_9 == 0) && (analogRead(irs_9) < 1000)){RGB_9 = turn; if(turn == 1){turn=2;} else{turn=1;}}

  //check win for blue
  
  if(RGB_1 == 1 && RGB_2 == 1 && RGB_3 == 1){win = 1;}   //first line
  if(RGB_4 == 1 && RGB_5 == 1 && RGB_6 == 1){win = 1;}   //second line
  if(RGB_7 == 1 && RGB_8 == 1 && RGB_9 == 1){win = 1;}   //third line
  if(RGB_1 == 1 && RGB_4 == 1 && RGB_7 == 1){win = 1;}   //first column
  if(RGB_2 == 1 && RGB_5 == 1 && RGB_8 == 1){win = 1;}   //second column
  if(RGB_3 == 1 && RGB_6 == 1 && RGB_9 == 1){win = 1;}   //third column
  if(RGB_1 == 1 && RGB_5 == 1 && RGB_9 == 1){win = 1;}   //diagonal upper left to lower right
  if(RGB_3 == 1 && RGB_5 == 1 && RGB_7 == 1){win = 1;}   //diagonal upper right to lower left

/*
    if((RGB_1 == 1 && RGB_2 == 1 && RGB_3 == 1) ||             //1.line
       (RGB_4 == 1 && RGB_5 == 1 && RGB_6 == 1) ||             //2.line
       (RGB_7 == 1 && RGB_8 == 1 && RGB_9 == 1) ||             //3.line
       (RGB_1 == 1 && RGB_4 == 1 && RGB_7 == 1) ||             //1.column
       (RGB_2 == 1 && RGB_5 == 1 && RGB_8 == 1) ||             //2.column
       (RGB_3 == 1 && RGB_6 == 1 && RGB_9 == 1) ||             //3.column
       (RGB_1 == 1 && RGB_5 == 1 && RGB_9 == 1) ||             //diagonal upper left to lower right
       (RGB_3 == 1 && RGB_5 == 1 && RGB_7 == 1)){win = 1;}     //diagonal upper right to lower left
*/

  //check win for red
  
  if(RGB_1 == 2 && RGB_2 == 2 && RGB_3 == 2){win = 2;}   //first line
  if(RGB_4 == 2 && RGB_5 == 2 && RGB_6 == 2){win = 2;}   //second line
  if(RGB_7 == 2 && RGB_8 == 2 && RGB_9 == 2){win = 2;}   //third line
  if(RGB_1 == 2 && RGB_4 == 2 && RGB_7 == 2){win = 2;}   //first column
  if(RGB_2 == 2 && RGB_5 == 2 && RGB_8 == 2){win = 2;}   //second column
  if(RGB_3 == 2 && RGB_6 == 2 && RGB_9 == 2){win = 2;}   //third column
  if(RGB_1 == 2 && RGB_5 == 2 && RGB_9 == 2){win = 2;}   //diagonal upper left to lower right
  if(RGB_3 == 2 && RGB_5 == 2 && RGB_7 == 2){win = 2;}   //diagonal upper right to lower left

/*
    if((RGB_1 == 2 && RGB_2 == 2 && RGB_3 == 2) ||             //1.line
       (RGB_4 == 2 && RGB_5 == 2 && RGB_6 == 2) ||             //2.line
       (RGB_7 == 2 && RGB_8 == 2 && RGB_9 == 2) ||             //3.line
       (RGB_1 == 2 && RGB_4 == 2 && RGB_7 == 2) ||             //1.column
       (RGB_2 == 2 && RGB_5 == 2 && RGB_8 == 2) ||             //2.column
       (RGB_3 == 2 && RGB_6 == 2 && RGB_9 == 2) ||             //3.column
       (RGB_1 == 2 && RGB_5 == 2 && RGB_9 == 2) ||             //diagonal upper left to lower right
       (RGB_3 == 2 && RGB_5 == 2 && RGB_7 == 2)){win = 2;}     //diagonal upper right to lower left
*/

  //action for win
  
  if(win == 1){
    pixels.setPixelColor(0, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(1, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(2, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(3, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(4, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(5, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(6, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(7, pixels.Color(0,0,255)); pixels.show();
    pixels.setPixelColor(8, pixels.Color(0,0,255)); pixels.show();

    delay(5000);

    pixels.setPixelColor(0, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(1, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(2, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(3, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(4, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(5, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(6, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(7, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(8, pixels.Color(0,0,0)); pixels.show();


    reset = 1;
  }

  if(win == 2){
    
    pixels.setPixelColor(0, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(1, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(2, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(3, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(4, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(5, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(6, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(7, pixels.Color(255,0,0)); pixels.show();
    pixels.setPixelColor(8, pixels.Color(255,0,0)); pixels.show();

    delay(5000);

    pixels.setPixelColor(0, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(1, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(2, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(3, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(4, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(5, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(6, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(7, pixels.Color(0,0,0)); pixels.show();
    pixels.setPixelColor(8, pixels.Color(0,0,0)); pixels.show();

    reset = 1;
  }

  //declaring a draw

  if((RGB_1 == 1 || RGB_1 == 2) && (RGB_2 == 1 || RGB_2 == 2) && (RGB_3 == 1 || RGB_3 == 2) && (RGB_4 == 1 || RGB_4 == 2) && (RGB_5 == 1 || RGB_5 == 2) && (RGB_6 == 1 || RGB_6 == 2) && (RGB_7 == 1 || RGB_7 == 2) && (RGB_8 == 1 || RGB_8 == 2) && (RGB_9 == 1 || RGB_9 == 2)){

    pixels.setPixelColor(0, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(1, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(2, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(3, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(4, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(5, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(6, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(7, pixels.Color(0,255,0)); pixels.show();
    pixels.setPixelColor(8, pixels.Color(0,255,0)); pixels.show();
    
    }

  //turning on the LEDs
  
  if(RGB_1 == 1){pixels.setPixelColor(0, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_2 == 1){pixels.setPixelColor(1, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_3 == 1){pixels.setPixelColor(2, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_4 == 1){pixels.setPixelColor(3, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_5 == 1){pixels.setPixelColor(4, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_6 == 1){pixels.setPixelColor(5, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_7 == 1){pixels.setPixelColor(6, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_8 == 1){pixels.setPixelColor(7, pixels.Color(0,0,255)); pixels.show();}
  if(RGB_9 == 1){pixels.setPixelColor(8, pixels.Color(0,0,255)); pixels.show();}

  if(RGB_1 == 2){pixels.setPixelColor(0, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_2 == 2){pixels.setPixelColor(1, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_3 == 2){pixels.setPixelColor(2, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_4 == 2){pixels.setPixelColor(3, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_5 == 2){pixels.setPixelColor(4, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_6 == 2){pixels.setPixelColor(5, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_7 == 2){pixels.setPixelColor(6, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_8 == 2){pixels.setPixelColor(7, pixels.Color(255,0,0)); pixels.show();}
  if(RGB_9 == 2){pixels.setPixelColor(8, pixels.Color(255,0,0)); pixels.show();}

  //reset the game
  
  if(reset == 1){
    RGB_1 = 0;
    RGB_2 = 0;
    RGB_3 = 0;
    RGB_4 = 0;
    RGB_5 = 0;
    RGB_6 = 0;
    RGB_7 = 0;
    RGB_8 = 0;
    RGB_9 = 0;

    turn = 1;

    win = 0;

    reset = 0;}
}
