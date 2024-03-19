#ifndef BIT_MATHS_H
#define BIT_MATHS_H

#define SET_BIT(VAR, BIT_NO) VAR |= (1<<BIT_NO)
#define CLR_BIT(VAR, BIT_NO) VAR &= (~(1<<BIT_NO))
#define TOGGLE_BIT(VAR, BIT_NO) VAR ^= (1<<BIT_NO)
#define GET_BTI(VAR, BIT_NO) VAR = ((VAR>>BIT_NO) & 1)

#endif