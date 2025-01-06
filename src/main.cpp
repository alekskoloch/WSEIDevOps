#include "DataLoader.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <random>

namespace
{
constexpr auto defaultTableName{ "mountains" };
constexpr auto exampleIndex{ 0 };

constexpr auto endl{ '\n' };

constexpr auto questionMessage{ "What is the height of the mountain: " };
constexpr auto correctMessage{ "Correct!" };
constexpr auto incorrectMessage{ "Incorrect!" };
constexpr auto playAgainMessage{ "Do you want to play again? (y/n)" };
constexpr auto invalidAnswerMessage{ "Invalid answer!" };
constexpr auto correctMessageIsMessage{ "The correct answer is: " };

constexpr auto playAgain{ 'y' };
constexpr auto exitGame{ 'n' };
constexpr auto questionMark{ '?' };

constexpr auto answersCount{ 4 };
constexpr auto optionMark{ ") "};
constexpr auto answerA{ 'a' };
constexpr auto answerB{ 'b' };
constexpr auto answerC{ 'c' };
constexpr auto answerD{ 'd' };
} // namespace

int main( int argc, char* argv[] )
{
    std::string tableName{ defaultTableName };
    if ( argc > 1 )
    {
        std::string argument{ argv[ 1 ] };
        if ( argument == "worldHighestMountains" )
        {
            tableName = "worldHighestMountains";
        }
        else if ( argument == "mountains" )
        {
            tableName = "mountains";
        }
        else
        {
            std::cout << "Unknown argument: " << argument << std::endl;
            throw std::runtime_error( "Unknown table name" );
        }
    }

    DataLoader dataLoader;
    auto mountains = dataLoader.load( tableName );

    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> dis( 0, mountains.size() - 1 );

    bool inGame{ true };
    while ( inGame )
    {
        int index{ dis( gen ) };

        std::cout << questionMessage << mountains.at( index ).name << questionMark << endl;

        std::vector< int > answers;

        answers.push_back( mountains.at( index ).height );

        while ( answers.size() < answersCount )
        {
            int randomIndex{ dis( gen ) };
            if ( randomIndex != index )
            {
                answers.push_back( mountains.at( randomIndex ).height );
            }
        }

        std::shuffle( answers.begin(), answers.end(), gen );

        std::cout << std::string( 1, answerA ) + optionMark << answers.at( 0 ) << endl;
        std::cout << std::string( 1, answerB ) + optionMark << answers.at( 1 ) << endl;
        std::cout << std::string( 1, answerC ) + optionMark << answers.at( 2 ) << endl;
        std::cout << std::string( 1, answerD ) + optionMark << answers.at( 3 ) << endl;

        char playerAnswer;
        std::cin >> playerAnswer;

        auto checkAnswer{ [ & ]( size_t answerIndex )
        {
            if ( answers.at( answerIndex ) == mountains.at( index ).height )
            {
                std::cout << correctMessage << std::endl;
            }
            else
            {
                std::cout << incorrectMessage << std::endl;
                std::cout << correctMessageIsMessage << mountains.at(index).height << std::endl;
            }
        } };

        switch ( playerAnswer )
        {
        case answerA:
            checkAnswer( 0 );
            break;  
        case answerB:
            checkAnswer( 1 );
            break; 
        case answerC:
            checkAnswer( 2 );
            break;
        case answerD:
            checkAnswer( 3 );
            break;
        default:
            std::cout << invalidAnswerMessage << endl;
            break;
        }

        std::cout << playAgainMessage << endl;

        char playAgain;
        std::cin >> playAgain;

        if ( playAgain != ::playAgain )
        {
            inGame = false;
        }
    }

    return EXIT_SUCCESS;
}