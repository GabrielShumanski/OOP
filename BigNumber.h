#pragma once
#include <vector>

class BigNumber
{
public:
    BigNumber(const char* nums);
    bool operator<(BigNumber& other);
    bool operator==(BigNumber& other);
    bool operator<=(BigNumber& other);
    bool operator>=(BigNumber& other);
    bool operator>(BigNumber& other);
    bool operator!=(BigNumber& other);
    bool operator<(int number);
    bool operator==(int number);
    bool operator<=(int number);
    bool operator>=(int number);
    bool operator>(int number);
    bool operator!=(int number);
private:
    bool chekIfNegative(const char nums);
    int findRightNum(int num, bool numIsNegative,int size, int count);
    int findNumSize(int number);
private:
    std::vector<char> num;
    bool negative;
};
