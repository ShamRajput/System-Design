#include "DebitCard.hpp"
#include <iostream>

DebitCard::DebitCard(const std::string &inName, const size_t &inNumber):Card(inName,inNumber)
{
    
}

void DebitCard::pay() 
{
    std::cout << "Payment Done by Debit card " << mNumber << " " << mName << "\n";
}