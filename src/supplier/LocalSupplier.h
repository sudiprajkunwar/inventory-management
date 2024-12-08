#ifndef LOCALSUPPLIER_H
#define LOCALSUPPLIER_H

#include "Supplier.h"
#include <string>
#include <iostream>

class Organization; 

class LocalSupplier : public Supplier
{
public:
    LocalSupplier(const std::string &name);
    void notifyRestock(const std::string &productId, int quantity) override;
    void subscribeToOrganization(Organization *org) override;
};

#endif
