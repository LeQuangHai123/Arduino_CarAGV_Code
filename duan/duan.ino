int stop_distance = 20;// Khoảng cách phát hiện vật cản
//Kết nối SRF 05 OR 04
  const int trigPin = 11; // kết nối chân trig với chân 11 arduino
  const int echoPin = 12; // kết nối chân echo với chân 12 arduino

//L298 kết nối arduino
  const int motorA1      = 7;  // kết nối chân IN1 với chân 3 arduino
  const int motorA2      = 6;  // kết nối chân IN2 với chân 4 arduino
  const int motorAspeed  = 8;  // kết nối chân ENA với chân 5 arduino
  const int motorB1      = 5; // kết nối chân IN3 với chân 7 arduino
  const int motorB2      = 4; // kết nối chân IN4 với chân 8 arduino
  const int motorBspeed  =3;  // kết nối chân ENB với chân 6 arduino
 

//kết nối của 3 cảm biến hồng ngoại (dò line )
  const int L_S =10;  // cb dò line de queo phải 
  const int L_S_S =14;  // cb dò line phải 1
  const int R_S_S =16;  // cb dò line phải 1
  const int S_S =2;  // cb dò line giữa
  const int R_S =9; //cb dò line trái 
  const int DK =13; //Nhận tín hiệu từ D0 của esp8266
  const int DK1 =15; //Nhận tín hiệu từ D1 của esp8266
  

  const int button =22;
  
  int left_sensor_state;// biến lưu cảm biến hồng ngoại line trái
  int left_sensor_state_S;// biến lưu cảm biến hồng ngoại line trái 1
  int s_sensor_state;   // biến lưu cảm biến hồng ngoại line giữa
  int right_sensor_state;// biến lưu cảm biến hồng ngoại line phải
  int right_sensor_state_S;// biến lưu cảm biến hồng ngoại line phải

  long duration; // 
  int distance;  // biến khoảng cách
  int a=0,b=0,c=0,d=0,e=0,f=0,k=0,m=0,n=0,l=0;      

void setup() {
  pinMode(L_S,INPUT); // chân cảm biến khai báo là đầu vào
  pinMode(R_S,INPUT);
  pinMode(S_S,INPUT);
  pinMode(R_S_S,INPUT);
  pinMode(L_S_S,INPUT);
  pinMode(DK,INPUT);
  pinMode(DK1,INPUT);
  pinMode(button, INPUT);
  pinMode(motorA1, OUTPUT); 
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorAspeed, OUTPUT);
  pinMode(motorBspeed, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    
  Serial.begin(9600);                          
  
}

void loop() {
   left_sensor_state = digitalRead(L_S);
   s_sensor_state = digitalRead(S_S);
   right_sensor_state = digitalRead(R_S);
   right_sensor_state_S = digitalRead(R_S_S);
   left_sensor_state_S = digitalRead(L_S_S);
   while((digitalRead (DK) == 0)&&(digitalRead (DK1) == 0)&&(digitalRead (button) == 0)) {Stop();}
       while(digitalRead (DK) == 1)
  {
      m=0;
      if(b==0)
      { 
       forword1();
        delay(250);
        b++;
        }
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}// đi tiến
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnLeft();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)&&(digitalRead(L_S_S) == 1)&&(digitalRead(R_S_S) == 1)) 
      {
        cho:
        Stop(); 
        if(digitalRead (DK) == 1)
        goto cho;
      }
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();} // rẻ trái
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)&&(digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 1)) {turnLeft(); delay(100);}
      if ((digitalRead(L_S) == 0)&&(digitalRead(L_S_S) == 1)) {turnLeft();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(L_S_S) == 1)) {turnLeft();}
      if(distance < stop_distance) {Stop();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)&&(digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 0))
      {
        while(m==0){
        turnLeft1(); 
        if ((digitalRead(L_S) == 1)||(digitalRead(S_S) == 1)||(digitalRead(R_S) == 1)) {m++;} }
      }
  }
   while((digitalRead (button) == 1)&&(b!=0)&&(digitalRead (DK) == 0))
  {
      n=0;
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;          
           if(c==0)
      { 
       
       forword1();
        delay(250);
        c++;
        }
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}// đi tiến
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();} // rẻ trái
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 1)) {turnLeft(); delay(100);}
      if(distance < stop_distance) {Stop();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)&&(digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 0))
      {
        while(n==0){
        turnLeft1(); 
        if ((digitalRead(L_S) == 1)||(digitalRead(S_S) == 1)||(digitalRead(R_S) == 1)) {n++;} }
      }
      bb:
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)&&(digitalRead(R_S_S) == 1)&&(digitalRead(L_S_S) == 1))
      {
Stop();
        b=0;
        c=0;
        if(digitalRead (button) == 1) goto bb;
      }
  }
        
  while(digitalRead (DK1) == 1)
  {
       l=0;
       if(d==0)
      { 
       forword1();
        delay(250);
        d++;
        }
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;
       if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}// đi tiến
       if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){forword();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();} // rẻ trái
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(R_S_S) == 1)&&((digitalRead(L_S) == 0)||(digitalRead(S_S) == 0)||(digitalRead(R_S) == 0))){forword(); delay(200);}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)&&(digitalRead(R_S_S) == 1)&&(digitalRead(L_S_S) == 1)) 
      {
        abcd:
        Stop();
        if(digitalRead (DK1) == 1)
        goto abcd;
      }
      if(distance < stop_distance) {Stop();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)&&(digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 0))
      {
        while(l==0){
        turnLeft1(); 
        if ((digitalRead(L_S) == 1)||(digitalRead(S_S) == 1)||(digitalRead(R_S) == 1)) {l++;} }
      }
  }
   while((d!=0)&&(digitalRead (button) == 1)&&(digitalRead (DK1) == 0))
  {
      k=0;
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;       
       if(e==0)
      { 
       forword1();
        delay(250);
        e++;
        }
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}// đi tiến
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();} // rẻ trái
            cc:
      if ((digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)&&(digitalRead(L_S_S) == 1)) 
      {
        Stop();
        e=0;
        d=0;
        if(digitalRead (button) == 1) goto cc;
      }
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();} // rẻ trái
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if (((digitalRead(L_S) == 1)||(digitalRead(L_S_S) == 1))&&((digitalRead(R_S_S) == 1)||(digitalRead(R_S) == 1))) {forword(); delay(300);}
      if(distance < stop_distance) {Stop();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)&&(digitalRead(L_S_S) == 0)&&(digitalRead(R_S_S) == 0))
      {
        while(k==0){
        turnLeft1(); 
        if ((digitalRead(L_S) == 1)||(digitalRead(S_S) == 1)||(digitalRead(R_S) == 1)) {k++;} }
      }
  }
 }



void forword(){ // chương
 
    digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 90);
analogWrite (motorBspeed, 90);
  
  
}

void forword1(){ // chương
  
    digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 90);
analogWrite (motorBspeed, 90);
  
  
}

void turnRight(){
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 75);
  analogWrite (motorBspeed, 75);
  
}


void turnLeft(){
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 75);
  analogWrite (motorBspeed, 75);
}

void turnLeft1(){
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, 80);
  analogWrite (motorBspeed, 80);
}

void Stop(){

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,LOW);
}
