# 🔢 Number System Converter in C

![Made with C](https://img.shields.io/badge/Made%20with-C-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Project-Completed-brightgreen?style=for-the-badge)
![GitHub last commit](https://img.shields.io/github/last-commit/ASIF200615/Number-System-Converter?style=for-the-badge)

A powerful and user-friendly C program that lets you convert numbers between **Decimal, Binary, Octal, and Hexadecimal** systems — and even keeps a **conversion history**! Ideal for students, computer science learners, and interview preparation. 💻📚

---

## 🚀 Features

✅ Menu-driven interface  
✅ Converts between:
- Decimal ↔ Binary, Octal, Hexadecimal  
- Binary ↔ Decimal, Octal, Hexadecimal  
- Octal ↔ Decimal, Binary, Hexadecimal  
- Hexadecimal ↔ Decimal, Binary, Octal  

✅ Handles **invalid inputs** with clear messages
<br>
✅ Saves a **conversion history** to a `.txt` file  
✅ Logs date and time of each conversion  
✅ Easy to extend with more features  
✅ Compiles with any C compiler  

---

## 📸 Sample Output

```
===== Number System Converter =====
1. Decimal to Binary, Octal, Hexadecimal
2. Binary to Decimal, Octal, Hexadecimal
3. Octal to Decimal, Binary, Hexadecimal
4. Hexadecimal to Decimal, Binary, Octal
5. View Conversion History
6. Exit
Enter your choice: 1

Enter Decimal number: 25
Binary: 11001
Octal: 31
Hexadecimal: 19

===== Number System Converter =====
1. Decimal to Binary, Octal, Hexadecimal
2. Binary to Decimal, Octal, Hexadecimal
3. Octal to Decimal, Binary, Hexadecimal
4. Hexadecimal to Decimal, Binary, Octal
5. View Conversion History
6. Exit
Enter your choice: 2

Enter Binary number: 10101
Decimal: 21
Octal: 25
Hexadecimal: 15

===== Number System Converter =====
1. Decimal to Binary, Octal, Hexadecimal
2. Binary to Decimal, Octal, Hexadecimal
3. Octal to Decimal, Binary, Hexadecimal
4. Hexadecimal to Decimal, Binary, Octal
5. View Conversion History
6. Exit
Enter your choice: 5

Decimal: 25 → Binary: 11001, Octal: 31, Hexadecimal: 19
Binary: 10101 → Decimal: 21, Octal: 25, Hexadecimal: 15
```

---

## 🛠️ How to Run

### 🧱 Step 1: Compile the Code
```bash
gcc converter.c -o converter.exe
```

### ▶️ Step 2: Run the Program
```bash
./converter.exe     # For Windows
./converter         # For Linux/macOS
```

> 📝 A file named `conversion_history.txt` will be created to save all conversion logs.

---

## 📂 Files in This Project

| File Name              | Description |
|------------------------|-------------|
| `converter.c`          | Main source code of the converter (with menu, validation, logging, and error handling). |
| `conversion_history.txt` | Stores logs of all conversions performed during execution. |
| `.gitignore`           | Excludes unnecessary files like `.exe` and temporary files from Git. |
| `README.md`            | This file – provides project overview and instructions. |

> ⚠️ Note: Compiled files like `converter.exe` are not included in the repo. You must compile the program on your own system.

---

## 🧠 Topics Practiced

- Number system logic in C  
- Bitwise operations  
- File handling (text file creation & writing)  
- Menu-driven programming  
- Time and date functions  

---

## 🙌 Author

Made with ❤️ by [Asif](https://github.com/ASIF200615)








