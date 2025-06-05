/*
* Kelly Pratama
* June 4, 2025
* A program to convert a number into its spoken word counterpart. Inspired by Elementary Algebra and understanding the place value system.
*/

#include <string> 
#include <iostream>
#include <vector> 
#include <cassert>
#include <limits.h> // for INT_MAX

using namespace std; 

// helper function that takes in a 3 digit number and converts it into its spoken word counterpart
string convertThreeDigitToWords(int& num) {
    vector<string> ones = {"", "one", "two", "three", "four", "five", 
                           "six", "seven", "eight", "nine"};
    vector<string> teens = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
                            "sixteen", "seventeen", "eighteen", "nineteen"};
    vector<string> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", 
                           "sixty", "seventy", "eighty", "ninety"};

    string subresult = "";

    if (num >= 100) {
        subresult += ones[num / 100] + " hundred"; 
        num %= 100; 
        if (num > 0) {
            subresult += " and ";
        }
    }
    if (num >= 20) {
        subresult += tens[num / 10]; 
        num %= 10;
        if (num > 0) {
            subresult += "-";
        }
    }
    if (num >= 11) {
        subresult += teens[num - 10];
    } else if (num > 0) {
        subresult += ones[num]; 
    }

    return subresult;
}

// function that converts a long series of numbers that cannot fit into an integer
string numToWords(long& num) {
    string result = ""; 
    
    vector<string> place = {"", " thousand ", " million ", " billion ", " trillion "};

    vector<int> chunks; 
    
    while (num > 0) {
        int chunk = num % 1000; 
        chunks.push_back(chunk);
        num /= 1000; 
    }
    for (int i = 0; i < chunks.size(); i++ ) {
        result = convertThreeDigitToWords(chunks[i]) + place[i] + result;
    }
    return result;
}
int main() {
    long num1 = 9'054'208'731;
    long num2 = 2'140'234'063'795;

    cout << INT_MAX << endl;  // 2'147'483'647, around 2 billion

    string num2ans = "two trillion one hundred and forty billion two hundred and thirty-four million sixty-three thousand seven hundred and ninety-five";

    cout << numToWords(num1) << endl;
    assert(numToWords(num2) == num2ans);
    cout << "All testcases passed!" << endl; 
    
    return 0;
}