#ifndef PAYMENTMETHOD_HXX
#define PAYMENTMETHOD_HXX

class PaymentMethod
{
public:
    virtual void pay() = 0;
    virtual ~PaymentMethod() = default;
};

#endif