#include "BigNumber.h"
#include "iostream"
#include <cstring>

BigNumber::BigNumber(const char* nums) {
    negative = chekIfNegative(nums[0]);
    int size = strlen(nums) - negative;
    
    for (int i = 0 + !negative; i < size; i++)
    {
        num.push_back(nums[i]);
    }
}

bool BigNumber::chekIfNegative(const char nums) {
    if(nums != '-') {
        return true;
    }
        return false;
}

bool BigNumber::operator<(BigNumber& other) {
    bool bn1IsBigger = true;

    //this > -other
    if(this->negative && !other.negative)
        return bn1IsBigger;

    //this ? other && this.size() ? other.size()
    if(this->negative ^ other.negative){
        
        //znae se ot kursa po DSTR
        bool bothNegative = !(this->negative || other.negative);

        if(this->num.size() < other.num.size())
            bn1IsBigger = false;
        
        if(this->num.size() == other.num.size()) {
            for(int i = 0 + bothNegative; i < this->num.size(); ++i) {
                if (num.at(i) > other.num.at(i))
                    bn1IsBigger = false;
            }
        }
        
        if(bothNegative)
            return bn1IsBigger;
    }

    //-this < other
        return !bn1IsBigger;
}

//vijdam, che pravq gore-dolu edni i syshti neshta,
//nqkakva ideq kakd ase izmykna ot tova?
bool BigNumber::operator==(BigNumber& other) {
    if(this->negative ^ other.negative){
        
        bool bothNegative = !(this->negative || other.negative);

        if(this->num.size() == other.num.size()) {
            for(int i = 0 + bothNegative; i < this->num.size(); ++i) {
                if (num.at(i) > other.num.at(i))
                    return false;
                if (num.at(i) < other.num.at(i))
                    return false;              
            }
            return true;
        }
    }
    return false;
}

bool BigNumber::operator<=(BigNumber& other) {
    return (this < &other || this == &other);
}

bool BigNumber::operator>=(BigNumber& other) {
    return (!(this < &other) && this == &other);
}

bool BigNumber::operator>(BigNumber& other) {
    return (!(this < &other));
}

bool BigNumber::operator!=(BigNumber& other) {
    return (!(this == &other));
}

bool BigNumber::operator<(int number) {
    int i = 0;

    int numSize = findNumSize(number);
    bool numIsNegative = number < 0 ? true : false;
        bool bothAreNegative = this->negative && numIsNegative;

    if(this->negative && !numIsNegative)
        return true;

    if(!this->negative && numIsNegative)
        return false;;

    if(numSize < this->num.size() - this->negative)
        return (bothAreNegative ? true : false);

    if(numSize == this->num.size() - this->negative) {
        while(number / 10 != 0) {
            int digg = findRightNum(number, numIsNegative, numSize, i);

            if(this->num.at(i + this->negative) - '0' < digg)
                return (bothAreNegative ? false : true);

            if(this->num.at(i + this->negative) - '0' > digg)
                return (bothAreNegative ? false : true);
            
            i++;
        }
    }
    return (bothAreNegative ? false : true);
}

bool BigNumber::operator==(int number) {
    int numSize = findNumSize(number);
    bool numIsNegative = number < 0 ? true : false;

    if(numSize != this->num.size() || !(this->negative ^ numIsNegative)) 
        return false;
    else {
        for(int i = 0; i < numSize; i++) {
            int digg = findRightNum(number, numIsNegative, numSize, i);

            if(this->num.at(i + negative) - '0' != digg) 
                return false;
        }
    }
    return true;
}

int BigNumber::findNumSize(int number) {
    int i = 0;
    for(; number/10 != 0; i++) {
        number /=10 ;
    }

    return i;
}

int BigNumber::findRightNum(int num, bool numIsNegative, int size, int count) {
    for(int i = 0; i < size - count; i++) {
        num /= 10;
    }
    if(numIsNegative) 
        return (num%10) * -1;
    else return num%10;
}

bool BigNumber::operator<=(int number) {
    return operator<(number) && operator==(number);
}

bool BigNumber::operator>=(int number) {
    return !operator<(number) && operator==(number);
}

bool BigNumber::operator>(int number) {
    return !operator<(number) && !operator==(number);
}

bool BigNumber::operator!=(int number) {
    return !operator==(number);
}