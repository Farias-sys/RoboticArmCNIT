
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
  
}

void loop()
{
  // Pega o objeto


  pos_base = 40;
  mudar(servo_base, ini_base, pos_base);
  ini_base = pos_base;
 
  pos_z = 90;
  mudar(servo_z, ini_z, pos_z);
  ini_z = pos_z;

  pos_y = 76;
  mudar(servo_y, ini_y, pos_y);
  ini_y = pos_y;

  pos_claw=179;
  mudar(servo_claw, ini_claw, pos_claw);
  ini_claw = pos_claw;

  // Solta o objeto

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
  
  delay(200);
}
