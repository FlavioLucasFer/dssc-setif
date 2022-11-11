#include <cinttypes>
#include <cassert>
#include <iostream>
#include "list.h"

static void fill_list (list_t& list, uint32_t list_size)
{
    for (uint32_t i = 0; i < list_size; i++) {
        list.push_back(i);
    }
}

static void test_push_front ()
{
    list_t list;
    list.push_front(1);
    
    assert(list.front() == 1);
    assert(list.begin() == list.end());
    assert(list.begin()->previous == nullptr);
    assert(list.begin()->next == nullptr);
    assert(list.size() == 1);

    list.push_front(5);

    assert(list.front() == 5);
    assert(list.back() == 1);
    assert(list.begin() != list.end());
    assert(list.begin()->previous == nullptr);
    assert(list.begin()->next == list.end());
    assert(list.size() == 2);

    list.push_front(9);

    assert(list.front() == 9);
    assert(list.back() == 1);
    assert(list.begin() != list.end());
    assert(list.begin()->previous == nullptr);
    assert(list.begin()->next != list.end());
    assert(list.begin()->next->value == 5);
    assert(list.size() == 3);
}

static void test_push_back ()
{
    list_t list;
    list.push_back(1);

    assert(list.back() == 1);
    assert(list.end() == list.begin());
    assert(list.end()->previous == nullptr);
    assert(list.end()->next == nullptr);
    assert(list.size() == 1);

    list.push_back(5);

    assert(list.back() == 5);
    assert(list.front() == 1);
    assert(list.end() != list.begin());
    assert(list.end()->next == nullptr);
    assert(list.end()->previous == list.begin());
    assert(list.size() == 2);

    list.push_back(9);

    assert(list.back() == 9);
    assert(list.front() == 1);
    assert(list.end() != list.begin());
    assert(list.end()->next == nullptr);
    assert(list.end()->previous != list.end());
    assert(list.end()->previous->value == 5);
    assert(list.size() == 3);
}

static void test_get ()
{
    list_t list;
    fill_list(list, 10);

    list_node_t* node =  list.get(5);

    assert(node->value == 5);
    assert(node->previous->value == 4);
    assert(node->next->value == 6);

    assert(list.get(11) == nullptr);
}

static void test_erase_head (list_t list)
{
    list_node_t* new_head = list.erase(list.get(0));

    assert(new_head == list.begin());
    assert(new_head->value == 1);
    assert(new_head->previous == nullptr);
    assert(new_head->next->value == 2);
    assert(new_head->next->previous == new_head);

    assert(list.get(0) == nullptr);
}

static void test_erase_tail (list_t list)
{
    list_node_t* new_tail = list.erase(list.get(9));

    assert(new_tail == list.end());
    assert(new_tail->value == 8);
    assert(new_tail->next == nullptr);
    assert(new_tail->previous->value == 7);
    assert(new_tail->previous->next == new_tail);

    assert(list.get(10) == nullptr);
}

static void test_erase_middle (list_t list)
{
    list_node_t* next_node = list.erase(list.get(5));

    assert(next_node != list.begin());
    assert(next_node != list.end());
    assert(next_node->value == 6);

    assert(next_node->next->value == 7);
    assert(next_node->next->previous == next_node);
    
    assert(next_node->previous->value == 4);
    assert(next_node->previous->next == next_node);

    assert(list.get(5) == nullptr);
}

static void test_erase ()
{
    list_t list;
    fill_list(list, 10);

    test_erase_head(list);
    test_erase_tail(list);
    test_erase_middle(list);

    assert(list.erase(list.get(10)) == nullptr);
}

int main ()
{
    std::cout << "RUNNING DOUBLY LINKED LIST UNIT TESTS" << std::endl;
    
    std::cout << "<-- Testing list_t::push_front -->" << std::endl;
    test_push_front();
    std::cout << "list_t::push_front tests passed!" << std::endl;

    std::cout << "<-- Testing list_t::push_back -->" << std::endl;
    test_push_back();
    std::cout << "list_t::push_back tests passed!" << std::endl;

    std::cout << "<-- Testing list_t::get -->" << std::endl;
    test_get();
    std::cout << "list_t::get tests passed!" << std::endl;

    std::cout << "<-- Testing list_t::erase -->" << std::endl;
    test_erase();
    std::cout << "list_t::erase tests passed!" << std::endl;

    return 0;
}