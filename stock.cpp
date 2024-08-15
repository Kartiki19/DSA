#include<iostream>
#include<vector>

using namespace std;

int maxProfit(const vector<int> &prices){
    int n = prices.size();
    if (n<2) return 0;
    int buy_price = prices[0];
    int profit = 0;
    for(int price: prices){
        if(price < buy_price) buy_price = price;
        else if(price-buy_price > profit) profit = price - buy_price;
    }

    return profit;
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int answer = maxProfit(prices);
    cout << "Answer is:" << answer << endl;

    return 0;
}