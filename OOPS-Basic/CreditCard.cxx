#include "CreditCard.hpp"
#include <iostream>

CreditCard::CreditCard(const std::string &inName, const size_t &inNumber):Card(inName,inNumber)
{

}

void CreditCard::pay() 
{
    std::cout << "Payment Done by Credit card " << mNumber << " " << mName << "\n";
}