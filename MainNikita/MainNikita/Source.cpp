#include <iostream>
#include <string>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

// Функция для измерения времени выполнения
template<typename Func, typename... Args>
auto measure_time(Func&& func, Args&&... args) {
    auto start = high_resolution_clock::now();
    auto result = func(forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    return make_pair(result, duration);
}


int main() {
    string plaintext = "HELLO WORLD";
    string rsa_key = "dummy_key"; // Реализовать автоматический сбор сгенерированных ключей из файлов ребят
    string vigenere_key = "KEY";
    string playfair_key = "PLAYFAIR";

    // Имена функций изменить во время теста проекта

    auto [rsa_encrypted, rsa_time] = measure_time(rsa_encrypt, plaintext);
    auto [rsa_decrypted, rsa_time_dec] = measure_time(rsa_decrypt, rsa_encrypted);

    cout << "RSA Encryption: " << rsa_encrypted << " (Time: " << rsa_time << " µs)" << endl;
    cout << "RSA Decryption: " << rsa_decrypted << " (Time: " << rsa_time_dec << " µs)" << endl;

    auto [vigenere_encrypted, vigenere_time] = measure_time(vigenere_encrypt, plaintext, vigenere_key);
    auto [vigenere_decrypted, vigenere_time_dec] = measure_time(vigenere_decrypt, vigenere_encrypted, vigenere_key);

    cout << "Vigenère Encryption: " << vigenere_encrypted << " (Time: " << vigenere_time << " µs)" << endl;
    cout << "Vigenère Decryption: " << vigenere_decrypted << " (Time: " << vigenere_time_dec << " µs)" << endl;

    auto [playfair_encrypted, playfair_time] = measure_time(playfair_encrypt, plaintext, playfair_key);
    auto [playfair_decrypted, playfair_time_dec] = measure_time(playfair_decrypt, playfair_encrypted, playfair_key);

    cout << "Playfair Encryption: " << playfair_encrypted << " (Time: " << playfair_time << " µs)" << endl;
    cout << "Playfair Decryption: " << playfair_decrypted << " (Time: " << playfair_time_dec << " µs)" << endl;

    string xor_key = "KEY";
    auto [xor_encrypted, xor_time] = measure_time(xor_encrypt, plaintext, xor_key);
    auto [xor_decrypted, xor_time_dec] = measure_time(xor_decrypt, xor_encrypted, xor_key);

    cout << "XOR Encryption: " << xor_encrypted << " (Time: " << xor_time << " µs)" << endl;
    cout << "XOR Decryption: " << xor_decrypted << " (Time: " << xor_time_dec << " µs)" << endl;

    return 0;
}
