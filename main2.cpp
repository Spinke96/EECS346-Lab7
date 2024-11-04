#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Matrix {
    private:
        vector<vector<int>> data; // 2D array for matrix data (using int for simplicity)
    public:
        // 1. Read values from stdin into a matrix
        Matrix() { }
        Matrix(int rows, int cols) {
            this->data = vector<vector<int>> (rows, vector<int> (cols));
        }
        void readFromStdin(int size){
            this->data = vector<vector<int>> (size, vector<int> (size));
            for(int row = 0; row < size; row++){
                for(int col =0; col < size; col++){
                    cout << "Enter value at index (" << row <<", " << col << "): ";
                    cin >> this->data[row][col];
        }
            }
        }

        // 2. Display a matrix
        void display() const{
            for(int row = 0; row < this->data.size(); row++){
                for(int col =0; col < this->data[0].size(); col++){
                    cout << this->data[row][col] << " ";
                }
                cout << endl;
            }
        }
        
        // 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const{
            Matrix mat_sum(this->data.size(), this->data[0].size());
            for(int row = 0; row < this->data.size(); row++){
                for(int col = 0; col < this->data[0].size(); col++){
                    mat_sum.data[row][col] = this->data[row][col] + other.data[row][col];
                }
            }
            return mat_sum;
        }
        // 4. Multiply two matrices (operator overloading for *)
        Matrix operator*(const Matrix& other) const{
            Matrix mat_product(this->data.size(), other.data[0].size());
                for(int row = 0; row < this->data.size(); row++){
                    for(int col = 0; col < this->data[0].size(); col++){
                        for (int run = 0; run < this->data.size(); ++run) { // Iterate over columns of A / rows of B
                            mat_product.data[row][col] += this->data[row][run] * other.data[run][col];
                    }
                }
                }
                return mat_product;
        }
        // 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const{
            int sum_of_diagonals = 0;
            for(int row = 0; row < this->data.size(); row++){
                for(int col = 0; col < this->data[0].size(); col++){
                    if(row == col){
                        // cout << this->data[row][col] << endl;
                        sum_of_diagonals += this->data[row][col];
                    } else if(row == this->data.size() - 1 - col){
                        // cout << this->data[row][col] << endl;
                        sum_of_diagonals += this->data[row][col];
                    }
                }
            }
            return sum_of_diagonals;
        }
        // 6. Swap matrix rows
        void swapRows(int row1, int row2){
            Matrix mat_temp(this->data.size(), this->data[0].size());
                for(int row = 0; row < this->data.size(); row++){
                    for(int col = 0; col < this->data.size(); col++){
                        if(row == row1){
                        mat_temp.data[row][col] = this->data[row2][col];
                        }else if(row == row2){
                            mat_temp.data[row][col] = this->data[row1][col];
                        }else{
                            mat_temp.data[row][col] = this->data[row][col];
                        }
            }
            }

                swap(this->data, mat_temp.data);
        }
    };

int main() {
    // Example usage:
    Matrix mat1;
        cout << "Enter Size of Matrices: ";
        int size;
        cin >> size;
        mat1.readFromStdin(size);
        cout << "Matrix 1:" << endl;
        mat1.display();
    Matrix mat2;
        mat2.readFromStdin(size);
        cout << "Matrix 2:" << endl;
        mat2.display();
    Matrix sum = mat1 + mat2;
        cout << "Sum of matrices:" << endl;
        sum.display();
    Matrix product = mat1 * mat2;
        cout << "Product of matrices:" << endl;
        product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
        mat1.swapRows(0, 2);
        cout << "Matrix 1 after swapping rows:" << endl;
        mat1.display();
    return 0;
}