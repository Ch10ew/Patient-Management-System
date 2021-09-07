#ifndef PMS_LIST_TEST_H
#define PMS_LIST_TEST_H

#include "../Structures/List.h"

#include <iostream>

namespace pms
{
    class ListTest
    {
        public:
            ListTest();

            void HeadTest();
            void TailTest();
            void AtTest();
            void EmptyTest();
            void SizeTest();
            void ClearTest();
            void ShrinkToFitTest();
            void InsertHeadTest();
            void InsertInPlaceTest();
            void InsertTailTest();
            void RemoveHeadTest();
            void RemoveInPlaceTest();
            void RemoveTailTest();
            void SearchTest();
            void SwapTest();
            void SortTest();
            void operatorEqualTest();
    };

    ListTest::ListTest()
    {
        HeadTest();
        TailTest();
        AtTest();
        EmptyTest();
        SizeTest();
        ClearTest();
        ShrinkToFitTest();
        InsertHeadTest();
        InsertInPlaceTest();
        InsertTailTest();
        RemoveHeadTest();
        RemoveInPlaceTest();
        RemoveTailTest();
        SearchTest();
        SwapTest();
        SortTest();
        operatorEqualTest();
    }



    void ListTest::HeadTest()
    {
        std::cout << "Head() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Head() when list is empty." << std::endl;
        try
        {
            list.Head();
            std::cerr << "Failed Test - Head() did not throw when list is empty." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when list is empty.
        }

        std::cout << "Test B - Test Head() when list has 1 element." << std::endl;
        list.InsertTail(1);
        if (list.Head() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test C - Test Head() when list has 2 elements." << std::endl;
        list.InsertTail(2);
        if (list.Head() != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test D - Test Head() when list has 3 elements." << std::endl;
        list.InsertHead(3);
        if (list.Head() != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 1, 2 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test E - Test Head() when list has 4 elements." << std::endl;
        list.InsertHead(4);
        if (list.Head() != 4)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::TailTest()
    {
        std::cout << "Tail() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Tail() when list is empty." << std::endl;
        try
        {
            list.Tail();
            std::cerr << "Failed Test - Tail() did not throw when list is empty." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when list is empty.
        }

        std::cout << "Test B - Test Tail() when list has 1 element." << std::endl;
        list.InsertTail(1);
        if (list.Tail() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test C - Test Tail() when list has 2 elements." << std::endl;
        list.InsertTail(2);
        if (list.Tail() != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test D - Test Tail() when list has 3 elements." << std::endl;
        list.InsertHead(3);
        if (list.Tail() != 2)
        {
            std::cerr << "Failed Test - List contains { 3, 1, 2 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test E - Test Tail() when list has 4 elements." << std::endl;
        list.InsertHead(4);
        if (list.Tail() != 2)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::AtTest()
    {
        std::cout << "At() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test At(0) when list is empty." << std::endl;
        try
        {
            list.At(0);
            std::cerr << "Failed Test - At(0) did not throw when list is empty." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when list is empty.
        }

        std::cout << "Test B - Test At(0) when list has 1 element." << std::endl;
        list.InsertTail(1);
        if (list.At(0) != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, At(0) did not match element 0 of list." << std::endl;
            return;
        }
        
        std::cout << "Test C - Test At(0) when list has 2 elements." << std::endl;
        list.InsertTail(2);
        if (list.At(0) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }, At(0) did not match element 0 of list." << std::endl;
            return;
        }

        std::cout << "Test D - Test At(1) when list has 2 elements." << std::endl;
        if (list.At(1) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }, At(1) did not match element 1 of list." << std::endl;
            return;
        }

        std::cout << "Test E - Test At(0) when list has 3 elements." << std::endl;
        list.InsertHead(3);
        if (list.At(0) != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 1, 2 }, At(0) did not match element 0 of list." << std::endl;
            return;
        }

        std::cout << "Test F - Test At(1) when list has 3 elements." << std::endl;
        if (list.At(1) != 1)
        {
            std::cerr << "Failed Test - List contains { 3, 1, 2 }, At(1) did not match element 1 of list." << std::endl;
            return;
        }

        std::cout << "Test G - Test At(2) when list has 3 elements." << std::endl;
        if (list.At(2) != 2)
        {
            std::cerr << "Failed Test - List contains { 3, 1, 2 }, At(2) did not match element 2 of list." << std::endl;
            return;
        }

        std::cout << "Test H - Test At(0) when list has 4 elements." << std::endl;
        list.InsertHead(4);
        if (list.At(0) != 4)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, At(0) did not match element 0 of list." << std::endl;
            return;
        }

        std::cout << "Test I - Test At(1) when list has 4 elements." << std::endl;
        if (list.At(1) != 3)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, At(1) did not match element 1 of list." << std::endl;
            return;
        }

        std::cout << "Test J - Test At(2) when list has 4 elements." << std::endl;
        if (list.At(2) != 1)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, At(2) did not match element 2 of list." << std::endl;
            return;
        }

        std::cout << "Test K - Test At(3) when list has 4 elements." << std::endl;
        if (list.At(3) != 2)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 1, 2 }, At(3) did not match element 3 of list." << std::endl;
            return;
        }

        std::cout << "Test L - Test At(-1) when list has 4 elements." << std::endl;
        try
        {
            list.At(-1);
            std::cerr << "Failed Test - At(-1) did not throw when index is invalid." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when negative index is given.
        }

        std::cout << std::endl; // newline
    }



