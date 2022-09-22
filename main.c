#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
    struct doubly_linked_list_t* a;
    a = dll_create();
    if (a == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int choice, value, index;
    while (1)
    {
        printf("Co chcesz zrobic? ");
        if (!scanf("%d", &choice))
        {
            dll_clear(a);
            free(a);
            printf("Incorrect input");
            return 1;
        }
        switch (choice)
        {
        case 0:
            dll_clear(a);
            free(a);
            return 0;
            break;
        case 1:
            printf("Podaj liczbe ");
            if (!scanf("%d", &value))
            {
                dll_clear(a);
                free(a);
                printf("Incorrect input");
                return 1;
            }
            if (dll_push_back(a, value))
            {
                dll_clear(a);
                free(a);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        case 2:
            if (a->head == NULL) printf("List is empty\n");
            else printf("%d\n", dll_pop_back(a, NULL));
            break;
        case 3:
            printf("Podaj liczbe ");
            if (!scanf("%d", &value))
            {
                dll_clear(a);
                free(a);
                printf("Incorrect input");
                return 1;
            }
            if (dll_push_front(a, value))
            {
                dll_clear(a);
                free(a);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        case 4:
            if (a->head == NULL) printf("List is empty\n");
            else printf("%d\n", dll_pop_front(a, NULL));
            break;
        case 5:
            printf("Podaj liczbe ");
            if (!scanf("%d", &value))
            {
                dll_clear(a);
                free(a);
                printf("Incorrect input");
                return 1;
            }
            printf("Podaj index ");
            if (!scanf("%d", &index))
            {
                dll_clear(a);
                free(a);
                printf("Incorrect input");
                return 1;
            }
            index = dll_insert(a, index, value);
            if (index == 1)
                printf("Index out of range\n");
            else if(index == 2)
            {
                dll_clear(a);
                free(a);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        case 6:
            if (a->head == NULL)
                printf("List is empty\n");
            else
            {
                printf("Podaj index ");
                if (!scanf("%d", &index))
                {
                    dll_clear(a);
                    free(a);
                    printf("Incorrect input");
                    return 1;
                }
                index = dll_remove(a, index, &value);
                if (value == 1)
                    printf("Index out of range\n");
                else
                    printf("%d\n", index);
            }
            break;
        case 7:
            if (a->head == NULL)
                printf("List is empty\n");
            else
                printf("%d\n", dll_back(a, NULL));
            break;
        case 8:
            if (a->head == NULL)
                printf("List is empty\n");
            else
                printf("%d\n", dll_front(a, NULL));
            break;
        case 9:
            if (a->head == NULL)
                printf("1\n");
            else
                printf("0\n");
            break;
        case 10:
            printf("%d\n", dll_size(a));
            break;
        case 11:
            dll_clear(a);
            printf("\n");
            break;
        case 12:
            if (a->head == NULL)
                printf("List is empty\n");
            else
            {
                printf("Podaj index ");
                if (!scanf("%d", &index))
                {
                    dll_clear(a);
                    free(a);
                    printf("Incorrect input");
                    return 1;
                }
                index = dll_at(a, index, &value);
                if (value == 1)
                    printf("Index out of range\n");
                else
                    printf("%d\n", index);
            }
            break;
        case 13:
            if (a->head == NULL)
                printf("List is empty\n");
            else
            {
                dll_display(a);
                printf("\n");
            }
            break;
        case 14:
            if (a->head == NULL)
                printf("List is empty\n");
            else
            {
                dll_display_reverse(a);
                printf("\n");
            }
            break;
        default:
            printf("Incorrect input data\n");
            break;
        }
    }

    dll_clear(a);
    free(a);
    return 0; //Unreachable code
}

