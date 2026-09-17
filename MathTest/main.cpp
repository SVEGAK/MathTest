#include <iostream>
#include "main.h"
#include <string>
Task::Task() {
	srand(time(0));
	num_1 = rand();
	num_2 = rand();
	op = Operations(rand() % 4);
	answer = get_answer(num_1, num_2, op);
}
Task::Task(int min, int max, Operations operation) {
	srand(time(0));
	if (min > max) {std::swap(min,max);}
	num_1 = rand() % (max - min+1)+min;
	num_2 = rand() % (max - min+1)+min;
	op = operation;
	answer = get_answer(num_1, num_2, op);
}
MathTest::MathTest(int count){
	if (count <= 0) { throw std::invalid_argument("Tasks count can't be lower then zero."); }
	_count = count;
	_correct_count = 0;
	_user_answers = new int[count];
	_tasks = new Task[count];

}

MathTest::MathTest(int count, int min, int max) : MathTest(count, min, max, op_random){}

MathTest::MathTest(int count, int min, int max, Operations operation)
{
	if (count <= 0) { throw std::invalid_argument("Tasks count can't be lower then zero."); }
	_count = count;
	_correct_count = 0;
	_user_answers = new int[count];
	_tasks = new Task[count];
	for (int i = 0; i < count; i++) {
		_tasks[i] = Task(min, max, operation);
	}
}
 Task Task::exact(int n1, int n2, Operations operation) {
	 Task t; // Создаем объект (можно использовать любой существующий конструктор)
	 t.num_1 = n1;
	 t.num_2 = n2;
	 t.op = operation;
	 t.answer = get_answer(n1, n2, operation);
	 return t;
 }

MathTest::~MathTest()
{
	delete[] _user_answers;
	delete[] _tasks;
}
void MathTest::insert_answer(size_t num)
{
	std::cin >> _user_answers[num];
}

void MathTest::output_cur_task(size_t number)
{
	std::cout << "  " <<   _tasks[number].num_1;
	switch (_tasks[number].op) {
	case(op_add):
		std::cout << " + ";
		break;
	case(op_divide):
		std::cout << " / ";
		break;
	case(op_subtract):
		std::cout << " - ";
		break;
	case(op_multiplicate):
		std::cout << " * ";
		break;
	}
	std::cout << _tasks[number].num_2 << " |";

}

void MathTest::insert_answer_message(int i)
{
	std::cout << "\nQuestion n" << i << "\nInsert answer : ";
}

void MathTest::set_current_task(size_t num, Task cur_task)
{
	_tasks[num] = cur_task;
}


void MathTest::run()
{
	for (size_t i = 0;i < _count;i++) {
		//system("cls");
		(*this).output_cur_task(i);
		insert_answer_message(i);
		insert_answer(i);
		if (_user_answers[i] == _tasks[i].answer){
			_correct_count++;
		}
	}
	show_statistics();
}

void MathTest::show_statistics()
{
	std::cout << "\n|           No |";
	for (size_t i = 1; i < (_count+1);i++) {
		std::cout << "         " << i << " |";
	}
	std::cout << "\n+" << std::string((14 + (12 * _count)), '-') << "+";
	std::cout << "\n|  Question    |";
	for (size_t i = 0;i < _count; i++) {
		(*this).output_cur_task(i);
	}
	std::cout << "\n|  True Answer |";
	for (size_t i = 0;i < _count; i++) {
		std::cout << "       " << _tasks[i].answer << " |";
	}
	std::cout << "\n|  Your Answer |";
	for (size_t i = 0;i < _count; i++) {
		std::cout << "       " << _user_answers[i] << " |";
	}
	std::cout << "\n|       Result |";
	for (size_t i = 0;i < _count; i++) {
		std::cout << "       ";
		if (_user_answers[i] == _tasks[i].answer) {
			std::cout << "+ ";
		
		}
		else { std::cout << "-"; }
		std::cout << " |";
	}
	std::cout << "\n\nTotal Result : " << _correct_count << " / " << _count << "(mark : ";
	float mark = (static_cast<float>(_correct_count) / _count) * 100;
	if     (mark > 90){ std::cout << "A"; }
	else if(mark >= 75) { std::cout << "B"; }
	else if(mark > 50 ) { std::cout << "C"; }
	else if (mark > 35) { std::cout << "D"; }
	else if (mark > 15) { std::cout << "E"; }
					else{ std::cout << "F"; }
	std::cout << " )";
}
