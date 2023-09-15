#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

// void sort(struct text_parametrs *text, int (* function_pointer) (const char *, const char *, size_t, size_t))
// {
//     MYASSERT(text->string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

//     for (size_t number_pass = 0; number_pass < text->number_lines - 1; number_pass++)
//     {
//         MYASSERT(number_pass < text->number_lines, GOING_BEYOUND_BOUNDARY_ARRAY, return);

//         size_t index_min = find_min(text->string_array + number_pass, 
//                                     text->number_lines - number_pass, 
//                                     text->size_string  + number_pass, function_pointer) + number_pass;

//         swap_pointer(text->string_array, index_min, number_pass, text->size_string);
//     }
// }

// size_t find_min(const char *const *string_array, const size_t number_lines, size_t *size_string, 
//                 int (* function_pointer) (const char *, const char *, size_t, size_t))
// {
//     MYASSERT(string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

//     const char *pointer_minimum = *string_array;
//     size_t index_min = 0;

//     for(size_t index = 1; index < number_lines; index++)
//     {
//         MYASSERT(index < number_lines, GOING_BEYOUND_BOUNDARY_ARRAY, return 0);
//         //printf("function_pointer = %d\n", function_pointer(pointer_minimum, string_array[index], size_string[index_min], size_string[index]));

//         if(function_pointer(pointer_minimum, string_array[index], size_string[index_min], size_string[index]) > 0)
//         {
//             pointer_minimum = string_array[index];
//             index_min = index;
//         }
//     }
//     return index_min;
// }

