/*
 * MACROS.h
 *
 * Created: 23/04/2023 6:30:56 PM
 *  Author: Mohamed Osama
 */ 


#ifndef _MACROS_H_
#define _MACROS_H_



#define SET_BIT(REG,BIT_NUM) 	REG = REG | (1<<BIT_NUM)
#define TGL_BIT(REG,BIT_NUM)	REG = REG ^ (1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)	REG = REG & ~(1<<BIT_NUM)
#define CLR_REG(REG)            REG=0
#define SET_REG(REG)            REG=255		//0b11111111

#define SET_REG_VAL(REG,VAL)	REG=VAL
#define  READ_BIT(REG,BIT_NUM)	((REG>>BIT_NUM) & 1)

#define  SET_REG_MASK(REG,MASK)	REG=REG|MASK		// 0b00000101		
#define  CLR_REG_MASK(REG,MASK)	REG=REG & ~MASK		// 0b00000101


#endif /* _MACROS_H_ */