
# include "greatestCommonDivisor_ofStrings.hpp"

size_t gcd(size_t lengthStr1, size_t lengthStr2)
{
    if (lengthStr2 == 0)
        return lengthStr1;
    return gcd(lengthStr2, lengthStr1 % lengthStr2);
}

string Solution::gcdOfStrings(string str1, string str2) 
{
    if (str1 + str2 != str2 + str1)
        return "";
    size_t gcdLength = gcd(str1.length(), str2.length());
    return str1.substr(0, gcdLength);
}