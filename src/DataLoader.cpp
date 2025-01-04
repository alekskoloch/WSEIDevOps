#include "DataLoader.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace
{
constexpr auto dataFilePath{ "config/data.json" };

constexpr auto pathErrorMessage{ "Failed to open data.json file" };
constexpr auto tableErrorMessage{ "Table not found: "};
}

Mountains DataLoader::load( const std::string& tableName )
{
    std::ifstream file( dataFilePath );
    if ( !file.is_open() )
    {
        throw std::runtime_error( pathErrorMessage );
    }

    nlohmann::json jsonData;
    file >> jsonData;

    Mountains mountains;

    if ( jsonData.contains( tableName ) )
    {
        for ( const auto& item : jsonData[ tableName ] )
        {
            std::string name{ item[ "name" ] };
            unsigned height{ item[ "height" ] };
            mountains.push_back( { name, height } );
        }
    }
    else
    {
        throw std::runtime_error( tableErrorMessage + tableName );
    }

    return mountains;
}
