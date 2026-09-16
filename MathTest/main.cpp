#include <iostream>
#include "main.h"
Task::Task() {
	srand(time(0));
	num_1 = rand();
	num_2 = rand();
	op = Operations(rand() % 4);
	answer = get_answer(num_1, num_2, op);
}
Task::Task(int min, int max, Operations operation) {
	srand(time(0));
	num_1 = rand() % (max - min+1);
	num_2 = rand() % (max - min+1);
	op = operation;
	answer = get_answer(min, max, op);
}
MathTest::MathTest(int count){
	if (count <= 0) { throw std::invalid_argument("Tasks count can't be lower then zero."); }
	_count = count;
	_correct_count = 0;
	_user_answers = new int[count];
	_tasks = new Task[count];

}

MathTest::MathTest(int count, int min, int max) : MathTest(count, min, max, op_random){}

MathTest::MathTest(int count, int min, int max, Operations op)
{
	if (count <= 0) { throw std::invalid_argument("Tasks count can't be lower then zero."); }
	_count = count;
	_correct_count = 0;
	_user_answers = new int[count];
	_tasks = new Task[count];
	for (int i = 0; i < count; i++) {
		_tasks[i] = Task(min, max, op);
	}
}

MathTest::~MathTest()
{
	delete[] _user_answers;
	delete[] _tasks;
}

void MathTest::run()
{
}

void MathTest::show_statistics()
{
}
