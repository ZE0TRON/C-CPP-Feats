#include <stdio.h>


// Defining the macro
// with card suits
#define SUITS \
    X(CLUBS) \
    X(HEARTS) \
    X(SPADES) \
    X(DIAMONDS)

// Creating the enum of suits
// by macro expansion

typedef enum suits {
    #define X(value) value,
        SUITS
    #undef X
} suits;

// Util function to print the string of the suit
char *toString(suits value) {
    switch (value) {
        #define X(suit) \
            case suit: \
                return #suit;
                SUITS
        #undef X
    }
}

int main() {
    suits suit = SPADES;
    printf("%s",toString(suit));
}