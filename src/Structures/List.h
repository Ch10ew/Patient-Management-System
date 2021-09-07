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
            // Constructors
            List();
            List(const List<T> &source);
            
            // Element Access
            const T& Head() const;
            const T& Tail() const;
            const T& At(const int n) const;

            // Capacity
            const bool Empty() const;
            const int Size() const;

            // Modifiers
            void Clear();
            void ShrinkToFit(const int size);
            void InsertHead(const T data);
            void InsertInPlace(const T data, const int index);
            void InsertTail(const T data);
            void RemoveHead();
            void RemoveInPlace(const int index);
            void RemoveTail();

            // Operations
            int Search(const T data) const;
            void Swap(const int a, const int b);
            std::vector<T> ToVector();

            /// WIP
            void Sort();
            template<class Compare>
            void Sort(Compare func);

            // Operator Overloads
            void operator=(const List<T>& source);
        
        private:
            // Auxiliary functions for `Sort()`
            List<T> Sorter(List<T> input_list);

            template <class Compare>
            List<T> Sorter(List<T> input_list, Compare func);

            List<T> Merge(List<T> left_list, List<T> right_list);

            template <class Compare>
            List<T> Merge(List<T> left_list, List<T> right_list, Compare func);

        private:
            std::shared_ptr<ListNode<T>> head_ = nullptr;
            std::shared_ptr<ListNode<T>> tail_ = nullptr;
            int size_ = 0;
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
    ///   List class constructor definitions.
    /// ========================================
    // Constructors
    template <typename T>
    List<T>::List()
    {
    }

    template <typename T>
    List<T>::List(const List<T> &source)
    {
        *this = source;
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
    const T& List<T>::At(const int n) const
    {
        int counter = 0;
        std::shared_ptr<ListNode<T>> current = head_;

        while (current)
        {
            if (counter == n)
            {
                return current->data;
            }

            current = current->next;
            ++counter;
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
    const int List<T>::Size() const
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
    void List<T>::ShrinkToFit(const int size)
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
            head_->prev = tmp;
            tmp->next = head_;
        }

        head_ = tmp;

        if (size_ == 0)
            tail_ = tmp;

        ++size_;
    }

    template <typename T>
    void List<T>::InsertInPlace(const T data, const int index)
    {
        if (index == size_ - 1)
        {
            this->InsertTail(data);
            return;
        }

        int counter = 0;
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

        if (size_ == 0)
        {
            head_ = tmp;
            tail_ = tmp;
        }
        else
        {
            while (current->next)
            {
                current = current->next;
            }
            current->next = tmp;
            tmp->prev = current;
            tail_ = tmp;
        }
        ++size_;
    }

    template <typename T>
    void List<T>::RemoveHead()
    {
        if (size_ < 1)
            return;
        
        if (size_ == 1)
        {
            Clear();
            return;
        }

        std::shared_ptr<ListNode<T>> tmp = head_;
        head_ = head_->next;
        tmp->next = nullptr; // clean up `next` ptr from head
        //head_->prev = nullptr;
        --size_;
    }

    template <typename T>
    void List<T>::RemoveInPlace(const int index)
    {
        if (index == size_ - 1)
        {
            this->RemoveTail();
            return;
        }

        int counter = 0;
        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            if (index == counter)
            {
                std::shared_ptr<ListNode<T>> prev = current->prev;
                std::shared_ptr<ListNode<T>> next = current->next;

                if (prev)
                    prev->next = next;
                else
                    head_ = next;
                
                if (next)
                    next->prev = prev;
                else
                    tail_ = prev;
                
                current->prev = nullptr;
                current->next = nullptr;
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
        if (size_ < 1)
            return;
        
        if (size_ == 1)
        {
            Clear();
            return;
        }

        std::shared_ptr<ListNode<T>> current = head_;
        while (current->next)
        {
            current = current->next;
        }
        tail_ = current->prev;
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
    void List<T>::Swap(const int a, const int b)
    {
        if (a > size_ || b > size_)
            return;

        if (a == b)
            return;

        int counter = 0;
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
    
    /**
     * @brief Sorts the current list
     * 
     * @tparam T Type used for List<T>
     */
    template <typename T>
    void List<T>::Sort()
    {
        *this = Sorter(*this);
    }

    /**
     * @brief Sorts the current list
     * 
     * @tparam T Type used for List<T>
     * @param func Comparison function in the form of `bool foo(const T& lhs, const T& rhs)`
     */
    template <typename T>
    template <class Compare>  // trying to use a named requirement, might fail if compiler doesnt like this
    void List<T>::Sort(Compare func)
    {
        *this = Sorter(*this, func);
    }

    template <typename T>
    void List<T>::operator=(const List<T>& source)
    {
        this->Clear();

        for (int i = 0; i < source.Size(); ++i)
        {
            T data_copy = source.At(i);
            this->InsertTail(data_copy);
        }
    }

    template <typename T>
    List<T> List<T>::Sorter(List<T> input_list)
    {
        // No sorting needed
        if (input_list.Size() <= 1)
            return input_list;
        
        // Divide List into sublists
        List<T> left_list;
        List<T> right_list;

        for (int i = 0; i < input_list.Size(); ++i)
        {
            if (i < input_list.Size() / 2)
            {
                T data_copy = input_list.At(i);
                left_list.InsertTail(data_copy);
            }
            else
            {
                T data_copy = input_list.At(i);
                right_list.InsertTail(data_copy);
            }
        }

        // Recursively sor the sublists
        left_list = Sorter(left_list);
        right_list = Sorter(right_list);

        // Merge sorted sublists
        return Merge(left_list, right_list);
    }

    template <typename T>
    template <class Compare>
    List<T> List<T>::Sorter(List<T> input_list, Compare func)
    {
        // No sorting needed
        if (input_list.Size() <= 1)
            return input_list;
        
        // Divide List into sublists
        List<T> left_list;
        List<T> right_list;

        for (int i = 0; i < input_list.Size(); ++i)
        {
            if (i < input_list.Size() / 2)
            {
                T data_copy = input_list.At(i);
                left_list.InsertTail(data_copy);
            }
            else
            {
                T data_copy = input_list.At(i);
                right_list.InsertTail(data_copy);
            }
        }

        // Recursively sor the sublists
        left_list = Sorter(left_list);
        right_list = Sorter(right_list);

        // Merge sorted sublists
        return Merge(left_list, right_list, func);
    }

    /**
     * @brief Sorts and merges two `List<T>`
     * 
     * @tparam T Type used for List<T>
     * @param left_list (Sorted) Left list to be merged
     * @param right_list (Sorted) Right list to be merged
     * @return List<T> Sorted and merged list of `left_list` and `right_list`
     */
    template <typename T>
    List<T> List<T>::Merge(List<T> left_list, List<T> right_list)
    {
        List<T> return_list;

        while (left_list.Size() != 0 && right_list.Size() != 0)
        {
            if (left_list.Head() < right_list.Head())  // Normal comparison
            {
                T data_copy = left_list.Head();
                return_list.InsertTail(data_copy);
                left_list.RemoveHead();
            }
            else
            {
                T data_copy = right_list.Head();
                return_list.InsertTail(data_copy);
                right_list.RemoveHead();
            }
        }

        // In the case where the lists were not balanced, e.g. left list size 4, right list size 3
        while (left_list.Size() != 0)
        {
            T data_copy = left_list.Head();
            return_list.InsertTail(data_copy);
            left_list.RemoveHead();
        }

        while (right_list.Size() != 0)
        {
            T data_copy = right_list.Head();
            return_list.InsertTail(data_copy);
            right_list.RemoveHead();
        }

        return return_list;
    }

    /**
     * @brief Sorts and merges two `List<T>`
     * 
     * @tparam T Type used for List<T>
     * @param left_list (Sorted) Left list to be merged
     * @param right_list (Sorted) Right list to be merged
     * @return List<T> Sorted and merged list of `left_list` and `right_list`
     */
    template <typename T>
    template <class Compare>
    List<T> List<T>::Merge(List<T> left_list, List<T> right_list, Compare func)
    {
        List<T> return_list;

        while (left_list.Size() != 0 && right_list.Size() != 0)
        {
            if (func(left_list.Head(), right_list.Head()))  // Use of `func`
            {
                T data_copy = left_list.Head();
                return_list.InsertTail(data_copy);
                left_list.RemoveHead();
            }
            else
            {
                T data_copy = right_list.Head();
                return_list.InsertTail(data_copy);
                right_list.RemoveHead();
            }
        }

        // In the case where the lists were not balanced, e.g. left list size 4, right list size 3
        while (left_list.Size() != 0)
        {
            T data_copy = left_list.Head();
            return_list.InsertTail(data_copy);
            left_list.RemoveHead();
        }

        while (right_list.Size() != 0)
        {
            T data_copy = right_list.Head();
            return_list.InsertTail(data_copy);
            right_list.RemoveHead();
        }

        return return_list;
    }

} // namespace pms

#endif // PMS_LIST_H