    void ListTest::EmptyTest()
    {
        std::cout << "Empty() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Empty() when list is empty." << std::endl;
        if (!list.Empty())
        {
            std::cerr << "Failed Test - Empty() did not return true when list is empty." << std::endl;
            return;
        }

        std::cout << "Test B - Test Empty() when list has 1 element." << std::endl;
        list.InsertTail(1);
        if (list.Empty())
        {
            std::cerr << "Failed Test - List contains { 1 }, Empty() did not return false when list is not empty." << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::SizeTest()
    {
        std::cout << "Size() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Size() when list is empty." << std::endl;
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Size() did not return 0 when list is empty." << std::endl;
            return;
        }

        std::cout << "Test B - Test Size() when list has 1 element." << std::endl;
        list.InsertTail(1);
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Size() did not return 1." << std::endl;
            return;
        }

        std::cout << "Test C - Test Size() when list has 2 elements." << std::endl;
        list.InsertHead(2);
        if (list.Size() != 2)
        {
            std::cerr << "Failed Test - List contains { 2, 1 }, Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test D - Test Size() when list has 3 elements." << std::endl;
        list.InsertInPlace(3, 0);
        if (list.Size() != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 2, 1 }, Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test E - Test Size() when list has 4 elements." << std::endl;
        list.InsertInPlace(4, 1);
        if (list.Size() != 4)
        {
            std::cerr << "Failed Test - List contains { 3, 4, 2, 1 }, Size() did not return 4." << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::ClearTest()
    {
        std::cout << "Clear() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Clear() when list is empty." << std::endl;
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }

        std::cout << "Test B - Test Clear() when list has 1 element." << std::endl;
        list.InsertTail(1);
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }

        std::cout << "Test C - Test Clear() when list has 2 elements." << std::endl;
        list.InsertTail(1);
        list.InsertHead(2);
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }
        std::cout << "Test D - Test Clear() when list has 3 elements." << std::endl;
        list.InsertTail(1);
        list.InsertHead(2);
        list.InsertInPlace(3, 2);
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::ShrinkToFitTest()
    {
        std::cout << "ShrinkToFit() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test ShrinkToFit(1) when list is empty." << std::endl;
        list.ShrinkToFit(1);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - ShrinkToFit(1) added elements to empty list. (Size != 0)" << std::endl;
            return;
        }

        std::cout << "Test B - Test ShrinkToFit(0) when list has 1 element." << std::endl;
        list.InsertTail(1);
        list.ShrinkToFit(0);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - ShrinkToFit(0) did not shrink list to size 0." << std::endl;
            return;
        }

