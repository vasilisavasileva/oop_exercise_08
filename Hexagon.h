#pragma once
#include"figure.h"
#include<array>

struct Hexagon : figure {
private:
	std::array<vertex, 6> vertices_;
public:
	void Read(std::istream& is) override;
	void Print(std::ostream& os) const override;

};
