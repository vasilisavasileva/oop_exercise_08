#include"Hexagon.h"
#include<iostream>
#include<fstream>


void Hexagon::Read(std::istream& is) {
	for (int i = 0; i < 6; i++) {
		is >> vertices_[i].x >> vertices_[i].y;
	}
}

void Hexagon::Print(std::ostream& os) const {
	os << "Octagon" << std::endl;
	for (int i = 0; i < 6; i++) {
		os << vertices_[i].x << ' ' << vertices_[i].y << std::endl;
	}
}
