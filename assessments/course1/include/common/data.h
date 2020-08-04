#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts a signed integer to array of chars in given base.
 *
 * Integer-to-ASCII converts data from a standard integer type into an ASCII string.
 *
 * @param data Decimal number to be converted
 * @param ptr  Pointer to the corresponding ASCII convertion
 * @param base NUmerical base of conversion
 *
 * @return Length of array containing NUL character and sign
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts signed number in given base represented as a string into integer.
 *
 * ASCII-to-Integer converts data from an ASCII represented string into an integer type.
 * The number of digits includes '-' sign and '\0'.
 *
 * @param ptr  	Pointer to the corresponding ASCII representation
 * @param digits Length of ASCII string
 * @param base 	Numerical base of ASCII representation
 *
 * @return Converted decimal value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* _DATA_H__ */ 

