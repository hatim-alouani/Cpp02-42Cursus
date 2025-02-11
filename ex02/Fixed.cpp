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

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(){
    fixedValue++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed save = *this;
    fixedValue++;
    return save;
}

Fixed& Fixed::operator--(){
    fixedValue--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed save = *this;
    fixedValue--;
    return save;
}


bool Fixed::operator>(const Fixed& other) const{
    return fixedValue > other.fixedValue;
}

bool Fixed::operator<(const Fixed& other) const{
    return fixedValue < other.fixedValue;
}

bool Fixed::operator>=(const Fixed& other) const{
    return fixedValue >= other.fixedValue;
}


bool Fixed::operator<=(const Fixed& other) const{
    return fixedValue <= other.fixedValue;
}


bool Fixed::operator==(const Fixed& other) const{
    return fixedValue == other.fixedValue;
}


bool Fixed::operator!=(const Fixed& other) const{
    return fixedValue != other.fixedValue;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)  {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)  {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)  {
    if (a < b)
        return a;
    return b;
}