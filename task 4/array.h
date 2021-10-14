#pragma once

class CArray {
public:
	CArray(int _col = 3, int _row = 3);
	CArray(int** _array, int _col, int _row);
	~CArray();

	friend const int task(const CArray&);

	int get_rows();
	int get_columns();

	const int& operator()(int _col, int _row);

private:
	int** m_pArray;
	int m_iColumns;
	int m_iRows;
};

