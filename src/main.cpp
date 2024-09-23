#include "Product.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

int main()
{
    /*
    * Exercise 1
    */
    std::vector<Product> products {
        {100.0, 0.10, 50},
        {200.0, 0.15, 30},
        {300.0, 0.20, 20},
        {150.0, 0.05, 40}
    };

    std::vector<double> revenues(products.size());
    
    //Map product prices -> revenues
    std::transform(products.begin(),products.end(),revenues.begin(),[](Product p){
        return p.computeRevenue();
    });

    //Display the vector of revenues
    for(int i{0}; i<revenues.size(); ++i)
        std::cout << "Revenue for product " << i << " = " << revenues[i] << std::endl;

    //Compute total revenue of the entire store
    double totalRevenue = std::accumulate(revenues.begin(), revenues.end(), 0.0);
    std::cout << "Total Revenue = " << totalRevenue;

    /*
    * Exercise 2
    */

    //A list of orders placed by customers
    //Each order is given by a triple (customerId, orderId, productIds)
    std::vector<Order> orders{
        {1, 1001, {1, 2, 3}},
        {2, 1002, {2, 4}},
        {1, 1003, {1, 3, 5}},
        {3, 1004, {3}},
        {2, 1005, {4}},
        {1, 1001, {1, 2, 3}} //Duplicate order by customer 1, should be removed
    };

    //Product to price map
    std::unordered_map<long, double> productPriceMap {
        {1, 100.0},
        {2, 50.0},
        {3, 75.0},
        {4, 200.0},
        {5, 150.0}
    };

    //Remove duplicate orders (by order id)
    //Let's put these orders into an ordered set
    std::set<Order> setOfOrders(orders.begin(), orders.end());
    orders.assign(setOfOrders.begin(), setOfOrders.end());

    std::cout << "\n\nNumber of Unique orders = " << orders.size();

    //Total amount spend by each customer
    std::map<long,double> totalSpendByCustomer {};

    for(int i{0};i<orders.size();++i)
    {
        std::vector<long> productIds {orders[i].getProductIds()};
        std::vector<double> prices (productIds.size());

        std::transform(productIds.begin(), productIds.end(), prices.begin(), [&](long productId) { 
            return productPriceMap[productId]; 
        });

        if(totalSpendByCustomer.count(orders[i].getCustomerId()) > 0)
                totalSpendByCustomer[orders[i].getCustomerId()] += std::accumulate(prices.begin(), prices.end(), 0.0);
            else
                totalSpendByCustomer[orders[i].getCustomerId()] = std::accumulate(prices.begin(), prices.end(), 0.0);
    }
    
    std::cout << "\nTotal amount spent by each customer" << std::endl;

    for(auto element : totalSpendByCustomer)
    {
        std::cout << "Customer Id = " << element.first << ", total spend = " << element.second << "\n";
    }

    //Identify the star-customers who have spent larger than a certain threshold
    double thresholdAmount {};
    std::cout << "\nEnter a threshold to identify premium customers = ";
    std::cin >> thresholdAmount;
    std::vector<std::pair<const long, double>> starCustomers {};
    std::copy_if(totalSpendByCustomer.begin(), totalSpendByCustomer.end(), std::back_inserter(starCustomers), [thresholdAmount](std::pair<const long, double> element){
        return element.second > thresholdAmount;
    });

    std::cout << "\nList of star customers follows...";
    for(auto v : starCustomers)
        std::cout << "\nCustomerId = " << v.first << ", Amount spend = " << v.second; 

    //Most frequently purchased product amongst all customers 
    std::cout << "\nMost frequently purchased product follows...";
    std::map<long, int> productCounts {};
    for(auto o : orders)
    {
        std::vector<long> productIds {o.getProductIds()};
        for(auto p : productIds)
            productCounts[p]++;
    }

    //Iterate through the productCounts map to find the element with the largest v
    std::pair<long, int> maxProductCount {};
    int maxValue {};
    for(auto [k,v]: productCounts)
    {
        if(v >= maxValue)
        {
            maxValue = v;
            maxProductCount.first = k;
            maxProductCount.second = v;
        }
    }

    std::cout << "\nProductId = " << maxProductCount.first << ", Count = " << maxProductCount.second; 

    //TODO : Sort customers by their total spending in descending order
    // std::sort(totalSpendByCustomer.begin(),
    // totalSpendByCustomer.end(),
    // [](std::pair<long, double> lhs, std::pair<long, double> rhs){
    //     return lhs.second > rhs.second;
    // }
    // );

    // std::cout << "\nlisting customers in descending order of their spend follows...";
    // for(auto [k,v] : totalSpendByCustomer)
    //     std::cout << "\nCustomerId = " << k << "Amount Spend = " << v;

    return 0;
}