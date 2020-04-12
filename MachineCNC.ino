/**
 * Arduino code for CNC Machine created by Sofien Kriaa
 */

int EncoderMY = 2;
int EncoderMZ = 3;
int EncoderMX = A0;

int MotorYPin1 = 8;
int MotorYPin2 = 9;
int MotorZPin1 = 10;
int MotorZPin2 = 11;
int MotorXPin1 = 12;
int MotorXPin2 = 13;

/**
 * @brief rotate specified Motor in direction 1
 */
void RotateMotorDir1(int MotorPin1, int MotorPin2) {
  digitalWrite(MotorPin1, HIGH);
  digitalWrite(MotorPin2, LOW);
}

/**
 * @brief rotate specified Motor in direction 2
 */
void RotateMotorDir2(int MotorPin1, int MotorPin2) {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, HIGH);
}

/**
 * @brief stop specified Motor
 */
void StopMotor(int MotorPin1, int MotorPin2) {
  digitalWrite(MotorPin1, LOW);
  digitalWrite(MotorPin2, LOW);
}

/**
 * @brief get value of the analog sensor and convert it to boolean
 */
int GetAndConvertAnalogEncoderValue() {
  int sensorValue = analogRead(EncoderMX);
  int returnValue = 0;
  if (sensorValue < 200) {
    returnValue = 1;
  }
  return returnValue;
}

/**
 * @brief rotate Motor X in direction 1 with steps number
 */
void RotateMotorXDir1WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    /** @note motor X needs speed limitation */
    analogWrite(6, 236);
    RotateMotorDir1(MotorXPin1, MotorXPin2);
    state = GetAndConvertAnalogEncoderValue();

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorXPin1, MotorXPin2);  
}

/**
 * @brief rotate Motor X in direction 2 with steps number
 */
void RotateMotorXDir2WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    /** @note motor X needs speed limitation */
    analogWrite(6, 236);
    RotateMotorDir2(MotorXPin1, MotorXPin2);
    state = GetAndConvertAnalogEncoderValue();

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorXPin1, MotorXPin2);  
}

/**
 * @brief rotate Motor Y in direction 1 with steps number
 */
void RotateMotorYDir1WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    RotateMotorDir1(MotorYPin1, MotorYPin2);
    state = digitalRead(EncoderMY);

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorYPin1, MotorYPin2);
}

/**
 * @brief rotate Motor Y in direction 2 with steps number
 */
void RotateMotorYDir2WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    RotateMotorDir2(MotorYPin1, MotorYPin2);
    state = digitalRead(EncoderMY);

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorYPin1, MotorYPin2);
}

/**
 * @brief rotate Motor Z in direction 1 with steps number
 */
void RotateMotorZDir1WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    RotateMotorDir1(MotorZPin1, MotorZPin2);
    state = digitalRead(EncoderMZ);

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorZPin1, MotorZPin2);
}

/**
 * @brief rotate Motor Z in direction 1 with steps number
 */
void RotateMotorZDir2WithSteps(int steps) {
  int count = 0;
  int state = 0;
  int prevState = 0;
  while (count < steps) {
    RotateMotorDir2(MotorZPin1, MotorZPin2);
    state = digitalRead(EncoderMZ);

    if (state != prevState) {
      count++;
    }
    prevState = state;
  }
  StopMotor(MotorZPin1, MotorZPin2);
}


void setup() {
  //Serial.begin(9600);
  pinMode(MotorXPin1, OUTPUT);
  pinMode(MotorXPin2, OUTPUT);
  pinMode(MotorYPin1, OUTPUT);
  pinMode(MotorYPin2, OUTPUT);
  pinMode(MotorZPin1, OUTPUT);
  pinMode(MotorZPin2, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  RotateMotorXDir2WithSteps(20);
  RotateMotorYDir2WithSteps(1000);
  RotateMotorXDir1WithSteps(20);
  RotateMotorYDir1WithSteps(1000);

}
