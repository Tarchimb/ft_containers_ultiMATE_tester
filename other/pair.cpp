#include "../common.cpp"

std::string testName("pair");

template <class T, class U>
void test_pair(const T& valT, const U& valU);

template <class T, class U>
void test_pair_constructor(const T& valT, const U& valU);

template <class T, class U>
void test_pair_equal(const T& valT, const U& valU);

template <class T, class U>
void test_pair_operator(const T& valT, const U& valU);

int main(void)
{
	test_pair<int, int>(1, 2);
	test_pair<double, float>(4.00001, 3.14f);
	test_pair<TestStruct, char>(TestStruct(1, 2, "3"), 'd');

	ofs.close();
}

template <class T, class U>
void test_pair(const T& valT, const U& valU)
{
	test_pair_constructor(valT, valU);
	test_pair_equal(valT, valU);
	test_pair_operator(valT, valU);
}

template <class T, class U>
void test_pair_constructor(const T& valT, const U& valU)
{
	{ // Default constructor
		TEST_INIT();
		CURRENT_NAMESPACE::pair<T, U> p;
		write_result(ofs, p);
	}
	{ // Copy constructor
		TEST_INIT();
		CURRENT_NAMESPACE::pair<T, U> p0;
		p0.first = valT; p0.second = valU;
		write_result(ofs, p0);
		CURRENT_NAMESPACE::pair<T, U> p1(p0);
		write_result(ofs, p1);
		CURRENT_NAMESPACE::pair<T, U> p2 = p0;
		write_result(ofs, p2);
	}
	{ // Initialization constructor
		TEST_INIT();
		CURRENT_NAMESPACE::pair<T, U> p(valT, valU);
		write_result(ofs, p);
	}
}

template <class T, class U>
void test_pair_equal(const T& valT, const U& valU)
{
	{ // Operator equal
		TEST_INIT();
		CURRENT_NAMESPACE::pair<T, U> p0(valT, valU);
		write_result(ofs, p0);
		CURRENT_NAMESPACE::pair<T, U> p1;
		p1 = p0;
		write_result(ofs, p1);
		p0.first = p0.first * 2;
		p0.second = p0.second * 2;
		CURRENT_NAMESPACE::pair<T, U> p2;
		p2 = p0;
		write_result(ofs, p0);
		write_result(ofs, p2);
	}
}

template <class T, class U>
void test_pair_operator(const T& valT, const U& valU)
{
	CURRENT_NAMESPACE::pair<T, U> low;
	CURRENT_NAMESPACE::pair<T, U> mid(low.first * 2, low.second * 2);

	{ // equal & different
		TEST_INIT();
		write_result(ofs, (low == mid));
		write_result(ofs, (low == low));
		write_result(ofs, (low != mid));
		write_result(ofs, (low != low));
	}
	{ // less & less (or equal
		write_result(ofs, (low < mid));
		write_result(ofs, (low < low));
		write_result(ofs, (low <= mid));
		write_result(ofs, (low <= low));
	}
	{ // greather & g(reater or equal
		TEST_INIT();
		write_result(ofs, (low > mid));
		write_result(ofs, (low > low));
		write_result(ofs, (low >= mid));
		write_result(ofs, (low >= low));
	}
}
