#include <Servo.h>



// Motor da base (primeiro motor)

#define A3_base A3 // Fio verde
#define D11_base 11
int pos_base = 0;
Servo servo_base;

// Motor Z

#define A2_z A2 // Fio roxo
#define D10_z 10
int pos_z = 0;
Servo servo_z;

// Motor Y

#define A1_y A1 // Fio Azul
#define D6_y 6 
int pos_y = 0;
Servo servo_y;

// Motor da garra

#define A0_claw A0 // Fio amarelo
#define D9_claw 9
int pos_claw = 0;
Servo servo_claw;

int ini_base=0;
int ini_z=0;
int ini_y=0;
int ini_claw=0;

// cor

#define out_s0 2 // para o pino S0 do sensor
#define out_s1 3 // para o pino S1 do sensor
#define out_s2 4 // para o pino S2 do sensor
#define out_s3 5 // para o pino S3 do sensor
#define in_out 7 // recebe do pino OUT do sensor

int v_red=0;
int v_green=0;
int v_blue=0;
int v_white=0;

void mudar (Servo servo, int inicial, int final ) {

    if(inicial < final) {

      for (int i=inicial; i<=final; i++){
        servo.write(i);
        delay(15); 
      }
    }else{
        for (int i=inicial; i>=final; i--){
          servo.write(i);
          delay(15); 
        }
    }
}



void setup()
{
  Serial.begin(9600);
  pinMode(A3_base, INPUT);
  pinMode(D11_base, OUTPUT);

  pinMode(A2_z, INPUT);
  pinMode(D10_z, OUTPUT);

  pinMode(A1_y, INPUT);
  pinMode(D6_y, OUTPUT);

  pinMode(A0_claw, INPUT);
  pinMode(D9_claw, OUTPUT);

  servo_base.attach(D11_base, 500, 2500);
  servo_z.attach(D10_z, 500, 2500);
  servo_y.attach(D6_y, 500, 2500);
  servo_claw.attach(D9_claw, 500, 2500);

  servo_base.write(0);
  servo_claw.write(0);
  servo_z.write(0);
  servo_y.write(0);

  pinMode(out_s0, OUTPUT);
  pinMode(out_s1, OUTPUT);
  pinMode(out_s2, OUTPUT);
  pinMode(out_s3, OUTPUT);
  pinMode(in_out, INPUT);

  digitalWrite(out_s0,HIGH); // frequência de
  digitalWrite(out_s1,LOW);
  
}

void loop()
{
  // Sensor de cor

  digitalWrite(out_s2,LOW);
  digitalWrite(out_s3,LOW);
  v_red = pulseIn(in_out, LOW);

  digitalWrite(out_s2,HIGH);
  digitalWrite(out_s3,HIGH);
  v_green = pulseIn(in_out, LOW);

  digitalWrite(out_s2,LOW);
  digitalWrite(out_s3,HIGH);
  v_blue = pulseIn(in_out, LOW);

  Serial.println(" ");
  Serial.print("Red: ");
  Serial.print(v_red);
  Serial.print(" / Green: ");
  Serial.print(v_green);
  Serial.print(" / Blue: ");
  Serial.print(v_blue);
  
  // Pega o objeto

        pos_y = 50;
  mudar(servo_y, ini_y, pos_y);
  ini_y = pos_y;

  pos_base = 40;
  mudar(servo_base, ini_base, pos_base);
  ini_base = pos_base;
 
  pos_z = 90;
  mudar(servo_z, ini_z, pos_z);
  ini_z = pos_z;

  pos_y = 76;
  mudar(servo_y, ini_y, pos_y);
  ini_y = pos_y;

  pos_claw=100;
  mudar(servo_claw, ini_claw, pos_claw);
  ini_claw = pos_claw;
  
  pos_y = 50;
  mudar(servo_y, ini_y, pos_y);
  ini_y = pos_y;
  

  if (v_red < v_green){
      pos_base = 80;
      mudar(servo_base, ini_base, pos_base);
      ini_base = pos_base;
     
      pos_z = 90;
      mudar(servo_z, ini_z, pos_z);
      ini_z = pos_z;
    
      pos_y = 76;
      mudar(servo_y, ini_y, pos_y);
      ini_y = pos_y;
    
      pos_claw=0;
      mudar(servo_claw, ini_claw, pos_claw);
      ini_claw = pos_claw;
  } else if (v_green < v_red){
      pos_base = 120;
      mudar(servo_base, ini_base, pos_base);
      ini_base = pos_base;
     
      pos_z = 90;
      mudar(servo_z, ini_z, pos_z);
      ini_z = pos_z;
    
      pos_y = 76;
      mudar(servo_y, ini_y, pos_y);
      ini_y = pos_y;
    
      pos_claw=0;
      mudar(servo_claw, ini_claw, pos_claw);
      ini_claw = pos_claw;
  } 
  
  // Solta o objeto


  
  delay(200);
}
