//============================================================================
// Name        : SimpleMutexExample.cpp
// Author      : TaneriMan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//This code written in Eclipse 2020/6 in mac. Do not forget to put this project your Eclipse Workspace
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
 *This example for race condition.
amount can be 0, 1, 2, 3, 4 or 5 because threads enter the critical section and
increment the value at the same time. This is Race Condition.
*/

int amountWithoutMutex = 0;
int amountWithMutex = 0;
std::mutex m; //mutex

void addAmountWithoutMutex()
{
	++amountWithoutMutex; //Critical Section
}

void addAmountWithMutex()
{
	m.lock(); //one thread enters others cannot
	++amountWithMutex; //Critical Section
	m.unlock(); //another one can enter
}

int main() {
	std::thread t1(addAmountWithoutMutex);
	std::thread t2(addAmountWithoutMutex);
	std::thread t3(addAmountWithoutMutex);
	std::thread t4(addAmountWithoutMutex);
	std::thread t5(addAmountWithoutMutex);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	cout << "amount without mutex: " << amountWithoutMutex << endl;

	/*This problem can be solved by MUTEX. Mutex doesn't give permission
	thread which want to enter critical section, it waits until unlock(). Here the modified code with
	mutex for threads. Every time the amount is 5. There is not Race Condition
	*/
	std::thread t6(addAmountWithMutex);
	std::thread t7(addAmountWithMutex);
	std::thread t8(addAmountWithMutex);
	std::thread t9(addAmountWithMutex);
	std::thread t10(addAmountWithMutex);
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	cout << "amount with mutex: " << amountWithMutex << endl;
	return 0;
}




