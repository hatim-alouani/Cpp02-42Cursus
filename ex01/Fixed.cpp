#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->fixedValue = 0;
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called" << std::endl;
    fixedValue = value * 256;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    fixedValue = roundf(value * 256);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixedValue(other.fixedValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedValue = other.fixedValue;
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedValue;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixedValue = raw;
}

float Fixed::toFloat() const {
    return  (float)(fixedValue) / 256;
}

int Fixed::toInt() const {
    return fixedValue / 256;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
