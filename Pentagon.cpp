#include"Pentagon.h"
#include<iostream>
#include<fstream>


void Pentagon::Read(std::istream& is) {
	for (int i = 0; i < 5; i++) {
		is >> vertices_[i].x >> vertices_[i].y;
	}
}

void Pentagon::Print(std::ostream& os) const{
	os << "Pentagon" << std::endl;
	for (int i = 0; i < 5; i++) {
		os << vertices_[i].x << ' ' << vertices_[i].y << std::endl;
	}
}