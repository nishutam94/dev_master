#include <iostream>

int main() {
    int x = 20;
    int y = 3;
    int r = 0;

    // Check if divisor is zero (avoid division by zero)
    if (y == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return -1;
    }

    // Perform division using bitwise operations
    for (int i = 16; i >= 0; i--) {
        // If (y << i) is less than or equal to x, subtract (y << i) from x and set the corresponding bit in the quotient
        if ((y << i) <= x) {
            x = x - (y << i);
            r = r | (1 << i);
        }
    }

    // Output the result: x will be the remainder, r will be the quotient
    std::cout << "Remainder: " << x << ", Quotient: " << r << std::endl;

    return 0;
}
