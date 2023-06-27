#include "MyString.h"
#include "Other_Func.h"


MyString::MyString()
{
	str = nullptr;

	size = free_memory = 0;
}

MyString::MyString(const char* ptr)
{
	this->size = lenght(ptr);

	free_memory = 0;

	str = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		str[i] = ptr[i];
	}
	str[size] = 0;
}

MyString::MyString(const MyString& other)
{
	copy_from(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
		return *this;

	if (str != nullptr)
	{
		delete[] str;
	}
	copy_from(other);

	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	move_from(other);
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this == &other)
		return *this;

	delete[] str;

	move_from(other);

	return *this;
}

MyString& MyString::operator+=(char symbol)
{
	if (free_memory == 0)
	{
		int size = this->size + this->size + 2;

		char* ptr = new char[size];

		for (int i = 0; i < this->size; i++)
		{
			ptr[i] = str[i];
		}
		delete[] str;

		str = ptr;

		free_memory = size - this->size - 2;
	}
	else
	{
		--free_memory;
	}
	str[size] = symbol;

	str[++size] = 0;

	return *this;
}

MyString& MyString::reverse()
{
	char* start, * end;

	char temp;

	start = str;

	end = &str[size - 1];

	while (start < end)
	{
		temp = *start;

		*start = *end;

		*end = temp;

		start++;

		end--;
	}

	return *this;
}

MyString::~MyString()
{
	delete[] str;
}

char MyString::operator[](int index) const
{
	return str[index];
}

const char* MyString::c_str() const
{
	return str;
}

int MyString::Size() const
{
	return size;
}

int MyString::capacity() const
{
	return size + free_memory;
}

void MyString::copy_from(const MyString& other)
{
	this->size = lenght(other.str);

	this->free_memory = 0;

	str = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		str[i] = other.str[i];
	}
	str[size] = 0;
}

void MyString::move_from(MyString& other)
{
	str = other.str;

	size = other.size;

	free_memory = other.free_memory;

	other.str = nullptr;

	other.size = other.free_memory = 0;
}