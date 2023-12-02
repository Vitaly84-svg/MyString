#include "Other_Func.h"
#include "MyString.h"


int lenght(const char* ptr)
{
	int count = 0;

	if (ptr == nullptr)

		return 0;

	while (*ptr++)
	{
		count++;
	}
	return count;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
	return os << other.c_str();
}

bool operator==(const MyString& ptr1, const MyString& ptr2)
{
	if (ptr1.Size() != ptr2.Size())
		return false;

	for (int i = 0; i < ptr1.Size(); i++)
	{
		if (ptr1[i] != ptr2[i])
			return false;
	}
	return true;
}

bool operator!=(const MyString& ptr1, const MyString& ptr2)
{
	return !(ptr1 == ptr2);
}

bool operator<(const MyString& ptr1, const MyString& ptr2)
{
	int count = 0;

	if (ptr1.Size() > ptr2.Size())
		count = ptr1.Size();

	else
		count = ptr2.Size();

	for (int i = 0; i < count; i++)
	{
		if (ptr1[i] == ptr2[i])
			continue;

		if (ptr1[i] < ptr2[i])
			return true;

		else
			return false;
	}
	return false;
}

const char* begin(const MyString& other)
{
	return other.c_str();
}

const char* end(const MyString& other)
{
	return other.c_str() + other.Size();
}

MyString& operator+=(MyString& ptr1, const MyString& ptr2)
{
	for (auto& x : ptr2)
		ptr1 += x;

	return ptr1;
}

MyString operator+(const MyString& ptr1, const MyString& ptr2)
{
	MyString temp = ptr1;

	temp += ptr2;

	return temp;
}