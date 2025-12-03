/* 
код на C++ (протестирован на JDoodle.com)

Нахождение всех простых чисел до заданного лимита

дата теста: 30.12.2024
*/

#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
    int f, limit = 0;
    cout << "Enter the limit number" << endl;
    cin >> limit;
    for (int j = 1; j <= limit; j++)
    {
        f = 0;
        for(int i = 2; i < j && f == 0; i++) 
        {
            if( j % i == 0 ) 
            {
                f = 1;  
                break;       
            }
        }
        if(f == 0)  
            cout << j << endl;
    }
    cin.get();
    return 0;
}
