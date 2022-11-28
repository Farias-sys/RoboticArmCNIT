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

void setup()
{
  pinMode(A3_base, OUTPUT);
  pinMode(D11_base, INPUT);

  pinMode(A2_z, OUTPUT);
  pinMode(D10_z, INPUT);

  pinMode(A1_y, OUTPUT);
  pinMode(D6_y, INPUT);

  pinMode(A0_claw, OUTPUT);
  pinMode(D9_claw, INPUT);

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
  // Lendo a posição do motor da base
  
  pos_base = analogRead(A3_base);
  servo_base.write(pos_base);

  // Lendo a posição z

  pos_z = analogRead(A2_z);
  servo_z.write(pos_z);

  // Lendo a posição y

  pos_y = analogRead(A1_y);
  servo_y.write(pos_y);

  // Lendo a posição da garra

  pos_claw = analogRead(A0_claw);
  servo_claw.write(pos_claw);
}
