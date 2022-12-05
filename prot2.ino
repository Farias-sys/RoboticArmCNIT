
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
  // Lendo a posição do motor da base


pos_base = 40;
  
  int valor_base = analogRead(A3_base);
  //pos_base = map(valor_base,0,1023,0,179); 
  mudar(servo_base, ini_base, pos_base);
  ini_base = pos_base;
 

  // Lendo a posição z

pos_z = 90;
  int valor_z = analogRead(A2_z);
  //pos_z = map(valor_z, 0, 1023, 0, 179);
  mudar(servo_z, ini_z, pos_z);
  ini_z = pos_z;

  // Lendo a posição y


pos_y = 76;
  int valor_y = analogRead(A1_y);
  //pos_y = map(valor_y, 0, 1023, 0, 179);
  mudar(servo_y, ini_y, pos_y);
  ini_y = pos_y;

  // Lendo a posição da garra

pos_claw=179;
  //pos_claw = analogRead(A0_claw);
  //pos_claw = map(pos_claw, 0, 1023, 0, 179);
  mudar(servo_claw, ini_claw, pos_claw);
  ini_claw = pos_claw;


  Serial.print("");
  Serial.print(pos_base);
  Serial.print(" : ");
  Serial.print(pos_z);
  Serial.print(" : ");
  Serial.print(pos_y);
  Serial.print(" : ");
  Serial.print(pos_claw);
  Serial.print(" : ");
  Serial.println();
  delay(200);
}
