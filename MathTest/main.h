#pragma once
#include <random>
enum Operations {op_add,op_subtract,op_multiplicate,op_divide,op_random };
struct Task {
	int num_1;
	int num_2;
	int answer;
	Operations op;
	Task();
	Task(int min, int max, Operations op);
};
class MathTest;
int get_answer(int min, int max, Operations op) {
	if (min > max) {
		int buff = max;
		max = min;
		min = buff;
	}
	if (op == op_random) { op = Operations(rand() % 4); }
	switch (op) {
		case op_add:
			return min + max;
		case op_subtract:
			return max - min;
		case op_multiplicate:
			return min * max;
		case op_divide:
			return max / min;
	}
}