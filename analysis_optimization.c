/**
 * ============================================================================
 * PHÂN TÍCH VÀ TỐI ỦU HÓA - SO SÁNH CÁC HÀM maxValue
 * ============================================================================
 * 
 * File này chứa phân tích chi tiết về các hàm maxValue được viết theo
 * 3 phương pháp khác nhau trong dự án.
 */

/**
 * ============================================================================
 * 1. SO SÁNH CÁC PHIÊN BẢN maxValue HIỆN TẠI
 * ============================================================================
 * 
 * PHIÊN BẢN 1: maxValue_ForLoop (utils1.c)
 * -----------------------------------------
 * int maxValue_ForLoop(int arr[], int size) {
 *     int max = arr[0];
 *     for (int i = 1; i < size; i++) {
 *         if (arr[i] > max) {
 *             max = arr[i];
 *         }
 *     }
 *     return max;
 * }
 * 
 * Ưu điểm:
 * + Nhanh nhất (O(n) time complexity)
 * + Ít tốn bộ nhớ nhất (O(1) space complexity)
 * + Code dễ đọc, dễ hiểu
 * + Không có overhead của function call
 * 
 * Nhược điểm:
 * - Không kiểm tra mảng rỗng
 * - Giả định mảng có ít nhất 1 phần tử
 * 
 * 
 * PHIÊN BẢN 2: maxValue_WhileLoop (utils2.c)
 * -----------------------------------------
 * int maxValue_WhileLoop(int arr[], int size) {
 *     int max = arr[0];
 *     int i = 1;
 *     while (i < size) {
 *         if (arr[i] > max) {
 *             max = arr[i];
 *         }
 *         i++;
 *     }
 *     return max;
 * }
 * 
 * Ưu điểm:
 * + Tương đương với for loop về performance
 * + Logic rõ ràng
 * 
 * Nhược điểm:
 * - Code dài hơn for loop một chút
 * - Cần quản lý biến đếm thủ công
 * - Dễ quên tăng biến đếm (bug tiềm ẩn)
 * 
 * 
 * PHIÊN BẢN 3: maxValue_Recursion (utils3.c)
 * -----------------------------------------
 * int maxValue_Recursion(int arr[], int size) {
 *     if (size == 1) {
 *         return arr[0];
 *     }
 *     int maxOfRest = maxValue_Recursion(arr, size - 1);
 *     if (arr[size - 1] > maxOfRest) {
 *         return arr[size - 1];
 *     } else {
 *         return maxOfRest;
 *     }
 * }
 * 
 * Ưu điểm:
 * + Code ngắn gọn, elegant
 * + Thể hiện tư duy chia nhỏ bài toán
 * 
 * Nhược điểm:
 * - CHẬM hơn nhiều (overhead của function call)
 * - TỐN BỘ NHỚ (O(n) space - call stack)
 * - Nguy cơ STACK OVERFLOW với mảng lớn
 * - Khó debug hơn
 */

/**
 * ============================================================================
 * 2. BẢNG SO SÁNH PERFORMANCE
 * ============================================================================
 * 
 * | Tiêu chí           | For Loop | While Loop | Recursion |
 * |--------------------|----------|------------|-----------|
 * | Time Complexity    | O(n)     | O(n)       | O(n)      |
 * | Space Complexity   | O(1)     | O(1)       | O(n)      |
 * | Tốc độ thực thi    | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐   | ⭐⭐⭐     |
 * | Dễ đọc             | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐    | ⭐⭐⭐⭐   |
 * | An toàn            | ⭐⭐⭐    | ⭐⭐⭐      | ⭐⭐       |
 * | Khuyến nghị sử dụng| 100%     | 80%        | 20%       |
 * 
 * KẾT LUẬN: For Loop là lựa chọn TỐT NHẤT!
 */

/**
 * ============================================================================
 * 3. HÀM CHUẨN TỐI ƯU ĐỀ XUẤT
 * ============================================================================
 * 
 * Dựa trên phân tích trên, đây là hàm maxValue CHUẨN và TỐI ƯU nhất:
 */

#include <stdio.h>
#include <limits.h>  // Để dùng INT_MIN

/**
 * Hàm tìm giá trị lớn nhất trong mảng - PHIÊN BẢN TỐI ƯU
 * 
 * Hàm này kết hợp ưu điểm của for loop với error handling tốt
 * 
 * @param arr: Mảng số nguyên
 * @param size: Kích thước của mảng
 * @return: Giá trị lớn nhất, hoặc INT_MIN nếu mảng rỗng
 * 
 * Cải tiến:
 * - Kiểm tra mảng rỗng
 * - Kiểm tra con trỏ NULL
 * - Dùng for loop (nhanh nhất)
 * - Code rõ ràng, dễ maintain
 * - Có documentation đầy đủ
 */
