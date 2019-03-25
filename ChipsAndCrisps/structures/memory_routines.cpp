#include "memory_routines.h"

namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		/*byte byteArray[4] = { 0,6,2,2 }; //na vyskusanie
		byte maska = 3;

		B = bitIndexOfBitMask(byteArray, 4, maska);*/
		B = 0xFF;
		return B;
	}
	byte & MemoryRoutines::byteReset(byte & B)
	{
		//TODO 01: MemoryRoutines
		B = 0;
		return B;
	}
	byte & MemoryRoutines::byteXOR(byte & B)
	{
		//TODO 01: MemoryRoutines
		B = B ^ 0;
		return B;
	}
	byte & MemoryRoutines::byteSHL(byte & B)
	{
		//TODO 01: MemoryRoutines
		B = B << 1;
		return B;
	}
	byte & MemoryRoutines::byteSHR(byte & B)
	{
		//TODO 01: MemoryRoutines
		B = B >> 1;
		return B;
	}
	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		//TODO 01: MemoryRoutines
		
		if ((B >> n) & 1) return true;
		else return false;
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		//TODO 01: MemoryRoutines
		B = ~(1 << n) & B;
		return B;
	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		//TODO 01: MemoryRoutines
		B = B | (1 << n);
		return B;
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		//TODO 01: MemoryRoutines
		B ^= ~(1 << n);
		return B;
	}

	//uloha
	int MemoryRoutines::bitIndexOfBitMask(const byte * bytes, int bytesCount, byte bitMask)
	{
		/*int index = 0;
		
		for (int j = 0; j < bytesCount;j++) {
			for (int k = 0; k < 8;k++) {

				if (bytes[j] & bitMask) {
					return index;
				}
				else {
					bytes[j] >> 1;
					index++;
				}
			}
		}*/
		return -1;
	}

	

	MemoryRoutines::MemoryRoutines()
	{
	}

}
