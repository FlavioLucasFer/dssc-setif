#include <cinttypes>

struct list_node_t
{
    int value;
    list_node_t *previous = nullptr;
    list_node_t *next = nullptr;

    list_node_t (const int& value)
    {
        this->value = value;
    }
};

// doubly linked list
class list_t 
{
    private:
        list_node_t* head = nullptr;
        list_node_t* tail = nullptr;
        uint32_t _size = 0;

    public:
        list_t ();
        ~list_t ();
        void push_front (const int& value) noexcept;
        void push_back (const int& value) noexcept;
        list_node_t* get (const int& value) noexcept;
        list_node_t* erase (list_node_t* node) noexcept;

    public:
        inline list_node_t* begin () const noexcept
        {
            return this->head;
        }
        inline list_node_t* end () const noexcept
        {
            return this->tail;
        }
        inline int& front ()
        {
            return this->head->value;
        }
        inline int& back ()
        {
            return this->tail->value;
        }
        inline uint32_t size ()
        {
            return this->_size;
        }
        inline bool empty ()
        {
            return this->_size == 0 
                || this->head == nullptr 
                || this->tail == nullptr;
        }
};
