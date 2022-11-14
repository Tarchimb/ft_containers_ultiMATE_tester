#include "../common.cpp"

std::string testName = "reserve";
std::ofstream ofs;

template <typename T>
void test_for_type(std::ofstream& ofs, vector<T>& vector1);

template <typename T>
void test_for_type();

int main(int argc, char** argv)
{

	test_for_type<int>();
	test_for_type<TestStruct>();

	ofs.close();
}

template <typename T>
void test_for_type()
{
	{ // reserve classic
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(5);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
	}
	{ // reserve higher then lower
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(5);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
		v.reserve(2);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
	}
	{ // invalid reserve
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		try { v.reserve(-2); }
		catch (std::exception& e) { write_result(ofs, "throw on invalid reserve"); }
	}
	{ // reserve 0
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(0);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
	}
	{ // reserve lower then higher
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v;
		v.reserve(10);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
		v.reserve(100);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
	}
	{ // reserve lower with existing values
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, T());
		v.reserve(5);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
		write_result(ofs, v);
	}
	{ // reserve higher with existing values
		change_ofs_to_next_test(ofs, testName);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;
		ofs << "test on line: " << __LINE__ << std::endl;
		vector<T> v(10, T());
		v.reserve(30);
		write_result<typename vector<T>::difference_type>(ofs, v.capacity());
		write_result(ofs, v);
	}
}