        std::cout << "Test C - Test ShrinkToFit(1) when list has 1 element." << std::endl;
        list.InsertTail(1);
        list.ShrinkToFit(1);
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - ShrinkToFit(1) did not shrink list to size 1." << std::endl;
            return;
        }

        std::cout << "Test D - Test ShrinkToFit(0) when list has 2 elements." << std::endl;
        list.InsertTail(1);
        list.InsertTail(2);
        list.ShrinkToFit(0);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - ShrinkToFit(0) did not shrink list to size 0." << std::endl;
            return;
        }

        std::cout << "Test E - Test ShrinkToFit(1) when list has 2 elements." << std::endl;
        list.InsertTail(1);
        list.InsertTail(2);
        list.ShrinkToFit(1);
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - ShrinkToFit(1) did not shrink list to size 1." << std::endl;
            return;
        }

        std::cout << "Test F - Test ShrinkToFit(2) when list has 2 elements." << std::endl;
        list.InsertTail(1);
        list.InsertTail(2);
        list.ShrinkToFit(2);
        if (list.Size() != 2)
        {
            std::cerr << "Failed Test - ShrinkToFit(2) did not shrink list to size 2." << std::endl;
            return;
        }

        std::cout << "Test G - Test ShrinkToFit(-1) when list is empty." << std::endl;
        list.Clear();
        try
        {
            list.ShrinkToFit(-1);
            std::cerr << "Failed Test - ShrinkToFit(-1) shrunk elements when index is invalid." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << std::endl; // newline
    }



    void ListTest::InsertHeadTest()
    {
        std::cout << "InsertHead() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test InsertHead(1) when list is empty." << std::endl;
        list.InsertHead(1);
        if (list.Head() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test B - Test InsertHead(2) when list has 1 element." << std::endl;
        list.InsertHead(2);
        if (list.Head() != 2)
        {
            std::cerr << "Failed Test - List contains { 2, 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test C - Test InsertHead(3) when list has 3 elements." << std::endl;
        list.InsertHead(3);
        if (list.Head() != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 2, 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test D - Test InsertHead(4) when list has 4 elements." << std::endl;
        list.InsertHead(4);
        if (list.Head() != 4)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 2, 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << std::endl; // newline
    }



    void ListTest::InsertInPlaceTest()
    {
        std::cout << "InsertInPlace() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test InsertInPlace(1, 0) when list is empty." << std::endl;
        list.InsertInPlace(1, 0);
        if (list.Head() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Head() did not match head of list." << std::endl;
            return;
        }

        std::cout << "Test B - Test InsertInPlace(1, 1) when list is empty." << std::endl;
        list.Clear();
        list.InsertInPlace(1, 1);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Illegal index given but element is inserted." << std::endl;
            return;
        }

        std::cout << "Test C - Test InsertInPlace(1, -1) when list is empty." << std::endl;
        list.Clear();
        list.InsertInPlace(1, -1);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Illegal index given but element is inserted." << std::endl;
            return;
        }

        /*
            ADD EDGE CASES HERE

            Size 0 inserts
            Size 1 inserts
            Size 2 inserts
            
            check for Head(), Tail(), Size()
        */

        std::cout << std::endl; // newline
    }



    void ListTest::InsertTailTest()
    {
        
    }



    void ListTest::RemoveHeadTest()
    {
        
    }



    void ListTest::RemoveInPlaceTest()
    {
        
    }



    void ListTest::RemoveTailTest()
    {
        
    }



    void ListTest::SearchTest()
    {
        
    }



    void ListTest::SwapTest()
    {
        
    }



    void ListTest::SortTest()
    {
        
    }



    void ListTest::operatorEqualTest()
    {
        
    }

} // namespace pms

#endif // PMS_LIST_TEST_H