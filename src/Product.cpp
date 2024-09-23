#include "Product.h"

//Parameterized constructor
Product::Product(double price, double rateOfDiscount, int quantitySold) : m_price{price}, m_rateOfDiscount{rateOfDiscount}, m_quantitySold{quantitySold} {}

//Copy constructor
Product::Product(const Product& product)
{
    if(this == &product)
        return;

    this->m_price = product.m_price;
    this->m_quantitySold = product.m_quantitySold;
    this->m_rateOfDiscount = product.m_rateOfDiscount;
}

Product::Product() : Product {0.00, 0.00, 0} {}

double Product::getPrice() {return m_price;}
double Product::getRateOfDiscount() {return m_rateOfDiscount;}
int Product::getQuantitySold(){return m_quantitySold;}

double Product::computeRevenue(){ return m_price * (1 - m_rateOfDiscount) * m_quantitySold;}
