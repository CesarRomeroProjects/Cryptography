# Project 0: Cryptography

# Overview
The purpose of this project is to familiarize you with the programming environment, submitting assignments, and basic C++ programming. The theme for this project is cryptography, but no prior knowledge of cryptography is required.

# Project Structure
This project is divided into three parts, each involving a different cryptographic protocol. The parts are as follows:

# Part 1: Shift Ciphers
Implement two functions:

- std::string encryptShift(const std::string &message, unsigned key);
- std::string decryptShift(const std::string &message, unsigned key);

These functions shift each capital letter in the message by the specified key, providing a simple encryption and decryption mechanism.

# Part 2: Accept No Substitude
Write a function:

- bool decryptSubstitution(const std::string &message, const std::string &crib, std::string &substitutionMap);

This function decrypts a ciphertext message with a given key and crib (known plaintext), revealing a substitution map.

# Part 3: That's Affine Cipher
Implement two functions:

- std::string encryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta);
- std::string decryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta);

These functions apply an affine cipher, encrypting and decrypting messages using an affine function.

# Restrictions
- Do not use the standard library for any portion that solves a significant part of your assignment. Certain standard library portions are allowed, such as std::atoi() or std::stoul().
- Do not use the using namespace std; directive anywhere in your code.