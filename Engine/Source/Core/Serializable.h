#pragma once
#include "Json.h"

class Seriallizable {
public:
	virtual ~Seriallizable() = default;

	virtual void Read(const json_t& value) = 0;
	virtual void Write(json_t& value) = 0;
};