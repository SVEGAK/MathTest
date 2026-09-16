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