#include <stdio.h>
#include <stdlib.h>  // Including the lib for calloc function

/**
 * unions_struct - using unions and struct to  print
 * the variant members of each.
 * Return 0,for success
 * Authors: JASPER && SOBIL
 */


struct details {
    int age;
    float weight;
    char name[30];
};



union particulars {
    char gender;
    int children;
    double networth;
};



int main() 
{
    struct details myDetails;

    // Use calloc to allocate memory for union particulars

    union particulars *ptrs = (union particulars *)calloc(1, sizeof(union particulars));

 
    if (ptrs == NULL) {
        printf("Memory allocation failed\n");
        return 1;  // Return an error code
    }



    // Input details
    printf("Enter your name: ");
    scanf("%29s", myDetails.name);  // Limit input to 29 characters to avoid buffer overflow

    printf("Enter your age: ");
    scanf("%d", &myDetails.age);

    printf("Enter your weight: ");
    scanf("%f", &myDetails.weight);

    printf("I am %s, I'm %d and weigh %f lbs\n", myDetails.name, myDetails.age, myDetails.weight);


    // Input particulars using union
    printf("Enter either M or F as your gender: ");
    scanf(" %c", &ptrs->gender);  // Notice the space before %c to consume any leading whitespace

    printf("Enter the number of children you have: ");
    scanf("%d", &ptrs->children);

    printf("Enter your net worth: ");
    scanf("%lf", &ptrs->networth);

    printf("Gender: %c, Children: %d, Net Worth: %f\n", ptrs->gender, ptrs->children, ptrs->networth);


    // Free allocated memory
    free(ptrs);

    return 0;

}
