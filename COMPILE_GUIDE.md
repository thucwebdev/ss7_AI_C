# 🔧 HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY

## Cách 1: Sử dụng GCC (MinGW trên Windows)

### Cài đặt GCC:
1. Tải MinGW: https://sourceforge.net/projects/mingw/
2. Hoặc tải MSYS2: https://www.msys2.org/
3. Thêm đường dẫn vào PATH

### Biên dịch:
```bash
cd d:\ptit\C
gcc main.c utils1.c utils2.c utils3.c -o program.exe
```

### Chạy:
```bash
./program.exe
```

---

## Cách 2: Sử dụng Visual Studio (MSVC)

### Từ Developer Command Prompt:
```bash
cd d:\ptit\C
cl main.c utils1.c utils2.c utils3.c /Fe:program.exe
```

### Chạy:
```bash
program.exe
```

---

## Cách 3: Sử dụng Online Compiler

### Các website online compiler:
- **OnlineGDB**: https://www.onlinegdb.com/
- **Replit**: https://replit.com/
- **Programiz**: https://www.programiz.com/c-programming/online-compiler/

### Cách làm:
1. Copy nội dung của `utils.h`
2. Copy nội dung của `utils1.c`, `utils2.c`, `utils3.c`
3. Copy nội dung của `main.c`
4. Paste tất cả vào 1 file (hoặc tạo nhiều file nếu compiler hỗ trợ)
5. Nhấn Run

---

## Cách 4: Sử dụng VS Code với C/C++ Extension

### Cài đặt:
1. Cài extension "C/C++" của Microsoft
2. Cài MinGW hoặc MSVC
3. Cấu hình tasks.json

### File tasks.json mẫu:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "gcc",
            "args": [
                "main.c",
                "utils1.c",
                "utils2.c",
                "utils3.c",
                "-o",
                "program.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

### Chạy:
- Nhấn `Ctrl + Shift + B` để build
- Nhấn `F5` để debug

---

## Cách 5: Gộp tất cả vào 1 file (đơn giản nhất)

Tạo file `all_in_one.c`:

```c
// Bỏ hết nội dung utils1.c, utils2.c, utils3.c vào đây
// (không cần #include "utils.h")

// Sau đó copy main.c vào cuối
```

Biên dịch:
```bash
gcc all_in_one.c -o program.exe
```

---

## ⚠️ Lưu ý quan trọng

1. **Thứ tự file quan trọng**: Các file `.c` chứa implementation phải được compile cùng nhau
2. **Header file**: `utils.h` chỉ cần include, không cần compile riêng
3. **Linker**: GCC tự động link các file object lại với nhau
4. **Debug**: Thêm flag `-g` để debug: `gcc -g main.c utils1.c utils2.c utils3.c -o program.exe`
5. **Warning**: Thêm `-Wall` để hiện tất cả warning: `gcc -Wall ...`

---

## 🎯 Các lệnh hữu ích

### Compile với optimization:
```bash
gcc -O2 main.c utils1.c utils2.c utils3.c -o program_optimized.exe
```

### Compile với debug info:
```bash
gcc -g main.c utils1.c utils2.c utils3.c -o program_debug.exe
```

### Compile với warnings:
```bash
gcc -Wall -Wextra main.c utils1.c utils2.c utils3.c -o program.exe
```

### Xem preprocessor output:
```bash
gcc -E main.c > main_preprocessed.c
```

---

## 📊 Kiểm tra kết quả

Sau khi chạy thành công, bạn sẽ thấy:
✅ Kết quả tính tổng của 3 phương pháp
✅ Kết quả tìm max của 3 phương pháp  
✅ Thời gian thực thi của mỗi phương pháp
✅ So sánh và nhận xét
✅ Khuyến nghị sử dụng

---

**Nếu gặp lỗi**, hãy kiểm tra:
- GCC đã được cài đặt chưa? (`gcc --version`)
- Đường dẫn file có đúng không?
- Tất cả các file .c có cùng thư mục với .h không?
