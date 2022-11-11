#include "list.h"

list_t::list_t () {}

list_t::~list_t ()
{
    // TODO: free all allocated memory
    // A FAZER: liberar toda a memória alocada
}

void list_t::push_front (const int& value) noexcept
{
    // TODO: insert data at the beginning of the list_t
    // A FAZER: inserir dado no começo da lista
}

void list_t::push_back (const int& value) noexcept
{
    // TODO: insert data at the end of the list_t
    // A FAZER: inserir dado no final da lista
}

list_node_t* list_t::get (const int& value) noexcept
{
    /*
    TODO: 
        1. find and return the fisrt node with the given value
        2. if no node found, return null pointer (nullptr)
    */
    /*
    A FAZER:
        1. encontre e retorne o primeiro nó com o valor recebido
        2. se nenhum nó for encontrado, retorne um ponteiro nulo (nullptr)
    */
   return nullptr;
}

list_node_t* list_t::erase (list_node_t* node) noexcept
{
    /*
    TODO:
        1. find the fisrt node with the given value
        2. safely remove the found node (fix the related pointers first)
        3. return the node that now ocupates the place of the removed node
        4. if no node found, return null pointer (nullptr)
    */
    /*
    A FAZER:
        1. encontre o primeiro nó com o valor recebido
        2. remova o nó encontrado de maneira segura (arrume os ponteiros relacionados primeiro)
        3. retorne o nó que agora ocupa o lugar do nó removido
        4. se nenhum nó for encontrado, retorne um ponteiro nulo (nullptr)
    */
   return nullptr;
}