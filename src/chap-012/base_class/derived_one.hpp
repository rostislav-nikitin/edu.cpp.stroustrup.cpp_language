#ifndef DERIVED_ONE_HPP
#define DERIVED_ONE_HPP

#include <string>

#include "base.hpp"

class derived_one : public base
{
public:
	virtual std::string iam() const override;

};

#endif
