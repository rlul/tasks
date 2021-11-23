#include <memory>
#include <exception>
#include <stdarg.h>


template<typename T>
class vector_t {
public:
	vector_t(int size = 0, ...) 
		: m_capacity(size) {
		if (!size) return;
		va_list args;
		va_start(args, size);
		m_array = new T[size]{ 0 };
		memcpy(m_array, &va_arg(args, T), size * sizeof(T));
		va_end(args);
		update_iter();
	}
	~vector_t() {
		delete[] m_array;
	}

	int& at(int index) {
		if (index < 0)
			throw std::exception("Invalid index!");
		return operator[](index);
	}
	int& operator[](int index) {
		if (index >= m_capacity) {
			int newcap = m_capacity + (index - m_capacity) + 1;
			T* p_newarr = new T[newcap]{0};
			memcpy(p_newarr, m_array, m_capacity * sizeof(T));
			m_array = p_newarr;
			m_capacity = newcap;
			update_iter();
		}
		return m_array[index];
	}

	T* push(T obj) {
		if (size() >= m_capacity) {
			operator[](m_capacity) = obj;
			return m_last;
		}
		*m_last = obj;
		m_last++;
		return m_last;
	}
	T pop() {
		m_last--;
		T buf = *m_last;
		memset(m_last, 0, sizeof(T));

		return buf;
	}

	void erase(int index) {

	}

	int* begin() {
		return m_first;
	}
	int* end() {
		return m_last;
	}

	unsigned int size() const {
		return m_last - m_first;
	}
	unsigned int capacity() const {
		return m_capacity;
	}

private:
	void update_iter() {
		m_first = m_array;
		m_last = m_array + m_capacity;
	}

protected:
	T* m_array;
	T* m_first, * m_last;
	unsigned int m_capacity;
};