int maxValue_Optimized(int arr[], int size) {
    // BƯỚC 1: Kiểm tra input hợp lệ
    if (arr == NULL) {
        printf("Loi: Mang la NULL!\n");
        return INT_MIN;
    }
    
    if (size <= 0) {
        printf("Loi: Mang rong!\n");
        return INT_MIN;
    }
    
    // BƯỚC 2: Khởi tạo max với phần tử đầu tiên
    int max = arr[0];
    
    // BƯỚC 3: Duyệt qua các phần tử còn lại
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // BƯỚC 4: Trả về kết quả
    return max;
}

/**
 * ============================================================================
 * 4. KHUYẾN NGHỊ IMPLEMENTATION
 * ============================================================================
 * 
 * NÊN LÀM:
 * ✅ Dùng For Loop cho các bài toán duyệt mảng
 * ✅ Kiểm tra input (NULL, size <= 0)
 * ✅ Viết documentation đầy đủ
 * ✅ Đặt tên biến rõ ràng
 * ✅ Sử dụng const cho tham số không thay đổi: const int arr[]
 * 
 * KHÔNG NÊN:
 * ❌ Dùng Recursion cho mảng lớn (> 1000 phần tử)
 * ❌ Bỏ qua kiểm tra input
 * ❌ Code quá phức tạp không cần thiết
 * ❌ Optimize sớm mà chưa đo performance
 * 
 * 
 * BEST PRACTICES:
 * 1. Đơn giản > Phức tạp
 * 2. Rõ ràng > Thông minh
 * 3. Đúng > Nhanh
 * 4. Maintainable > Elegant
 */

/**
 * ============================================================================
 * 5. CODE MẪU SỬ DỤNG HÀM TỐI ƯU
 * ============================================================================
 */

// Hàm main để demo hàm tối ưu
int main() {
    printf("================================================\n");
    printf("  DEMO HAM maxValue TOI UU\n");
    printf("================================================\n\n");
    
    // Test case 1: Mảng bình thường
    int arr1[] = {15, 7, 23, 9, 42, 11, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test 1 - Mang binh thuong:\n");
    printf("Mang: [15, 7, 23, 9, 42, 11, 8]\n");
    printf("Max = %d\n\n", maxValue_Optimized(arr1, size1));
    
    // Test case 2: Mảng có 1 phần tử
    int arr2[] = {100};
    int size2 = 1;
    printf("Test 2 - Mang 1 phan tu:\n");
    printf("Mang: [100]\n");
    printf("Max = %d\n\n", maxValue_Optimized(arr2, size2));
    
    // Test case 3: Mảng rỗng
    printf("Test 3 - Mang rong:\n");
    int result3 = maxValue_Optimized(arr1, 0);
    printf("Result: %d (INT_MIN)\n\n", result3);
    
    // Test case 4: Con trỏ NULL
    printf("Test 4 - Con tro NULL:\n");
    int result4 = maxValue_Optimized(NULL, 5);
    printf("Result: %d (INT_MIN)\n\n", result4);
    
    // Test case 5: Mảng có số âm
    int arr5[] = {-5, -2, -10, -1, -20};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test 5 - Mang so am:\n");
    printf("Mang: [-5, -2, -10, -1, -20]\n");
    printf("Max = %d\n\n", maxValue_Optimized(arr5, size5));
    
    printf("================================================\n");
    printf("KET LUAN:\n");
    printf("- Ham maxValue_Optimized xu ly tot moi truong hop\n");
    printf("- An toan, nhanh, de doc\n");
    printf("- Day la PHIEN BAN CHUAN nen su dung!\n");
    printf("================================================\n");
    
    return 0;
}

/**
 * ============================================================================
 * 6. TÓM TẮT KẾT QUẢ PHÂN TÍCH
 * ============================================================================
 * 
 * QUÁ TRÌNH AI TẠO RA:
 * 1. AI tạo 3 phiên bản khác nhau của hàm maxValue
 * 2. Mỗi phiên bản trong 1 file riêng (utils1.c, utils2.c, utils3.c)
 * 3. Tất cả đều HOẠT ĐỘNG ĐÚNG
 * 4. Tất cả đều CHO KẾT QUẢ GIỐNG NHAU
 * 
 * SAU KHI PHÂN TÍCH:
 * 1. For Loop là TỐT NHẤT về mọi mặt
 * 2. While Loop tương đương nhưng code dài hơn
 * 3. Recursion chỉ nên dùng cho mục đích học tập
 * 
 * ĐỀ XUẤT CUỐI CÙNG:
 * → Sử dụng maxValue_Optimized() như hàm CHUẨN duy nhất
 * → Loại bỏ 3 phiên bản cũ để code gọn gàng hơn
 * → Hoặc giữ lại để tham khảo và học tập
 * 
 * KINH NGHIỆM RÚT RA:
 * ✓ Đơn giản là tốt nhất
 * ✓ For loop là lựa chọn mặc định cho duyệt mảng
 * ✓ Luôn kiểm tra input trước khi xử lý
 * ✓ Documentation quan trọng không kém code
 * ✓ Test nhiều trường hợp để đảm bảo đúng
 * 
 * ============================================================================
 */
