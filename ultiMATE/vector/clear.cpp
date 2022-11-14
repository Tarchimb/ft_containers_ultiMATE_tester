#include "../common.cpp"

std::string testName("clear");
std::ofstream ofs;

template <typename T>
void test_for_type(vector<T>& vector1, const T& value);

int main(int argc, char** argv)
{
	vector<int> v1(10, 0);
	test_for_type<int>(v1, 1);

	vector<double> v2(50, 42.424242f);
	test_for_type<double>(v2, 1);

	vector<TestStruct> v3(100, TestStruct(10, 42, "test"));
	test_for_type<TestStruct>(v3, TestStruct(1, 1, "1"));


	ofs.close();
}

template <typename T>
void test_for_type(vector<T>& vector1, const T& value)
{
	{ // clear empty vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.clear();
		write_result(ofs, v);
	}
	{ // clear filled vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.clear();
		write_result(ofs, v);
	}
	{ // clear filled vector then re-assign it
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.clear();
		v.assign(vector1.begin(), vector1.end());
		write_result(ofs, v);
	}
	{ // clear vector multiple times
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.clear();
		v.clear();
		v.clear();
		write_result(ofs, v);
	}
	{ // clear vector, reserve then re-clear
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.clear();
		v.reserve(20);
		v.clear();
		write_result(ofs, v);
	}
	{ // checking iterators validity
		typedef typename vector<T>::iterator iterator;
		change_ofs_to_next_test(ofs, testName);
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		iterator it1 = v.begin();
		iterator it2 = v.end();
		v.clear();
		write_result(ofs, v);
		write_result(ofs, it1 == v.begin());
		write_result(ofs, it2 == v.end());
	}
}

