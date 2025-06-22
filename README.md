# Fixed-point-cpp

A lightweight, header-only C++ class that implements fixed-point arithmetic as a replacement for floating-point operations in performance-critical or hardware-constrained environments.

---

## 💡 Motivation

Floating-point math is a brilliant invention... but let's face it — it's not always ideal.

In many situations, especially on microcontrollers or older hardware, floating-point operations:
- Consume more power
- Require more computational overhead
- May not be supported natively (no FPU)
- Can introduce rounding errors in places you don’t expect

So here’s an attempt at creating a **simple fixed-point type**, where we prioritize **speed over precision, range, or safety**. It’s not for every use case, but in low-level systems, embedded devices, or performance-critical inner loops — it just might shine. 🚀

---

## ⚙️ What It Is

This project provides a `Fixed` class using **variable fractional bits** (Q24.8 format included) to:
- Represent floats as integers under the hood
- Replace float/double types where feasible
- Gain some speed (especially on targets without FPUs)
- Keep things simple and educational

---

## ✨ Features

- Fixed-point math using integer ops
- Arithmetic: `+`, `-`, `*`, `/`
- Comparisons: `<`, `>`, `==`, etc.
- Prefix/postfix `++` / `--`
- Casting to `int` and `float`
- `min()` and `max()` helpers
- `std::ostream` support (`<<`)
- Inline, header-only implementation
- Implementing the variable fractional precision using templates.

---

## 🧪 Example

```cpp
#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed8_t a(10);          // from int
    Fixed8_t b(3.5f);        // from float

    std::cout << "a: " << a << ", b: " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";

    if (a > b)
        std::cout << "a is greater than b\n";
}
```

---

## 🔧 How to Use

Just include the header:
```cpp
#include "Fixed.hpp"
```

No extra dependencies. No build system required. Use with any modern C++ compiler:
You can build the project using the provided Makefile.
#### ✅ Build & Run:
```bash
make
./Fixed
```
#### 🧹 Clean Build Files:
```bash
make clean     # removes object files
make fclean    # removes object files + binary
make re        # full rebuild
```
Alternatively, you can compile manually:
```bash
c++ -Wall -Wextra -Werror main.cpp -o Fixed
```
## 🛠️ TODO

chosing between using int under the hood or long, (probably using template for that). 

Handle overflow cases gracefully.

Add unit tests (GoogleTest?...), I did provide the main.cpp for fast testing tho.

Explain the math behind fixed-point and and why Fixed shines(or send a PR and do it for me 😄)

## 📜 License

MIT — do whatever you want, just don’t blame me if it breaks.
## ❤️ Contribute

Floating point may not be the root of all evil, but this repo is open to improvement. Found a bug? Want to optimize the math? add more tests? Submit a PR or open an issue.