#include "../common/vector_common.cpp"
// #include <stdexcept>
// #include <string>

std::string testName("random");

int main(void)
{
    INIT_SIGNAL();
    { // Test basic functions
		TEST_INIT();
		CURRENT_NAMESPACE::vector<std::string> v;
		
		for (int i = 0; i < 15; i++)
		{
			v.insert(v.end(), std::to_string(i));
		}
		write_result(ofs, v);

		v.insert(v.begin(), v.begin(), v.end());
		write_result(ofs, v);
		write_result(ofs, v[5]);
		write_result(ofs, v.at(5));

		CURRENT_NAMESPACE::vector<std::string>::iterator it = v.erase(v.end() - 1);
        if (it == v.end()) {
            write_result(ofs, "End");
        }
		write_result(ofs, v);
		
		v.clear();
		write_result(ofs, v);

		v.clear();
		write_result(ofs, v);

		v.clear();
		write_result(ofs, v);

		v.insert(v.end(), "MATE");
		write_result(ofs, v);
	}
	{ // Test pop_back
		TEST_INIT();

		CURRENT_NAMESPACE::vector<int> v;
		for (int i = 0; i < 15; i++)
		{
			v.push_back(i);
		}	
		write_result(ofs, v);

		v.pop_back();
		write_result(ofs, v);

		for (int i = 0; i < 4; i++)
		{
			v.pop_back();
		}
		write_result(ofs, v);

        for (CURRENT_NAMESPACE::vector<int>::const_reverse_iterator crit = v.rbegin(); crit != v.rend(); ++crit) {
            write_result(ofs, *crit);
        }
	}
	{ // Test basic functions
		TEST_INIT();

		CURRENT_NAMESPACE::vector<int> v;
		for (int i = 0; i < 15; i++)
		{
			v.push_back(i);
		}	
		write_result(ofs, v);

		CURRENT_NAMESPACE::vector<int>::iterator it = v.insert(v.begin(), 123);
		write_result(ofs, *it);
		write_result(ofs, v.front());
		write_result(ofs, v.back());
		write_result(ofs, v.empty() == true);
		
		v.clear();
		write_result(ofs, v);

		v.resize(50, 2);
		write_result(ofs, v);

		v.assign(11, 4);
		write_result(ofs, v);

		v.erase(v.begin(), v.begin() + 10);
		write_result(ofs, v);

		v.assign(v.begin() + 2, v.begin() + 6);
		write_result(ofs, v);
	}
	{ // Test comparisons
		TEST_INIT();

		CURRENT_NAMESPACE::vector<TestStruct> v;
		CURRENT_NAMESPACE::vector<TestStruct> v1;

		v.assign(10, TestStruct(10, 12, "a"));
		write_result(ofs, v == v1);
		write_result(ofs, v != v1);
		write_result(ofs, v > v1);
		write_result(ofs, v < v1);
		write_result(ofs, v >= v1);
		write_result(ofs, v <= v1);
	}
	{// Test exception for at
		TEST_INIT();

		CURRENT_NAMESPACE::vector<TestStruct> v;

		v.assign(10, TestStruct(10, 12, "a"));

		try {
			try {
				write_result(ofs, v.at(24));
			} catch (std::out_of_range &e) {
				write_result(ofs, "OUT OF RANGE");
			}
		} catch (...) {
			write_result(ofs, "UNHANDLED EXCEPTION");
		}

	}
}
