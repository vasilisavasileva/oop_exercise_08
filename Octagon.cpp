#include"Octagon.h"
#include<iostream>
#include<fstream>


void Octagon::Read(std::istream& is) {
	for (int i = 0; i < 8; i++) {
		is >> vertices_[i].x >> vertices_[i].y;
	}
}

void Octagon::Print(std::ostream& os) const {
	os << "Octagon" << std::endl;
	for (int i = 0; i < 8; i++) {
		os << vertices_[i].x << ' ' << vertices_[i].y << std::endl;
	}
}
