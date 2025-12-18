#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc Student
struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Hàm in danh sách sinh viên dưới dạng bảng
void printStudents(struct Student students[], int count) {
    printf("\n");
    printf("========================================================================\n");
    printf("| %-5s | %-25s | %-5s | %-8s |\n", "ID", "Ten", "Tuoi", "GPA");
    printf("========================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-25s | %-5d | %-8.2f |\n", 
               students[i].id, 
               students[i].name, 
               students[i].age, 
               students[i].gpa);
    }
    
    printf("========================================================================\n");
}

int main() {
    // Khởi tạo mảng 3 sinh viên mẫu
    struct Student students[3] = {
        {1, "Nguyen Van A", 20, 3.75},
        {2, "Tran Thi B", 21, 3.92},
        {3, "Le Van C", 19, 3.45}
    };
    
    printf("CHUONG TRINH QUAN LY SINH VIEN\n");
    printf("================================\n");
    printf("Danh sach sinh vien:\n");
    
    // In danh sách sinh viên
    printStudents(students, 3);
    
    return 0;
}
