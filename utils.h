/**
 * utils.h - Header file chứa khai báo các hàm tiện ích
 * 
 * File này chứa các khai báo hàm để tính tổng và tìm giá trị lớn nhất
 * của một mảng số nguyên theo nhiều phương pháp khác nhau.
 */

#ifndef UTILS_H
#define UTILS_H

// ============================================
// CÁC HÀM TÍNH TỔNG MẢNG (sumArray)
// ============================================

/**
 * Tính tổng các phần tử trong mảng bằng vòng lặp FOR
 * File: utils1.c
 */
int sumArray_ForLoop(int arr[], int size);

/**
 * Tính tổng các phần tử trong mảng bằng vòng lặp WHILE
 * File: utils2.c
 */
int sumArray_WhileLoop(int arr[], int size);

/**
 * Tính tổng các phần tử trong mảng bằng ĐỆ QUY (Recursion)
 * File: utils3.c
 */
int sumArray_Recursion(int arr[], int size);


// ============================================
// CÁC HÀM TÌM GIÁ TRỊ LỚN NHẤT (maxValue)
// ============================================

/**
 * Tìm giá trị lớn nhất trong mảng bằng vòng lặp FOR
 * File: utils1.c
 */
int maxValue_ForLoop(int arr[], int size);

/**
 * Tìm giá trị lớn nhất trong mảng bằng vòng lặp WHILE
 * File: utils2.c
 */
int maxValue_WhileLoop(int arr[], int size);

/**
 * Tìm giá trị lớn nhất trong mảng bằng ĐỆ QUY (Recursion)
 * File: utils3.c
 */
int maxValue_Recursion(int arr[], int size);

#endif // UTILS_H
