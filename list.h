
#include 'player.h'
template< Player T >
class List {
private:
	// Объявление структуры узла для использования в классе Iterator
	struct Node;

public:
	// Класс итератора односвязного списка
	class Iterator {
	public:
		Iterator(Node* node) : m_node(node) { }

		// Проверка на равенство
		bool operator==(const Iterator& other) const {
			if (this == &other) {
				return true;
			}
			return m_node == other.m_node;
		}

		// Проверка на неравенство
		bool operator!=(const Iterator& other) const {
			return !operator==(other);
		}

		// Получение значения текущего узла
		T operator*() const {
			if (m_node) {
				return m_node->m_t;
			} // Иначе достигнут конец списка. Уместно возбудить исключение
			return T();
		}

		// Переход к следующему узлу
		void operator++() {
			if (m_node) {
				m_node = m_node->m_next;
			} // Иначе достигнут конец списка. Уместно возбудить исключение
		}

	private:
		Node* m_node;
	};

public:
	List();

	~List();

	// Добавление узла в список
	void append(const T& t);

	// Удаление последнего добавленного узла из списка
	void remove();

	// Получить головной элемент списка
	T head() const;

	// Получить итератор на начало списка
	Iterator begin() const;

	// Получить итератор на конец списка
	Iterator end() const;

	// Получить размер списка
	size_t size() const;

private:
	// Структура узла односвязного списка
	struct Node {
		Node() : m_next(NULL) { }

		Node(const T& t) : m_t(t), m_next(NULL) { }

		// Значение узла
		T m_t;

		// Указатель на следующий узел
		Node* m_next;
	};

	// Голова односвязного списка
	Node* m_head;
};