#include <iostream>
#include "SalesData.h"

using namespace std;

int main()
{
    SalesData total;
    
    if (read(cin, total))
    {
        SalesData trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }

    return 0;
}
