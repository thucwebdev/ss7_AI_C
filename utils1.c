/**
 * utils1.c - Các hàm sử dụng vòng lặp FOR
 * 
 * File này chứa các hàm xử lý mảng sử dụng vòng lặp FOR truyền thống
 */

#include "utils.h"

/**
 * Hàm tính tổng các phần tử trong mảng bằng vòng lặp FOR
 * 
 * @param arr: Mảng số nguyên cần tính tổng
 * @param size: Kích thước của mảng
 * @return: Tổng các phần tử trong mảng
 * 
 * Cách hoạt động:
 * - Bước 1: Khởi tạo biến sum = 0
 * - Bước 2: Duyệt qua từng phần tử của mảng từ index 0 đến size-1
 * - Bước 3: Cộng dồn từng phần tử vào biến sum
 * - Bước 4: Trả về kết quả
 */
int sumArray_ForLoop(int arr[], int size) {
    // Bước 1: Khởi tạo biến tổng
    int sum = 0;
    
    // Bước 2 & 3: Duyệt mảng và cộng dồn
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // sum = sum + arr[i]
    }
    
    // Bước 4: Trả về kết quả
    return sum;
}


/**
 * Hàm tìm giá trị lớn nhất trong mảng bằng vòng lặp FOR
 * 
 * @param arr: Mảng số nguyên
 * @param size: Kích thước của mảng
 * @return: Giá trị lớn nhất trong mảng
 * 
 * Cách hoạt động:
 * - Bước 1: Giả sử phần tử đầu tiên là lớn nhất
 * - Bước 2: Duyệt qua các phần tử còn lại
 * - Bước 3: Nếu tìm thấy phần tử lớn hơn, cập nhật max
 * - Bước 4: Trả về giá trị lớn nhất
 */
int maxValue_ForLoop(int arr[], int size) {
    // Bước 1: Giả sử phần tử đầu là lớn nhất
    int max = arr[0];
    
    // Bước 2 & 3: So sánh với các phần tử còn lại
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Cập nhật max nếu tìm thấy giá trị lớn hơn
        }
    }
    
    // Bước 4: Trả về kết quả
    return max;
}
