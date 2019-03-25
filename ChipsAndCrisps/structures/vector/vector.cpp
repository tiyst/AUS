#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		//TODO 01: Vector
		memory_ = memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		//TODO 01: Vector
		free(memory_); //vycistenie pamate
		memory_ = nullptr;  //zmazanie smerníka
		size_ = 0; //vynulovanie velkosti
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		//TODO 01: Vector
		if (this != &other) {
			size_ = other.size_;
			memory_ = realloc(memory_, size_); //zvacsenie pamate
			memory_ = memcpy(memory_, other.memory_, size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const //porovnanie velkosti alebo nieco take
	{
		//TODO 01: Vector
		return size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
	}

	byte& Vector::operator[](const int index) //tento to vrati odkazom
	{
		//TODO 01: Vector
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!"); //kontrola parametra index
		return *(reinterpret_cast<byte*>(memory_) + index);// posunie smernik memory o index a vrati to na èo uakzujem
	}

	byte Vector::operator[](const int index) const //tento to vrati kopiou
	{
		//TODO 01: Vector
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vector!");//kontrola parametra index
		return *(reinterpret_cast<byte*>(memory_) + index); // posunie smernik memory o index a vrati to na èo uakzujem
															//pretypuj sa ze si smernik na byte
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		//TODO 01: Vector
		DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Invalid end index in Vector!");  //+1-otvoreny interval, ak kopirujes cele

		memcpy(&dest, getBytePointer(index), count);
		return dest;

	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Invalid src index in Vector!");
		DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Invalid dest index in Vector!");
		DSRoutines::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid end index in Vector");
		DSRoutines::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid end index in Vector");

		/*
		if (src.memory_ == dest.memory_) {
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		*/
		if ((&src == &dest) && (((srcStartIndex >= destStartIndex) && (srcStartIndex < destStartIndex + length)) || destStartIndex >= srcStartIndex) && (destStartIndex < srcStartIndex + length))
			{
				memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}
		else
			{
				memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
			}


	}

	byte* Vector::getBytePointer(const int index) const
	{
		//TODO 01: Vector
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in Vektor");
		return reinterpret_cast<byte*>(memory_) + index;
	}

}