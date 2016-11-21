
#include 'player.h'
template< Player T >
class List {
private:
	// ���������� ��������� ���� ��� ������������� � ������ Iterator
	struct Node;

public:
	// ����� ��������� ������������ ������
	class Iterator {
	public:
		Iterator(Node* node) : m_node(node) { }

		// �������� �� ���������
		bool operator==(const Iterator& other) const {
			if (this == &other) {
				return true;
			}
			return m_node == other.m_node;
		}

		// �������� �� �����������
		bool operator!=(const Iterator& other) const {
			return !operator==(other);
		}

		// ��������� �������� �������� ����
		T operator*() const {
			if (m_node) {
				return m_node->m_t;
			} // ����� ��������� ����� ������. ������� ��������� ����������
			return T();
		}

		// ������� � ���������� ����
		void operator++() {
			if (m_node) {
				m_node = m_node->m_next;
			} // ����� ��������� ����� ������. ������� ��������� ����������
		}

	private:
		Node* m_node;
	};

public:
	List();

	~List();

	// ���������� ���� � ������
	void append(const T& t);

	// �������� ���������� ������������ ���� �� ������
	void remove();

	// �������� �������� ������� ������
	T head() const;

	// �������� �������� �� ������ ������
	Iterator begin() const;

	// �������� �������� �� ����� ������
	Iterator end() const;

	// �������� ������ ������
	size_t size() const;

private:
	// ��������� ���� ������������ ������
	struct Node {
		Node() : m_next(NULL) { }

		Node(const T& t) : m_t(t), m_next(NULL) { }

		// �������� ����
		T m_t;

		// ��������� �� ��������� ����
		Node* m_next;
	};

	// ������ ������������ ������
	Node* m_head;
};