# 🎯 C++ Programming Basics# 🎯 Time Difference Calculator



> A comprehensive collection of learning materials and exercises for my third semester of C++ programming journey.A C++ program that dynamically retrieves all available time zones from the system and calculates time differences between selected time zones.



## 📚 Topics Covered
## 📚 Features



• 🌟 Introduction to C++ Programming  - 🌟 Dynamic time zone retrieval from Windows system registry

• 📦 Variables and Data Types  - 📦 User-friendly selection of source and target time zones

• 🔄 Control Structures  - 🔄 Time input in 12-hour format (e.g., "3:00 PM")

• ⚡ Functions  - ⚡ Calculation of time differences and display of both times

• 🎯 Arrays and Pointers  - 🎯 Handles time zone offsets and conversions

• 🔰 Object-Oriented Programming Concepts  

• 🕐 Time and Date Manipulation  ## 🎯 Purpose

• 📂 File I/O Operations  

This project demonstrates:

## 🎯 Purpose- Advanced C++ programming with chrono library

- Windows API integration for system information retrieval

This repository serves as my learning playground to:- Time zone handling and calculations

- User input parsing and validation

• Master fundamental C++ programming concepts  - Building practical utilities in C++

• Practice coding exercises  

• Document my progress in C++  ## ⚙️ Compilation

• Build a strong foundation for advanced topics  

### Requirements

## ⚙️ Compilation Commands- Windows operating system

- MinGW-w64 or MSVC compiler with C++ support

### For C++ Programs- Windows SDK (for registry access)



#### 1. Optimized Build with Link-Time Optimization### Build Command

```bash

```bashg++ TimeDifferenceCalculator/main.cpp -ladvapi32 -o TimeDifferenceCalculator/main.exe

g++ -Os -s -flto -o <output-file> <source-file>```

```

### Optimized Build

#### 2. Simple Optimized Build```bash

g++ -Os -s -flto TimeDifferenceCalculator/main.cpp -ladvapi32 -o TimeDifferenceCalculator/main.exe

```bash```

g++ -Os -s -o <output-file> <source-file>

```## 🚀 Usage



#### 3. With Windows Libraries (for registry access)1. Run the compiled executable: `TimeDifferenceCalculator/main.exe`

2. Select source time zone from the displayed list

```bash3. Enter time in 12-hour format (e.g., "3:00 PM")

g++ <source-file> -ladvapi32 -o <output-file>4. Select target time zone

```5. View the time difference and converted times



## About## 📁 Project Structure



This is my learning repository. You wouldn't find anything exciting here! 😗🙃- `TimeDifferenceCalculator/main.cpp` - Main program file containing all functionality

- `TimeDifferenceCalculator/README.md` - Detailed project documentation

---

## 🛠️ Technologies Used

Made with ❤️ during my third semester

- C++ Standard Library (chrono, iostream, vector, string)
- Windows Registry API
- Unicode string handling

## 📝 Example Output

```
Available time zones:
1. (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi
...
54. (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi
...
114. (UTC+09:00) Osaka, Sapporo, Tokyo

Select source time zone (enter number): 54
Enter time in 12-hour format (e.g., 3:00 PM): 3:00 PM
Select target time zone (enter number): 114

From (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi to (UTC+09:00) Osaka, Sapporo, Tokyo -> Difference: +3 hours 30 minutes
Time in (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi: 15:00
Time in (UTC+09:00) Osaka, Sapporo, Tokyo: 18:30
```

## 📈 Learning Outcomes

This project helped in understanding:
- System-level programming with Windows APIs
- Time zone database management
- String manipulation and parsing
- Error handling and user input validation
- Building cross-platform compatible code (with Windows specifics)

## 🤝 Contributing

This is a learning project. Feel free to fork and experiment!

## 📄 License

This project is for educational purposes.

---

Made with ❤️ during C++ learning journey