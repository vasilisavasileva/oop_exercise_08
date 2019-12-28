#pragma once
#include<iostream>

struct figure {
	virtual void Read(std::istream& is) = 0;
	virtual void Print(std::ostream& os) const = 0;
	virtual ~figure() = default;
};

struct vertex {
	int x, y;
};