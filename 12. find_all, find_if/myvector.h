#pragma warning(disable: 4996)
#include <memory>
#include <exception>
#include <initializer_list>

template<typename T>
class vector_t {
public:
	vector_t(int size = 0) 
		: m_capacity(size), m_first(0), m_last(0) {
		printf("[!] vector_t(int size)\n");
		if (!size) return;
		m_array = new T[size]{ 0 };
		update_iter();
	}
	vector_t(std::initializer_list<T> list)
		: m_capacity(list.size()) {
		printf("[!] vector_t(std::initializer_list<T> list)\n");
		int size = list.size();
		if (!size) return;
		m_array = new T[size]{ 0 };
		memcpy(m_array, list.begin(), size * sizeof(T));
		update_iter();
	}

	// ~~~ КОПИРОВАНИЕ ~~~
	vector_t(const vector_t& orig)
		: m_capacity(orig.size()) {
		printf("[!] vector_t(const vector_t& orig)\n");
		int size = orig.size();					// Узнаём размер оригинала
		m_array = new T[size];					// Выделяем память под массив
		memcpy(m_array, orig.m_array, size);	// Копируем данные из оригинального массива
		update_iter();							// Обновляем итераторы начала, конца
	}
	vector_t& operator=(const vector_t& orig) {

		if (!&orig || this == &orig)			// Проверяем равен ли оригинал нулю, 
			return *this;						//	соответствует ли он текущему векроту.

		int size = orig.size();					// Узнаём размер массива
		m_array = new T[size];					// Выделяем память под массив
		m_capacity = size;						// Задаём новую вместимость
		memcpy(m_array, orig.m_array, size);	// Копируем данные из оригинального массива
		update_iter();							// Обновляем итераторы начала, конца
	}

	// ~~~ ПЕРЕМЕЩЕНИЕ ~~~
	vector_t(vector_t&& orig)
		: m_capacity(orig.size()) {
		printf("[!] vector_t(vector_t&& orig)\n");
		int size = orig.size();					// Узнаём размер оригинала
		m_array = new T[size];					// Выделяем память под массив
		memcpy(m_array, orig.m_array, size);	// Копируем данные из оригинального массива
		update_iter();							// Обновляем итераторы начала, конца

		orig.m_array = 0;						// Очищаем оригинал
		orig.m_capacity = 0;
	}
	vector_t& operator=(vector_t&& orig) {

		if (!&orig || this == &orig)			// Проверяем равен ли оригинал нулю, 
			return *this;						//	соответствует ли он текущему векроту.

		int size = orig.size();					// Узнаём размер массива
		m_array = new T[size];					// Выделяем память под массив
		m_capacity = size;						// Задаём новую вместимость
		memcpy(m_array, orig.m_array, size);	// Копируем данные из оригинального массива
		update_iter();							// Обновляем итераторы начала, конца						

		orig.m_array = 0;						// Очищаем оригинал
		orig.m_capacity = 0;
	}

	~vector_t() {
		printf("[!] ~vector()\n");
		delete[] m_array;
	}

	T& at(int index) {
		if (index < 0)
			throw std::exception("Invalid index!");
		return operator[](index);
	}
	T& operator[](int index) {
		if (index >= m_capacity) {
			int newcap = m_capacity + (index - m_capacity) + 1;
			T* p_newarr = new T[newcap]{ 0 };
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

	T* begin() {
		return m_first;
	}
	T* end() {
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

class vectorview_t {
public:
	vectorview_t(const vector_t<int> vec)
		: m_vec(std::move(vec)) {}

protected:
	vector_t<int> m_vec;
};