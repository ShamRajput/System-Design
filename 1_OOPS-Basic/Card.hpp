
#ifndef OOPS_BASIC_CARD_HXX
#define OOPS_BASIC_CARD_HXX

#include <string>
class Card
{
protected:
    std::string mName;
    size_t mNumber;    
public:
    Card(const std::string& inName, const size_t& inNumber );
    virtual ~Card() = default;
};
#endif