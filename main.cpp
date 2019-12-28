#include<memory>
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<Windows.h>
#include<future>
#include<condition_variable>
#include<string>
#include"figure.h"
#include"Pentagon.h"
#include"Hexagon.h"
#include"Octagon.h"
#include"Factory.h"
#include"Handlers.h"


void handle(std::vector<std::unique_ptr<figure>>& figures, int buffer_size, std::condition_variable& cv_mtx1, std::condition_variable& cv_mtx2, std::mutex& mtx, bool& stop_thrd) {
	std::unique_lock<std::mutex> lock(mtx);
	cv_mtx2.notify_all();
	std::vector<std::unique_ptr<handler>> handlers;

	handlers.push_back(std::make_unique<file_handler>());
	handlers.push_back(std::make_unique<console_handler>());
	while (!(stop_thrd)) {
		cv_mtx1.wait(lock);
		//std::cout << figures.size() << std::endl;
		if (figures.size() != 0) {
			for (int i = 0; i < handlers.size(); ++i) {
				handlers[i]->exec(figures);
			}
		}
		figures.clear();
		cv_mtx2.notify_all();
	}
	return;
}
int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	std::condition_variable cv_mtx1;
	std::condition_variable cv_mtx2;
	std::vector<std::unique_ptr<figure>> figures;
	std::unique_ptr<factory> my_factory;
	std::mutex mtx;
	std::unique_lock<std::mutex> lock(mtx);
	int buffer_size, menu;
	buffer_size = std::stoi(argv[1]);
	bool stop_thrd = false;
	std::thread handler(handle, std::ref(figures), buffer_size, std::ref(cv_mtx1), std::ref(cv_mtx2), ref(mtx), std::ref(stop_thrd));
	cv_mtx2.wait(lock);
	while (true) {
		for (int i = 0; i < buffer_size; ++i) {
			std::cout << "1. Pentagon" << std::endl;
			std::cout << "2. Hexagon" << std::endl;
			std::cout << "3. Octagon" << std::endl;
			std::cin >> menu;
			switch (menu) {
			case 1:
				my_factory = std::make_unique<pentagon_factory>();
				figures.push_back(my_factory->factoring(std::cin));
				break;
			case 2:
				my_factory = std::make_unique<hexagon_factory>();
				figures.push_back(my_factory->factoring(std::cin));
				break;
			case 3:
				my_factory = std::make_unique<octagon_factory>();
				figures.push_back(my_factory->factoring(std::cin));
				break;
			}
		}
		cv_mtx1.notify_all();
		cv_mtx2.wait(lock);
		std::cout << "The buffer is filled" << std::endl;
		std::cout << "Want to create a new one?" << std::endl;
		std::cout << "y for Yes, n for No" << std::endl;
		char choise;
		std::cin >> choise;
		if (choise != 'y')
			break;
	}
	stop_thrd = true;
	cv_mtx1.notify_all();
	lock.unlock();
	handler.join();
	return 0;
}
