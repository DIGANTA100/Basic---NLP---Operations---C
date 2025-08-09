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

basic-nlp-operations-c/
│
├── main.c # Main program file
├── stopwords.txt # List of stop words (optional)
├── README.md # Project documentation
└── sample_input.txt # Example documents
