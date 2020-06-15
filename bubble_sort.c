/* Take user input array from command line and output sorted array
   in both increasing and decreasing order with bubble sort. */

#include <stdio.h>
#include <stdlib.h>

int *check_input(int argc, char **argv);
int *bubble_sort_plus(int *arr, int count);
int *bubble_sort_minus(int *arr, int count);
void print_array(int *arr, int count);


int main(int argc, char **argv)
{
    int *arr = check_input(argc, argv);

    int count = argc - 1;
    printf("Input Array:\t\t");
    print_array(arr, count);

    int *plus = bubble_sort_plus(arr, count);

    printf("Increasing Order:\t");
    print_array(plus, count);

    int *minus = bubble_sort_minus(arr, count);

    printf("Decreasing Order:\t");
    print_array(minus, count);

    return 0;
}


/* Take command line input and create integer array */
int *check_input(int argc, char **argv)
{
    if (argc == 1) {
        printf("Enter valid array.\n");
        exit(1);
    }

    int *arr;
    arr = (int *)malloc(sizeof(int));

    for(int i=0; argv[i + 1]; i++) {
        arr = (int *)realloc(arr, (i + 1) * sizeof(int));
        arr[i] = (atoi)(argv[i+1]);
    }

    return arr;
}

/* Sort array in increasing order. */
int *bubble_sort_plus(int *arr, int count)
{
    for(int i=0; i<count-1; i++) {
        for(int j=0; j<count-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }

    return arr;
}

int *bubble_sort_minus(int *arr, int count)
{
    for(int i=0; i<count-1; i++) {
        for(int j=0; j<count-i-1; j++) {
            if (arr[j] < arr[j + 1]) {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }

    return arr;
}

void print_array(int *arr, int count)
{
    for(int i=0; i<count; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}