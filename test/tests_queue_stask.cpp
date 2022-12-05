#include "Queue_Stack.h"

#include <gtest.h>

//тесты на стэк

TEST(Stack, can_create_stack){

	ASSERT_NO_THROW(Stack<int> stack);
}

TEST(Stack, can_get_size) {

	Stack<int> stack;
	stack.push(5);
	stack.push(10);
	EXPECT_EQ(2, stack.size());
}

TEST(Stack, get_size_test) {

	Stack<int> stack;
	EXPECT_EQ(0, stack.size());
}

TEST(Stack, empty_test) {

	Stack<int> stack;
	ASSERT_NO_THROW(stack.empty());
}

TEST(Stack, empty_test_empty){

	Stack<int> stack;
	EXPECT_EQ(1, stack.empty());
}

TEST(Stack, empty_test_not_empty){

	Stack<int> stack;
	stack.push(5);
	stack.push(10);
	EXPECT_EQ(0, stack.empty());
}

TEST(Stack, can_push_elements) {

	Stack<int> stack;
	ASSERT_NO_THROW(stack.push(5));
}

TEST(Stack, can_pop_elements) {

	Stack<int> stack;
	stack.push(5);
	ASSERT_NO_THROW(stack.pop());
}

TEST(Stack, can_not_pop_elements_empty) {

	Stack<int> stack;
	ASSERT_ANY_THROW(stack.pop());
}

TEST(Stack, can_top) {

	Stack<int> stack;
	stack.push(5);
	EXPECT_EQ(5, stack.top());
}