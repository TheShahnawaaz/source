#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void create(struct Array *a, int size)
{
    a->A = (int *)malloc(sizeof(int) * size);
    a->size = size;
    a->length = 0;
}
void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
    printf("\n");
}
void append(struct Array *a, int x)
{
    if (a->length == a->size)
    {
        a->A = (int *)realloc(a->A, sizeof(int) * a->size * 2);
        a->size *= 2;
    }
    a->A[a->length] = x;
    a->length++;
}
void insert(struct Array *a, int x, int index)
{
    if (index < 0 || index > a->length)
    {
        printf("Invalid Index!!!!\n");
        return;
    }

    if (a->length == a->size)
    {
        a->A = (int *)realloc(a->A, sizeof(int) * a->size * 2);
        a->size *= 2;
    }
    int i = a->length;
    for (; i != index; i--)
    {
        a->A[i] = a->A[i - 1];
    }
    a->A[i] = x;
    a->length++;
    return;
}
void delete (struct Array *a, int index)
{
    if (index < 0 || index > a->length)
    {
        printf("Invalid Index!!!!\n");
    }
    int i = index;
    for (; i < a->length; i++)
    {
        a->A[i] = a->A[i + 1];
    }
    a->length--;
}
int search(struct Array a, int key)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int binary_search(struct Array a, int key, int l, int r)
{
    // printf("%d %d\n",l,r);
    int mid = (l + r) / 2;
    if (l >= r)
    {
        return -1;
    }

    if (key == a.A[mid])
    {
        return mid;
    }
    else if (key > a.A[mid])
    {
        return binary_search(a, key, mid + 1, r);
    }
    else if (key < a.A[mid])
    {
        return binary_search(a, key, l, mid - 1);
    }
}
void set(struct Array *a, int index, int x)
{
    if (index < 0 || index > a->length)
    {
        printf("Invalid Index!!!!\n");
        return;
    }
    a->A[index] = x;
}
int get(struct Array a, int index)
{
    if (index < 0 || index > a.length)
    {
        printf("Invalid Index!!!!\n");
        return -1;
    }
    return a.A[index];
}
int max(struct Array a)
{
    int max = a.A[0];
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] > max)
        {
            max = a.A[i];
        }
    }
    return max;
}
int min(struct Array a)
{
    int min = a.A[0];
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] < min)
        {
            min = a.A[i];
        }
    }
    return min;
}
int sum(struct Array a)
{
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
        sum += a.A[i];
    }
    return sum;
}
int sum_reccursive(struct Array a, int length)
{
    if (length == 0)
    {
        return 0;
    }
    return sum_reccursive(a, length - 1) + a.A[length - 1];
}
float avg(struct Array a)
{
    return (float)sum(a) / a.length;
}
void reverse(struct Array *a)
{
    for (int i = 0; i < a->length / 2; i++)
    {
        int temp = a->A[i];
        a->A[i] = a->A[a->length - 1 - i];
        a->A[a->length - 1 - i] = temp;
    }
    return;
}
int coprime(int num1, int num2)
{
    int min, count, flag = 1;

    min = num1 < num2 ? num1 : num2;

    for (count = min; count >= 2; count--)
    {
        if (num1 % count == 0 && num2 % count == 0)
        {
            return count;
        }
    }

    return (flag);
}
void rotateLeft(struct Array *a, int d)
{
    if (coprime(a->length, d) == 1)
    {
        // int *current = &arr[d];
        int *left = &a->A[0];
        int prev_stored = *left;
        int To_put = a->A[d];
        for (int i = 0; i < a->length; i++)
        {
            // current = current < &arr[0] ? (current + arr_count) : (current);
            left = left < &a->A[0] ? (left + a->length) : (left);

            prev_stored = *left;
            *left = To_put;
            // current -= d;
            left -= d;
            To_put = prev_stored;
        }
    }
    else
    {
        int n = coprime(a->length, d);
        for (int j = 0; j < n; j++)
        {
            int *left = &a->A[0 + j];
            int prev_stored = *left;
            int To_put = a->A[d + j];
            for (int i = 0; i < a->length / n; i++)
            {
                // current = current < &arr[0] ? (current + arr_count) : (current);
                left = left < &a->A[0] ? (left + a->length) : (left);

                prev_stored = *left;
                *left = To_put;
                // current -= d;
                left -= d;
                To_put = prev_stored;
            }
        }
    }
    return;
}
int isSorted(struct Array a)
{
    for (int i = 0; i < a.length - 1; i++)
    {
        if (a.A[i] > a.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void insert_in_sorted(struct Array *a, int key)
{
    if (!isSorted(*a))
    {
        printf("Array is not Sorted!!!!\n");
        return;
    }

    for (int i = a->length - 1; i >= 0; i--)
    {
        if (a->A[i] > key)
        {
            a->A[i + 1] = a->A[i];
        }
        else
        {
            a->A[i + 1] = key;
            a->length++;
            return;
        }
    }
}
void rearrange_pos_neg(struct Array *a)
{
    int i = 0;
    int j = a->length - 1;
    while (j > i)
    {
        while (a->A[i] < 0)
            i++;
        while (a->A[j] >= 0)
            j--;
        if (i < j)
            swap(&a->A[i], &a->A[j]);
        // printf("Swapped!!!\n");
    }
}
struct Array *merge(struct Array a, struct Array b)
{
    // '''Hello'''
    if (!isSorted(a) || !isSorted(b))
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    while (i < a.length && j < b.length)
    {
        if (a.A[i] < b.A[j])
        {
            c->A[k++] = a.A[i++];
        }
        else
        {
            c->A[k++] = b.A[j++];
        }
    }
    for (; i < a.length; i++)
    {
        c->A[k++] = a.A[i++];
    }
    for (; j < b.length; j++)
    {
        c->A[k++] = b.A[j++];
    }
    c->length = a.length + b.length;
    c->size = 2 * c->length;
    return c;
}
struct Array *Union(struct Array a, struct Array b)
{
    // '''Hello'''
    if (!isSorted(a) || !isSorted(b))
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    while (i < a.length && j < b.length)
    {
        if (a.A[i] < b.A[j])
        {
            c->A[k++] = a.A[i++];
        }
        else if (a.A[i] > b.A[j])
        {
            c->A[k++] = b.A[j++];
        }
        else
        {
            c->A[k++] = a.A[i++];
            j++;
        }
    }
    for (; i < a.length; i++)
    {
        c->A[k++] = a.A[i++];
    }
    for (; j < b.length; j++)
    {
        c->A[k++] = b.A[j++];
    }
    c->length = k;
    c->size = 2 * c->length;
    return c;
}
struct Array *Intersection(struct Array a, struct Array b)
{
    // '''Hello'''
    if (!isSorted(a) || !isSorted(b))
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    while (i < a.length && j < b.length)
    {
        if (a.A[i] < b.A[j])
        {
            i++;
        }
        else if (a.A[i] > b.A[j])
        {
            j++;
        }
        else if (a.A[i] == b.A[j])
        {
            c->A[k++] = a.A[i++];
            j++;
        }
    }
    c->length = k;
    c->size = 2 * c->length;
    return c;
}
struct Array *Difference(struct Array a, struct Array b)
{
    // '''Hello'''
    if (!isSorted(a) || !isSorted(b))
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    while (i < a.length && j < b.length)
    {
        if (a.A[i] < b.A[j])
        {
            c->A[k++] = a.A[i++];
        }
        else if (a.A[i] > b.A[j])
        {
            j++;
        }
        else if(a.A[i] == b.A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < a.length; i++)
    {
        c->A[k++] = a.A[i++];
    }
    c->length = k;
    c->size = 2 * c->length;
    return c;
}
int main()
{
    struct Array a;
    create(&a, 5);
    append(&a, 3);
    append(&a, 13);
    append(&a, 16);
    append(&a, 19);
    append(&a, 60);
    display(a);
    // insert(&a, 6, 3);
    // display(a);
    // // reverse(&a);
    // // display(a);
    // // rotateLeft(&a, 2);
    // rearrange_pos_neg(&a);
    // display(a);
    // printf("Dmne");
    // printf("%d",search(a,15));
    // printf("%d ", get(a, 5));
    // printf("%d %d", min(a), max(a));
    struct Array b;
    create(&b, 20);
    append(&b, 13);
    append(&b, 19);
    append(&b, 25);
    append(&b, 58);
    append(&b, 95);
    display(b);
    display(*Difference(a, b));
    return 0;
}