#include "../common.cpp"

std::string testName("insert");
std::ofstream ofs;

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

template <typename T>
void test_insert_single_value(const T& value); // const iterator, const T&
template <typename T>
void test_insert_multiple_value(const T& value); // const iterator, size_type,  const T&
template <typename T>
void test_insert_range(vector<T>& v); // const iterator, inputIt, inputIt

int main(int argc, char** argv)
{
	test_insert_single_value<int>(1);
	test_insert_single_value<TestStruct>(TestStruct(42, 10, "test"));


	test_insert_multiple_value<int>(1);
	test_insert_multiple_value<TestStruct>(TestStruct(42, 10, "test"));


	vector<int> v1;
	for (int i = 0; i < 20; i++) v1.push_back(i);
	test_insert_range<int>(v1);

	vector<TestStruct> v3;
	for (int i = 0; i < 20; i++) v3.push_back(TestStruct(i, i, std::string(std::to_string(i))));
	test_insert_range<TestStruct>(v3);

	ofs.close();
}

template <typename T>
void test_insert_single_value(const T& value)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;
	{ // insert value at beginning
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, value);
		write_result(ofs, v1);
	}
	{ // insert value in middle
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		const_iterator cit = v1.end() - 5;
		v1.insert(cit, value * 2);
		write_result(ofs, v1);
	}
	{ // insert value with empty vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1;
		v1.clear();
		iterator it = v1.begin();
		v1.insert(it, value * 4);
		write_result(ofs, v1);
	}
	{ // insert value at end
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.end();
		v1.insert(it, value * 8);
		write_result(ofs, v1);
	}
	{ // insert value from vector itself
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, *it);
		write_result(ofs, v1);
	}
	{ // insert value from vector itself multiple times
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, *it);
		it = v1.begin();
		v1.insert(it, *it);
		it = v1.begin();
		v1.insert(it, *it);
		it = v1.begin();
		v1.insert(it, *it);
		it = v1.begin();
		v1.insert(it, *it);
		write_result(ofs, v1);
	}
}

template <typename T>
void test_insert_multiple_value(const T& value)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;
	{ // insert multiple values at vector beginning
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, 5, value);
		write_result(ofs, v1);
	}
	{ // insert multiple values in middle
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		const_iterator cit = v1.end() - 5;
		v1.insert(cit, 30, value * 2);
		write_result(ofs, v1);
	}
	{ // insert multiple values with empty vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		v1.clear();
		iterator it = v1.begin();
		v1.insert(it, 10, value * 4);
		write_result(ofs, v1);
	}
	{ // insert multiple values at vector end
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.end();
		v1.insert(it, 2, value * 8);
		write_result(ofs, v1);
	}
	{ // insert multiple values from vector itself
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, 5, *it);
		write_result(ofs, v1);
	}
	{ // insert multiple values from vector itself multiple times
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(20, T());
		iterator it = v1.begin();
		v1.insert(it, 5, *it);
		it = v1.begin();
		v1.insert(it, 4, *it);
		it = v1.begin();
		v1.insert(it, 3, *it);
		it = v1.begin();
		v1.insert(it, 2, *it);
		write_result(ofs, v1);
	}
}

template <typename T>
void test_insert_range(vector<T>& v)
{
	typedef typename vector<T>::iterator iterator;
	typedef typename vector<T>::const_iterator const_iterator;

	const_iterator vBegin = v.begin();
	const_iterator vEnd = v.end();

	{ // insert range from another vector at the beginning
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		iterator it = v1.begin();
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert range from another vector in the middle
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		const_iterator cit = v1.end() - 5;
		v1.insert(cit, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert range from another vector with modified range in empty vector
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vBegin += v.size() / 4;
		vEnd -= v.size() / 4;
		vector<T> v1;
		v1.clear();
		iterator it = v1.begin();
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert range from vector itself to beginning
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		vBegin = v1.begin();
		vEnd = v1.end();
		iterator it = v1.begin();
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert range from vector itself in the middle
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		vBegin = v1.begin();
		vEnd = v1.end();
		iterator it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert range from vector itself in the middle multiple times
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		vBegin = v1.begin();
		vEnd = v1.end();
		iterator it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		vBegin = v1.begin();
		vEnd = v1.end();
		it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		vBegin = v1.begin();
		vEnd = v1.end();
		it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		vBegin = v1.begin();
		vEnd = v1.end();
		it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		vBegin = v1.begin();
		vEnd = v1.end();
		it = v1.begin() + 5;
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
	{ // insert from large range
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v1(10, T());
		vector<T> v2(10000, T());
		vBegin = v2.begin();
		vEnd = v2.end();
		iterator it = v1.begin();
		v1.insert(it, vBegin, vEnd);
		write_result(ofs, v1);
	}
}
