#include 'list.h'
#include 'player.h'
#include <iostream>
using namespace std;
template< Player T >
List< T >::List() : m_head(NULL) {
}

void List::printList{
	р = first;
while (p) {
	cout « p->plr « » »;
	р = p->next;
}
}
template< Player T >
void List< T >::append(const T &t) {
	// Создаем новый узел для значения
	// Не забудем проверить, что память удалось выделить
	if (Node* node = new Node(t)) {
		// Новый узел привязывается к старому головному элементу
		node->m_next = m_head;

		// Новый узел сам становится головным элементом
		m_head = node;
	}
}

template< Player T >
void List< T >::remove() {
	if (m_head) { // Если список не пуст:
				  // Сохраняем указатель на второй узел, который станет новым головным элементом
		Node* newHead = m_head->m_next;

		// Освобождаем память, выделенную для удаляемого головного элемента
		delete m_head;

		// Назначаем новый головной элемент
		m_head = newHead;
	} // Иначе могли бы возбудить исключение
}

template< Player T >
List< T >::~List() {
	while (m_head) {
		remove();
	}
}
template< Player T >
typename List< T >::Iterator List< T >::begin() const {
	// Итератор пойдет от головного элемента...
	return Iterator(m_head);
}

template< Player T >
typename List< T >::Iterator List< T >::end() const {
	// ... и до упора, т.е. NULL
	return Iterator(NULL);
}
template< Player T >
size_t List< T >::size() const {
	size_t s = 0;
	for (Iterator it = begin(); it != end(); ++it) {
		++s;
	}

	/*
	Но можно и без итераторов
	for( Node* n = m_head; n != NULL; n = n->m_next ) {
	++s;
	}
	*/

	return s;
}