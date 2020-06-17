#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftLightSensor, sensorReflection)
#pragma config(Sensor, in2,    middleLightSensor, sensorReflection)
#pragma config(Sensor, in3,    rightLightSensor, sensorReflection)
#pragma config(Sensor, in4,    LaunchArmPot,   sensorNone)
#pragma config(Sensor, dgtl8,  Sonar,          sensorSONAR_cm)
#pragma config(Sensor, I2C_1,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           rightDrive,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           clawMotor,     tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           clawExtender,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawWrist,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           launchArm,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           leftIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightIntake,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          load,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveForward(float x) {
	if (x < 0) {
		motor[rightDrive] = -127;
		motor[leftDrive] = -127;
		wait1Msec(-650 * x);
	}
	else {
		motor[rightDrive] = 127;
		motor[leftDrive] = 127;
		wait1Msec(650 * x);
	}
	stopMotor(rightDrive);
	stopMotor(leftDrive);
}

void spin(float x) {
	if (x < 0) {
		motor[rightDrive] = -127;
		motor[leftDrive] = 127;
		wait1Msec(-7 * x);
	}
	else {
		motor[rightDrive] = 127;
		motor[leftDrive] = -127;
		wait1Msec(7 * x);
	}
	stopMotor(rightDrive);
	stopMotor(leftDrive);
}

void startIntake() {
	motor[rightIntake] = -40;
	motor[leftIntake] = -40;
	motor[load] = 40;
}
void stopIntake() {
	stopMotor(rightIntake);
	stopMotor(leftIntake);
	stopMotor(load);
}

void launch() {
	motor[load] = 63.5;
	motor[rightIntake] = 127;
	motor[leftIntake] = 127;
	wait1Msec(500);
	stopMotor(rightIntake);
	stopMotor(leftIntake);
	stopMotor(load);
}

void moveArms(float x) {
	if (x < 0) {
		motor[launchArm] = -100;
		motor[clawArm] = -100;
		wait1Msec(-100 * x);
	}
	else {
		motor[launchArm] = 100;
		motor[clawArm] = 100;
		wait1Msec(100 * x);
	}
	stopMotor(launchArm);
	stopMotor(clawArm);
}

void extendClaw(float x) {
	motor[clawExtender] = 127;
	wait1Msec(1000 * x);
	stopMotor(clawExtender);
}

void closeClaw() {
	motor[clawMotor] = 127;
	wait1Msec(250);
	stopMotor(clawMotor);
}
void openClaw() {
	motor[clawMotor] = -127;
	wait1Msec(250);
	stopMotor(clawMotor);
}

task main()
{
	moveArms(0.1);
	startIntake();
	moveForward(3.5);
	stopIntake();
	moveForward(-1.25);
	motor[clawWrist] = -100;
	extendClaw(1);
	moveForward(0.2);
	stopMotor(clawWrist);
	closeClaw();
	motor[clawArm] = 95;
	moveForward(-2.45);
	stopMotor(clawArm);
	motor[clawWrist] = 85;
	motor[clawExtender] = 20;
	wait1Msec(500);
	stopMotor(clawWrist);
	stopMotor(clawExtender);
	spin(38);
	moveForward(-0.4);
	motor[clawExtender] = -120;
	motor[clawWrist] = -40;
	wait1Msec(500);
	stopMotor(clawWrist);
	openClaw();
	spin(-10);
	motor[clawArm] = -127;
	motor[clawWrist] = -80;
	motor[launchArm] = -127;
	wait1Msec(90);
	stopMotor(launchArm);
	wait1Msec(100);
	stopMotor(clawWrist);
	stopMotor(clawArm);
	spin(29);
	motor[launchArm] = 120;
	wait1Msec(291);               // high shot
	stopMotor(launchArm);
	launch();
	motor[launchArm] = -127;
	wait1Msec(65);                // med shot
	stopMotor(launchArm);
	motor[load] = -127;
	motor[rightIntake] = 127;
	motor[leftIntake] = 127;
	wait1Msec(1000);
	stopMotor(rightIntake);
	stopMotor(leftIntake);
	stopMotor(load);
	moveForward(3.2);
	motor[clawArm] = -127;
	motor[launchArm] = -67;
	motor[clawExtender] = 50;
	motor[clawWrist] = -20;
	moveForward(-1.2);
	spin(-73);
	moveForward(-1.8);
	stopMotor(clawWrist);
	stopMotor(clawExtender);
	stopMotor(clawArm);
	stopMotor(launchArm);
	moveForward(1.4);
	closeClaw();
	motor[clawArm] = 80;
	moveForward(3.3);
	stopMotor(clawArm);
	openClaw();
	motor[clawArm] = -127;
	spin(-70);
	moveForward(-2.4);                 // back into second
	moveForward(1.4);
	stopMotor(clawArm);
	spin(78);
	moveForward(2.6);
	closeClaw();
	motor[clawWrist] = 40;
	motor[clawArm] = 65;
	spin(10);
	moveForward(1.6);
	stopMotor(clawWrist);
	stopMotor(clawArm);
	spin(-80.5);
	moveForward(-2);                         // back into third
	motor[launchArm] = -127;
	moveForward(3.75);
	stopMotor(launchArm);
	spin(-68);
	startIntake();
	moveForward(1.75);
	stopIntake();
	moveForward(-2.7);
	spin(38);
	startIntake();
	moveForward(1.3);
	stopIntake();
	moveForward(-1);
	spin(-88);
	moveForward(-0.5);
	motor[launchArm] = 120;
	wait1Msec(350);                             // high shot
	stopMotor(launchArm);
	launch();
	motor[launchArm] = -127;
	wait1Msec(68);                              // med shot
	stopMotor(launchArm);
	motor[rightIntake] = 127;
	motor[leftIntake] = 127;
	motor[load] = -127;
	wait1Msec(1000);
	stopAllMotors();
	moveForward(-0.5);
	spin(32);
	moveForward(-2.2);
	motor[clawArm] = 127;
	motor[clawWrist] = 100;
	wait1Msec(310);
	stopMotor(clawArm);
	stopMotor(clawWrist);
	motor[clawExtender] = -127;
	wait1Msec(90);
	stopMotor(clawExtender);
	openClaw();
	motor[clawArm] = -127;
	motor[launchArm] = -20;
	motor[clawExtender] = -127;
	wait1Msec(700);
	stopMotor(clawArm);
	stopMotor(launchArm);
	stopMotor(clawExtender);
	moveForward(0.5);
	spin(-145);
	moveForward(-1.6);
	spin(-30);
	moveForward(-5.5);
}

/*

void moveForward(float x) {
int L = SensorValue(leftEncoder);
wait1Msec(100);
int y = x * 500;
if (x < 0) {
while (SensorValue(leftEncoder) - L > y) {
motor[rightDrive] = -127;
motor[leftDrive] = -127;
}
}
else {
while (SensorValue(leftEncoder) - L < y) {
motor[rightDrive] = 127;
motor[leftDrive] = 127;
}
}
stopMotor(rightDrive);
stopMotor(leftDrive);
}

*/