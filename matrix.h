#include <iostream>
using namespace std;

class Matrix {
private:
	int rows = 0;
	int cols = 0;
	double** data = nullptr;
public:
	Matrix() {}
	Matrix(int rows, int cols) { 
		this->rows = rows;
		this->cols = cols;
		data = new double* [rows];
		for (int i = 0; i < rows; i++) 
		{
			data[i] = new double[cols](); 
		}
	}
	~Matrix() 
	{
		if (data)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] data[i];
			}
			delete[] data;
		}
	}

	Matrix(const Matrix &m)
	{
		this->rows = m.rows;
		this->cols = m.cols;
		data = new double* [rows];
		for (int i = 0; i < rows; i++) 
		{
			data[i] = new double[cols];
			for (int j = 0; j < cols; j++) 
			{
				data[i][j] = m.data[i][j];
			}
		}

	}

	void fill();
	void out();
	Matrix multiplyMatrix(Matrix& m);

	Matrix& operator=(const Matrix& m) {
		if (this != &m)
		{
			for (int i = 0; i < rows; i++) delete[] data[i];
			delete[] data;
		}
		

		rows = m.rows;
		cols = m.cols;
		data = new double* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new double[cols];
			for (int j = 0; j < cols; j++) {
				data[i][j] = m.data[i][j];
			}
		}
		return *this;
	}

};







