#include "workFunction.h"
using namespace ThirdLab;  

    std::string workFunction::generateRandomString(size_t length)
    {
        std::string str;
        const char charset[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (size_t i = 0; i < length; i++) {
            int randomIndex = rand() % (sizeof(charset) - 1); // -1 to avoid null terminator
            str += charset[randomIndex];
        }

        return str;
    }

    int workFunction::generateUniqueInt(std::set<int>& uniqueInts, int min, int max)
    {
        while (true) {
            int num = min + rand() % (max - min + 1);
            if (uniqueInts.insert(num).second) {
                return num;
            }
        }
    }

