#include <iostream>
#include <stdio.h >
#include <math.h>
#include <stdlib.h>
using namespace std;


template <typename T>
class Array
{
private:
    T *A;
    int size;
    int length;
    int coprime(int num1, int num2);
    void swap(T *x, T *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int size)
    {
        size = size;
        length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void create(int size);
    void display();
    void append(T x);
    void insert(T x, int index);
    T Delete(int index);
    int search(T key);
    int binary_search(T key, int l, int r);
    void set(int index, T x);
    T get(int index);
    T max();
    T min();
    T sum();
    T sum_reccursive(int length);
    float avg();
    void reverse();

    void rotateLeft(int d);
    int isSorted();
    void insert_in_sorted(T key);
    void rearrange_pos_neg();
    Array merge(Array b);
    Array Union(Array b);
    Array Intersection(Array b);
    Array Difference(Array b);
    Array Union2(Array b);
    Array Intersection2(Array b);
    Array Difference2(Array b);
    Array Concat(Array b);
};
template <typename T>
void Array<T>::create(int size)
{
    A = (int *)malloc(sizeof(int) * size);
    size = size;
    length = 0;
}
template <typename T>
void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    printf("\n");
}
template <class T>
void Array<T>::append(T x)
{
    if (length == size)
    {
        A = (T *)realloc(A, sizeof(T) * size * 2);
        size *= 2;
    }
    A[length] = x;
    length++;
}
template <class T>
void Array<T>::insert(T x, int index)
{
    if (index < 0 || index > length)
    {
        printf("Invalid Index!!!!\n");
        return;
    }

    if (length == size)
    {
        A = (T *)realloc(A, sizeof(T) * size * 2);
        size *= 2;
    }
    int i = length;
    for (; i != index; i--)
    {
        A[i] = A[i - 1];
    }
    A[i] = x;
    length++;
    return;
}
template <typename T>
T Array<T>::Delete(int index)
{
    if (index < 0 || index > length)
    {
        printf("Invalid Index!!!!\n");
    }
    int i = index;
    T x = A[index];
    for (; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    length--;
    return x;
}
template <class T>
int Array<T>::search(T key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}
template <class T>
void Array<T>::swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}
template <class T>
int Array<T>::binary_search(T key, int l, int r)
{
    // printf("%d %d\n",l,r);
    int mid = (l + r) / 2;
    if (l >= r)
    {
        return -1;
    }

    if (key == A[mid])
    {
        return mid;
    }
    else if (key > A[mid])
    {
        return binary_search(key, mid + 1, r);
    }
    else if (key < A[mid])
    {
        return binary_search(key, l, mid - 1);
    }
    return -1;
}
template <class T>
void Array<T>::set(int index, T x)
{
    if (index < 0 || index > length)
    {
        printf("Invalid Index!!!!\n");
        return;
    }
    A[index] = x;
}
template <class T>
T Array<T>::get(int index)
{
    if (index < 0 || index > length)
    {
        printf("Invalid Index!!!!\n");
        return -1;
    }
    return A[index];
}
template <class T>
T Array<T>::max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
template <class T>
T Array<T>::min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}
template <class T>
T Array<T>::sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}
template <class T>
T Array<T>::sum_reccursive(int length)
{
    if (length == 0)
    {
        return 0;
    }
    return sum_reccursive(length - 1) + A[length - 1];
}
template <class T>
float Array<T>::avg()
{
    return (float)sum() / length;
}
template <class T>
void Array<T>::reverse()
{
    for (int i = 0; i < length / 2; i++)
    {
        int temp = A[i];
        A[i] = A[length - 1 - i];
        A[length - 1 - i] = temp;
    }
    return;
}
template <class T>
int Array<T>::coprime(int num1, int num2)
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
template <class T>
void Array<T>::rotateLeft(int d)
{
    if (coprime(length, d) == 1)
    {
        // int *current = &arr[d];
        int *left = &A[0];
        int prev_stored = *left;
        int To_put = A[d];
        for (int i = 0; i < length; i++)
        {
            // current = current < &arr[0] ? (current + arr_count) : (current);
            left = left < &A[0] ? (left + length) : (left);

            prev_stored = *left;
            *left = To_put;
            // current -= d;
            left -= d;
            To_put = prev_stored;
        }
    }
    else
    {
        int n = coprime(length, d);
        for (int j = 0; j < n; j++)
        {
            int *left = &A[0 + j];
            int prev_stored = *left;
            int To_put = A[d + j];
            for (int i = 0; i < length / n; i++)
            {
                // current = current < &arr[0] ? (current + arr_count) : (current);
                left = left < &A[0] ? (left + length) : (left);

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
template <class T>
int Array<T>::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
template <class T>
void Array<T>::insert_in_sorted(T key)
{
    if (!isSorted())
    {
        printf("Array is not Sorted!!!!\n");
        return;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        if (A[i] > key)
        {
            A[i + 1] = A[i];
        }
        else
        {
            A[i + 1] = key;
            length++;
            return;
        }
    }
}
template <class T>
void Array<T>::rearrange_pos_neg()
{
    int i = 0;
    int j = length - 1;
    while (j > i)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
        // printf("Swapped!!!\n");
    }
}
template <class T>
Array<T> Array<T>::merge(Array b)
{
    Array<T> c;
    int i = 0, j = 0, k = 0;
    while (i < length && j < b.length)
    {
        if (A[i] < b.A[j])
        {
            c.A[k] = A[i];
            i++;
        }
        else
        {
            c.A[k] = b.A[j];
            j++;
        }
        k++;
    }
    while (i < length)
    {
        c.A[k] = A[i];
        i++;
        k++;
    }
    while (j < b.length)
    {
        c.A[k] = b.A[j];
        j++;
        k++;
    }
    c.length = length + b.length;
    return c;
}
template <class T>
Array<T> Array<T>::Union(Array b)
{
    // '''Hello'''
    if (!isSorted() || !b.isSorted())
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    Array<T> c;
    while (i < length && j < b.length)
    {
        if (A[i] < b.A[j])
        {
            c.A[k++] = A[i++];
        }
        else if (A[i] > b.A[j])
        {
            c.A[k++] = b.A[j++];
        }
        else
        {
            c.A[k++] = A[i++];
            j++;
        }
    }
    for (; i < length; i++)
    {
         c.A[k++] = A[i++];
    }
    for (; j < b.length; j++)
    {
         c.A[k++] = b.A[j++];
    }
     c.length = k;
     c.size = 2 *  c.length;
    return c;
}
template <class T>
Array<T> Array<T>::Intersection(struct Array b)
{
    // '''Hello'''
    if (!isSorted() || !b.isSorted())
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    Array<T> c;

    while (i < length && j < b.length)
    {
        if (A[i] < b.A[j])
        {
            i++;
        }
        else if (A[i] > b.A[j])
        {
            j++;
        }
        else if (A[i] == b.A[j])
        {
             c.A[k++] = A[i++];
            j++;
        }
    }
     c.length = k;
     c.size = 2 *  c.length;
    b.display();
    return c;
}
template <class T>
Array<T> Array<T>::Difference(struct Array b)
{
    // '''Hello'''
    if (!isSorted() || !b.isSorted())
    {
        printf("Array is not Sorted!!!!\n");
        return 0;
    }
    int i, j, k;
    i = j = k = 0;
    Array<T> c;
    while (i < length && j < b.length)
    {
        if (A[i] < b.A[j])
        {
             c.A[k++] = A[i++];
        }
        else if (A[i] > b.A[j])
        {
            j++;
        }
        else if (A[i] == b.A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
    {
         c.A[k++] = A[i++];
    }
     c.length = k;
     c.size = 2 *  c.length;
    return c;
}
template <class T>
Array<T> Array<T>::Concat(Array b)
{
    Array<T> c;
    for (int i = 0; i < length; i++)
    {
        c.A[i] = A[i];
    }
    for (int i = 0; i < b.length; i++)
    {
        c.A[i + length] = b.A[i];
    }
    c.length = length + b.length;
    c.size = 2 * c.length;
    return c;
}
template <class T>
Array<T> Array<T>::Union2(Array b)
{
    Array<T> c;
    int i, j, k;
    i = j = k = 0;
    for (; i < length; i++)
    {
        c.A[k++] = A[i];
    }
    for (; j < b.length; j++)
    {
        if (search(b.A[j]) == -1)
        {
            // printf("%d ",search(b.A[j]));
            c.A[k++] = b.A[j];
        }
    }
    c.length = k;
    return c;
}
template <class T>
Array<T> Array<T>::Intersection2(Array b)
{
    Array<T> c;
    int i, j, k;
    i = j = k = 0;
    for (; j < b.length; j++)
    {
        if (search(b.A[j]) != -1)
        {
            c.A[k++] = b.A[j];
        }
    }
    c.length = k;
    return c;
}
template <class T>
Array<T> Array<T>::Difference2(Array b)
{
    Array<T> c;
    
    int i, j, k;
    i = j = k = 0;
    for (; i < length; i++)
    {
        if (b.search(A[i]) == -1)
        {
            c.A[k++] = A[i];
        }
    }
    c.length = k;
    return c;
}
int main()
{
    Array<float> a(10);
    a.append(35);
    a.append(40);
    a.append(15);
    a.append(30);
    a.insert(0, 0);
    cout << a.avg() << endl;
    cout << a.isSorted() << endl;
    a.insert_in_sorted(5);
    cout << a.isSorted() << endl;
    a.display();
    a.rearrange_pos_neg();
    cout << a.isSorted() << endl;
    cout << a.search(20) << endl;
    cout << a.binary_search(30, 0, 5) << endl;
    a.display();
    a.Delete(a.search(5));
    a.display();
    Array<float> b(10);
    b.append(5);
    b.append(15);
    b.append(25);
    b.append(35);
    b.insert(0, 0);
    b.display();
    // Array c = *(a.merge(b));
    // c.display();
    // a.display();
    // b.display();

    Array<float> c = a.Difference2(b);
    // a.display();
    // b.display();
    c.display();

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
    // struct Array b;
    // create(&b, 20);
    // append(&b, 13);
    // append(&b, 19);
    // append(&b, 25);
    // append(&b, 58);
    // append(&b, 95);
    // display(b);
    // display(*Difference(a, b));
    return 0;
}