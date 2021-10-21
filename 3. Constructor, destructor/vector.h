#pragma once

class CVector {
public:
	CVector(int* _arr, int _size);
	CVector(int _size = 10);
	~CVector();

	void push(int _obj);
	int pop();

	void sort();
	void task();


	int length() {
		return m_iLength;
	}

	const int& operator[](int _i) { 
		if (_i < 0 || _i >= m_iSize) 
			return 0;
		return m_pArray[_i]; 
	}
	
private:
	int* m_pArray;
	int m_iSize;
	int m_iLength;
};
