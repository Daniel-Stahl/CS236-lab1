#include "largeIntegers.hpp"

largeIntegers::largeIntegers(){};
largeIntegers::largeIntegers(string newNum) {
    num = newNum;
}

ostream& operator<< (ostream& output, const largeIntegers& lgInt) {
    output << lgInt.num << "\n";
    return output;
}

istream& operator>> (istream& input, largeIntegers& lgInt) {
    int x = 0;
    
    cout << "Enter an integer of at most 50 digits: ";
    
    input >> lgInt.num;
    
    int stringSize = lgInt.num.size() - 1;
    while (stringSize >= 0) {
        lgInt.largeNum.push_back(lgInt.num.at(stringSize));
        stringSize--;
    }
    
    return input;
}

largeIntegers largeIntegers::operator+(const largeIntegers& lgInt) {
    largeIntegers retInt;
    int diffSize = 0;
    int plusOne = 0;
    int x = 0;
    char tempNum;
    int twoDigits = 0;
    
    int vecSize = 0;
    
    
    if (this->largeNum.size() > lgInt.largeNum.size()) {
        vecSize = this->largeNum.size();
        diffSize = this->largeNum.size() - lgInt.largeNum.size();
    } else {
        vecSize = lgInt.largeNum.size();
        diffSize = lgInt.largeNum.size() - this->largeNum.size();
    }
    
    while (x < vecSize) {
        if (this->largeNum.size() > x && lgInt.largeNum.size() > x) {
            if (plusOne == 1) {
                tempNum = (this->largeNum.at(x) + lgInt.largeNum.at(x)) - '0';
                tempNum++;
            } else {
                tempNum = (this->largeNum.at(x) + lgInt.largeNum.at(x)) - '0';
            }
            
            if (tempNum <= '9') {
                retInt.largeNum.push_back(tempNum);
                plusOne = 0;
            } else {
                twoDigits = (int)(tempNum);
                tempNum = DecimalConverter(twoDigits);
                retInt.largeNum.push_back(tempNum);
                plusOne = 1;
            }
        } else if (this->largeNum.size() > x ) {
            tempNum = this->largeNum.at(x);
            retInt.largeNum.push_back(tempNum);
        } else {
            tempNum = lgInt.largeNum.at(x);
            retInt.largeNum.push_back(tempNum);
        }
        
        x++;
    }
    
    retInt.num.append(retInt.largeNum.rbegin(), retInt.largeNum.rend());
    cout << this->num + " + " + lgInt.num + " = " + retInt.num + "\n";
    
//    if (this->largeNum.size() > lgInt.largeNum.size()) {
//        diffSize = this->largeNum.size() - lgInt.largeNum.size();
//
//        while (x < diffSize) {
//            retInt.largeNum.push_back(this->largeNum.at(x));
//            x++;
//        }
//
//        for (x = 0; x < lgInt.largeNum.size(); x++) {
//
//            if (plusOne == 1) {
//                tempNum = (this->largeNum.at(diffSize+x) + lgInt.largeNum.at(x)) - '0';
//                tempNum++;
//            } else {
//                tempNum = (this->largeNum.at(diffSize+x) + lgInt.largeNum.at(x)) - '0';
//            }
//
//            if (tempNum < '9') {
//                retInt.largeNum.push_back(tempNum);
//                plusOne = 0;
//            } else {
//                twoDigits = (int)(tempNum);
//                //tempNum = (char)(twoDigits - 48 - 10);
//                tempNum = DecimalConverter(twoDigits);
//                retInt.largeNum.push_back(tempNum);
//                plusOne = 1;
//            }
//        }
//
//        retInt.num.append(retInt.largeNum.rbegin(), retInt.largeNum.rend());
//
//        cout << this->num + " + " + lgInt.num + " = " + retInt.num + "\n";
//
//    } else {
//        diffSize = lgInt.largeNum.size() - this->largeNum.size();
//    }
    
//    int stringSize = retInt.largeNum.size() - 1;
//    while (stringSize >= 0) {
//        retInt.num.append(retInt.largeNum.at(stringSize));
//        stringSize--;
//    }
    
    

    return retInt;
}

int largeIntegers::GetNumSize() const {
    return num.size();
}

char largeIntegers::DecimalConverter(int decimal) {
    char c;
    int tempNum = 0;
    
    tempNum = (decimal - 48) - 10;
    c = '0' + tempNum;
    
    return c;
};

