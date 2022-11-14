#include "../common.cpp"

std::string testName("assign");
std::ofstream ofs;

template <typename T>
void test_for_type(const T& value);

template <typename T>
void test_assign_fill_version(const T& value);

template <typename T>
void test_assign_range_version(vector<T>& v);

int main(int argc, char** argv)
{
	test_for_type<int>(10);
	test_for_type<TestStruct>(TestStruct(42, 10, "crampon"));
}

template <typename T>
void test_for_type(const T& value)
{
	test_assign_fill_version<T>(value);

	vector <T> v(10, value);
	test_assign_range_version<T>(v);
}

template <typename T>
void test_assign_fill_version(const T& value)
{
	{ // simple assign
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.assign(5, value);
		write_result(ofs, v);
	}
	{ // assign with count = 0
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.assign(0, value);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.assign(10, value * 2);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector + new size lower
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.assign(5, value * 2);
		write_result(ofs, v);
	}
	{ // Assign with existing values in vector + new size greater
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, value);
		v.assign(20, value * 2);
		write_result(ofs, v);
	}
}

template <typename T>
void test_assign_range_version(vector<T>& v)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	{ // Assign with vector iterators
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> vector;
		vector.assign(v.begin(), v.end());
		write_result(ofs, vector);
	}
	{ // Assign with vector const iterator 
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> vector;
		vector.assign(v.cbegin(), v.cend());
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators and modified range
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> vector;
		vector.assign(v.begin() + v.size() / 4, v.end() - v.size() / 4);
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators which are both equal
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		const_iterator cit = v.begin() + 2;
		vector<T> vector;
		vector.assign(cit, cit);
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators and existing values
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> vector(5, v[0] * 2);
		vector.assign(v.begin(), v.end());
		write_result(ofs, vector);
	}
	{ // Assign with vector iterators (modified range)  and existing values
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> vector(5, v[0] * 2);
		vector.assign(v.begin() + v.size() / 4, v.end() - v.size() / 4);
		write_result(ofs, vector);
	}

}
