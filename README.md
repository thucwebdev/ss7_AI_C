# 🎯 DỰ ÁN C - XỬ LÝ MẢNG VỚI NHIỀU PHƯƠNG PHÁP

## 📁 Cấu trúc dự án

```
C/
├── main.c          # File chính, gọi và test các hàm
├── utils.h         # Header file - khai báo các hàm
├── utils1.c        # Các hàm dùng FOR LOOP
├── utils2.c        # Các hàm dùng WHILE LOOP
├── utils3.c        # Các hàm dùng RECURSION (Đệ quy)
└── factorial.c     # File tính giai thừa (độc lập)
```

## 🔧 Cách biên dịch và chạy

### Trên Windows (PowerShell/CMD):
```bash
# Biên dịch tất cả các file
gcc main.c utils1.c utils2.c utils3.c -o program

# Chạy chương trình
./program
```

### Trên Linux/Mac:
```bash
# Biên dịch
gcc main.c utils1.c utils2.c utils3.c -o program

# Chạy
./program
```

### Debug mode (có thông tin debug):
```bash
gcc -g main.c utils1.c utils2.c utils3.c -o program_debug
```

## 📊 Các hàm được implement

### 1. **sumArray** - Tính tổng mảng
- `sumArray_ForLoop()` - Dùng vòng lặp for
- `sumArray_WhileLoop()` - Dùng vòng lặp while  
- `sumArray_Recursion()` - Dùng đệ quy

### 2. **maxValue** - Tìm giá trị lớn nhất
- `maxValue_ForLoop()` - Dùng vòng lặp for
- `maxValue_WhileLoop()` - Dùng vòng lặp while
- `maxValue_Recursion()` - Dùng đệ quy

## 🎯 Mục đích dự án

1. **So sánh các cách viết hàm khác nhau**
2. **Đo lường performance** của từng phương pháp
3. **Học cách tổ chức code** thành nhiều file
4. **Thực hành header file** và module hóa code

## 📈 Kết quả mong đợi

Chương trình sẽ:
- ✅ Test cả 3 phương pháp tính tổng
- ✅ Test cả 3 phương pháp tìm max
- ✅ So sánh thời gian thực thi
- ✅ Kiểm tra tính đúng đắn của kết quả
- ✅ Đưa ra nhận xét và khuyến nghị

## 🔍 Phân tích AI đã tạo

### ✅ Điểm mạnh:
1. **Code có cấu trúc tốt** - Tách biệt thành nhiều file
2. **Chú thích đầy đủ** - Giải thích từng bước
3. **Có so sánh performance** - Đo thời gian chạy
4. **Test đầy đủ** - Kiểm tra cả 3 phương pháp
5. **Dễ mở rộng** - Có thể thêm hàm mới dễ dàng

### ⚠️ Có thể cải thiện:
1. **Error handling** - Chưa kiểm tra mảng rỗng
2. **Input validation** - Chưa validate size < 0
3. **Memory** - Có thể tối ưu bộ nhớ cho đệ quy
4. **Testing** - Chưa có unit test tự động

---

**Ghi chú**: File này được AI tạo ra và đã được review, tối ưu hóa theo best practices.
