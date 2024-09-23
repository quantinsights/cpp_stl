#ifndef PRODUCT_H
#define PRODUCT_H

class Product{
    public:
        Product();
        Product(double price, double rateOfDiscount, int quantitySold);
        Product(const Product& p);

        double getPrice();
        double getRateOfDiscount();
        int getQuantitySold();
        double computeRevenue();
    private:
        double m_price;
        double m_rateOfDiscount;
        int m_quantitySold;
};

#endif