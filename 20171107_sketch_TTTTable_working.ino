//Connect to LED 1-9 (RGB_number_color) and their color (R)ED,(G)REEN,(B)LUE

int RGB_1_r = ;
int RGB_2_r = ;
int RGB_3_r = ;
int RGB_4_r = ;
int RGB_5_r = ;
int RGB_6_r = ;
int RGB_7_r = ;
int RGB_8_r = ;
int RGB_9_r = ;

int RGB_1_b = ;
int RGB_2_b = ;
int RGB_3_b = ;
int RGB_4_b = ;
int RGB_5_b = ;
int RGB_6_b = ;
int RGB_7_b = ;
int RGB_8_b = ;
int RGB_9_b = ;

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

const int irs_1 = A1; float dis_1 = analogRead(irs_1);
const int irs_2 = A2; float dis_2 = analogRead(irs_2);
const int irs_3 = A3; float dis_3 = analogRead(irs_3);
const int irs_4 = A4; float dis_4 = analogRead(irs_4);
const int irs_5 = A5; float dis_5 = analogRead(irs_5);
const int irs_6 = A6; float dis_6 = analogRead(irs_6);
const int irs_7 = A7; float dis_7 = analogRead(irs_7);
const int irs_8 = A8; float dis_8 = analogRead(irs_8);
const int irs_9 = A9; float dis_9 = analogRead(irs_9);

//variable to check whose turn it is, blue (1) beginns, then red (2)

int turn = 1;

//variable to check who won, no one (0), blue (1). red (2)

int win = 0;

//variable to reset the game after a person won
int reset = 0;


//___________________________________________________________________________


