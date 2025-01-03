#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <memory>

class Organization;

class Supplier : public std::enable_shared_from_this<Supplier>
{
public:
    Supplier(const std::string &name);
    virtual ~Supplier() = default;
    const std::string &getName() const;
    virtual void notifyRestock(const std::string &productId, int quantity) = 0;
    virtual void subscribeToOrganization(Organization *org) = 0;

protected:
    std::string name;
};

#endif
