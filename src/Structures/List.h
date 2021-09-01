#ifndef PMS_LIST_H
#define PMS_LIST_H

#include <memory>
#include <vector>

namespace pms
{
    /// ========================================
    ///   List node structure.
    /// ========================================
    /**
     * Supporting structure for List class.
     * Defines a single node of the list.
     */
    template <typename T>
    struct ListNode
    {
        ListNode() = delete;
        ListNode(T data);

        T data = nullptr;
        std::shared_ptr<ListNode<T>> prev = nullptr;
        std::shared_ptr<ListNode<T>> next = nullptr;
    };

    /// ========================================
    ///   List class.
    /// ========================================
    /**
     * Meta class for a list "structure". Type supplied in T
     * should have operator== and operator< overloads.
     */
    template <typename T>
    class List
    {
        public:
            // Element Access
            const T& Head() const;
            const T& Tail() const;
            const T& At(const size_t n) const;

            // Capacity
            const bool Empty() const;
            const size_t Size() const;

            // Modifiers
            void Clear();
            void ShrinkToFit(const size_t size);
            void InsertHead(const T data);
            void InsertInPlace(const T data, const size_t index);
            void InsertTail(const T data);
            void RemoveHead();
            void RemoveInPlace(const size_t index);
            void RemoveTail();

            // Operations
            int Search(const T data) const;
            void Swap(const size_t a, const size_t b);

            /// WIP
            void Sort();
            template<class Compare>
            void Sort(Compare func);

        private:
            std::shared_ptr<ListNode<T>> head_ = nullptr;
            std::shared_ptr<ListNode<T>> tail_ = nullptr;
            size_t size_ = 0;
    };



    /// ========================================
    ///   List node structure member function definitions.
    /// ========================================
    /*template <typename T>
    ListNode<T>::ListNode()
    {
    }*/

    template <typename T>
    ListNode<T>::ListNode(T data) : data(data)
    {
    }

    /// ========================================
    ///   List class member functions definitions.
    /// ========================================
    // Element Access
    template <typename T>
    const T& List<T>::Head() const
    {
        if (size_ > 0)
            return this->head_->data;

        throw std::runtime_error("List is empty.");
    }

    template <typename T>
    const T& List<T>::Tail() const
    {
        if (size_ > 0)
            return this->tail_->data;

        throw std::runtime_error("List is empty.");
    }

    template <typename T>
    const T& List<T>::At(const size_t n) const
    {
        size_t counter = 0;
        std::shared_ptr<ListNode<T>> current = head_;

        if (this->Size() < n)
        {
            while (current)
            {
                if (counter == n)
                {
                    return current->data;
                }

                current = current->next;
                ++counter;
            }
        }
        else
        {
            counter = this->Size() - 1;
            current = tail_;
            while (current)
            {
                if (counter == n)
                {
                    return current->data;
                }

                current = current->prev;
                --counter;
            }
        }

        throw std::runtime_error("List is empty.");
    }

    // Capacity
    template <typename T>
    const bool List<T>::Empty() const
    {
        return size_ == 0;
    }

    template <typename T>
    const size_t List<T>::Size() const
    {
        return size_;
    }

    // Modifiers
    template <typename T>
    void List<T>::Clear()
    {
        head_ = nullptr;
        size_ = 0;
    }

    template <typename T>
    void List<T>::ShrinkToFit(const size_t size)
    {
        int difference = int(size_) - int(size);
        if (difference > 0)
        {
            for (int i = 0; i < difference; ++i)
            {
                this->RemoveTail();
            }
        }
    }

    template <typename T>
    void List<T>::InsertHead(const T data)
    {
        std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(data);

        if (head_)
        {
            tmp->next = head_;
            tmp->next->prev = tmp;
        }

        head_ = tmp;

        if (size_ == 0)
            tail_ = tmp;

        ++size_;
    }

    template <typename T>
    void List<T>::InsertInPlace(const T data, const size_t index)
    {
        size_t counter = 0;
        std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(data);
        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            if (index == counter)
            {
                current = current->prev;
                if (current)
                {
                    current->next->prev = tmp; // set "after"'s `prev` to "new"
                    tmp->next = current->next; // set "new"'s next to "after"
                    current->next = tmp; // set "before"'s next to "new"
                    tmp->prev = current; // set "new"'s prev to "before"

                    if (index == size_)
                        tail_ = tmp;
                }
                else
                {
                    current = head_; // fix current from `nullptr` to `head_`
                    current->next->prev = tmp; // set "after"'s `prev` to "new"
                    tmp->next = current; // set "new"'s next to "after"
                    head_ = tmp;
                }
                ++size_;
                return;
            }

            current = current->next;
            ++counter;
        }
    }

    template <typename T>
    void List<T>::InsertTail(const T data)
    {
        std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(data);
        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            current = current->next;
        }
        current->next = tmp;
        tmp->prev = current;
        ++size_;
    }

    template <typename T>
    void List<T>::RemoveHead()
    {
        --size_;
        std::shared_ptr<ListNode<T>> tmp = head_;
        head_ = head_->next;
        tmp->next = nullptr; // clean up `next` ptr from head
        head_->prev = nullptr;
    }

    template <typename T>
    void List<T>::RemoveInPlace(const size_t index)
    {
        size_t counter = 0;
        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            if (index == counter)
            {
                current = current->prev;
                if (current)
                {
                    std::shared_ptr<ListNode<T>> after = current->next->next;

                    current->next->prev = nullptr; // set "current"'s `prev` to nullptr
                    current->next->next->prev = current; // set "after"'s prev to "before"
                    current->next->next = nullptr;  // set "current"'s `next` to nullptr
                    current->next = after; // set "before"'s next to "after"
                }
                else
                {
                    current = head_; // fix current from `nullptr` to `head_`
                    head_ = current->next; // set new head_
                    current->next->prev = nullptr; // set "after"'s `prev` to nullptr
                    current->next = nullptr; // set "current"'s next to nullptr
                }
                --size_;
                return;
            }

            current = current->next;
            ++counter;
        }
    }

    template <typename T>
    void List<T>::RemoveTail()
    {
        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            current = current->next;
        }
        current->prev->next = nullptr;
        current->prev = nullptr;
        --size_;
    }

    // Operations
    /**
     * Returns the index of the specified data.
     */
    template <typename T>
    int List<T>::Search(const T data) const
    {
        int counter = 0;
        std::shared_ptr<ListNode<T>> current = head_;
        while (current)
        {
            if (current->data == data)
            {
                return counter;
            }

            current = current->next;
            ++counter;
        }

        return -1;
    }

    template <typename T>
    void List<T>::Swap(const size_t a, const size_t b)
    {
        if (a > size_ || b > size_)
            return;

        if (a == b)
            return;

        size_t counter = 0;
        std::shared_ptr<ListNode<T>> a_node;
        std::shared_ptr<ListNode<T>> b_node;
        T tmp_data;
        std::shared_ptr<ListNode<T>> current = head_;
        while (current)
        {
            if (counter == a)
                a_node = current;

            if (counter == b)
                b_node = current;

            if (a_node && b_node)
                break;

            current = current->next;
            ++counter;
        }

        tmp_data = a_node->data;

        a_node->data = b_node->data;
        b_node->data = tmp_data;
    }

    template <typename T>
    void List<T>::Sort()
    {
        
    }

    template <typename T>
    template<class Compare>
    void List<T>::Sort(Compare func)
    {
        
    }

} // namespace pms

#endif // PMS_LIST_H
