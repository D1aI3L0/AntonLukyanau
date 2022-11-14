#include "Interface.h"


void Interface::Menu()
{
    int rep;
    do
    {
        fstream file;
        int pattern, argumentType;
        int method;
        int count;
        int fileType;
        Input::Int(pattern, "\nWhat template class do you want to use?\n1. Matrix\n2. Queue\n", 'b', 1, 2);
        Input::Int(argumentType, "\nWith what argument type do you want to work?\n1. Int\n2. Double\n3. String\n", 'b', 1, 3);
        Input::Int(method, "\nHow do you want to work?\n1. Read data from file\n2. Enter new data\n", 'b', 1, 2);
        Input::Int(fileType, "\nWhat file type do you want to use?\n1. Text\n2. Binary\n", 'b', 1, 2);
        switch (method)
        {
            case 1:
            {
                switch (pattern)
                {
                    case 1:
                    {
                        switch (fileType)
                        {
                            case 1:
                            {
                                switch (argumentType)
                                {
                                    case 1:
                                    {
                                        file.open(FileMInt, fstream::in);
                                        file >> count;
                                        Matrix<int>* matrix = new Matrix<int>[count];
                                        for(int i = 0; i < count; i++)
                                            file >> matrix[i];
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileMDouble, fstream::in);
                                        file >> count;
                                        Matrix<double>* matrix = new Matrix<double>[count];
                                        for(int i = 0; i < count; i++)
                                            file >> matrix[i];
                                        break;
                                    }

                                    case 3:
                                    {
                                        file.open(FileMString, fstream::in);
                                        file >> count;
                                        Matrix<string>* matrix = new Matrix<string>[count];
                                        for(int i = 0; i < count; i++)
                                            file >> matrix[i];
                                        break;
                                    }
                                }
                                break;
                            }

                            case 2:
                            {
                                switch (argumentType)
                                {
                                    case 1: {
                                        file.open(FileMBInt, fstream::in | fstream::binary);
                                        file.read((char *) &count, sizeof(int));
                                        Matrix<int> *matrix = new Matrix<int>[count];
                                        for (int i = 0; i < count; i++)
                                            matrix[i].FRead(file);

                                        for (int i = 0; i < count; i++)
                                        {
                                            cout << "Matrix " << count + 1 << endl << matrix[i];
                                        }
                                        break;
                                    }

                                    case 2: {
                                        file.open(FileMBDouble, fstream::in | fstream::binary);
                                        file.read((char *) &count, sizeof(int));
                                        Matrix<double> *matrix = new Matrix<double>[count];
                                        for (int i = 0; i < count; i++)
                                            matrix[i].FRead(file);
                                        for (int i = 0; i < count; i++)
                                        {
                                            cout << "Matrix " << count + 1 << endl << matrix[i];
                                        }
                                        break;
                                    }

                                    case 3: {
                                        file.open(FileMBString, fstream::in | fstream::binary);
                                        file.read((char *) &count, sizeof(int));
                                        Matrix<string> *matrix = new Matrix<string>[count];
                                        for (int i = 0; i < count; i++)
                                            matrix[i].FRead(file);
                                        for (int i = 0; i < count; i++)
                                        {
                                            cout << "Matrix " << count + 1 << endl << matrix[i];
                                        }
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        switch (fileType)
                        {
                            case 1:
                            {
                                switch (argumentType)
                                {
                                    case 1:
                                    {
                                        file.open(FileQInt, fstream::in);
                                        Queue<int> queue;
                                        file >> queue;
                                        cout << endl << queue;
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileQDouble, fstream::in);
                                        Queue<double> queue;
                                        file >> queue;
                                        cout << endl << queue;
                                        break;
                                    }

                                    case 3:
                                    {
                                        file.open(FileQString, fstream::in);
                                        Queue<string> queue;
                                        file >> queue;
                                        cout << endl << queue;
                                        break;
                                    }
                                }
                                break;
                            }

                            case 2:
                            {
                                switch (argumentType)
                                {
                                    case 1:
                                    {
                                        file.open(FileQBInt, fstream::in | fstream::binary);
                                        Queue<int> queue;
                                        queue.FRead(file);
                                        queue.Show();
                                        break;
                                    }
                                    case 2:
                                    {
                                        file.open(FileQBDouble, fstream::in | fstream::binary);
                                        Queue<double> queue;
                                        queue.FRead(file);
                                        queue.Show();
                                        break;
                                    }
                                    case 3:
                                    {
                                        file.open(FileQBString, fstream::in | fstream::binary);
                                        Queue<string> queue;
                                        queue.FRead(file);
                                        queue.Show();
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }

            case 2:
            {
                Input::Int(count, "How may arguments do you want to have(1-10)?\n", 'b', 1, 10);

                switch (pattern)
                {
                    case 1:
                    {
                        switch (argumentType)
                        {
                            case 1:
                            {
                                Matrix<int>* matrix = new Matrix<int>[count];
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter matrix " << i+1 << endl;
                                    cin >> matrix[i];
                                }

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileMInt, fstream::out);
                                        file << count << endl;
                                        for(int i = 0; i < count; i++)
                                            file << matrix[i];
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileMBInt, fstream::out | fstream::binary);
                                        file.write((char*)&count, sizeof(int));
                                        for(int i = 0; i < count; i++)
                                            matrix[i].FWrite(file);
                                        break;
                                    }
                                }
                                break;
                            }

                            case 2:
                            {
                                Matrix<double>* matrix = new Matrix<double>[count];
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter matrix " << i+1 << endl;
                                    cin >> matrix[i];
                                }

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileMDouble, fstream::out);
                                        file << count << endl;
                                        for(int i = 0; i < count; i++)
                                            file << matrix[i];
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileMBDouble, fstream::out | fstream::binary);
                                        file.write((char*)&count, sizeof(int));
                                        for(int i = 0; i < count; i++)
                                            matrix[i].FWrite(file);
                                        break;
                                    }
                                }
                                break;
                            }

                            case 3:
                            {
                                Matrix<string>* matrix = new Matrix<string>[count];
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter matrix " << i+1 << endl;
                                    cin >> matrix[i];
                                }

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileMString, fstream::out);
                                        file << count << endl;
                                        for(int i = 0; i < count; i++)
                                            file << matrix[i];
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileMBString, fstream::out | fstream::binary);
                                        file.write((char*)&count, sizeof(int));
                                        for(int i = 0; i < count; i++)
                                            matrix[i].FWrite(file);
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        switch (argumentType)
                        {
                            case 1:
                            {
                                Queue<int> queue;
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter element " << i+1 << endl;
                                    int data;
                                    cin >> data;
                                    queue.Push(data);
                                }

                                cout << endl << queue;

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileQInt, fstream::out);
                                        file << queue;
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileQBInt, fstream::out | fstream::binary);
                                        queue.FWrite(file);
                                        break;
                                    }
                                }
                                break;
                            }

                            case 2:
                            {
                                Queue<double> queue;
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter element " << i+1 << endl;
                                    double data;
                                    cin >> data;
                                    queue.Push(data);
                                }

                                cout << endl << queue;

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileQDouble, fstream::out);
                                        file << queue;
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileQBDouble, fstream::out | fstream::binary);
                                        queue.FWrite(file);
                                        break;
                                    }
                                }
                                break;
                            }

                            case 3:
                            {
                                Queue<string> queue;
                                for(int i = 0; i < count; i++)
                                {
                                    cout << "Enter element " << i+1 << endl;
                                    string data;
                                    cin >> data;
                                    queue.Push(data);
                                }

                                cout << endl << queue;

                                switch (fileType)
                                {
                                    case 1:
                                    {
                                        file.open(FileQString, fstream::out);
                                        file << queue;
                                        break;
                                    }

                                    case 2:
                                    {
                                        file.open(FileQBString, fstream::out | fstream::binary);
                                        queue.FWrite(file);
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }

        file.close();
        Input::Int(rep, "\nDo you want to do something else?\n1. Yes\n2. No\n", 'b', 1, 2);
    }while(rep == 1);
}

