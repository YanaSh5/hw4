#ifndef HW4_LIST_H
#define HW4_LIST_H
#include <iostream>
#include "Exceptions.h"
#include <functional>
template <class T>
class List {
    class node {
        friend class Iterator;
        friend class List<T>;
        T data;
        node *previous;
        node *next;

        node(T node_data, node *node_previous, node *node_next) :
                data(node_data), previous(node_previous), next(node_next) {}
    };

    int size;
    node *head;
    node *tail;
public:
    class Iterator{
        const List<T>* linked_list;
        node *current;
        Iterator(const List<T> *linked_list, node *current):
                linked_list(linked_list),
                current(current) {}
        friend class List<T>;
    public:
        Iterator& operator++();

        Iterator operator++(int);

        Iterator& operator--();

        Iterator operator--(int);

        bool operator==(const Iterator &iteratorPosition) const;

        bool operator!=(const Iterator &iteratorPosition) const;

        const T &operator*() const;

        Iterator(const Iterator &) = default;

        Iterator &operator=(const Iterator &) = default;

    };

    Iterator begin() const;

    Iterator end() const;

    void insert(const T &data, Iterator iterator);

    void insert(const T &data);

    void remove(Iterator iterator);

    //Iterator find(const Predicate& predicate);
    //void sort(const Compare& compare);
    int getSize();
};

template<class T>
Iterator& List<T>::Iterator::operator++() {
    current=current->next;
    return *this;
}
template<class T>
Iterator List<T>::Iterator::operator++(int) {
    Iterator result=*this;
    ++*this;
    return result;
}
template<class T>
Iterator& List<T>::Iterator::operator--() {
    current=current->previous;
    return *this;
}
template<class T>
Iterator List<T>::Iterator::operator--(int) {
    Iterator result=*this;
    --*this;
    return result;
}
template<class T>
bool List<T>::Iterator::operator==(const Iterator &iteratorPosition) const {
    return (((iteratorPosition.current==linked_list->tail)&&
            (current==linked_list->tail))||(iteratorPosition.current==current));
}
template<class T>
bool List<T>::Iterator::operator!=(const Iterator& iteratorPosition)const {
    return !(*this == iteratorPosition);
}

template<class T>
const T& List<T>::Iterator::operator*() const {
    if (linked_list->tail==current){
        throw mtm::ListExceptions::ElementNotFound();
    };
    return current->data;
}
template<class T>
Iterator List::begin() const {
    return Iterator(this,head);
}
template<class T>
Iterator List::end() const {
    return Iterator(this,tail);
}
template<class T>
void List::insert(const T &data) {
    node* temp = new node(data,tail,NULL);
    tail->next=temp;
    tail=temp;
    size++;
}
template<class T>
void List::insert(const T &data, Iterator iterator) {
    if (iterator.linked_list!=this){
        throw mtm::ListExceptions::ElementNotFound();
    }
    if (iterator.current==tail) {
        insert(data);
    }
    else {
        node* temp= new node(data, iterator.current->previous, iterator.current);
        iterator.current->previous->next=temp;
        iterator.current->previous=temp;
        size++;
    }
}
void List::remove(Iterator iterator) {

}



//iterator functions


#endif //HW4_LIST_H


