//represent a polynomial as a linked list and write functions for polynomial addition
#include <stdio.h>
#include <stdlib.h>

// Polynomial term structure
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term at the end of the polynomial
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
        *poly = newTerm;
    else {
        Term* currentTerm = *poly;
        while (currentTerm->next != NULL)
            currentTerm = currentTerm->next;
        currentTerm->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
            printf("+ ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
                insertTerm(&result, sum, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    // Add remaining terms of poly1
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    
    // Add remaining terms of poly2
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    
    return result;
}

// Function to free memory occupied by a polynomial
void freePolynomial(Term* poly) {
    while (poly != NULL) {
        Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Main function
int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    Term* sum = NULL;
    
    // Create the first polynomial: 3x^3 + 2x^2 + 5x^1
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 5, 1);
    
    // Create the second polynomial: 4x^3 + 1x^1 + 7x^0
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 7, 0);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);
    
    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    
    return 0;
}
