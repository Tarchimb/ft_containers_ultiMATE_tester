#include "../common/other_common.cpp"

std::string testName("is_integral");

int main(void)
{
    INIT_SIGNAL();
	{
		TEST_INIT();
		ofs << "bool: " << CURRENT_NAMESPACE::is_integral<bool>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "char: " << CURRENT_NAMESPACE::is_integral<char>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "signed char: " << CURRENT_NAMESPACE::is_integral<signed char>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "unsigned char: " << CURRENT_NAMESPACE::is_integral<unsigned char>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "wchar_t: " << CURRENT_NAMESPACE::is_integral<wchar_t>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "char16_t: " << CURRENT_NAMESPACE::is_integral<char16_t>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "char32_t: " << CURRENT_NAMESPACE::is_integral<char32_t>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "short: " << CURRENT_NAMESPACE::is_integral<short>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "unsigned short: " << CURRENT_NAMESPACE::is_integral<unsigned short>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "int: " << CURRENT_NAMESPACE::is_integral<int>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "unsigned int: " << CURRENT_NAMESPACE::is_integral<unsigned int>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "long: " << CURRENT_NAMESPACE::is_integral<long>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "unsigned long: " << CURRENT_NAMESPACE::is_integral<unsigned long>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "long long: " << CURRENT_NAMESPACE::is_integral<long long>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "unsigned long long: " << CURRENT_NAMESPACE::is_integral<unsigned long long>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "int128t: " << CURRENT_NAMESPACE::is_integral<__int128_t>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "uint128t: " << CURRENT_NAMESPACE::is_integral<__uint128_t>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "std::string: " << CURRENT_NAMESPACE::is_integral<std::string>::value << std::endl;
	}
	{
		TEST_INIT();
		ofs << "TestStruct: " << CURRENT_NAMESPACE::is_integral<TestStruct>::value << std::endl;
	}

	ofs.close();
}
