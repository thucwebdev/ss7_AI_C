/**
 * utils2.c - Các hàm sử dụng vòng lặp WHILE
 * 
 * File này chứa các hàm xử lý mảng sử dụng vòng lặp WHILE
 */

#include "utils.h"

/**
 * Hàm tính tổng các phần tử trong mảng bằng vòng lặp WHILE
 * 
 * @param arr: Mảng số nguyên cần tính tổng
 * @param size: Kích thước của mảng
 * @return: Tổng các phần tử trong mảng
 * 
 * Cách hoạt động:
 * - Bước 1: Khởi tạo biến sum = 0 và index = 0
 * - Bước 2: Lặp khi index < size
 * - Bước 3: Cộng dồn arr[index] vào sum và tăng index
 * - Bước 4: Trả về kết quả
 */
int sumArray_WhileLoop(int arr[], int size) {
    // Bước 1: Khởi tạo các biến
    int sum = 0;
    int i = 0;
    
    // Bước 2 & 3: Lặp và cộng dồn
    while (i < size) {
        sum += arr[i];  // Cộng phần tử hiện tại vào sum
        i++;            // Tăng index lên 1
    }
    
    // Bước 4: Trả về kết quả
    return sum;
}


/**
 * Hàm tìm giá trị lớn nhất trong mảng bằng vòng lặp WHILE
 * 
 * @param arr: Mảng số nguyên
 * @param size: Kích thước của mảng
 * @return: Giá trị lớn nhất trong mảng
 * 
 * Cách hoạt động:
 * - Bước 1: Khởi tạo max = phần tử đầu, index = 1
 * - Bước 2: Lặp khi index < size
 * - Bước 3: So sánh và cập nhật max nếu cần
 * - Bước 4: Trả về giá trị lớn nhất
 */
int maxValue_WhileLoop(int arr[], int size) {
    // Bước 1: Khởi tạo
    int max = arr[0];
    int i = 1;
    
    // Bước 2 & 3: Lặp và so sánh
    while (i < size) {
        if (arr[i] > max) {
            max = arr[i];  // Cập nhật max
        }
        i++;  // Tăng index
    }
    
    // Bước 4: Trả về kết quả
    return max;
}
