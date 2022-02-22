#define LEFT 1
#define RIGHT 2

#define LED RED_LED
int calibratedBlack;
bool left__turn;
int lowMotor_turn = 25;
int highMotor_turn = 190;
int lowMotor = 50;
int highMotorLeft = 245;   // actually right I think
int highMotorRight = 255;  // actually left I think
int AnalogValue[5] = {0, 0, 0, 0, 0};
int AnalogPin[5] = {A14, A13, A11, A9, A6};
int distanceSensorPin = A0;
int distanceVal;
int motor1PWM = 39;     // P2.6
int motor1Phase = 40;   // P2.7
int motor2PWM = 37;     // 5.6
int motor2Phase = 38;   // 2.4
bool not_halt = false;
bool first_go = true;

int sensorArray[10] = {0, 0, 0, 0, 0};
int i = 0;
bool atWall = false;
int total;

// Keep track of position
int position;               // Initial position
int destination;
int facing = RIGHT;         // Initial direction facing
int junction_turn = NULL;   // Direction to turn at junction
int ignore_lines = 0;       // Num stops to ignore
bool hitLine = FALSE;

void setup() 
{
  Serial.begin(9600);
  delay(500);
  read_Analog();
  //calibratedBlack = calibrate_black_line();
  calibratedBlack = 600;
  connectToWiFi();
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(RED_LED, LOW);
}

void loop() 
{
  connect();
  sendData();
  recvResponse();
  gotoPosition();
  hitLine = FALSE;
  position = destination;
  
}
