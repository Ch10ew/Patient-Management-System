#ifndef PMS_LIST_H
#define PMS_LIST_H

#include <initializer_list>
#include <cmath>
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
    ///   Optimization structures.
    /// ========================================
    enum class TransversalStartNode
    {
        HEAD,
        CURRENT,
        TAIL
    };

    enum class TransversalDirection
    {
        LEFT = -1,
        RIGHT = 1
    };

    /**
     * @brief Defines the transversal start node, direction, and distance for operations in the list
     * 
     */
    struct TransversalInfo
    {
        TransversalStartNode start_node;
        TransversalDirection direction;
        int distance;
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
            List(std::initializer_list<T> initializer_list);
            template <typename ...Ts>
            List(Ts&&...ts);

            // Element Access
            T& Head() const;
            T& Tail() const;
            T& At(const int n) const;

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
			T Pop();

            // Operations
            int Search(const T data);

            template <class Compare>
            int Search(const T data, Compare func);

            void Swap(const int a, const int b);
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

            // Optimization auxiliary functions
            const TransversalInfo GetTransversalInfo(const int index) const;

        private:
            std::shared_ptr<ListNode<T>> head_ = nullptr;
            std::shared_ptr<ListNode<T>> tail_ = nullptr;
            std::shared_ptr<ListNode<T>> current_ = nullptr;
            int size_ = 0;
            int current_index_ = 0;
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
    // Default constructor
    template <typename T>
    List<T>::List()
    {
    }

    // Copy constructor
    template <typename T>
    List<T>::List(const List<T> &source)
    {
        *this = source;
    }

    // Constructor for initializer list initialization
    template <typename T>
    List<T>::List(std::initializer_list<T> initializer_list)
    {
        for (auto iterator = initializer_list.begin(); iterator != initializer_list.end(); ++iterator)
        {
            InsertTail(*iterator);
        }
    }

    /// ========================================
    ///   List class member functions definitions.
    /// ========================================
    // Element Access
    template <typename T>
    T& List<T>::Head() const
    {
        if (size_ > 0)
            return head_->data;

        throw std::out_of_range("pms::List<T>::Head(): List is empty");
    }

    template <typename T>
    T& List<T>::Tail() const
    {
        if (size_ > 0)
            return tail_->data;

        throw std::out_of_range("pms::List<T>::Tail(): List is empty");
    }

    template <typename T>
    T& List<T>::At(const int n) const
    {
        if (n < 0)
            throw std::out_of_range("pms::List<T>::At(): Negative index");

        std::shared_ptr<ListNode<T>> current = current_;
        TransversalInfo transversal_info = GetTransversalInfo(n);

        switch (transversal_info.start_node)
        {
            case TransversalStartNode::HEAD:
                current = head_;
                break;
            case TransversalStartNode::TAIL:
                current = tail_;
                break;
        }

        int counter = 0;
        while (current)
        {
            if (counter == transversal_info.distance)
            {
                return current->data;
            }

            if (transversal_info.direction == TransversalDirection::RIGHT)
                current = current->next;
            else
                current = current->prev;
            
            ++counter;
        }

        throw std::out_of_range("pms::List<T>::At(): List is empty");
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
        if (size_ == 0)
            return;

        std::shared_ptr<ListNode<T>> current = head_;
        std::shared_ptr<ListNode<T>> prev = head_;
        if (current)
            current = current->next;
        
        while (current)
        {
            prev = current;
            current = current->next;
            if (current)
            {
                prev->next = nullptr;
                current->prev = nullptr;
            }
        }
        head_->next = nullptr;
        
        head_ = nullptr;
        current_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    template <typename T>
    void List<T>::ShrinkToFit(const int size)
    {
        if (size < 0)
            throw std::out_of_range("pms::List<T>::Head(): Negative index");

        int difference = int(size_) - int(size);
        if (difference > 0)
        {
            for (int i = 0; i < difference; ++i)
            {
                RemoveTail();
            }
            return;
        }
        
        throw std::length_error("pms::List<T>::Head(): New size given is larger than size of original list");
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
        current_ = head_;
        current_index_ = 0;
    }

    template <typename T>
    void List<T>::InsertInPlace(const T data, const int index)
    {
        if (index < 0)
            throw std::out_of_range("pms::List<T>::Head(): Negative index");
        
        if (index > size_)
            throw std::out_of_range("pms::List<T>::Head(): Index out of range");

        if (index == size_)
        {
            InsertTail(data);
            return;
        }
        
        std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(data);
        std::shared_ptr<ListNode<T>> current = current_;
        TransversalInfo transversal_info = GetTransversalInfo(index);

        switch (transversal_info.start_node)
        {
            case TransversalStartNode::HEAD:
                current = head_;
                current_index_ = 0;
                break;
            case TransversalStartNode::TAIL:
                current = tail_;
                current_index_ = size_ - 1;
                break;
        }

        int counter = 0;
        while (current)
        {
            if (counter == transversal_info.distance)
            {
                std::shared_ptr<ListNode<T>> prev = current->prev;
                
                if (prev)
                {
                    prev->next = tmp;
                    tmp->prev = prev;
                }
                else
                    head_ = tmp;

                current->prev = tmp;
                tmp->next = current;
                
                ++size_;
                return;
            }

            if (transversal_info.direction == TransversalDirection::RIGHT)
            {
                current = current->next;
                ++current_index_;
            }
            else
            {
                current = current->prev;
                --current_index_;
            }
            ++counter;
        }
    }

    template <typename T>
    void List<T>::InsertTail(const T data)
    {
        std::shared_ptr<ListNode<T>> tmp = std::make_shared<ListNode<T>>(data);
        std::shared_ptr<ListNode<T>> current = tail_;

        if (size_ == 0)
        {
            head_ = tmp;
            tail_ = tmp;
        }
        else
        {
            current->next = tmp;
            tmp->prev = current;
            tail_ = tmp;
        }
        ++size_;
        current_ = tail_;
        current_index_ = size_ - 1;
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
        head_->prev = nullptr;

        --size_;
        current_ = head_;
        current_index_ = 0;
    }

    template <typename T>
    void List<T>::RemoveInPlace(const int index)
    {
        if (index < 0)
            throw std::out_of_range("pms::List<T>::Head(): Negative index");

        if (index >= size_)
            throw std::out_of_range("pms::List<T>::RemoveInPlace(): Index out of range");

        if (index == size_ - 1)
        {
            RemoveTail();
            return;
        }

        std::shared_ptr<ListNode<T>> current = current_;
        TransversalInfo transversal_info = GetTransversalInfo(index);

        switch (transversal_info.start_node)
        {
            case TransversalStartNode::HEAD:
                current = head_;
                current_index_ = 0;
                break;
            case TransversalStartNode::TAIL:
                current = tail_;
                current_index_ = size_ - 1;
                break;
        }

        int counter = 0;
        while (current)
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

            if (transversal_info.direction == TransversalDirection::RIGHT)
            {
                current = current->next;
                ++current_index_;
            }
            else
            {
                current = current->prev;
                --current_index_;
            }
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

        std::shared_ptr<ListNode<T>> current = tail_;
        tail_ = current->prev;
        tail_->next = nullptr;
        current->prev = nullptr;
        --size_;
        current_ = tail_;
        current_index_ = size_ - 1;
    }

    /**
     * @brief remove the tail from a list and return the data`
     * 
     * @tparam T Type used for List<T>
     * @return T Type data in the tail of the list
     */
	template<typename T>
	T List<T>::Pop()			
	{
		if(size_ == 0) 
			throw std::out_of_range("pms::List<T>::Pop(): List is empty");
		T data_copy = tail_->data;
		RemoveTail();
		return data_copy;
	}
    
    // Operations
    /**
     * Returns the index of the specified data.
     */
    template <typename T>
    int List<T>::Search(const T data)
    {
        int counter = 0;
        current_ = head_;

        while (current_)
        {
            if (current_->data == data)
            {
                return counter;
            }

            current_ = current_->next;
            ++current_index_;
            ++counter;
        }

        return -1;
    }

    
    template <typename T>
    template <class Compare>
    int List<T>::Search(const T data, Compare func)
    {
        int counter = 0;
        current_ = head_;

        while (current_)
        {
            if (func(current_->data, data))
            {
                return counter;
            }

            current_ = current_->next;
            ++current_index_;
            ++counter;
        }

        return -1;
    }

    template <typename T>
    void List<T>::Swap(const int a, const int b)
    {
        if (a > size_ || b > size_)
            throw std::out_of_range("pms::List<T>::Swap(): Index out of range");

        if (a == b)
            throw std::logic_error("pms::List<T>::Swap(): Logic error; same index given");

        std::shared_ptr<ListNode<T>> a_node;
        std::shared_ptr<ListNode<T>> b_node;
        T tmp_data;
        std::shared_ptr<ListNode<T>> current = head_;
        
        int counter = 0;
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
        if (size_ == 0)
            throw std::length_error("pms::List<T>::Sort(): List is empty");
        
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
        if (size_ == 0)
            throw std::length_error("pms::List<T>::Sort(): List is empty");
        
        *this = Sorter(*this, func);
    }

    template <typename T>
    void List<T>::operator=(const List<T>& source)
    {
        Clear();

        for (int i = 0; i < source.Size(); ++i)
        {
            InsertTail(source.At(i));
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
            T data_copy = input_list.At(i);
            if (i < input_list.Size() / 2)
            {
                left_list.InsertTail(data_copy);
            }
            else
            {
                right_list.InsertTail(data_copy);
            }
        }

        // Recursively sort the sublists
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

        // Recursively sort the sublists
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
    
    template <typename T>
    const TransversalInfo List<T>::GetTransversalInfo(const int index) const
    {
        TransversalInfo return_transversal_info;
        int difference_head = index;
        int difference_tail = (size_ - 1) - index;
        int difference_current = abs(current_index_ - index);

        if (difference_head > difference_tail)
        {
            if (difference_tail > difference_current)
            {
                return_transversal_info.start_node = TransversalStartNode::CURRENT;
                return_transversal_info.distance = difference_current;
                difference_current = current_index_ - index;
                if (difference_current < 0)
                    return_transversal_info.direction = TransversalDirection::LEFT;
                else
                    return_transversal_info.direction = TransversalDirection::RIGHT;
            }
            else
            {
                return_transversal_info.start_node = TransversalStartNode::TAIL;
                return_transversal_info.distance = difference_tail;
                return_transversal_info.direction = TransversalDirection::LEFT;
            }
        }
        else
        {
            if (difference_head > difference_current)
            {
                return_transversal_info.start_node = TransversalStartNode::CURRENT;
                return_transversal_info.distance = difference_current;
                difference_current = current_index_ - index;
                if (difference_current < 0)
                    return_transversal_info.direction = TransversalDirection::LEFT;
                else
                    return_transversal_info.direction = TransversalDirection::RIGHT;
            }
            else
            {
                return_transversal_info.start_node = TransversalStartNode::HEAD;
                return_transversal_info.distance = difference_head;
                return_transversal_info.direction = TransversalDirection::RIGHT;
            }
        }

        return return_transversal_info;
    }

} // namespace pms

#endif // PMS_LIST_H
