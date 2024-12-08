#include "./Product.h"

// Constructor
Product::Product(const std::string &id, const std::string &name, const std::string &category, double price, int stock, int threshold)
    : productId(id), productName(name), category(category), price(price), stockLevel(stock), reorderThreshold(threshold) {}

// Getters
std::string Product::getProductId() const
{
    return productId;
}

std::string Product::getProductName() const
{
    return productName;
}

std::string Product::getCategory() const
{
    return category;
}

double Product::getPrice() const
{
    return price;
}

int Product::getStockLevel() const
{
    return stockLevel;
}

int Product::getReorderThreshold() const
{
    return reorderThreshold;
}

void Product::updateStockLevel(int newStock)
{
    stockLevel = newStock;
}

bool Product::needsRestock() const
{
    return stockLevel < reorderThreshold;
}
