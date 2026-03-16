# 🔐 Cryptex

> A C++/.NET application for encrypting and decrypting text messages — supports RSA asymmetric encryption and Caesar cipher symmetric encryption through a simple interface.

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![.NET](https://img.shields.io/badge/.NET-512BD4?style=flat-square&logo=dotnet&logoColor=white)
![Cryptography](https://img.shields.io/badge/Domain-Cryptography-red?style=flat-square)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square)

---

## 📌 Overview

Cryptex implements two encryption schemes in a single C++/.NET application — RSA for real-world asymmetric encryption and Caesar cipher for understanding the fundamentals of symmetric substitution. Designed to be both educational and practically usable for encrypting text messages.

---

## 🔑 Supported Encryption Methods

### 🔒 RSA (Asymmetric)
- Public/private key pair generation
- Encrypt with public key → decrypt with private key
- Secure — even if the public key is exposed, messages cannot be decrypted without the private key
- Used in real-world secure communication (HTTPS, SSH, PGP)

### 🔄 Caesar Cipher (Symmetric)
- Shifts each character by a fixed key value (shift offset)
- Simple substitution cipher — encrypt and decrypt with the same key
- Educational — demonstrates the concept of symmetric encryption and its fundamental weakness (brute-forceable in 25 attempts)

---

## ✨ Features

- Encrypt any text message using RSA or Caesar cipher
- Decrypt messages back to plaintext
- Key generation for RSA
- Configurable shift key for Caesar cipher
- Clean interface for switching between encryption modes
- Suitable for both learning cryptography concepts and practical text encryption

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|-----------|
| Language | C++ |
| Framework | .NET (C++/CLI) |
| RSA | .NET `System::Security::Cryptography::RSA` |
| Caesar | Custom implementation |
| Interface | Windows Forms / Console |

---

## 📁 Project Structure

```
cryptex/
│
├── main.cpp              # Entry point + interface
├── rsa.cpp               # RSA encrypt/decrypt using .NET crypto
├── rsa.h
├── caesar.cpp            # Caesar cipher implementation
├── caesar.h
│
└── README.md
```

> **Note:** Update file names to match your actual source files before pushing.

---

## ⚙️ Setup & Run

### Requirements
- Visual Studio with C++/CLI support
- .NET Framework

### Build & Run
Open the solution in Visual Studio → Build → Run.

---

## 🖥️ Usage Example

```
===== Cryptex =====
1. RSA Encryption
2. Caesar Cipher
3. Exit
===================

Select mode: 2
Enter message : Hello NUST
Enter shift key: 3
Encrypted : Khoor QXVW

Enter encrypted message: Khoor QXVW
Enter shift key: 3
Decrypted : Hello NUST
```

---

## 💡 RSA vs Caesar — Key Differences

| Property | RSA | Caesar Cipher |
|----------|-----|---------------|
| Type | Asymmetric | Symmetric |
| Keys | Public + Private | Single shared key |
| Security | Cryptographically secure | Easily brute-forced |
| Use case | Real secure communication | Educational |
| Key size | 1024–4096 bits | 1–25 (shift value) |

---

## 💡 Key Learnings

- **Why RSA is asymmetric** — encryption and decryption use mathematically linked but different keys. Knowing the public key tells you nothing useful about the private key.
- **Why Caesar is weak** — only 25 possible keys. Any attacker can try all of them in seconds. It demonstrates why key space size matters in cryptography.
- **Why .NET for RSA?** — Implementing RSA from scratch requires big integer arithmetic and prime generation. The .NET `RSACryptoServiceProvider` provides a battle-tested, correct implementation.

---

## 🔮 Possible Extensions

- [ ] AES symmetric encryption (stronger than Caesar)
- [ ] File encryption support
- [ ] Digital signatures using RSA
- [ ] Vigenère cipher as an intermediate step between Caesar and modern crypto
- [ ] Key export/import to file

---

## 👤 Author

**Abu-Bakar Chaudhary**  
Computer Engineering · NUST · Class of 2027  
[GitHub](https://github.com/abu-bakarchaudhary) · [LinkedIn](https://linkedin.com/in/abu-bakarchaudhary)
