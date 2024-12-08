#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "../product/Product.h"
#include "../supplier/Supplier.h"

class Organization
{
private:
    std::vector<Product> products;
    std::vector<std::shared_ptr<Supplier>> suppliers;

public:
    void addProduct(const Product &product);
    void removeProductById(const std::string &productId);
    Product *searchProductById(const std::string &productId);
    void displayInventory() const;

    void addSupplier(std::shared_ptr<Supplier> supplier);
    void notifySuppliers(const std::string &productId, int quantity);
    void updateStockLevel(const std::string &productID, int newStock);

    void generateReport() const;
};

#endif
