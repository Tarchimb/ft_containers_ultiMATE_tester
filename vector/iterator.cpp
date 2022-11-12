#include "../common.cpp"

int test = 1;
std::string testName("iterator");

void test_input_iterator(std::ofstream& ofs);
void test_forward_iterator(std::ofstream& ofs);
void test_bidirectional_iterator(std::ofstream& ofs);
void test_random_access_iterator(std::ofstream& ofs);

void change_ofs_to_next_test(std::ofstream& ofs)
{
	if (ofs.is_open())
		ofs.close();
	open_file(ofs, testName + "_" + std::to_string(test));
	ofs << "the following tests are from file: " << __FILE__ << std::endl;
	test++;
}

int main(int argc, char** argv)
{
	std::ofstream ofs;

	test_input_iterator(ofs);
	test_forward_iterator(ofs);
	test_bidirectional_iterator(ofs);
	test_random_access_iterator(ofs);

	ofs << "--- vector iterator end --- " << std::endl;
	ofs.close();
}

void test_input_iterator(std::ofstream& ofs)
{
	// X b(a)
	// b = a
	// a == b
	// a != b
	// *a
	// ++a
	// a++
	// *a++
	{
		int array_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		typedef typename vector<int>::iterator iterator;
		typedef typename vector<int>::const_iterator const_iterator;

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_int);
			write_result(ofs, *it);
			it++;
			write_result(ofs, *it);
			write_result(ofs, *it++);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it1(array_int);
			iterator it2 = it1;
			write_result(ofs, *it2);
			write_result(ofs, ++(*it2));
			++it2;
			++it2++;
			write_result(ofs, *it2);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_int);
			const_iterator cit1;
			const_iterator cit2(array_int);
			write_result(ofs, *cit2);
			cit2++; write_result(ofs, *cit2);
			const_iterator cit3 = cit2;
			write_result(ofs, *cit3);

			const_iterator cit4 = it;
			write_result(ofs, *cit4);
			const_iterator cit5(it);
			write_result(ofs, *cit5);
		}
	}
	{
		TestStruct array_struct[10];
		for (int i = 0; i < 10; i++)
		{
			array_struct[i].a = i;
			array_struct[i].b = i;
			array_struct[i].c = std::to_string(i);
		}
		typedef typename vector<TestStruct>::iterator iterator;
		typedef typename vector<TestStruct>::const_iterator const_iterator;

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_struct);
			write_result(ofs, *it);
			it++;
			write_result(ofs, *it);
			write_result(ofs, *it++);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it1(array_struct);
			write_result(ofs, *it1);
			it1++;
			write_result(ofs, *it1);
			write_result(ofs, *it1++);
			iterator it2 = it1;
			write_result(ofs, *it2);
			++it2;
			++it2++;
			write_result(ofs, *it2);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_struct);
			const_iterator cit1;
			const_iterator cit2(array_struct);
			write_result(ofs, *cit2);
			cit2++;
			write_result(ofs, *cit2);
			const_iterator cit3 = cit2;
			write_result(ofs, *cit3);

			const_iterator cit4 = it;
			write_result(ofs, *cit4);
			const_iterator cit5(it);
			write_result(ofs, *cit5);
		}
	}
}

void test_forward_iterator(std::ofstream& ofs)
{
	// X a
	// *a = t

	{
		int array_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		typedef typename vector<int>::iterator iterator;
		typedef typename vector<int>::const_iterator const_iterator;

		change_ofs_to_next_test(ofs);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;

		iterator it1;
		const_iterator it2;

		iterator it3(array_int + 4);
		*it3 = 0;
		write_result(ofs, *it3);
		write_result(ofs, array_int[4]);
	}
	{
		typedef typename vector<TestStruct>::iterator iterator;
		typedef typename vector<TestStruct>::const_iterator const_iterator;

		change_ofs_to_next_test(ofs);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;

		iterator it1;
		const_iterator it2;

		TestStruct array_struct[10];
		for (int i = 0; i < 10; i++)
		{
			array_struct[i].a = i;
			array_struct[i].b = i;
			array_struct[i].c = std::to_string(i);
		}

		iterator it3(array_struct + 4);
		TestStruct a;
		it3->a = 42;
		write_result(ofs, *it3);
		write_result(ofs, array_struct[4]);
	}
}

