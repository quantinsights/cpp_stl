#ifndef ORDER_H
#define ORDER_H

#include <vector>


class Order{
    public:
        Order();
        Order(const Order& c);
        Order(long customerId, long orderId, std::vector<long> productIds);

        long getCustomerId();
        long getOrderId() const;
        double getOrderAmount();
        void setOrderAmount(double amt);
        std::vector<long> getProductIds();
        bool operator<(const Order& o) const;

    private:
        long m_customerId;
        long m_orderId;
        double m_orderAmount;
        std::vector<long> m_productIds;
};
#endif ORDER_H