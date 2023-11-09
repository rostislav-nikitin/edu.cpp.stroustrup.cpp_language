#ifndef DERIVED_TWO_HPP
#define DERIVED_TWO_HPP

#include <string>

#include "base.hpp"

class derived_two : public base
{
public:
	virtual std::string iam() const override;

};

#endif
