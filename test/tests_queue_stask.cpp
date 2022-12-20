#include "Queue_Stack.h"

#include <gtest.h>

//stack_tests

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


//queue_tests

TEST(Queue, can_create_queue) {

	ASSERT_NO_THROW(Queue<int> queue);
}

TEST(Queue, empty_test) {

	Queue<int> queue;
	ASSERT_NO_THROW(queue.empty());
}

TEST(Queue, empty_test_empty) {

	Queue<int> queue;
	EXPECT_EQ(1, queue.empty());
}

TEST(Queue, empty_test_not_empty) {
	Queue<int> queue;
	queue.push(1);
	EXPECT_EQ(0, queue.empty());
}

TEST(Queue, can_push_elements) {

	Queue<int> queue;
	ASSERT_NO_THROW(queue.push(1));
}

TEST(Queue, can_pop_elements) {

	Queue<int> queue;
	queue.push(1);
	ASSERT_NO_THROW(queue.pop());
}

TEST(Queue, can_not_pop_elements_empty) {
	Queue<int> queue;
	ASSERT_ANY_THROW(queue.pop());
}

TEST(Queue, can_top) {

	Queue<int> queue;
	queue.push(5);
	EXPECT_EQ(5, queue.top());
}

TEST(Queue, can_get_size)
{
	Queue<int> queue;
	for (int i = 0; i < 3; i++){
	
		queue.push(i);
	}
	EXPECT_EQ(3, queue.size_q());
}

TEST(Queue, can_resize) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.pop();
	queue.pop();
	queue.push(5);
	queue.push(6);
	queue.push(7);
	queue.push(8);
	queue.push(9);
	EXPECT_EQ(7, queue.size_q());
}

TEST(Queue, can_resize_check) {
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.pop();
	queue.pop();
	queue.push(5);
	queue.push(6);
	queue.push(7);
	queue.push(8);
	queue.push(9);
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
	queue.pop();
	std::cout << queue.top() << std::endl;
}