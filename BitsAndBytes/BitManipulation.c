/*
		Author 			: Marius Celliers
		Date   			: 2024/02/04
		Description:	: Usefull Code for Bit Manipulation
		Contact 		: marius.celliers@gmail.com
*/
#include <stdio.h>
#include <stdbool.h>

//OPTION A: Using Struct and Union to Access The Bits in an unsigned byte
// With the Union the total space used is only one byte ( bool actually also use 1 byte you can test it by using sizeof(bool)) 
// There are some slight overhead of using union-struct but your code is easier to read 
typedef union {
    struct {
        bool bit0 : 1;
        bool bit1 : 1;
        bool bit2 : 1;
        bool bit3 : 1;
        bool bit4 : 1;
        bool bit5 : 1;
        bool bit6 : 1;
        bool bit7 : 1;
    } bits;

    unsigned char byte;
} st_byte;

//	Option B  define expressions in your header files
//  Uses less code space
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define BIT_SET(var,pos) ((var) |= (1<<(pos)))
#define BIT_CLEAR(var,pos) ((var) &= ~(1<<(pos)))
#define BIT_FLIP(var,pos) ((var) ^= (1<<(pos)))

/*    Main Function  for Test  */
 int main()
{
	//Option A
	st_byte NewByteValue;				// Create an instance of st_byte
    NewByteValue.byte = 5;				// Here you can set all the bits at once
    NewByteValue.bits.bit7 = true;		// Here you can set each bit indifidually
	//Option B
	byte OptBByte = 0; 
	
	//Show/Display the values : Option A
	printf("Byte: %d\n", NewByteValue.byte);
	printf(" Bit0: %d\n", NewByteValue.bits.bit0);
    printf(" Bit1: %d\n", NewByteValue.bits.bit1);
    printf(" Bit2: %d\n", NewByteValue.bits.bit2);
    printf(" Bit3: %d\n", NewByteValue.bits.bit3);
    printf(" Bit4: %d\n", NewByteValue.bits.bit4);
    printf(" Bit5: %d\n", NewByteValue.bits.bit5);
    printf(" Bit6: %d\n", NewByteValue.bits.bit6);
    printf(" Bit7: %d\n", NewByteValue.bits.bit7);
	
	//Option B
	BIT_SET(OptBByte,0);      // Set Bit0 to true
	BIT_CLEAR(OptBByte,1);    // Set Bit1 to false
	BIT_SET(OptBByte,2);      // Set Bit2 to true
	//Show/Display the values : Option A
	printf("Byte: %d\n", OptBByte.byte);		//Value should now be 5
	//Now lets flip the first 3 bits       101  to 010
	BIT_FLIP(OptBByte,0);
	BIT_FLIP(OptBByte,1);
	BIT_FLIP(OptBByte,2);
	//Show/Display the values : Option A
	printf("Byte: %d\n", OptBByte.byte);		//Value should now be 2

	
} // Main End 