int compare_line(const char *string_1, const char *string_2, size_t size_string_1, size_t size_string_2)
{
    MYASSERT(string_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_1 != string_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    #define MOVE_TO_ALPHA(string)                                               \
        while(!isalpha(*string) && *string != '\n' && *string != '\0')          \
            ++string;                                                           \
                                                                                \
        if(*string == '\n' || *string == '\0')                                  \
            break

    while(*string_1 != '\n' && *string_2 != '\n' && 
          *string_1 != '\0' && *string_2 != '\0')
    {  
        MOVE_TO_ALPHA(string_1);
        MOVE_TO_ALPHA(string_2);

        if(tolower(*string_1) != tolower(*string_2))
            return (tolower(*string_1) - tolower(*string_2));

        ++string_1;
        ++string_2;
    }

//     #undef MOVE_TO_ALPHA

//     if(*string_2 != '\n' && *string_2 != '\0')
//         return -1;
    
//     if(*string_1 != '\n' && *string_1 != '\0')
//         return 1;

//     return 0;
// }

// int reverse_compare_line(const char *string_1, const char *string_2, size_t size_string_1, size_t size_string_2)
// {
//     MYASSERT(string_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
//     MYASSERT(string_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
//     MYASSERT(string_1 != string_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

//     const char *end_string_1 = string_1 + size_string_1 - 1;
//     const char *end_string_2 = string_2 + size_string_2 - 1;
//     // printf("string_1 = %p end_string_1 = %p size_string_1 = %u\n",string_1, end_string_1, size_string_1);
//     // print_string(string_1);
//     // printf("string_2 = %p end_string_2 = %p size_string_2 = %u\n",string_2, end_string_2, size_string_2);
//     // print_string(string_2);

//     #define MOVE_TO_ALPHA(string, end_string)                        \
//         while(!isalpha(*end_string) && end_string > string)          \
//             --end_string;                                            \
//                                                                      \
//         if(end_string <= string)                                     \
//             break

//     while(end_string_1 > string_1 && 
//           end_string_2 > string_2)
//     {  
//         MOVE_TO_ALPHA(string_1, end_string_1);
//         MOVE_TO_ALPHA(string_2, end_string_2);

//         if(tolower(*end_string_1) != tolower(*end_string_2))
//             return (tolower(*end_string_1) - tolower(*end_string_2));

//         --end_string_1;
//         --end_string_2;
//     }

//     #undef MOVE_TO_ALPHA

//     if(end_string_1 > string_1)
//         return -1;
    
//     if(end_string_2 > string_2)
//         return 1;

//     return 0;
// }

// void swap_pointer(const char **string_array, size_t index_min, size_t number_pass, size_t *size_string)
// {
//     MYASSERT(string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

//     // printf("\n-------------------------------------------------------\n");
//     // printf("*(string_array + number_pass) = %p *(size_string + number_pass) = %u\n",*(string_array + number_pass), *(size_string + number_pass));
//     // print_string(*(string_array + number_pass));

//     // printf("*(string_array + index_min) = %p *(size_string + index_min) = %u\n",*(string_array + index_min), *(size_string + index_min));
//     // print_string(*(string_array + index_min));

//     const char *pointer_buffer = *(string_array + number_pass); 

//     *(string_array + number_pass) = *(string_array + index_min);
//     *(string_array + index_min) = pointer_buffer;

//     size_t size_buffer = *(size_string + number_pass); 


//     *(size_string + number_pass) = *(size_string + index_min);
//     *(size_string + index_min) = size_buffer;

//     // printf("\n\n*(string_array + number_pass) = %p *(size_string + number_pass) = %u\n",*(string_array + number_pass), *(size_string + number_pass));
//     // print_string(*(string_array + number_pass));

//     // printf("*(string_array + index_min) = %p *(size_string + index_min) = %u\n",*(string_array + index_min), *(size_string + index_min));
//     // print_string(*(string_array + index_min));
//     // printf("\n-------------------------------------------------------\n");
// }

void quick_sort( void *array,
                 size_t number_elements,
                 size_t size_elements,
                 int (*compare )(const void *, const void *))
{
    void *left_border  = array;
    void *right_border = (char *) array + size_elements * (number_elements - 1);

    printf("left_border = %p  right_border = %p\n", left_border, right_border);

    if(left_border + size_elements < right_border)
    {
    left_border = partition(left_border, right_border, array, number_elements, size_elements, compare);

    quick_sort(array, ((char *)left_border - (char *)array) / size_elements + 1, size_elements, compare);
    quick_sort((char *)left_border + size_elements, ((char *)right_border - (char *)left_border) / size_elements ,size_elements, compare);
    }

    if((char *)right_border - (char *)left_border == size_elements && compare(left_border, right_border) > 0)
        swap_values(left_border, right_border, size_elements);    
}
void *partition( void *left_border,
                 void *right_border,
                 void *array,
                 size_t number_elements,
                 size_t size_elements,
                 int (*compare )(const void *, const void *))
{

    void *pivot = calloc(1, size_elements);
    void *pointer_pivot = (char *) left_border + size_elements * (number_elements / 2);

    memcpy(pivot, pointer_pivot, size_elements);

    printf("pivot = %d\n", (*(int *) pivot));

    //print_partition( (int *)left_border, (int *) right_border, (int *) pointer_pivot, (int *) array, number_elements);

    while(left_border < right_border)
    {
        print_partition( (int *)left_border, (int *) right_border, (int *) pointer_pivot, (int *) array, number_elements);
        while(compare(left_border, pivot) < 0)
        {
            left_border = (char*)left_border + size_elements;
            print_partition( (int *)left_border, (int *) right_border, (int *) pointer_pivot, (int *) array, number_elements);
        }

        while(compare(right_border, pivot) > 0)
        {
            right_border = (char*)right_border - size_elements;
            print_partition( (int *)left_border, (int *) right_border, (int *) pointer_pivot, (int *) array, number_elements);
        }

        if (left_border >= right_border)
            break;

        swap_values(left_border, right_border, size_elements);

            left_border = (char*)left_border + size_elements;
            right_border = (char*)right_border - size_elements;
    }
    free (pivot);

    print_partition( (int *)left_border, (int *) right_border, (int *) pointer_pivot, (int *) array, number_elements);

    return find_min_pointer (left_border, right_border);
}

int compare_int (const void *number_1, const void *number_2)
{
    return (*((const int *) number_1) - *((const int *) number_2));
}

void swap_values(void* value_1, void* value_2, const size_t size_elements)
{
    MYASSERT(value_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(value_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    void *swap_buffer = calloc(1, size_elements);

    memcpy(swap_buffer, value_1, size_elements);
    memcpy(value_1, value_2, size_elements);
    memcpy(value_2, swap_buffer, size_elements);


}

void *find_min_pointer(void *pointer_1, void *pointer_2)
{
    if (pointer_1 < pointer_2)
        return pointer_1;
    
    return pointer_2;
}