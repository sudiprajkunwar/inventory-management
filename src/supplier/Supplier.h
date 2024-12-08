#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <memory>

// Forward declaration to avoid circular dependency
class Organization;

class Supplier : public std::enable_shared_from_this<Supplier>
{
public:
    Supplier(const std::string &name);
    virtual ~Supplier() = default;
    const std::string &getName() const;
    bool isSupplierSubscribed() const; // Check if supplier is subscribed

    // Abstract method to notify supplier for restocking
    virtual void notifyRestock(const std::string &productId, int quantity) = 0;

    // Method to subscribe to an organization for inventory notifications
    virtual void subscribeToOrganization(Organization *org) = 0;

protected:
    std::string name;
    bool isSubscribed;
};

#endif
