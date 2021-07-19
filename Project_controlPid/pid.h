#pragma once


typedef struct PID {
	float Kp;
	float Ki;
	float Kd;

	const float standard;

	float nowError;
	float lastError;

	float sumError;
	
}PID;