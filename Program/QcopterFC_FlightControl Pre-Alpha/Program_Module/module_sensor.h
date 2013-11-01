/* #include "module_sensor.h" */

#ifndef __MODULE_SENSOR_H
#define __MODULE_SENSOR_H

#include "stm32f4xx.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define ACC_X_OFFSET ((s16)0)
#define ACC_Y_OFFSET ((s16)0)
#define ACC_Z_OFFSET ((s16)8192)
#define GYR_X_OFFSET ((s16)0)
#define GYR_Y_OFFSET ((s16)0)
#define GYR_Z_OFFSET ((s16)0)
#define MAG_X_OFFSET ((s16)0)
#define MAG_Y_OFFSET ((s16)0)
#define MAG_Z_OFFSET ((s16)0)
#define TEMP_OFFSET  ((s16)(-12421))  // (340*35)+521
/*=====================================================================================================*/
/*=====================================================================================================*/
typedef struct {
  s16 X;
  s16 Y;
  s16 Z;
  s16 OffsetX;
  s16 OffsetY;
  s16 OffsetZ;
  float TrueX;
  float TrueY;
  float TrueZ;
} Sensor;

typedef struct {
  s16 T;
  s16 OffsetT;
  float TrueT;
} SensorTemp;
/*=====================================================================================================*/
/*=====================================================================================================*/
extern Sensor Acc;
extern Sensor Gyr;
extern Sensor Mag;
extern Sensor Ang;
extern SensorTemp Temp;
extern float Ellipse[5];
/*=====================================================================================================*/
/*=====================================================================================================*/
void Sensor_Config( void );
u8 Sensor_Init( void );
void EllipseFitting( float* Ans, s16* MagDataX, s16* MagDataY, u8 Num );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif
