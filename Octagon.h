#pragma once
#include"figure.h"
#include<array>

struct Octagon : figure {
private:
	std::array<vertex, 8> vertices_;
public:
	void Read(std::istream& is) override;
	void Print(std::ostream& os) const override;

};
