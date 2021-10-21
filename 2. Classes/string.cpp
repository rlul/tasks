#pragma warning(disable : 4996)

#include "string.h"
#include <iostream>

CString::CString(const char* _str) {
	m_iSize = strlen(_str);
	m_pChars = new char[m_iSize+1];
	memcpy(m_pChars, _str, m_iSize);
	m_pChars[m_iSize] = 0x0;
}

CString::~CString() {
	delete[] m_pChars;
}

void CString::task() {
	bool flag = false;
	for (int i = 0; i < m_iSize; i++) {
		if (m_pChars[i] == '!') {
			flag = true;
			m_pChars[i] = '?';
		}
	}
	if (flag)
		return;
	for (int i = 0; i < m_iSize / 2; i++)
		std::swap(m_pChars[i], m_pChars[m_iSize - 1 - i]);
}