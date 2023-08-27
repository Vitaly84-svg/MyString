#pragma once


class MyString
{
public:
	MyString();

	MyString(const char*);

	MyString(const MyString&);

	MyString& operator=(const MyString&);

	MyString(MyString&&) noexcept;

	MyString& operator=(MyString&&) noexcept;

	MyString& operator+=(char);

	MyString& reverse();

	~MyString();

	char operator[](int) const;

	const char* c_str() const;

	int Size() const;

	int capacity() const;

private:
	char* str;

	int size;

	int free_memory;

	void copy_from(const MyString&);

	void move_from(MyString&);
};

