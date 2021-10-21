#include "vector.h"
#include <iostream>

CVector::CVector(int* _arr, int _size) {
	m_iLength = _size;
	m_iSize = _size * 2;
	m_pArray = new int[_size];
	memcpy(m_pArray, _arr, _size * sizeof(int));
}

CVector::CVector(int _size) {
	m_iSize = _size;
	m_pArray = new int[_size];
	m_iLength = 0;
}

CVector::~CVector() {
	delete[] m_pArray;
}

void CVector::push(int _obj) {
	if (m_iLength == m_iSize)
		return;
	m_pArray[m_iLength] = _obj;
	m_iLength++;
}

int CVector::pop() {
	if (!m_iLength)
		return 0;
	m_iLength--;
	int buf = 0;
	std::swap(buf, m_pArray[m_iLength]);
	return buf;
}

void CVector::sort() {
	bool flag;
	for (int i = 0; i < m_iLength; i++) {
		flag = true;
		for (int j = 0; j < m_iLength - (i + 1); j++) {
			if (m_pArray[j] < m_pArray[j + 1]) {
				flag = false;
				std::swap(m_pArray[j], m_pArray[j + 1]);
			}
		}
		if (flag)
			return;
	}
}

void CVector::task() {
	for (int i = 0; i < m_iLength; i++)
		if (m_pArray[i] < 0)
			m_pArray[i] *= m_pArray[i];
}