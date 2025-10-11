// main.cpp — ex01 Span testleri (C++98)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void title(const char* s) {
    std::cout << "\n==== " << s << " ====\n";
}

// 1) Temel doğruluk: örnek küçük set
static void test_basic()
{
    title("Basic correctness");
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try
    {
            sp.addNumber(1);
    }
    catch (const std::exception& e)
    {
         std::cout << e.what() << std::endl;
    }
    Span sp1 = sp;
    std::cout << "shortestSpan = " << sp1.shortestSpan() << "\n"; // beklenen: 2 (9-11 veya 6-3 = 3; en küçüğü 2)
    std::cout << "longestSpan  = " << sp1.longestSpan()  << "\n"; // beklenen: 17-3 = 14
}

// 2) Negatif + pozitif + tekrar (zero span kontrolü)
static void test_mixed_and_duplicates()
{
    title("Mixed signs & duplicates (zero span)");
    Span sp(6);
    Span sp1;
    sp.addNumber(-10);
    sp.addNumber(0);
    sp.addNumber(0);     // duplicate -> shortest 0 olmalı
    sp.addNumber(5);
    sp.addNumber(20);
    sp.addNumber(-7);
    sp1 = sp;
    std::cout << "shortestSpan = " << sp1.shortestSpan() << "  (beklenen 0)\n";
    std::cout << "longestSpan  = " << sp1.longestSpan()  << "  (beklenen 30: 20 - (-10))\n";
}

// 3) Hata durumları: kapasite dolu / eleman < 2
static void test_errors()
{
    title("Error cases");
    // <2 eleman
    try {
        Span s1(1);
        s1.addNumber(42);
        std::cout << "shortestSpan = " << s1.shortestSpan() << "\n"; // throw beklenir
    } catch (const std::exception& e) {
        std::cout << "caught (shortestSpan with <2): " << e.what() << "\n";
    }
    try {
        Span s2(1);
        s2.addNumber(42);
        std::cout << "longestSpan  = " << s2.longestSpan() << "\n"; // throw beklenir
    } catch (const std::exception& e) {
        std::cout << "caught (longestSpan with <2): " << e.what() << "\n";
    }
    // kapasite taşması
    try {
        Span s3(2);
        s3.addNumber(1);
        s3.addNumber(2);
        s3.addNumber(3); // throw beklenir
        std::cout << "capacity overflow test FAILED\n";
    } catch (const std::exception& e) {
        std::cout << "caught (capacity overflow): " << e.what() << "\n";
    }
}

// 4) Büyük veri (10k): performans & doğruluk
static void test_large()
{
    title("Large dataset (10,000 numbers)");
    const int N = 10000;
    Span sp(N);

    // Deterministic doldurma: 0..9999
    for (int i = 0; i < N; ++i)
        sp.addNumber(i);

    // short = 1 (ardışık fark 1), long = 9999 - 0
    std::cout << "shortestSpan = " << sp.shortestSpan() << "  (beklenen 1)\n";
    std::cout << "longestSpan  = " << sp.longestSpan()  << "  (beklenen 9999)\n";
}


int main()
{
    test_basic();
    test_mixed_and_duplicates();
    test_errors();
    test_large();
    return 0;
}
