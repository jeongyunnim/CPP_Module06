#pragma once
#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include <cstdlib>
#include <sys/time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif