/*
Name: exp-producer-consumer-semaphores.cpp
Copyright:
Author: DINGPENG
Date: 11/10/17 11:27
Description:
- 操作系统-生产者消费者问题模拟
- 模拟纪录型信号量解决方案
- 可以通过调整producer()和consumer()中Sleep()的时间，
  来调节生产者和消费者的速度，从而看到不同的实验现象
Environment: DEV C++ (TDM-GCC-4.9.2)
*/

#include <iostream>
#include <cstdlib>		//srand() rand()
#include <ctime>		//time()
#include <Windows.h>	//createThread() Sleep()

#define n 10

int in = 0, out = 0;
int buffer[n]; //定义缓冲区
int mutex = 1, full = 0, empty = n; //定义信号量

void wait(int &s) {
	while (s <= 0);
	s--;
}

void signal(int &s) {
	s++;
}

DWORD WINAPI producer(LPVOID lpParameter) {
	while (true) {
		int nextp;
		//生产者生产产品
		srand(time(NULL));
		nextp = 10 + rand() % 90;
		Sleep(2000);
		std::cout << "\n@@@ 生产者生产产品" << nextp << "\n";
		if (!empty) std::cout << "\n!!!缓冲区已满\n";
		//等待缓冲区非满
		wait(empty);
		//向缓冲区放入产品
		wait(mutex);
		buffer[in] = nextp;
		in = (in + 1) % n;
		std::cout << "\n+++ 缓冲区放入产品" << nextp << "\n";
		signal(mutex);
		signal(full);
	}
}

DWORD WINAPI consumer(LPVOID lpParameter) {
	while (true) {
		int nextc;
		if (!full) std::cout << "\n!!!缓冲区为空\n";
		//等待缓冲区非空
		wait(full);
		//从缓冲区取出产品
		wait(mutex);
		nextc = buffer[out];
		std::cout << "\n--- 缓冲区取出产品" << nextc << "\n";
		out = (out + 1) % n;
		signal(mutex);
		signal(empty);
		//消费者消费产品
		Sleep(4000);
		std::cout << "\n$$$ 消费者消费产品" << nextc << "\n";
	}
}

int main() {
	HANDLE thread1, thread2;
	thread1 = CreateThread(NULL, 0, producer, NULL, 0, NULL); //创建生产者进程
	thread2 = CreateThread(NULL, 0, consumer, NULL, 0, NULL); //创建消费者进程
	while (1); //让两个线程持续运行
	return 0;
}
