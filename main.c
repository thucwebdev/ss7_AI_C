/**
 * main.c - Chương trình chính để test các hàm xử lý mảng
 * 
 * Chương trình này demo 3 cách khác nhau để:
 * 1. Tính tổng các phần tử trong mảng
 * 2. Tìm giá trị lớn nhất trong mảng
 * 
 * Các phương pháp: For Loop, While Loop, Recursion
 */

#include <stdio.h>
#include <time.h>
#include "utils.h"

// Hàm in mảng ra màn hình
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

// Hàm vẽ đường phân cách
void printSeparator() {
    printf("========================================\n");
}

int main() {
    // Bước 1: Khai báo và khởi tạo mảng test
    int arr[] = {15, 7, 23, 9, 42, 11, 8, 31, 5, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Bước 2: Hiển thị thông tin chương trình
    printSeparator();
    printf("  CHUONG TRINH TEST CAC HAM XU LY MANG\n");
    printSeparator();
    printf("\nMang test: ");
    printArray(arr, size);
    printf("Kich thuoc mang: %d phan tu\n", size);
    
    // ============================================
    // PHẦN 1: TEST CÁC HÀM TÍNH TỔNG (sumArray)
    // ============================================
    printf("\n");
    printSeparator();
    printf("  PHAN 1: TINH TONG CAC PHAN TU\n");
    printSeparator();
    
    // Phương pháp 1: For Loop
    clock_t start = clock();
    int sum1 = sumArray_ForLoop(arr, size);
    clock_t end = clock();
    double time1 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n1. Phuong phap FOR LOOP (utils1.c):\n");
    printf("   - Ket qua: %d\n", sum1);
    printf("   - Thoi gian: %.2f microseconds\n", time1);
    printf("   - Cach lam: Duyet mang bang vong lap for, cong don tung phan tu\n");
    
    // Phương pháp 2: While Loop
    start = clock();
    int sum2 = sumArray_WhileLoop(arr, size);
    end = clock();
    double time2 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n2. Phuong phap WHILE LOOP (utils2.c):\n");
    printf("   - Ket qua: %d\n", sum2);
    printf("   - Thoi gian: %.2f microseconds\n", time2);
    printf("   - Cach lam: Duyet mang bang vong lap while, logic tuong tu for\n");
    
    // Phương pháp 3: Recursion
    start = clock();
    int sum3 = sumArray_Recursion(arr, size);
    end = clock();
    double time3 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n3. Phuong phap RECURSION (utils3.c):\n");
    printf("   - Ket qua: %d\n", sum3);
    printf("   - Thoi gian: %.2f microseconds\n", time3);
    printf("   - Cach lam: Ham tu goi chinh no, chia bai toan thanh bai toan nho hon\n");
    
    // Kiểm tra tính đúng đắn
    printf("\n>> Kiem tra: ");
    if (sum1 == sum2 && sum2 == sum3) {
        printf("TAT CA CAC PHUONG PHAP CHO KET QUA GIONG NHAU! ✓\n");
    } else {
        printf("CO SAI SOT! Cac ket qua khong giong nhau.\n");
    }
    
    // ============================================
    // PHẦN 2: TEST CÁC HÀM TÌM MAX (maxValue)
    // ============================================
    printf("\n");
    printSeparator();
    printf("  PHAN 2: TIM GIA TRI LON NHAT\n");
    printSeparator();
    
    // Phương pháp 1: For Loop
    start = clock();
    int max1 = maxValue_ForLoop(arr, size);
    end = clock();
    time1 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n1. Phuong phap FOR LOOP (utils1.c):\n");
    printf("   - Ket qua: %d\n", max1);
    printf("   - Thoi gian: %.2f microseconds\n", time1);
    printf("   - Cach lam: Duyet mang, so sanh va cap nhat max\n");
    
    // Phương pháp 2: While Loop
    start = clock();
    int max2 = maxValue_WhileLoop(arr, size);
    end = clock();
    time2 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n2. Phuong phap WHILE LOOP (utils2.c):\n");
    printf("   - Ket qua: %d\n", max2);
    printf("   - Thoi gian: %.2f microseconds\n", time2);
    printf("   - Cach lam: Dung while loop, logic tuong tu for loop\n");
    
    // Phương pháp 3: Recursion
    start = clock();
    int max3 = maxValue_Recursion(arr, size);
    end = clock();
    time3 = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("\n3. Phuong phap RECURSION (utils3.c):\n");
    printf("   - Ket qua: %d\n", max3);
    printf("   - Thoi gian: %.2f microseconds\n", time3);
    printf("   - Cach lam: So sanh phan tu cuoi voi max cua phan con lai (de quy)\n");
    
    // Kiểm tra tính đúng đắn
    printf("\n>> Kiem tra: ");
    if (max1 == max2 && max2 == max3) {
        printf("TAT CA CAC PHUONG PHAP CHO KET QUA GIONG NHAU! ✓\n");
    } else {
        printf("CO SAI SOT! Cac ket qua khong giong nhau.\n");
    }
    
    // ============================================
    // PHẦN 3: KẾT LUẬN VÀ KHUYẾN NGHỊ
    // ============================================
    printf("\n");
    printSeparator();
    printf("  KET LUAN VA KHUYEN NGHI\n");
    printSeparator();
    printf("\n>>> SO SANH CAC PHUONG PHAP:\n\n");
    
    printf("1. FOR LOOP:\n");
    printf("   + Uu diem: Nhanh, de doc, hieu qua\n");
    printf("   + Nhuoc diem: Khong co\n");
    printf("   + Khuyen nghi: DUNG cho hau het cac truong hop\n\n");
    
    printf("2. WHILE LOOP:\n");
    printf("   + Uu diem: Tuong duong for loop\n");
    printf("   + Nhuoc diem: Code dai hon mot chut\n");
    printf("   + Khuyen nghi: Dung khi khong biet truoc so lan lap\n\n");
    
    printf("3. RECURSION:\n");
    printf("   + Uu diem: Code ngan gon, de hieu logic\n");
    printf("   + Nhuoc diem: Cham hon, ton bo nho (call stack)\n");
    printf("   + Khuyen nghi: CHI dung cho cac bai toan co tinh chat de quy tu nhien\n\n");
    
    printf(">>> GOI Y TOI UU:\n");
    printf("- Nen SU DUNG: For Loop cho cac bai toan xu ly mang\n");
    printf("- Tranh dung: Recursion cho mang lon (de tran stack)\n");
    printf("- Nen viet: Code de doc, de bao tri hon la qua phuc tap\n\n");
    
    printSeparator();
    printf("Chuong trinh ket thuc thanh cong!\n");
    printSeparator();
    
    return 0;
}
