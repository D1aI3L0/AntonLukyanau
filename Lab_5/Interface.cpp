#include "Interface.h"


void Interface::Menu()
{
    int rep;
    do
    {
        int pattern;
        cout << "\nWhat template class do you want to use?\n1. Matrix\n2. Queue\n";
        cin >> pattern;

        switch (pattern)
        {
            case 1:
            {
                int type;
                cout << "\nWhat arguments type do you want to use?\n"
                        "1. Integer\n"
                        "2. Double\n"
                        "3. Char\n";
                cin >> type;

                switch (type)
                {
                    case 1:
                    {
                        Matrix<int> m;
                        cin >> m;
                        m.Menu();
                        break;
                    }

                    case 2:
                    {
                        Matrix<double> m;
                        cin >> m;
                        m.Menu();
                        break;
                    }

                    case 3:
                    {
                        Matrix<char> m;
                        cin >> m;
                        m.Menu();
                        break;
                    }


                    default: break;
                }

                break;
            }

            case 2:
            {
                cout << "\nWhat arguments type do you want to use?\n"
                        "1. Class circle\n"
                        "2. Class triangle\n"
                        "3. Class double triangle\n";
                int type;
                cin >> type;

                switch (type)
                {
                    case 1:
                    {
                        Queue<Circle> qe;
                        qe.Menu();
                        break;
                    }

                    case 2:
                    {
                        Queue<Triangle> qe;
                        qe.Menu();
                        break;
                    }

                    case 3:
                    {
                        Queue<RightTriangle> qe;
                        qe.Menu();
                        break;
                    }

                    default: break;
                }

            }

            default: break;
        }

        cout << "Do you want to repeat the program?\n"
                "1. Yes\n"
                "2. No\n";
        cin >> rep;
    } while (rep == 1);
}