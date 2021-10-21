#include <iostream>
#include "string.h"

int main() {
	CString str("very funny and original?");
	str.task();
	printf("%s\n", str.c_ret());
	CString* p_str = new CString("i'm funny too!");
	p_str->task();
	printf("%s\n", p_str->c_ret());
	return 0;

}