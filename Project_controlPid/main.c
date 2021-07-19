
/**
 *
 * 此方法是基于已知速度（或不考虑硬件层面的计数速度计算法）的PID闭环调节
 * 
*/





#include<stdio.h>

#define			P			0.21f
#define			I			0.9785f
#define			D			0.006f

#define			STANDARD	100.00

#define			MAXPWM		255

int abs(int num) {
	if (num < 0)
		return -num;
	else
		return num;
}

void main() {
	float speedNow = 0;
	int pwm = 0;
	float errorNow = 0;
	float errorLast = 0;
	float errorSum = 0;

	float errorLastLast = 0;
	printf("————————————————————————————————————————————————————————\n");
	for (int i = 0; i < 1000; i++) {

		// method1   p=1.2  i=0.0525  d=0.003

		/**
		errorNow = (speedNow - STANDARD);

		errorSum += errorNow;

		pwm = P * errorNow + I * errorSum + D * (errorNow - errorLast);
		pwm = abs(pwm);
		if (pwm > MAXPWM)
			pwm = MAXPWM;
		//if (errorSum > 10000)
			//errorSum = 0;
		speedNow = pwm * 0.7 + 10;

		errorLast = errorNow;

		printf("  i = %-5d   pwm = %-8d    speed = %-10.2f    errorSum = %-10.2f\n", i+1,pwm, speedNow,errorSum);

		*/



		//method2  p=0.21  i=0.9785  d=0.006
		errorNow = (STANDARD - speedNow);
		
		pwm += P * (errorNow - errorLast) + I * (errorNow) + D * (errorNow - 2 * errorLast + errorLastLast);
		
		speedNow = pwm * 0.7 + 10;

		errorLastLast = errorLast;
		errorLast = errorNow;

		printf("  i = %-5d   pwm = %-8d    speed = %-10.2f\n", i + 1, pwm, speedNow);
	}
}

