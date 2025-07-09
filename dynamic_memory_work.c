#include <stdio.h>
#include <stdlib.h>



void FindMinMax(int *arr, int size, int *min, int *max) {
   *max = arr[0];
   *min = arr[0];

   for(int i = 1; i < size; ++i) {
    if (arr[i] < *min) {
        *min = arr[i];
    }

    if (arr[i] > *max) {
        *max = arr[i];
    }
   }

   printf("The smallest value is %d.\nThe maximum value is %d.\n", *min, *max);

}

void assign_numbers(int *arr, int size) {
    int each_num;
    printf("Please enter %d integers\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Please enter a random integer number %d: \n", i + 1);
        scanf("%d", &each_num);
        arr[i] = each_num;
    }
}

int* create_array(int size ) {
    int choice;
    printf("Please enter 1 for the memory allocation or enter 0 for : \n");
    scanf("%d", &choice);

    int* my_array = NULL;

    if (choice == 1) {
        my_array = (int*) malloc(size * sizeof(int));
    } else if (choice == 0) {
        my_array = (int*) calloc(size, sizeof(int));
    } else {
        printf("Invalid choice.\n");
        return NULL;
    }

    if (my_array == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    return my_array;

    }
    
int main() {
    int size_of_array, min_num, max_num, flag;
    printf("Please enter a size for the array: \n");
    scanf("%d", &size_of_array);

    int* my_array = create_array(size_of_array);
    if (my_array == NULL) {
        return 1; 
    }
    assign_numbers(my_array, size_of_array);

    FindMinMax(my_array, size_of_array, &min_num, &max_num);

    printf("Enter 1 if you want to reallocate memory:  \n");
    scanf("%d", &flag);
    if (flag == 1) {
        int new_size;
        printf("Enter new size for the array: ");
        scanf("%d", &new_size);
        int* temp = realloc(my_array, new_size * sizeof(int));

        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        my_array = temp;
         if (new_size > size_of_array) {
            printf("Please enter %d more numbers:\n", new_size - size_of_array);
            for (int i = size_of_array; i < new_size; ++i) {
                printf("Enter integer %d: ", i + 1);
                scanf("%d", &my_array[i]);
            }
        }
        
        FindMinMax(my_array, new_size, &min_num, &max_num);

    }

    free(my_array);
    return 0;
}