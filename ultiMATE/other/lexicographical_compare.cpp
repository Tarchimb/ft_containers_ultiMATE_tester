//
// Created by Cyril Battistolo on 18/11/2022.
//

#include "../common.cpp"

std::string testName("lexicographical_compare");

bool compare_function (char c1, char c2);

int main(int argc, char** argv)
{
	ofs << std::boolalpha;
	{
		TEST_INIT();
		char foo[] = "Apple";
		char bar[] = "apartment";
		ofs << ft::lexicographical_compare(foo, foo + 3, bar + 3, bar) << std::endl;
	}
	{
		TEST_INIT();
		std::string foo = "heyyyyyy!";
		std::string bar = "heydoooo!";
		ofs << ft::lexicographical_compare(foo.begin(), foo.begin() + 2, bar.begin(), bar.begin() + 2) << std::endl;
	}
	{
		TEST_INIT();
		std::string foo = "heyyyyyy!";
		std::string bar = "heydohey!";
		ofs << ft::lexicographical_compare(foo.begin(), foo.begin() + 3, bar.end() - 4, bar.end()) << std::endl;
	}
	{
		TEST_INIT();
		char foo[] = "Apple";
		char bar[] = "apartment";
		ofs << ft::lexicographical_compare(foo, foo + 3, bar + 3, bar, compare_function) << std::endl;
	}
	{
		TEST_INIT();
		std::string foo = "heyyyyyy!";
		std::string bar = "Heydoooo!";
		ofs << ft::lexicographical_compare(foo.begin(), foo.begin() + 2, bar.begin(), bar.begin() + 2, compare_function) << std::endl;
	}
	ofs.close();
}

bool compare_function (char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}
