#pragma once

class CString {
public:
	CString(const char*);
	~CString();

	void task();			// #4
	const char* c_ret() {
		return m_pChars;
	}

private:
	char* m_pChars  = 0;
	int	  m_iSize	= 0;
};