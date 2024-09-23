#include "Order.h"

Order::Order(long customerId, long orderId, std::vector<long> productIds) : m_customerId {customerId}, m_orderId {orderId}, m_orderAmount{0.00}, m_productIds{productIds} {}

Order::Order(const Order& order)
{
    if(this == &order)
        return;

    this->m_customerId = order.m_customerId;
    this->m_orderId = order.m_orderId;
    this->m_orderAmount = order.m_orderAmount;
    this->m_productIds = order.m_productIds;
}

Order::Order() : m_customerId {0}, m_orderId {0},  m_orderAmount {0.00}, m_productIds {} {}

long Order::getCustomerId() { return m_customerId; }
long Order::getOrderId() const { return m_orderId; }
double Order::getOrderAmount() { return m_orderAmount; }
void Order::setOrderAmount(double amt) { m_orderAmount = amt; }
std::vector<long> Order::getProductIds() { return m_productIds; }
bool Order::operator<(const Order& o) const{
    return this->getOrderId() < o.getOrderId();
}