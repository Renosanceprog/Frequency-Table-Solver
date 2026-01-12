# Frequency Table Solver & Statistics Calculator

A C-based command-line tool that automates the creation of **Grouped Frequency Distribution Tables**. It takes raw data parameters and generates a fully formatted ASCII table, complete with calculations for Class Boundaries, Cumulative Frequencies, and Measures of Central Tendency (Mean, Median, Mode).

## Features

* **Automated Table Generation:** Draws a clean ASCII table with dynamic rows based on class intervals ($k$).
* **Complete Statistical Breakdown:** Automatically calculates:
    * **Class Intervals** (Lower/Upper Class)
    * **Midpoints** ($X$)
    * **Class Boundaries** ($CB$)
    * **Cumulative Frequencies** ($<CF$ and $>CF$)
    * **Relative Frequency** ($RF$) and **Percentages**.
* **Central Tendency Engine:** Computes the **Mean**, **Median**, and **Mode** for grouped data.
* **Flexible Input:** Accepts custom ranges ($R$), class widths ($i$), and frequency lists.

## Installation & Usage

### 1. Compile the Code
You need a C compiler (like GCC). If you are using VS Code with MinGW:

```bash
gcc class_intervalsprot.c -o freq_solver

```

### 2. Run the Program

**Windows:**

```bash
./FTable_solverV2.exe

```

**Linux/Mac:**

```bash
./FTable_solverV2

```

### 3. Input Guide

The program will ask for the following parameters:

1. **Data Range ():** Difference between highest and lowest value.
2. **Class Width ():** The range for a single interval.
3. **First Interval Range:** The Lower and Upper limits of the first class (e.g., `23` and `25`).
4. **Frequency List:** A space-separated list of frequencies (e.g., `4 4 19 7 2 1`).

## 📊 Logic & Formulas

This tool automates the standard statistical formulas for grouped data:

| Parameter | Formula / Logic |
| :--- | :--- |
| **Intervals ($k$)** | $k = \lceil R / i \rceil$ |
| **Midpoint ($X$)** | $X = (LC + UC) / 2$ |
| **Boundaries ($CB$)** | $LC - 0.5$ and $UC + 0.5$ |
| **Less Than CF** | Running total of frequencies from top to bottom. |
| **Mean** | $\bar{x} = \frac{\sum fX}{N}$ |
| **Median** | $L_{med} + \left[ \frac{(N/2) - <CF_{prev}}{f_{med}} \right] i$ |
| **Mode** | $L_{mo} + \left[ \frac{d_1}{d_1 + d_2} \right] i$ |

## 📝 Example Output

```text
input data range (R): 17
input data class width (i): 3
input first lower class range: 23
input first upper class range: 25
Enter your list of frequencies (e.g., 4 4 19 7 2 1): 4 4 19 7 2 1
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| CLASS INTERVAL  | F               | X               | CLASS BOUNDARY  | <CF             | >CF             | RF              | %               |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 23 - 25         | 4               | 24.0            | 22.5 - 25.5     | 37              | 4               | 0.11            | 11              |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 20 - 22         | 4               | 21.0            | 19.5 - 22.5     | 33              | 8               | 0.11            | 11%             |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 17 - 19         | 19              | 18.0            | 16.5 - 19.5     | 29              | 27              | 0.51            | 51%             |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 14 - 16         | 7               | 15.0            | 13.5 - 16.5     | 10              | 34              | 0.19            | 19%             |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 11 - 13         | 2               | 12.0            | 10.5 - 13.5     | 3               | 36              | 0.05            | 5%              |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
| 8 - 10          | 1               | 9.0             | 7.5 - 10.5      | 1               | 37              | 0.03            | 3%              |
+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+
k = 6
N = 37

Central Tendencies:
Mean: 17.84
Median: 17.84
Mode: 17.83

```

## 🗺️ Roadmap

* [ ] Add support for CSV file input.
* [ ] Implement Standard Deviation and Variance calculations.
* [ ] Add option to export table to `.txt` file.

---

*Created as a Computer Science project for Statistics & Algorithms.*
