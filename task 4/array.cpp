#include "array.h"

CArray::CArray(int _col, int _row) {
	m_iRows = _row;
	m_iColumns = _col;
	m_pArray = new int* [_row];
	for (int i = 0; i < _row; i++)
		m_pArray[_row] = new int[_col];
}

CArray::CArray(int** _array, int _col, int _row) {
	m_pArray = _array;
	m_iRows = _row;
	m_iColumns = _col;
}

CArray::~CArray() {
	for (int i = 0; i < m_iRows; i++)
		delete[] m_pArray[i];
	delete[] m_pArray;
}

const int task(const CArray& arr) {
	int sum = 0;
	for (int i = 0; i < arr.m_iRows; i++) {
		int temp_sum = 0;
		for (int j = 0; j < arr.m_iColumns; j++) {
			if (arr.m_pArray[i][j] >= 0)
				temp_sum += arr.m_pArray[i][j];
			else {
				temp_sum = 0;
				break;
			}
		}
		sum += temp_sum;
	}

	return sum;
}

int CArray::get_rows() {
	return m_iRows;
}
int CArray::get_columns() {
	return m_iColumns;
}

const int& CArray::operator()(int _col, int _row) {
	return m_pArray[_col][_row];
}