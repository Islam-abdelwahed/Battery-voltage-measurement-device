/*
 * BIT_Math.h
 *
 * Created: 2/16/2024 11:24:23 AM
 *  Author: @islam_elsayed
 */ 

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
	#ifndef BIT_MATH_H_
	#define BIT_MATH_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
 #define Set_Bit(REG,BIT)        (REG |= (1<<BIT))
 #define Clr_Bit(REG,BIT)        (REG &= ~(1<<BIT))
 #define Toggle_Bit(REG,BIT)     (REG ^= (1<<BIT))
 #define Get_Bit(REG,BIT)        ((REG>>BIT) & (0x01))
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/

#endif /* BIT_MATH_H_ */