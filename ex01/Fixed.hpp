#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

    private:
        int fixedValue;
        static const int fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        float toFloat( void ) const;
        int toInt( void ) const;
};

#endif
