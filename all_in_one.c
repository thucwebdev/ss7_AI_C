/**
 * ============================================================================
 * ALL_IN_ONE.c - TẤT CẢ CODE TRONG 1 FILE
 * ============================================================================
 * 
 * File này gộp tất cả code từ utils1.c, utils2.c, utils3.c, và main.c
 * vào 1 file duy nhất để dễ dàng compile và test.
 * 
 * Cách compile:
 *   gcc all_in_one.c -o program.exe
 * 
 * Cách chạy:
 *   ./program.exe
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>

// ============================================================================
// PHẦN 1: CÁC HÀM SỬ DỤNG FOR LOOP (từ utils1.c)
// ============================================================================

int sumArray_ForLoop(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int maxValue_ForLoop(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ============================================================================
// PHẦN 2: CÁC HÀM SỬ DỤNG WHILE LOOP (từ utils2.c)
// ============================================================================

int sumArray_WhileLoop(int arr[], int size) {
    int sum = 0;
    int i = 0;
    while (i < size) {
        sum += arr[i];
        i++;
    }
    return sum;
}

int maxValue_WhileLoop(int arr[], int size) {
    int max = arr[0];
    int i = 1;
    while (i < size) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    return max;
}

// ============================================================================
// PHẦN 3: CÁC HÀM SỬ DỤNG RECURSION (từ utils3.c)
// ============================================================================

int sumArray_Recursion(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    return arr[size - 1] + sumArray_Recursion(arr, size - 1);
}

int maxValue_Recursion(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int maxOfRest = maxValue_Recursion(arr, size - 1);
    if (arr[size - 1] > maxOfRest) {
        return arr[size - 1];
    } else {
        return maxOfRest;
    }
}

// ============================================================================
// PHẦN 4: HÀM TỐI ƯU ĐỀ XUẤT (từ analysis_optimization.c)
// ============================================================================

int maxValue_Optimized(int arr[], int size) {
    if (arr == NULL) {
        printf("Loi: Mang la NULL!\n");
        return INT_MIN;
    }
    if (size <= 0) {
        printf("Loi: Mang rong!\n");
        return INT_MIN;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ============================================================================
// PHẦN 5: HÀM TIỆN ÍCH
// ============================================================================

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void printSeparator() {
    printf("========================================\n");
}

// ============================================================================
// PHẦN 6: CHƯƠNG TRÌNH CHÍNH (từ main.c)
// ============================================================================

int main() {
    // Mảng test
    int arr[] = {15, 7, 23, 9, 42, 11, 8, 31, 5, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Header
    printSeparator();
    printf("  CHUONG TRINH TEST CAC HAM XU LY MANG\n");
    printSeparator();
    printf("\nMang test: ");
    printArray(arr, size);
    printf("Kich thuoc mang: %d phan tu\n", size);
    
    // ========================================
    // PHẦN 1: TEST TÍNH TỔNG
    // ========================================
    printf("\n");
    printSeparator();
    printf("  PHAN 1: TINH TONG CAC PHAN TU\n");
    printSeparator();
    
    clock_t start, end;
    double time1, time2, time3;
    
    // For Loop
    start = clock();
    int sum1 = sumArray_ForLoop(arr, size);
    end = clock();
    time1 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n1. Phuong phap FOR LOOP:\n");
    printf("   - Ket qua: %d\n", sum1);
    printf("   - Thoi gian: %.2f microseconds\n", time1);
    printf("   - Cach lam: Duyet mang bang vong lap for\n");
    
    // While Loop
    start = clock();
    int sum2 = sumArray_WhileLoop(arr, size);
    end = clock();
    time2 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n2. Phuong phap WHILE LOOP:\n");
    printf("   - Ket qua: %d\n", sum2);
    printf("   - Thoi gian: %.2f microseconds\n", time2);
    printf("   - Cach lam: Duyet mang bang vong lap while\n");
    
    // Recursion
    start = clock();
    int sum3 = sumArray_Recursion(arr, size);
    end = clock();
    time3 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n3. Phuong phap RECURSION:\n");
    printf("   - Ket qua: %d\n", sum3);
    printf("   - Thoi gian: %.2f microseconds\n", time3);
    printf("   - Cach lam: Ham tu goi chinh no (de quy)\n");
    
    printf("\n>> Kiem tra: ");
    if (sum1 == sum2 && sum2 == sum3) {
        printf("TAT CA CHO KET QUA GIONG NHAU! ✓\n");
    } else {
        printf("CO SAI SOT!\n");
    }
    
    // ========================================
    // PHẦN 2: TEST TÌM MAX
    // ========================================
    printf("\n");
    printSeparator();
    printf("  PHAN 2: TIM GIA TRI LON NHAT\n");
    printSeparator();
    
    // For Loop
    start = clock();
    int max1 = maxValue_ForLoop(arr, size);
    end = clock();
    time1 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n1. Phuong phap FOR LOOP:\n");
    printf("   - Ket qua: %d\n", max1);
    printf("   - Thoi gian: %.2f microseconds\n", time1);
    
    // While Loop
    start = clock();
    int max2 = maxValue_WhileLoop(arr, size);
    end = clock();
    time2 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n2. Phuong phap WHILE LOOP:\n");
    printf("   - Ket qua: %d\n", max2);
    printf("   - Thoi gian: %.2f microseconds\n", time2);
    
    // Recursion
    start = clock();
    int max3 = maxValue_Recursion(arr, size);
    end = clock();
    time3 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n3. Phuong phap RECURSION:\n");
    printf("   - Ket qua: %d\n", max3);
    printf("   - Thoi gian: %.2f microseconds\n", time3);
    
    printf("\n>> Kiem tra: ");
    if (max1 == max2 && max2 == max3) {
        printf("TAT CA CHO KET QUA GIONG NHAU! ✓\n");
    } else {
        printf("CO SAI SOT!\n");
    }
    
    // ========================================
    // PHẦN 3: TEST HÀM TỐI ƯU
    // ========================================
    printf("\n");
    printSeparator();
    printf("  PHAN 3: TEST HAM TOI UU\n");
    printSeparator();
    
    printf("\n>>> Test ham maxValue_Optimized():\n");
    
    // Test bình thường
    printf("\nTest 1 - Mang binh thuong:\n");
    int result1 = maxValue_Optimized(arr, size);
    printf("Max = %d\n", result1);
    
    // Test mảng rỗng
    printf("\nTest 2 - Mang rong:\n");
    maxValue_Optimized(arr, 0);
    
    // Test NULL
    printf("\nTest 3 - Con tro NULL:\n");
    maxValue_Optimized(NULL, 5);
    
    // Test mảng âm
    int arr_negative[] = {-5, -2, -10, -1, -20};
    printf("\nTest 4 - Mang so am:\n");
    int result4 = maxValue_Optimized(arr_negative, 5);
    printf("Max = %d\n", result4);
    
    // ========================================
    // KẾT LUẬN
    // ========================================
    printf("\n");
    printSeparator();
    printf("  KET LUAN\n");
    printSeparator();
    
    printf("\n>>> SO SANH:\n\n");
    printf("1. FOR LOOP:\n");
    printf("   + Nhanh nhat\n");
    printf("   + De doc, de hieu\n");
    printf("   + Khuyen nghi: SU DUNG cho hau het truong hop\n\n");
    
    printf("2. WHILE LOOP:\n");
    printf("   + Tuong duong for loop\n");
    printf("   + Code dai hon\n");
    printf("   + Khuyen nghi: Dung khi can dieu kien phuc tap\n\n");
    
    printf("3. RECURSION:\n");
    printf("   + Code ngan gon\n");
    printf("   + CHAM hon, TON BO NHO\n");
    printf("   + Khuyen nghi: CHI dung khi can thiet\n\n");
    
    printf(">>> KET LUAN CUOI CUNG:\n");
    printf("- FOR LOOP la lua chon TOT NHAT!\n");
    printf("- Luon kiem tra input truoc khi xu ly\n");
    printf("- Don gian > Phuc tap\n\n");
    
    printSeparator();
    printf("Chuong trinh ket thuc thanh cong!\n");
    printSeparator();
    
    return 0;
}

/**
 * ============================================================================
 * GHI CHÚ VỀ FILE NÀY
 * ============================================================================
 * 
 * File này được tạo ra để bạn có thể compile và test dễ dàng mà không cần
 * phải lo về việc link nhiều file.
 * 
 * CÁCH SỬ DỤNG:
 * 
 * 1. Compile:
 *    gcc all_in_one.c -o program.exe
 * 
 * 2. Chạy:
 *    ./program.exe
 * 
 * 3. Hoặc compile với warning:
 *    gcc -Wall all_in_one.c -o program.exe
 * 
 * 4. Hoặc compile với optimization:
 *    gcc -O2 all_in_one.c -o program.exe
 * 
 * HOẶC dùng online compiler:
 * - OnlineGDB: https://www.onlinegdb.com/
 * - Replit: https://replit.com/
 * - Copy toàn bộ file này và paste vào, nhấn Run!
 * 
 * ============================================================================
 */
