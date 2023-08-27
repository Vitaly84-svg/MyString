#pragma once
#include <iostream>
#include "MyString.h"


int lenght(const char*);

std::ostream& operator<<(std::ostream&, const MyString&);

bool operator==(const MyString&, const MyString&);

bool operator!=(const MyString&, const MyString&);

bool operator<(const MyString&, const MyString&);

const char* begin(MyString&);

const char* end(MyString&);

MyString& operator+=(MyString&, const MyString&);

MyString operator+(const MyString&, const MyString&);