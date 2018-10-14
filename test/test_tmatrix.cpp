
#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> mt1(5);
	mt1[1][1] = 1;
	TMatrix<int> mt2(mt1);
	EXPECT_EQ(mt1, mt2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> mt1(5);
	mt1[1][1] = 1;
	TMatrix<int> mt2(mt1);
	EXPECT_NE(&mt1[1][1], &mt2[1][1]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> mt1(5);
	EXPECT_EQ(5, mt1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> mt1(5);
	mt1[1][1] = 1;
	EXPECT_EQ(1, mt1[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt1(5);
	ASSERT_ANY_THROW(mt1[-1][1] = -1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mt1(5);
	ASSERT_ANY_THROW(mt1[10][10] = -1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt1(5);
	mt1[1][1] = 1;
	ASSERT_NO_THROW(mt1 = mt1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(5);
	mt1[1][1] = 1;
	mt2 = mt1;
	EXPECT_EQ(mt1, mt2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(10);
	mt1[1][1] = 1;
	mt2 = mt1;
	EXPECT_EQ(5, mt2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(10);
	mt1[1][1] = 1;
	mt2 = mt1;
	EXPECT_EQ(mt1, mt2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(5);
	mt1[1][1] = 1;
	mt2 = mt1;
	EXPECT_TRUE(mt1 == mt2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mt1(5);
	EXPECT_TRUE(mt1 == mt1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(10);
	EXPECT_FALSE(mt1 == mt2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(5);
	TMatrix<int> mt3(5);
	mt1[1][1] = 1;
	mt2[1][1] = 1;
	mt3[1][1] = 2;
	EXPECT_EQ(mt3, mt1 + mt2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(10);
	mt1[1][1] = 1;
	mt2[1][1] = 1;
	ASSERT_ANY_THROW(mt1 + mt2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(5);
	TMatrix<int> mt3(5);
	mt1[1][1] = 1;
	mt2[1][1] = 1;
	mt3[1][1] = 0;
	EXPECT_EQ(mt3, mt1 - mt2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt1(5);
	TMatrix<int> mt2(10);
	mt1[1][1] = 1;
	mt2[1][1] = 1;
	ASSERT_ANY_THROW(mt1 - mt2);
}
