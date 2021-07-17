
#include <iostream>
#include <math.h>
using namespace std;

// seesaw 

/*
 * 了崔塀PID距准
 * newData = oldData + Kp*(errorNow) + Ki*( ‘(errorNow) ) + Kd*(errorLast - errorNow)
**/




#define MAX 99




//  set the change 
float randomChange(float angle) {
    return (angle + 40);
}


int main()
{ 
    // 0.95  0.00  0.3
    float Kp = 1;
    float Ki = 0.00;
    float Kd = 0.5;

    int i = 0;
    float angleFirst, angle;
    float angleStandard = 90.0f;    // standard angle is 90
    cout << "input the first angle: ";
    cin >> angleFirst;              // init the first angle 
    angle = angleFirst;             // send the angleFirst to angle
    
    float errorNow;
    float errorSum = 0;
    float errorLast = 0;
    printf("%3s %25s %20s %20s\n", "number", "errorNow", "angle", "errorSum");
    cout << "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl;
    while (i++ < MAX) {

        errorNow = angleStandard - angle;
        errorSum += errorNow;
        if (errorSum > 10000000)
            errorSum = 0;
        if (errorSum < -10000000)
            errorSum = 0;
        angle += Kp *errorNow + Ki * errorSum + Kd * (errorLast - errorNow);
        errorLast = errorNow;
        printf("%3d  %25.2f  %20.2f %20.2f\n ", i,errorNow, angle,errorSum);
    }
}
