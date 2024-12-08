
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
public:
    Product(const std::string &id, const std::string &name, const std::string &category, double price, int stock, int threshold);

    // Getters
    std::string getProductId() const;
    std::string getProductName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStockLevel() const;
    int getReorderThreshold() const;

    // Setter for stock level
    void updateStockLevel(int soldQuantity);
    bool needsRestock();

private:
    std::string productId;
    std::string productName;
    std::string category;
    double price;
    int stockLevel;
    int reorderThreshold;
};

#endif // PRODUCT_H
