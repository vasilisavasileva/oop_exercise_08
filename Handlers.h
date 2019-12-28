#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"figure.h"


struct handler {
	virtual void exec(std::vector<std::unique_ptr<figure>>& figures) = 0;
	virtual ~handler() = default;
};

struct file_handler : handler {
	void exec(std::vector<std::unique_ptr<figure>>& figures) override {
		static int count_file = 0;
		std::string filename = "";
		++count_file;

		filename = "file_" + std::to_string(count_file) + ".txt";
		std::ofstream file(filename);
		for (int i = 0; i < figures.size(); ++i) {
			figures[i]->Print(file);
		}
	}
};
struct console_handler : handler {
	void exec(std::vector<std::unique_ptr<figure>>& figures) override {
		for (int i = 0; i < figures.size(); ++i) {
			figures[i]->Print(std::cout);
		}
	}
};
