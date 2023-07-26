#include <Windows.h>
#include <iostream>

void decode_string(char* s)
{
    while (*s)
    {
        *s = s[0] ^ 0x31 ^ s[1];
        s++;
    }
}

int get_date()
{
    SYSTEMTIME SystemTime;
    GetSystemTime(&SystemTime);

    char pszDate[200];
    GetDateFormatA( LOCALE_USER_DEFAULT, DATE_LONGDATE, &SystemTime, NULL, pszDate, 200 );
    std::cout << "Current date: " << pszDate << std::endl;
    return 1337;
}

int main()
{
    if (get_date() == 1337) {
        MessageBoxA(NULL, "Test passed!", "Test Case 1", MB_OK);
        std::cout << "Test passed!\n";
    }
    std::cout << "Test Case 1 finished\n";
    return 0;
}
