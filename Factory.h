#pragma once
#include<iostream>
#include"figure.h"
#include"Pentagon.h"
#include"Hexagon.h"
#include"Octagon.h"
#include<memory>

struct factory {
public:
	virtual std::unique_ptr<figure> factoring(std::istream& is) = 0;
	virtual ~factory() = default;
};

struct pentagon_factory : factory{
	std::unique_ptr<figure> factoring(std::istream& is) override {
		std::unique_ptr<Pentagon> t_pent;
		t_pent = std::make_unique<Pentagon>();
		t_pent->Read(is);
		return std::move(t_pent);
	}
};

struct hexagon_factory : factory {
	std::unique_ptr<figure> factoring(std::istream& is) override {
		std::unique_ptr<Hexagon> t_hex;
		t_hex = std::make_unique<Hexagon>();
		t_hex->Read(is);
		return std::move(t_hex);
	}
};

struct octagon_factory : factory {
	std::unique_ptr<figure> factoring(std::istream& is) override {
		std::unique_ptr<Octagon> t_oct;
		t_oct = std::make_unique<Octagon>();
		t_oct->Read(is);
		return std::move(t_oct);
	}
};