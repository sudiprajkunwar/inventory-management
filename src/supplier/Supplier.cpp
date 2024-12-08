#include "./Supplier.h"
#include "../organization/Organization.h"

Supplier::Supplier(const std::string &name) : name(name) {}

const std::string &Supplier::getName() const
{
    return name;
}

void Supplier::subscribeToOrganization(Organization *org)
{
    std::shared_ptr<Supplier> self = shared_from_this();
    org->addSupplier(self);
}

