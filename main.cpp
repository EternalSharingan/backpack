#include <iostream>

using namespace std;

class Backpack
{
public:
    int* values;
    int* weights;
    int vw_size;
    int backpack_size;
    int** solution_matrix;

    Backpack(int* values, int* weights, int vw_size, int backpack_size)
    {
        this->values  = values;
        this->weights = weights;
        this->vw_size = vw_size+1;
        this->backpack_size = backpack_size+1;

        create_solution_matrix();
    }

private:
    void create_solution_matrix()
    {
        solution_matrix = new int* [backpack_size];
        for (int i = 0; i < backpack_size; i++)
        {
            solution_matrix[i] = new int [vw_size];
            solution_matrix[i][0] = 0;
        }
    }

    void print_solution_matrix()
    {
        for(int i = 0; i < backpack_size; i++)
        {
            for(int j = 0; j < vw_size; j++)
            {
                cout << solution_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void print_taken_items()
    {
        int i = backpack_size-1, j = vw_size-1;
        while(i != 0)
        {
            if(solution_matrix[i][j] == solution_matrix[i][j-1])
            {
                cout << j <<" item is not taken" << endl;
            }
            else
            {
                cout << j <<" item is taken" << endl;
                i = i - weights[j-1];
            }
            j--;
        }
    }

public:
    void solve()
    {
        for(int j = 1; j < vw_size; j++)
        {
            for(int i = 0; i < backpack_size; i++)
            {
                if(weights[j-1] > i)
                {
                    solution_matrix[i][j] = solution_matrix[i][j-1];
                }
                else
                {
                    int k = i - weights[j-1];
                    solution_matrix[i][j] = max(solution_matrix[i][j-1], values[j-1]+solution_matrix[k][j-1]);
                }
            }
        }
        print_solution_matrix();
        print_taken_items();
    }
};



int main()
{

    /*int vw_size = 3;
    int backpack_size = 9;

    int *values = new int[vw_size];
    values[0] = 5, values[1] = 6, values[2] = 3;

    int *weights = new int[vw_size];
    weights[0] = 4, weights[1] = 5, weights[2] = 2;*/

    int vw_size = 4;
    int backpack_size = 7;

    int *values = new int[vw_size];
    values[0] = 16, values[1] = 19, values[2] = 23, values[3] = 28;

    int *weights = new int[vw_size];
    weights[0] = 2, weights[1] = 3, weights[2] = 4, weights[3] = 5;

    Backpack *obj = new Backpack(values, weights, vw_size, backpack_size);
    obj->solve();

    return 0;
}
