#include <Wire.h>
#include <ros.h>
#include <std_msgs/String.h>

#define InputAA 8
#define InputAB 7
#define InputBA 4
#define InputBB 9
#define interruptEncoderPinA 2
#define interruptEncoderPinD 3
#define PWMOutputMotorA 6
#define PWMOutputMotorB 5
//Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

#define wheel_radius 3.0//In cm
#define w2w 13.5//cm
#define CPR 32
#define gear_ratio 19
#define del_t 0.05 //in seconds



#define max_rpmA 479.6
volatile float set_rpmA=200.0;
volatile float curr_rpmA=0;
float errorA=0,preverrorA=0,IA=0;

#define max_rpmB 489.4
volatile float set_rpmB=200.0;
volatile float curr_rpmB=0;
float errorB=0,preverrorB=0,IB=0;

//volatile float sys_dist=0.0;
volatile float curr_pos_x=0.0;
volatile float curr_pos_y=0.0;

volatile float Dl=0,Dr=0,Dc=0;

int motion_direction=0;
int PWMA,PWMB;
uint32_t timer;

void messageCb( const std_msgs::String& toggle_msg){
if(toggle_msg.data[0]=='F')  //check 1st letter of the string
 forward();
else if(toggle_msg.data[0]=='B')  //check 1st letter of the string
 backward();
else if(toggle_msg.data[0]=='R')  //check 1st letter of the string
 rightTurn();
else if(toggle_msg.data[0]=='L')  //check 1st letter of the string
 leftTurn();
else if(toggle_msg.data[0]=='S')  //check 1st letter of the string
 brake(); 
else
 freeRun();
}

ros::NodeHandle nh;
ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );

void setup() {
Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
  pinMode(PWMOutputMotorA,OUTPUT);
  pinMode(PWMOutputMotorB,OUTPUT);
  pinMode(InputAA,OUTPUT);
  pinMode(InputAB,OUTPUT);
  pinMode(InputBA,OUTPUT);
  pinMode(InputBB,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);

}

void loop(){
  int i;
 
  i=200;
  PWMA=i;
  PWMB=i;
  analogWrite(PWMOutputMotorA,PWMA);
 /* Serial.print(PWMA);
  Serial.print('\t');+
  Serial.println(PWMB);*/
  analogWrite(PWMOutputMotorB,PWMB);

  nh.spinOnce();
  delay(1);

}
