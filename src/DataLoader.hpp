#pragma once

#include "Mountain.hpp"

#include <nlohmann/json.hpp>

#include <string>
#include <vector>

using Mountains = std::vector< Mountain >;

class DataLoader
{
public:
    Mountains load( const std::string& tableName );
};