void setup() {

// set LEDs as OUTPUT and Sensors as INPUT

pinMode(RGB_1_r,OUTPUT);
pinMode(RGB_2_r,OUTPUT);
pinMode(RGB_3_r,OUTPUT);
pinMode(RGB_4_r,OUTPUT);
pinMode(RGB_5_r,OUTPUT);
pinMode(RGB_6_r,OUTPUT);
pinMode(RGB_7_r,OUTPUT);
pinMode(RGB_8_r,OUTPUT);
pinMode(RGB_9_r,OUTPUT);

pinMode(RGB_1_b,OUTPUT);
pinMode(RGB_2_b,OUTPUT);
pinMode(RGB_3_b,OUTPUT);
pinMode(RGB_4_b,OUTPUT);
pinMode(RGB_5_b,OUTPUT);
pinMode(RGB_6_b,OUTPUT);
pinMode(RGB_7_b,OUTPUT);
pinMode(RGB_8_b,OUTPUT);
pinMode(RGB_9_b,OUTPUT);

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


//_____________________________________________________________


void loop() {

  //check sensors, to turn light on and switch players turn
  
  if((RGB_1 == 0) && (dis_1 < 1000)){RGB_1 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_2 == 0) && (dis_2 < 1000)){RGB_2 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_3 == 0) && (dis_3 < 1000)){RGB_3 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_4 == 0) && (dis_4 < 1000)){RGB_4 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_5 == 0) && (dis_5 < 1000)){RGB_5 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_6 == 0) && (dis_6 < 1000)){RGB_6 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_7 == 0) && (dis_7 < 1000)){RGB_7 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_8 == 0) && (dis_8 < 1000)){RGB_8 = turn; if(turn == 1){turn=2;} else{turn=1;}}
  if((RGB_9 == 0) && (dis_9 < 1000)){RGB_9 = turn; if(turn == 1){turn=2;} else{turn=1;}}

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
**/

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
**/

  //action for win
  
  if(win == 1){
    digitalWrite(RGB_1_r,LOW);
    digitalWrite(RGB_2_r,LOW);
    digitalWrite(RGB_3_r,LOW);
    digitalWrite(RGB_4_r,LOW);
    digitalWrite(RGB_5_r,LOW);
    digitalWrite(RGB_6_r,LOW);
    digitalWrite(RGB_7_r,LOW);
    digitalWrite(RGB_8_r,LOW);
    digitalWrite(RGB_9_r,LOW);
                                    //setting LEDs to winners color for 5s/5000ms
    digitalWrite(RGB_1_b,HIGH);
    digitalWrite(RGB_2_b,HIGH);
    digitalWrite(RGB_3_b,HIGH);
    digitalWrite(RGB_4_b,HIGH);
    digitalWrite(RGB_5_b,HIGH);
    digitalWrite(RGB_6_b,HIGH);
    digitalWrite(RGB_7_b,HIGH);
    digitalWrite(RGB_8_b,HIGH);
    digitalWrite(RGB_9_b,HIGH);

    delay(5000);

    digitalWrite(RGB_1_b,LOW);
    digitalWrite(RGB_2_b,LOW);
    digitalWrite(RGB_3_b,LOW);
    digitalWrite(RGB_4_b,LOW);
    digitalWrite(RGB_5_b,LOW);
    digitalWrite(RGB_6_b,LOW);
    digitalWrite(RGB_7_b,LOW);
    digitalWrite(RGB_8_b,LOW);
    digitalWrite(RGB_9_b,LOW);

    reset = 1;
  }

  if(win == 2){
    digitalWrite(RGB_1_b,LOW);
    digitalWrite(RGB_2_b,LOW);
    digitalWrite(RGB_3_b,LOW);
    digitalWrite(RGB_4_b,LOW);
    digitalWrite(RGB_5_b,LOW);
    digitalWrite(RGB_6_b,LOW);
    digitalWrite(RGB_7_b,LOW);
    digitalWrite(RGB_8_b,LOW);
    digitalWrite(RGB_9_b,LOW);
                                    //setting LEDs to winners color for 5s/5000ms
    digitalWrite(RGB_1_r,HIGH);
    digitalWrite(RGB_2_r,HIGH);
    digitalWrite(RGB_3_r,HIGH);
    digitalWrite(RGB_4_r,HIGH);
    digitalWrite(RGB_5_r,HIGH);
    digitalWrite(RGB_6_r,HIGH);
    digitalWrite(RGB_7_r,HIGH);
    digitalWrite(RGB_8_r,HIGH);
    digitalWrite(RGB_9_r,HIGH);

    delay(5000);

    reset = 1;
  }

  //turning on the LEDs
  
  if(RGB_1 == 1){digitalWrite(RGB_1_b,HIGH);}
  if(RGB_2 == 1){digitalWrite(RGB_2_b,HIGH);}
  if(RGB_3 == 1){digitalWrite(RGB_3_b,HIGH);}
  if(RGB_4 == 1){digitalWrite(RGB_4_b,HIGH);}
  if(RGB_5 == 1){digitalWrite(RGB_5_b,HIGH);}
  if(RGB_6 == 1){digitalWrite(RGB_6_b,HIGH);}
  if(RGB_7 == 1){digitalWrite(RGB_7_b,HIGH);}
  if(RGB_8 == 1){digitalWrite(RGB_8_b,HIGH);}
  if(RGB_9 == 1){digitalWrite(RGB_9_b,HIGH);}

  if(RGB_1 == 2){digitalWrite(RGB_1_r,HIGH);}
  if(RGB_2 == 2){digitalWrite(RGB_2_r,HIGH);}
  if(RGB_3 == 2){digitalWrite(RGB_3_r,HIGH);}
  if(RGB_4 == 2){digitalWrite(RGB_4_r,HIGH);}
  if(RGB_5 == 2){digitalWrite(RGB_5_r,HIGH);}
  if(RGB_6 == 2){digitalWrite(RGB_6_r,HIGH);}
  if(RGB_7 == 2){digitalWrite(RGB_7_r,HIGH);}
  if(RGB_8 == 2){digitalWrite(RGB_8_r,HIGH);}
  if(RGB_9 == 2){digitalWrite(RGB_9_r,HIGH);}

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
