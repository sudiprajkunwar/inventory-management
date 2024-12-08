#include <iostream>
#include "./src/organization/Organization.h"
#include "./src/supplier/LocalSupplier.h"
#include "./src/supplier/GlobalSupplier.h"

int main()
{
    Organization org;

    // Create suppliers
    std::shared_ptr<LocalSupplier> localSupplier = std::make_shared<LocalSupplier>("Local Supplier");
    std::shared_ptr<GlobalSupplier> globalSupplier = std::make_shared<GlobalSupplier>("Global Supplier");

    org.addSupplier(localSupplier);
    org.addSupplier(globalSupplier);

    localSupplier->subscribeToOrganization(&org);
    globalSupplier->subscribeToOrganization(&org);

    // Adding products
    org.addProduct(Product("P001", "Laptop", "Electronics", 1200.50, 50, 10));
    org.addProduct(Product("P002", "Smartphone", "Electronics", 800.75, 30, 5));
    org.addProduct(Product("P003", "Coffee Maker", "Home Appliances", 150.25, 15, 3));

    // Generate inventory report
    org.generateReport();
    return 0;
}
