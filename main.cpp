#include <iostream>

#include <cstring>

using namespace std;

int main()
{
    char s[251], x[251];

    cin.getline(s,251);

    cin.getline(x,251);

    char *pch1, *pch2;

          pch1 = strtok(s," ;");
         pch2 = strtok(NULL," ;");

   while(pch2 != NULL)
    {

        if(strcmp(pch1,x) == 0)
            cout << pch2 << endl;
         pch1 = strtok(NULL," ;");
         pch2 = strtok(NULL," ;");


    }


    return 0;
}