void test_bidirectional_iterator(std::ofstream& ofs)
{
	// --a
	// a--
	// *a--
	{
		int array_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		typedef typename vector<int>::iterator iterator;
		typedef typename vector<int>::const_iterator const_iterator;

		change_ofs_to_next_test(ofs);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;

		iterator it2(array_int + 9);
		write_result(ofs, *it2);
		it2--;
		write_result(ofs, *it2);
		write_result(ofs, *it2--);
		iterator it3 = it2;
		write_result(ofs, *it3);
		write_result(ofs, --(*it3));
		--it3;
		--it3--;
		write_result(ofs, *it3);

		const_iterator cit1;
		const_iterator cit2(array_int + 1);
		write_result(ofs, *cit2);
		cit2--;
		write_result(ofs, *cit2);
		const_iterator cit3 = cit2;
		write_result(ofs, *cit3);

		const_iterator cit4 = it3;
		write_result(ofs, *cit4);
		const_iterator cit5(it3);
		write_result(ofs, *cit5);
	}
	{
		TestStruct array_struct[10];
		for (int i = 0; i < 10; i++)
		{
			array_struct[i].a = i;
			array_struct[i].b = i;
			array_struct[i].c = std::to_string(i);
		}
		typedef typename vector<TestStruct>::iterator iterator;
		typedef typename vector<TestStruct>::const_iterator const_iterator;

		change_ofs_to_next_test(ofs);
		ofs << "the following tests are from file: " << __FILE__ << std::endl;

		iterator it2(array_struct + 9);
		write_result(ofs, *it2);
		it2--;
		write_result(ofs, *it2);
		write_result(ofs, *it2--);
		iterator it3 = it2;
		write_result(ofs, *it3);
		--it3;
		--it3--;
		write_result(ofs, *it3);

		const_iterator cit1;
		const_iterator cit2(array_struct + 1);
		write_result(ofs, *cit2);
		cit2--;
		write_result(ofs, *cit2);
		const_iterator cit3 = cit2;
		write_result(ofs, *cit3);

		const_iterator cit4 = it3;
		write_result(ofs, *cit4);
		const_iterator cit5(it3);
		write_result(ofs, *cit5);
	}
}

void test_random_access_iterator(std::ofstream& ofs)
{
	// a + n
	// n + a
	// a - n
	// a - b
	// a < b
	// a > b
	// a <= b
	// a >= b
	// a += n
	// a -= n
	// a[n]

	{
		int array_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		typedef typename vector<int>::iterator iterator;
		typedef typename vector<int>::const_iterator const_iterator;

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_int);
			ofs << "operator + :" << std::endl;
			it = it + 2; write_result(ofs, *it);
			it = 3 + it; write_result(ofs, *it);
			ofs << "operator - :" << std::endl;
			it = it - 4; write_result(ofs, *it);
			iterator it2(it + 2); write_result(ofs, it2 - it);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_int);
			iterator it2(array_int + 4);
			ofs << "operator < & > :" << std::endl;
			write_result(ofs, it < it2);
			write_result(ofs, it > it2);
			ofs << "operator <= & >= :" << std::endl;
			write_result(ofs, it <= it2);
			write_result(ofs, it >= it2);
			it = it2;
			write_result(ofs, it <= it2);
			write_result(ofs, it >= it2);
		}

		{
			iterator it(array_int);
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			ofs << "operator += :" << std::endl;
			it += 6; write_result(ofs, *it);
			it += -1; write_result(ofs, *it);

			ofs << "operator -= :" << std::endl;
			it -= 3; write_result(ofs, *it);
			it -= -1; write_result(ofs, *it);
		}

	}
	{
		TestStruct array_struct[10];
		for (int i = 0; i < 10; i++)
		{
			array_struct[i].a = i;
			array_struct[i].b = i;
			array_struct[i].c = std::to_string(i);
		}
		typedef typename vector<TestStruct>::iterator iterator;
		typedef typename vector<TestStruct>::const_iterator const_iterator;

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_struct);
			ofs << "operator + :" << std::endl;
			it = it + 2; write_result(ofs, *it);
			it = 3 + it; write_result(ofs, *it);
			ofs << "operator - :" << std::endl;
			it = it - 4; write_result(ofs, *it);
			iterator it2(it + 2); write_result(ofs, it2 - it);
		}

		{
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			iterator it(array_struct);
			iterator it2(array_struct + 4);
			ofs << "operator < & > :" << std::endl;
			write_result(ofs, it < it2);
			write_result(ofs, it > it2);
			ofs << "operator <= & >= :" << std::endl;
			write_result(ofs, it <= it2);
			write_result(ofs, it >= it2);
			it = it2;
			write_result(ofs, it <= it2);
			write_result(ofs, it >= it2);
		}

		{
			iterator it(array_struct);
			change_ofs_to_next_test(ofs);
			ofs << "the following tests are from file: " << __FILE__ << std::endl;
			ofs << "operator += :" << std::endl;
			it += 6; write_result(ofs, *it);
			it += -1; write_result(ofs, *it);

			ofs << "operator -= :" << std::endl;
			it -= 3; write_result(ofs, *it);
			it -= -1; write_result(ofs, *it);
		}

	}
}
