#include <iostream>

using namespace std;

void cyclicShiftRight(double** Neo, int line, int column, int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < line; i++) {
            double t = Neo[i][column - 1];
            int j;
            for (j = column - 1; j > 0; j--) {
                Neo[i][j] = Neo[i][j - 1];
            }
            Neo[i][j] = t;
        }
    }
}

void recurciveCyclicShiftRight(double** Neo, int line, int column, int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < line; i++) {
            double t = Neo[i][column - 1];
            int j;
            for (j = column - 1; j > 0; j--) {
                Neo[i][j] = Neo[i][j - 1];
            }
            Neo[i][j] = t;
        }
    }
}

void cyclicShiftDown(double** Neo, int line, int column, int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < column; i++) {
            double t = Neo[line - 1][i];
            int j;
            for (j = line - 1; j > 0; j--) {
                Neo[j][i] = Neo[j - 1][i];
            }
            Neo[j][i] = t;
        }
    }
}

void PrintMatrix(double** Neo, int line, int column) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            cout << "\t" << Neo[i][j];
        }
        cout << "\n";
    }
}

void CreateMatrix(double** Neo, int line, int column) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            // Neo[i][j]=rand()%5;
            Neo[i][j] = -5 + rand() % 10;
        }
    }
}

int RowWithMaxNull(double** Neo, int line, int column) {
    int rowNumber = -1;
    int maxNull = 0;

    for (int i = 0; i < line; i++) {
        int nullCount = 0;
        for (int j = 0; j < column; j++) {
            if (Neo[i][j] == 0) {
                nullCount++;
            }
        }

        if (nullCount > maxNull) {
            maxNull = nullCount;
            rowNumber = i;
        }
    }

    return rowNumber;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int line, column, n;
    int a;
    cout << "Number of lines   k = ";
    cin >> line;
    cout << "Number of columns n = ";
    cin >> column;
    double** Neo;
    Neo = new double* [line];
    for (int i = 0; i < line; i++) {
        Neo[i] = new double[column];
    }

    CreateMatrix(Neo, line, column);
    PrintMatrix(Neo, line, column);


    cout << "\n\nMove on \nx = ";
    cin >> n;
    cout << "Move left - 1" << endl;
    cout << "Move bottom   - 2" << endl;
    cout << "Enter the number (1 or 2) = ";
    cin >> a;

    switch (a) {
    case 1:
        cyclicShiftRight(Neo, line, column, n);
        break;
    case 2:
        cyclicShiftDown(Neo, line, column, n);
        break;
    default: cout << "Error, matrix will not be changed" << endl;
    }

    cout << "\n" << "Matrix after moving:" << "\n\n";
    PrintMatrix(Neo, line, column);

    int rowWithMaxNull = RowWithMaxNull(Neo, line, column);
    if (rowWithMaxNull >= 0)
        cout << "The index of the first line where the most zeros: " << rowWithMaxNull << endl;
    else
        cout << "\nNone lines with 0";


    // Очищення пам'яті
    for (int i = 0; i < line; i++) {
        delete[]Neo[i];
    }

    delete[] Neo;

    return 0;
}
