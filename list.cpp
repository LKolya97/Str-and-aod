#include 'list.h'
#include 'player.h'
#include <iostream>
using namespace std;
template< Player T >
List< T >::List() : m_head(NULL) {
}

void List::printList{
	� = first;
while (p) {
	cout � p->plr � � �;
	� = p->next;
}
}
template< Player T >
void List< T >::append(const T &t) {
	// ������� ����� ���� ��� ��������
	// �� ������� ���������, ��� ������ ������� ��������
	if (Node* node = new Node(t)) {
		// ����� ���� ������������� � ������� ��������� ��������
		node->m_next = m_head;

		// ����� ���� ��� ���������� �������� ���������
		m_head = node;
	}
}

template< Player T >
void List< T >::remove() {
	if (m_head) { // ���� ������ �� ����:
				  // ��������� ��������� �� ������ ����, ������� ������ ����� �������� ���������
		Node* newHead = m_head->m_next;

		// ����������� ������, ���������� ��� ���������� ��������� ��������
		delete m_head;

		// ��������� ����� �������� �������
		m_head = newHead;
	} // ����� ����� �� ��������� ����������
}

template< Player T >
List< T >::~List() {
	while (m_head) {
		remove();
	}
}
template< Player T >
typename List< T >::Iterator List< T >::begin() const {
	// �������� ������ �� ��������� ��������...
	return Iterator(m_head);
}

template< Player T >
typename List< T >::Iterator List< T >::end() const {
	// ... � �� �����, �.�. NULL
	return Iterator(NULL);
}
template< Player T >
size_t List< T >::size() const {
	size_t s = 0;
	for (Iterator it = begin(); it != end(); ++it) {
		++s;
	}

	/*
	�� ����� � ��� ����������
	for( Node* n = m_head; n != NULL; n = n->m_next ) {
	++s;
	}
	*/

	return s;
}