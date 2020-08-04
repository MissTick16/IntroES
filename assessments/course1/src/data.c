#include "data.h"
#include "platform.h"
#include <stdlib.h>

void reverse(uint8_t *data, uint8_t len)
{
	uint8_t *start = data, *end = data + len - 1;

	while (start < end) {
		uint8_t tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t digit;
	uint8_t *current = ptr;
	uint8_t len = 0;

	uint8_t negative = data < 0 ? 1 : 0;

	if (negative)
		data = -data;

	while (data) {
		digit = data % base;
		data = data / base;
		*current++ = (digit < 9) ? digit + '0' : (digit - 10) + 'A';
		len++;
	}

	if (negative) {
		*current++ = '-';
		len++;
	}
	
	*current = '\0';
	len++;

	reverse(ptr, len - 1);
	return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	if (ptr == NULL)
		return 0;


	uint8_t *end = ptr + digits - 2; //skip '\0' --> ex = -4096\0 has digits = 6
	
	int32_t result = 0;
	uint32_t power = 1; 
	uint8_t digit = 0;

	while (--digits) {
		if (*end >= '0' && *end <= '9')
			digit = *end - '0';
		else if (*end >= 'A' && *end <='9')
			digit = *end + 10 - 'A';
		else {
			// found a minus
			result = -result;
			break;
		}

		result += digit * power;
		power = power * base;
		end--;
	}

	return result;
}