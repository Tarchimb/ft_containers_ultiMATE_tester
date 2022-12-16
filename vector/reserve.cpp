#include "../common/vector_common.cpp"

std::string testName = "reserve";

template <typename T>
void test_for_type(std::ofstream& ofs, CURRENT_NAMESPACE::vector<T>& vector1);

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
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v;
			v.reserve(5);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			exit(0);
		}
	}
	{ // reserve higher then lower
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v;
			v.reserve(5);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			v.reserve(2);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			exit(0);
		}
	}
	{ // invalid reserve
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v;
			try { v.reserve(-2); }
			catch (std::exception& e) { write_result(ofs, "throw on invalid reserve"); }
			exit(0);
		}
	}
	{ // reserve 0
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v;
			v.reserve(0);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			exit(0);
		}
	}
	{ // reserve lower then higher
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v;
			v.reserve(10);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			v.reserve(100);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			exit(0);
		}
	}
	{ // reserve lower with existing values
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v(10, T());
			v.reserve(5);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			write_result(ofs, v);
			exit(0);
		}
	}
	{ // reserve higher with existing values
		TEST_INIT()
		{
			CURRENT_NAMESPACE::vector<T> v(10, T());
			v.reserve(30);
			write_result<typename CURRENT_NAMESPACE::vector<T>::difference_type>(ofs, v.capacity());
			write_result(ofs, v);
			exit(0);
		}
	}
}
