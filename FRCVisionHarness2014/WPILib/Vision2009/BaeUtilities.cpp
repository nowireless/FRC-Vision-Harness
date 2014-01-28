/********************************************************************************
*  Project   		: FIRST Motor Controller
*  File Name  		: BaeUtilities.cpp        
*  Contributors   	: JDG, ELF, EMF
*  Creation Date 	: July 20, 2008
*  Revision History	: Source code & revision history maintained at sourceforge.WPI.edu    
*  File Description	: Open source utility extensions for FIRST Vision API.
*/                            
/*----------------------------------------------------------------------------*/
/*        Copyright (c) FIRST 2008.  All Rights Reserved.                     */
/*  Open Source Software - may be modified and shared by FRC teams. The code  */
/*  must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib. */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>
#include <math.h>
#include <stdio.h> 
 
#include "BaeUtilities.h"

/**
 *   Utility functions 
 */


/**
 * @brief Normalizes a value in a range, used for drive input
 * @param position The position in the range, starting at 0
 * @param range The size of the range that position is in
 * @return The normalized position from -1 to +1
 */
double RangeToNormalized(double position, int range){
	return(((position*2.0)/(double)range)-1.0);
}

/**
 * @brief Convert a normalized value to the corresponding value in a range.
 * This is used to convert normalized values to the servo command range.
 * @param normalizedValue The normalized value (in the -1 to +1 range)
 * @param minRange The minimum of the range (0 is default)
 * @param maxRange The maximum of the range (1 is default)
 * @return The value in the range corresponding to the input normalized value
 */
float NormalizeToRange(float normalizedValue, float minRange, float maxRange) {
	float range = maxRange-minRange;
	float temp = (float)((normalizedValue / 2.0)+ 0.5)*range;
	return (temp + minRange);
}	
float NormalizeToRange(float normalizedValue) {
	return (float)((normalizedValue / 2.0) + 0.5);
}	

