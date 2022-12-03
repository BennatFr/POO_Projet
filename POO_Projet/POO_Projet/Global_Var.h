#pragma once
#include "Connection_DB.h"

#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

bool is_number(const std::string& s);
namespace EnumVar {

	enum type_Seach { COMMAND, PERSONNEL, CLIENT, STOCK, STATS, FACTURE };
};

#endif