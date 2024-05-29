/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 17/3/2024  ************************************/
/*************************** SWC : DIO         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef ST_INTERFACE_H
#define ST_INTERFACE_H

/*
Components : Stepper motor - 4 Darlington (ULN 2003)
Connections : Seek the datasheet of the stepper motor
Red -> Common VCC
Activation Sequence :
                        1 -> Blue
                        2 -> Pink
                        3 -> Yellow
                        4 -> Orange
                        and all should get LOW PINs State to operate
Degree/Step : Seek datasheet of the stepper motor used ("Degree\Step" "Resolution" 
                                                        "Stride Angle(Smallest angle = angle/half step)")
Frequency : 100HZ -> Should be a delay after each step to perform the step

Stride Angle = 5.625/64
Angle/Half Step = 0.08789 Degree
Angle/Full Step = 0.08789 Degree * 2 = 0.1757 Degree

1 Step ----> 0.1757 Degree
No. of Steps ----> 360 Degree
No. of Steps = 2048 Step/360 Degree

******************** Equations *******************
No. of Steps = (Desired Degree * (360 / Stride Angle)UL ) / 360
No. of iteration = No. of Steps / 4
*/
#define ST_u8_CCW 1
#define ST_u8_CW 0

u8 ST_u8MoveMotor(u8 Copy_u8Direction, u16 Copy_u16Degree);

#endif
