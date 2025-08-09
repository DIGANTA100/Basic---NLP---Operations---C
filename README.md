# 📝 Basic NLP Operations in C

## 📌 Overview
This project implements **Basic Natural Language Processing (NLP)** operations in **C**.  
It processes text documents through the following steps:

- 🔡 **Case normalization** – convert all text to lowercase  
- ✂️ **Tokenization** – split text into individual words (tokens)  
- 🚫 **Stop word removal** – remove common words like *the*, *is*, *and*  
- 🌱 **Simple stemming** – reduce words to their root form  
- 📊 **TF Calculation** – Term Frequency  
- 📈 **IDF Calculation** – Inverse Document Frequency  
- 📐 **TF-IDF Scores** – Term frequency–inverse document frequency  

The program runs in an **interactive loop**, allowing users to:
1. Input multiple documents  
2. Apply NLP operations  
3. Analyze results

All string operations use standard C library functions (`<string.h>`, `<ctype.h>`) without pointers.

---

## ⚙️ Features
- **Interactive command loop**
- **Document storage** and token storage in arrays
- **Basic preprocessing pipeline**
- **Mathematical scoring (TF, IDF, TF-IDF)**
- **Custom stop word filtering**
- **No pointers used** (for clarity in learning)

---

## 📂 File Structure
<br>
basic-nlp-operations-c/  <br>
│  <br>
├── main.c # Main program file  <br>
├── stopwords.txt # List of stop words   <br>
├── README.md # Project documentation  <br>
└── sample_input.txt # Example documents


---

## 🛠️ How to Compile & Run

### **1️⃣ Compile**
```bash
gcc main.c -o nlp
```
### 2️⃣ Run
```bash
./nlp
```
## 📜 License
This project is released under the MIT License — feel free to use, modify, and share.


