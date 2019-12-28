#pragma once
#include"figure.h"
#include<array>

struct Pentagon : figure {
private:
	std::array<vertex, 5> vertices_;
public:
	void Read(std::istream& is) override;
	void Print(std::ostream& os) const override;

};