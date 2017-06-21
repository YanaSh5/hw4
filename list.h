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
    List();
    ~List();
    List(const List&);
    List& operator=(const List&);
    bool operator==(const List&) const;
    bool operator!=(const List&) const;
    class Iterator{
        const List<T>* linked_list;
        node *current;
        Iterator(const List<T> *linked_list, node *current):
                linked_list(linked_list), current(current) {}
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

//    Iterator find_if(Iterator first, Iterator last, Predicate pred);
    //void sort(const Compare& compare);
    int getSize();
};
template<class T>
List<T>::List() :
        head(NULL) , tail(NULL), size(0)
{}
template<class T>
List<T>::~List() {
    while(head!=NULL){
        node* to_delete=head;
        head=head->next;
        delete to_delete;
        size--;
    }
}
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    current=current->next;
    return *this;
}
template<class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator result=*this;
    ++*this;
    return result;
}
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    current=current->previous;
    return *this;
}
template<class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int) {
    Iterator result=*this;
    --*this;
    return result;
}
template<class T>
bool List<T>::Iterator::operator==(const Iterator &iteratorPosition) const {
    return (((iteratorPosition.current==linked_list->tail)&&
            (current==linked_list->tail))
            ||(iteratorPosition.current==current));
}
template<class T>
bool List<T>::Iterator::operator!=(const Iterator& iteratorPosition)const {
    return !(*this == iteratorPosition);
}

template<class T>
const T& List<T>::Iterator::operator*() const {
    if (linked_list->tail==NULL){
        throw mtm::ListExceptions::ElementNotFound();
    };
    return current->data;
}
template<class T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(this,head);
}
template<class T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(this,tail);
}
template<class T>
void List<T>::insert(const T &data) {
    node* temp = new node(data,tail,NULL);
    if(size==0){
        head=temp;
        tail=temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}
template<class T>
void List<T>::insert(const T &data, Iterator iterator) {
    if (iterator.linked_list!=this){
        throw mtm::ListExceptions::ElementNotFound();
    }
    if (iterator.current==tail) {
        insert(data);
    }
    else if (iterator.current==head){
        node* temp= new node(data, NULL, iterator.current);
        iterator.current->previous=temp;
        head=temp;
        size++;
    }
    else {
        node* temp= new node(data, iterator.current->previous, iterator.current);
        iterator.current->previous->next=temp;
        iterator.current->previous=temp;
        size++;
    }
}
template <class T>
void List<T>::remove(Iterator iterator) {
    if (iterator.linked_list!=this || this->getSize()==0){
        throw mtm::ListExceptions::ElementNotFound();
    }
    iterator.current->previous->next=iterator.current->next;
    iterator.current->next->previous=iterator.current->previous;
    delete iterator.current;
    size--;
    iterator.current=NULL;
}


template <class T>
List<T>::List(const List<T>& list){
    for (Iterator it=list.begin(); it.current!=NULL; it++){
        this->insert(it.operator*());/////need to be updated
    }
}

/*template <class T>
void List<T>::~List<T>() {
    for (Iterator it=this->begin(); it.current!=NULL; it++){
        delete it.current;
    }
}*/////////////////////////

template <class T>
List<T>& List<T>::operator=(const List<T>& list) {///destractor/////////////////////////???
    if (*this==list){
        return *this;
    }
    List temp=List(list);
    this->~List;
    *this=temp;
    return *this;
}

template<class T>
bool List<T>::operator==(const List& list) const {
    if (list.size!=this->size){
        return false;
    }
    Iterator it1 = list.begin();
    Iterator it2 = this->begin();
    while ((it1.current != NULL) && (it2.current != NULL)) {
        if ((it1.current->data) != (it2.current->data)) {
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}

template <class T>
bool List<T>::operator!=(const List& list) const {
    return !(*this==list);
}
template <class T>
int List<T>::getSize() {
    return size;
}
//iterator functions


#endif //HW4_LIST_H


