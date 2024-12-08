#ifndef GLOBALSUPPLIER_H
#define GLOBALSUPPLIER_H

#include "Supplier.h"
#include <string>
#include <iostream>

class Organization; // Forward declaration to avoid circular dependency

class GlobalSupplier : public Supplier
{
public:
    GlobalSupplier(const std::string &name);
    void notifyRestock(const std::string &productId, int quantity) override;
    void subscribeToOrganization(Organization *org) override;
};

#endif
