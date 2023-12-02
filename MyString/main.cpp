#include "MyString.h"
#include "Other_Func.h"
#include <vector>
#include <algorithm>



int main()
{
	MyString str1("lemon");

	MyString str2("cherry");

	MyString str3("straw");

	MyString str4("berry");

	MyString str5 = str3 + str4;

	MyString str6("ap");

	str6 += "p";

	str6 += "l";

	str6 += "e";

	MyString str7("pineapple");

	MyString str8("ognam");

	str8.reverse();

	MyString str9("mangoline");

	std::vector <MyString> vec{ str1,str2,str5,str6,str7,str8 };

	vec.push_back(str9);

	for (auto& x : vec)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end(), [](const MyString& a, const MyString& b) {return b < a; });

	for (auto& x : vec)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;


	return 0;
}