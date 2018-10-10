#include <iostream>
#include <ctime>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize(void)
{
    char *arr = new char[20];
    char an[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789@#*&";
    for (int i = 0; i < 8; i++)
        arr[i] = an[rand()%65];
    *(reinterpret_cast<int *>(arr + 8)) = rand();
    for (int i = 12; i < 20; i++)
        arr[i] = an[rand()%65];
    return arr;
}

Data *deserialize(void *raw)
{
    char *arr = reinterpret_cast<char *>(raw);
    Data *result = new Data;
    for (int i = 0; i < 8; i++)
        result->s1 += arr[i];
    result->n = *(reinterpret_cast<int *>(&arr[9]));
    for (int i = 12; i < 20; i++)
        result->s2 += arr[i];
    return result;
}

int main() {

    srand(time(NULL));
    
    Data * result = deserialize(serialize());
    std::cout << result->s1 << std::endl;
    std::cout << result->n << std::endl;
    std::cout << result->s2 << std::endl;

    return 0;
}