/**
 * utils3.c - Các hàm sử dụng ĐỆ QUY (Recursion)
 * 
 * File này chứa các hàm xử lý mảng sử dụng phương pháp đệ quy
 * Đệ quy là kỹ thuật hàm tự gọi chính nó với tham số thay đổi
 */

#include "utils.h"

/**
 * Hàm tính tổng các phần tử trong mảng bằng ĐỆ QUY
 * 
 * @param arr: Mảng số nguyên cần tính tổng
 * @param size: Kích thước của mảng
 * @return: Tổng các phần tử trong mảng
 * 
 * Cách hoạt động (Đệ quy):
 * - Điều kiện dừng: Nếu size = 0, trả về 0
 * - Bước đệ quy: Tổng = phần tử cuối + tổng của (size-1) phần tử đầu
 * 
 * Ví dụ: sumArray([1,2,3,4], 4)
 *   = 4 + sumArray([1,2,3], 3)
 *   = 4 + 3 + sumArray([1,2], 2)
 *   = 4 + 3 + 2 + sumArray([1], 1)
 *   = 4 + 3 + 2 + 1 + sumArray([], 0)
 *   = 4 + 3 + 2 + 1 + 0
 *   = 10
 */
int sumArray_Recursion(int arr[], int size) {
    // Điều kiện dừng: Mảng rỗng có tổng = 0
    if (size == 0) {
        return 0;
    }
    
    // Bước đệ quy: Tổng = phần tử cuối + tổng phần còn lại
    return arr[size - 1] + sumArray_Recursion(arr, size - 1);
}


/**
 * Hàm tìm giá trị lớn nhất trong mảng bằng ĐỆ QUY
 * 
 * @param arr: Mảng số nguyên
 * @param size: Kích thước của mảng
 * @return: Giá trị lớn nhất trong mảng
 * 
 * Cách hoạt động (Đệ quy):
 * - Điều kiện dừng: Nếu size = 1, trả về phần tử duy nhất
 * - Bước đệ quy: So sánh phần tử cuối với max của phần còn lại
 * 
 * Ví dụ: maxValue([3,7,2,9,1], 5)
 *   So sánh: 1 vs maxValue([3,7,2,9], 4)
 *   So sánh: 9 vs maxValue([3,7,2], 3)
 *   So sánh: 2 vs maxValue([3,7], 2)
 *   So sánh: 7 vs maxValue([3], 1) = 3
 *   Kết quả: max(1, max(9, max(2, max(7, 3)))) = 9
 */
int maxValue_Recursion(int arr[], int size) {
    // Điều kiện dừng: Chỉ còn 1 phần tử
    if (size == 1) {
        return arr[0];
    }
    
    // Bước đệ quy: Tìm max của phần còn lại
    int maxOfRest = maxValue_Recursion(arr, size - 1);
    
    // So sánh phần tử cuối với max của phần còn lại
    if (arr[size - 1] > maxOfRest) {
        return arr[size - 1];
    } else {
        return maxOfRest;
    }
}
