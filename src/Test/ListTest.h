#ifndef PMS_LIST_TEST_H
#define PMS_LIST_TEST_H

#include "../Structures/List.h"

#include <iostream>

namespace pms
{
    // For sorting
    bool Sort2Comparison(int a, int b)
    {
        return a < b;
    }



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
            void Search2Test();
            void SwapTest();
            void SortTest();
            void Sort2Test();
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
        Sort2Test();
        operatorEqualTest();
    }



    void ListTest::HeadTest()
    {
        std::cout << std::endl; // newline
        
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
    }



    void ListTest::TailTest()
    {
        std::cout << std::endl; // newline

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
    }



    void ListTest::AtTest()
    {
        std::cout << std::endl; // newline

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
            // Passed test, Correct behaviour is to throw when index is negative.
        }
    }



    void ListTest::EmptyTest()
    {
        std::cout << std::endl; // newline

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
    }



    void ListTest::SizeTest()
    {
        std::cout << std::endl; // newline

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
    }



    void ListTest::ClearTest()
    {
        std::cout << std::endl; // newline

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
        list.InsertTail(2);
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }
        std::cout << "Test D - Test Clear() when list has 3 elements." << std::endl;
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Clear();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - Clear() did not clear list. (Size != 0)" << std::endl;
            return;
        }
    }



    void ListTest::ShrinkToFitTest()
    {
        std::cout << std::endl; // newline

        std::cout << "ShrinkToFit() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test ShrinkToFit(1) when list is empty." << std::endl;
        try
        {
            list.ShrinkToFit(1);
            std::cerr << "Failed Test - ShrinkToFit(2) did not throw when length error." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when length error.
        }

        std::cout << "Test B - Test ShrinkToFit(0) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.ShrinkToFit(0);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - ShrinkToFit(0) did not shrink list to size 0." << std::endl;
            return;
        }

        std::cout << "Test C - Test ShrinkToFit(1) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        try
        {
            list.ShrinkToFit(2);
            std::cerr << "Failed Test - ShrinkToFit(1) did not throw when length error." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when length error.
        }

        std::cout << "Test D - Test ShrinkToFit(0) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.ShrinkToFit(0);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - ShrinkToFit(0) did not shrink list to size 0." << std::endl;
            return;
        }

        std::cout << "Test E - Test ShrinkToFit(1) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.ShrinkToFit(1);
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - ShrinkToFit(1) did not shrink list to size 1." << std::endl;
            return;
        }

        std::cout << "Test F - Test ShrinkToFit(2) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        try
        {
            list.ShrinkToFit(2);
            std::cerr << "Failed Test - ShrinkToFit(2) did not throw when length error." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when length error.
        }

        std::cout << "Test G - Test ShrinkToFit(-1) when list is empty." << std::endl;
        list.Clear();
        try
        {
            list.ShrinkToFit(-1);
            std::cerr << "Failed Test - ShrinkToFit(-1) shrunk elements when out of range." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }
    }



    void ListTest::InsertHeadTest()
    {
        std::cout << std::endl; // newline

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
    }



    void ListTest::InsertInPlaceTest()
    {
        std::cout << std::endl; // newline

        std::cout << "InsertInPlace() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test InsertInPlace(1, 0) when list is empty." << std::endl;
        list.InsertInPlace(1, 0);
        if (list.Head() != 1 || list.Tail() != 1 || list.Size() != 1)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 1)
                std::cerr << "Failed Test - List contains { 1 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 1)
                std::cerr << "Failed Test - List contains { 1 }, Size() did not return 1." << std::endl;
            return;
        }

        std::cout << "Test B - Test InsertInPlace(1, 1) when list is empty." << std::endl;
        try
        {
            list.Clear();
            list.InsertInPlace(1, 1);
            std::cerr << "Failed Test - InsertInPlace(1, 1) did not throw when out of range." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test C - Test InsertInPlace(1, -1) when list is empty." << std::endl;
        try
        {
            list.Clear();
            list.InsertInPlace(1, -1);
            std::cerr << "Failed Test - InsertInPlace(1, -1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test D - Test InsertInPlace(2, 0) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertHead(1);
        list.InsertInPlace(2, 0);
        if (list.Head() != 2 || list.Tail() != 1 || list.Size() != 2)
        {
            if (list.Head() != 2)
                std::cerr << "Failed Test - List contains { 2, 1 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 1)
                std::cerr << "Failed Test - List contains { 2, 1 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 2)
                std::cerr << "Failed Test - List contains { 2, 1 }, Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test E - Test InsertInPlace(2, 1) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertHead(1);
        list.InsertInPlace(2, 1);
        if (list.Head() != 1 || list.Tail() != 2 || list.Size() != 2)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 2)
                std::cerr << "Failed Test - List contains { 1, 2 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 2)
                std::cerr << "Failed Test - List contains { 1, 2 }, Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test F - Test InsertInPlace(2, 2) when list has 1 element." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertInPlace(2, 2);
            std::cerr << "Failed Test - InsertInPlace(1, -1) did not throw when out of range." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test G - Test InsertInPlace(2, -1) when list has 1 element." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertInPlace(2, -1);
            std::cerr << "Failed Test - InsertInPlace(2, -1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test H - Test InsertInPlace(3, 0) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertInPlace(3, 0);
        if (list.Head() != 3 || list.Tail() != 2 || list.Size() != 3)
        {
            if (list.Head() != 3)
                std::cerr << "Failed Test - List contains { 3, 1, 2 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 2)
                std::cerr << "Failed Test - List contains { 3, 1, 2 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 3, 1, 2 }, Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test I - Test InsertInPlace(3, 1) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertInPlace(3, 1);
        if (list.Head() != 1 || list.Tail() != 2 || list.Size() != 3)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 3, 2 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 2)
                std::cerr << "Failed Test - List contains { 1, 3, 2 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 1, 3, 2 }, Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test J - Test InsertInPlace(3, 2) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertInPlace(3, 2);
        if (list.Head() != 1 || list.Tail() != 3 || list.Size() != 3)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }, Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test K - Test InsertInPlace(3, 3) when list has 2 elements." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertHead(2);
            list.InsertInPlace(3, -1);
            std::cerr << "Failed Test - InsertInPlace(3, 3) did not throw when out of range." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test L - Test InsertInPlace(3, -1) when list has 2 elements." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertHead(2);
            list.InsertInPlace(3, -1);
            std::cerr << "Failed Test - InsertInPlace(3, -1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test M - Test InsertInPlace(4, 0) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertInPlace(4, 0);
        if (list.Head() != 4 || list.Tail() != 3 || list.Size() != 4)
        {
            if (list.Head() != 4)
                std::cerr << "Failed Test - List contains { 4, 1, 2, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 4, 1, 2, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 4, 1, 2, 3 }, Size() did not return 4." << std::endl;
            return;
        }

        std::cout << "Test N - Test InsertInPlace(4, 1) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertInPlace(4, 1);
        if (list.Head() != 1 || list.Tail() != 3 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 4, 2, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 1, 4, 2, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 4, 2, 3 }, Size() did not return 4." << std::endl;
            return;
        }

        std::cout << "Test O - Test InsertInPlace(4, 2) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertInPlace(4, 2);
        if (list.Head() != 1 || list.Tail() != 3 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 3 }, Size() did not return 4." << std::endl;
            return;
        }

        std::cout << "Test P - Test InsertInPlace(4, 3) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertInPlace(4, 3);
        if (list.Head() != 1 || list.Tail() != 4 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Size() did not return 4." << std::endl;
            return;
        }

        std::cout << "Test Q - Test InsertInPlace(4, 4) when list has 3 elements." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertHead(2);
            list.InsertHead(3);
            list.InsertInPlace(4, 4);
            std::cerr << "Failed Test - InsertInPlace(4, 4) did not throw when out of range." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test R - Test InsertInPlace(4, -1) when list has 3 elements." << std::endl;
        try
        {
            list.Clear();
            list.InsertHead(1);
            list.InsertHead(2);
            list.InsertHead(3);
            list.InsertInPlace(4, -1);
            std::cerr << "Failed Test - InsertInPlace(4, -1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }
    }



    void ListTest::InsertTailTest()
    {
        std::cout << std::endl; // newline

        std::cout << "InsertTail() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test InsertTail(1) when list is empty." << std::endl;
        list.InsertTail(1);
        if (list.Tail() != 1)
        {
            std::cerr << "Failed Test - List contains { 1 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test B - Test InsertTail(2) when list has 1 element." << std::endl;
        list.InsertTail(2);
        if (list.Tail() != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test C - Test InsertTail(3) when list has 3 elements." << std::endl;
        list.InsertTail(3);
        if (list.Tail() != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }, Tail() did not match tail of list." << std::endl;
            return;
        }

        std::cout << "Test D - Test InsertTail(4) when list has 4 elements." << std::endl;
        list.InsertTail(4);
        if (list.Tail() != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Tail() did not match tail of list." << std::endl;
            return;
        }
    }



    void ListTest::RemoveHeadTest()
    {
        std::cout << std::endl; // newline

        std::cout << "RemoveHead() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test RemoveHead() when list is empty." << std::endl;
        list.RemoveHead();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List size is not 0." << std::endl;
            return;
        }

        std::cout << "Test B - Test RemoveHead() when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.RemoveHead();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List size is not 0." << std::endl;
            return;
        }

        std::cout << "Test C - Test RemoveHead() when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.RemoveHead();
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - List size is not 1." << std::endl;
            return;
        }

        std::cout << "Test D - Test RemoveHead() when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.RemoveHead();
        if (list.Size() != 2)
        {
            std::cerr << "Failed Test - List size is not 2." << std::endl;
            return;
        }
    }



    void ListTest::RemoveInPlaceTest()
    {
        std::cout << std::endl; // newline

        std::cout << "RemoveInPlace() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test RemoveInPlace(0) when list is empty." << std::endl;
        try
        {
            list.RemoveInPlace(0);
            std::cerr << "Failed Test - RemoveInPlace(0) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test B - Test RemoveInPlace(1) when list is empty." << std::endl;
        try
        {
            list.RemoveInPlace(1);
            std::cerr << "Failed Test - RemoveInPlace(1) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test C - Test RemoveInPlace(-1) when list is empty." << std::endl;
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test D - Test RemoveInPlace(0) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.RemoveInPlace(0);
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List contains {}. Size() did not return 0." << std::endl;
            return;
        }
        
        std::cout << "Test E - Test RemoveInPlace(1) when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        try
        {
            list.RemoveInPlace(1);
            std::cerr << "Failed Test - RemoveInPlace(1) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test F - Test RemoveInPlace(-1) when list is empty." << std::endl;
        list.Clear();
        list.InsertTail(1);
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test G - Test RemoveInPlace(0) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.RemoveInPlace(0);
        if (list.Head() != 2 || list.Tail() != 2 || list.Size() != 1)
        {
            if (list.Head() != 2)
                std::cerr << "Failed Test - List contains { 2 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 2)
                std::cerr << "Failed Test - List contains { 2 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 1)
                std::cerr << "Failed Test - List contains { 2 }. Size() did not return 1." << std::endl;
            return;
        }

        std::cout << "Test H - Test RemoveInPlace(1) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.RemoveInPlace(1);
        if (list.Head() != 1 || list.Tail() != 1 || list.Size() != 1)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 1)
                std::cerr << "Failed Test - List contains { 1 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 1)
                std::cerr << "Failed Test - List contains { 1 }. Size() did not return 1." << std::endl;
            return;
        }

        std::cout << "Test I - Test RemoveInPlace(2) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        try
        {
            list.RemoveInPlace(2);
            std::cerr << "Failed Test - RemoveInPlace(2) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test J - Test RemoveInPlace(-1) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test K - Test RemoveInPlace(0) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.RemoveInPlace(0);
        if (list.Head() != 2 || list.Tail() != 3 || list.Size() != 2)
        {
            if (list.Head() != 2)
                std::cerr << "Failed Test - List contains { 2, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 2, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 2)
                std::cerr << "Failed Test - List contains { 2, 3 }. Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test L - Test RemoveInPlace(1) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.RemoveInPlace(1);
        if (list.Head() != 1 || list.Tail() != 3 || list.Size() != 2)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 1, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 2)
                std::cerr << "Failed Test - List contains { 1, 3 }. Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test M - Test RemoveInPlace(2) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.RemoveInPlace(2);
        if (list.Head() != 1 || list.Tail() != 2 || list.Size() != 2)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 2)
                std::cerr << "Failed Test - List contains { 1, 2 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 2)
                std::cerr << "Failed Test - List contains { 1, 2 }. Size() did not return 2." << std::endl;
            return;
        }

        std::cout << "Test N - Test RemoveInPlace(3) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        try
        {
            list.RemoveInPlace(3);
            std::cerr << "Failed Test - RemoveInPlace(3) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test O - Test RemoveInPlace(-1) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test P - Test RemoveInPlace(0) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.RemoveInPlace(0);
        if (list.Head() != 2 || list.Tail() != 4 || list.Size() != 3)
        {
            if (list.Head() != 2)
                std::cerr << "Failed Test - List contains { 2, 3, 4 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 4)
                std::cerr << "Failed Test - List contains { 2, 3, 4 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 2, 3, 4 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test Q - Test RemoveInPlace(1) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.RemoveInPlace(1);
        if (list.Head() != 1 || list.Tail() != 4 || list.Size() != 3)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 3, 4 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 4)
                std::cerr << "Failed Test - List contains { 1, 3, 4 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 1, 3, 4 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test R - Test RemoveInPlace(2) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.RemoveInPlace(2);
        if (list.Head() != 1 || list.Tail() != 4 || list.Size() != 3)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 4 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 4 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 4 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test S - Test RemoveInPlace(3) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.RemoveInPlace(3);
        if (list.Head() != 1 || list.Tail() != 3 || list.Size() != 3)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 3)
                std::cerr << "Failed Test - List contains { 1, 2, 3 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test T - Test RemoveInPlace(4) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        try
        {
            list.RemoveInPlace(4);
            std::cerr << "Failed Test - RemoveInPlace(4) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test U - Test RemoveInPlace(-1) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }

        std::cout << "Test V - Test RemoveInPlace(0) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.RemoveInPlace(0);
        if (list.Head() != 2 || list.Tail() != 5 || list.Size() != 4)
        {
            if (list.Head() != 2)
                std::cerr << "Failed Test - List contains { 2, 3, 4, 5 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 5)
                std::cerr << "Failed Test - List contains { 2, 3, 4, 5 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 2, 3, 4, 5 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test W - Test RemoveInPlace(1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.RemoveInPlace(1);
        if (list.Head() != 1 || list.Tail() != 5 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 3, 4, 5 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 5)
                std::cerr << "Failed Test - List contains { 1, 3, 4, 5 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 3, 4, 5 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test X - Test RemoveInPlace(2) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.RemoveInPlace(2);
        if (list.Head() != 1 || list.Tail() != 5 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 5 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 5)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 5 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 4, 5 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test Y - Test RemoveInPlace(3) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.RemoveInPlace(3);
        if (list.Head() != 1 || list.Tail() != 5 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 5 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 5)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 5 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 5 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test Y - Test RemoveInPlace(4) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.RemoveInPlace(4);
        if (list.Head() != 1 || list.Tail() != 4 || list.Size() != 4)
        {
            if (list.Head() != 1)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Head() did not match head of list." << std::endl;
            if (list.Tail() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }, Tail() did not match tail of list." << std::endl;
            if (list.Size() != 4)
                std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Size() did not return 3." << std::endl;
            return;
        }

        std::cout << "Test Z - Test RemoveInPlace(5) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        try
        {
            list.RemoveInPlace(5);
            std::cerr << "Failed Test - RemoveInPlace(5) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when out of range.
        }

        std::cout << "Test AA - Test RemoveInPlace(-1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        try
        {
            list.RemoveInPlace(-1);
            std::cerr << "Failed Test - RemoveInPlace(-1) did not throw when index is negative." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when index is negative.
        }
    }



    void ListTest::RemoveTailTest()
    {
        std::cout << std::endl; // newline

        std::cout << "RemoveTail() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test RemoveTail() when list is empty." << std::endl;
        list.RemoveTail();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List size is not 0." << std::endl;
            return;
        }

        std::cout << "Test B - Test RemoveTail() when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.RemoveTail();
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List size is not 0." << std::endl;
            return;
        }

        std::cout << "Test C - Test RemoveTail() when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.RemoveTail();
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - List size is not 1." << std::endl;
            return;
        }

        std::cout << "Test D - Test RemoveTail() when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.RemoveTail();
        if (list.Size() != 2)
        {
            std::cerr << "Failed Test - List size is not 2." << std::endl;
            return;
        }
    }



    void ListTest::SearchTest()
    {
        std::cout << std::endl; // newline

        std::cout << "Search() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Search(0) when list is empty." << std::endl;
        if (list.Search(0) != -1)
        {
            std::cerr << "Failed Test - Search did not return -1." << std::endl;
            return;
        }

        std::cout << "Test B - Test Search(0) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        if (list.Search(0) != -1)
        {
            std::cerr << "Failed Test - Search did not return -1." << std::endl;
            return;
        }

        std::cout << "Test C - Test Search(1) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        if (list.Search(1) != 0)
        {
            std::cerr << "Failed Test - Search did not return 0." << std::endl;
            return;
        }

        std::cout << "Test D - Test Search(2) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        if (list.Search(2) != 1)
        {
            std::cerr << "Failed Test - Search did not return 1." << std::endl;
            return;
        }

        std::cout << "Test E - Test Search(3) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        if (list.Search(3) != 2)
        {
            std::cerr << "Failed Test - Search did not return 2." << std::endl;
            return;
        }

        std::cout << "Test F - Test Search(4) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        if (list.Search(4) != 3)
        {
            std::cerr << "Failed Test - Search did not return 3." << std::endl;
            return;
        }

        std::cout << "Test G - Test Search(5) when list is { 1, 2, 3, 4, 5 }." << std::endl;
        if (list.Search(5) != 4)
        {
            std::cerr << "Failed Test - Search did not return 4." << std::endl;
            return;
        }
    }



    void ListTest::SwapTest()
    {
        std::cout << std::endl; // newline

        std::cout << "Swap() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Swap(0, 0) when list is empty." << std::endl;
        try
        {
            list.Swap(0, 0);
            std::cerr << "Failed Test - Swap(0, 0) did not throw when same index." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when logic error.
        }

        std::cout << "Test B - Test Swap(0, 1) when list is empty." << std::endl;
        try
        {
            list.Swap(0, 1);
            std::cerr << "Failed Test - Swap(0, 1) did not throw when out of bounds." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when logic error.
        }

        std::cout << "Test C - Test Swap(0, 1) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.Swap(0, 1);
        if (list.At(0) != 2 || list.At(1) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }. Swap(0, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test D - Test Swap(1, 0) when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.Swap(1, 0);
        if (list.At(0) != 2 || list.At(1) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2 }. Swap(1, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test E - Test Swap(0, 1) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(0, 1);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(0, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test F - Test Swap(0, 2) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(0, 2);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(0, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test G - Test Swap(1, 0) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(1, 0);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(1, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test H - Test Swap(1, 2) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(1, 2);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(1, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test I - Test Swap(2, 0) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(2, 0);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(2, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test J - Test Swap(2, 1) when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.Swap(2, 1);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3 }. Swap(2, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test K - Test Swap(0, 1) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(0, 1);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(0, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test L - Test Swap(0, 2) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(0, 2);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(0, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test M - Test Swap(0, 3) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(0, 3);
        if (list.At(0) != 4 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(0, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test N - Test Swap(1, 0) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(1, 0);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(1, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test O - Test Swap(1, 2) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(1, 2);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(1, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test P - Test Swap(1, 3) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(1, 3);
        if (list.At(0) != 1 || list.At(1) != 4 || list.At(2) != 3 || list.At(3) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(1, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test Q - Test Swap(2, 0) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(2, 0);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(2, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test R - Test Swap(2, 1) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(2, 1);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(2, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test S - Test Swap(2, 3) when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.Swap(2, 3);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 4 || list.At(3) != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4 }. Swap(2, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test T - Test Swap(0, 1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(0, 1);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(0, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test U - Test Swap(0, 2) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(0, 2);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(0, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test U - Test Swap(0, 3) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(0, 3);
        if (list.At(0) != 4 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 1 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(0, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test V - Test Swap(0, 4) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(0, 4);
        if (list.At(0) != 5 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(0, 4) did not swap." << std::endl;
            return;
        }

        std::cout << "Test W - Test Swap(1, 0) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(1, 0);
        if (list.At(0) != 2 || list.At(1) != 1 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(1, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test X - Test Swap(1, 2) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(1, 2);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(1, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test Y - Test Swap(1, 3) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(1, 3);
        if (list.At(0) != 1 || list.At(1) != 4 || list.At(2) != 3 || list.At(3) != 2 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(1, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test Z - Test Swap(1, 4) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(1, 4);
        if (list.At(0) != 1 || list.At(1) != 5 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(1, 4) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AA - Test Swap(2, 0) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(2, 0);
        if (list.At(0) != 3 || list.At(1) != 2 || list.At(2) != 1 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(2, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AB - Test Swap(2, 1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(2, 1);
        if (list.At(0) != 1 || list.At(1) != 3 || list.At(2) != 2 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(2, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AC - Test Swap(2, 3) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(2, 3);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 4 || list.At(3) != 3 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(2, 3) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AD - Test Swap(2, 4) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(2, 4);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 5 || list.At(3) != 4 || list.At(4) != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(2, 4) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AE - Test Swap(3, 0) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(3, 0);
        if (list.At(0) != 4 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 1 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(3, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AF - Test Swap(3, 1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(3, 1);
        if (list.At(0) != 1 || list.At(1) != 4 || list.At(2) != 3 || list.At(3) != 2 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(3, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AG - Test Swap(3, 2) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(3, 2);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 4 || list.At(3) != 3 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(3, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AH - Test Swap(3, 4) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(3, 4);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 5 || list.At(4) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(3, 4) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AI - Test Swap(4, 0) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(4, 0);
        if (list.At(0) != 5 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 1)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(4, 0) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AJ - Test Swap(4, 1) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(4, 1);
        if (list.At(0) != 1 || list.At(1) != 5 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 2)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(4, 1) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AK - Test Swap(4, 2) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(4, 2);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 5 || list.At(3) != 4 || list.At(4) != 3)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(4, 2) did not swap." << std::endl;
            return;
        }

        std::cout << "Test AL - Test Swap(4, 3) when list has 5 elements." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.InsertTail(2);
        list.InsertTail(3);
        list.InsertTail(4);
        list.InsertTail(5);
        list.Swap(4, 3);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 5 || list.At(4) != 4)
        {
            std::cerr << "Failed Test - List contains { 1, 2, 3, 4, 5 }. Swap(4, 3) did not swap." << std::endl;
            return;
        }
    }



    void ListTest::SortTest()
    {
        std::cout << std::endl; // newline

        std::cout << "Sort() Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Sort() when list is empty." << std::endl;
        try
        {
            list.Sort();
            std::cerr << "Failed Test - Sort() did not throw when list is empty." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when list is empty.
        }

        std::cout << "Test B - Test Sort() when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.Sort();
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - Sort() changed the size of list from 1." << std::endl;
            return;
        }

        std::cout << "Test C - Test Sort() when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort();
        if (list.At(0) != 1 || list.At(1) != 2)
        {
            std::cerr << "Failed Test - List contains { 2, 1 }. Expected { 1, 2 }." << std::endl;
            return;
        }

        std::cout << "Test D - Test Sort() when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort();
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 2, 1 }. Expected { 1, 2, 3 }." << std::endl;
            return;
        }

        std::cout << "Test E - Test Sort() when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(4);
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort();
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 2, 1 }. Expected { 1, 2, 3, 4 }." << std::endl;
            return;
        }

        std::cout << "Test F - Test Sort() when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(5);
        list.InsertTail(4);
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort();
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 5, 4, 3, 2, 1 }. Expected { 1, 2, 3, 4, 5 }." << std::endl;
            return;
        }
    }



    void ListTest::Sort2Test()
    {
        std::cout << std::endl; // newline

        std::cout << "Sort() overload Testing" << std::endl;
        List<int> list;

        std::cout << "Test A - Test Sort2() when list is empty." << std::endl;
        try
        {
            list.Sort(Sort2Comparison);
            std::cerr << "Failed Test - Sort2() did not throw when list is empty." << std::endl;
            return;
        }
        catch(...)
        {
            // Passed test, Correct behaviour is to throw when list is empty.
        }

        std::cout << "Test B - Test Sort2() when list has 1 element." << std::endl;
        list.Clear();
        list.InsertTail(1);
        list.Sort(Sort2Comparison);
        if (list.Size() != 1)
        {
            std::cerr << "Failed Test - Sort2() changed the size of list from 1." << std::endl;
            return;
        }

        std::cout << "Test C - Test Sort2() when list has 2 elements." << std::endl;
        list.Clear();
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort(Sort2Comparison);
        if (list.At(0) != 1 || list.At(1) != 2)
        {
            std::cerr << "Failed Test - List contains { 2, 1 }. Expected { 1, 2 }." << std::endl;
            return;
        }

        std::cout << "Test D - Test Sort2() when list has 3 elements." << std::endl;
        list.Clear();
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort(Sort2Comparison);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3)
        {
            std::cerr << "Failed Test - List contains { 3, 2, 1 }. Expected { 1, 2, 3 }." << std::endl;
            return;
        }

        std::cout << "Test E - Test Sort2() when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(4);
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort(Sort2Comparison);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4)
        {
            std::cerr << "Failed Test - List contains { 4, 3, 2, 1 }. Expected { 1, 2, 3, 4 }." << std::endl;
            return;
        }

        std::cout << "Test F - Test Sort2() when list has 4 elements." << std::endl;
        list.Clear();
        list.InsertTail(5);
        list.InsertTail(4);
        list.InsertTail(3);
        list.InsertTail(2);
        list.InsertTail(1);
        list.Sort(Sort2Comparison);
        if (list.At(0) != 1 || list.At(1) != 2 || list.At(2) != 3 || list.At(3) != 4 || list.At(4) != 5)
        {
            std::cerr << "Failed Test - List contains { 5, 4, 3, 2, 1 }. Expected { 1, 2, 3, 4, 5 }." << std::endl;
            return;
        }
    }



    void ListTest::operatorEqualTest()
    {
        std::cout << std::endl; // newline

        std::cout << "operator=() Testing" << std::endl;
        List<int> list;
        List<int> equality_check_list;

        std::cout << "Test A - Test equality when supplied list is empty." << std::endl;
        list = equality_check_list;
        if (list.Size() != 0)
        {
            std::cerr << "Failed Test - List size is not 0." << std::endl;
            return;
        }
        
        std::cout << "Test B - Test equality when supplied list has 1 element." << std::endl;
        equality_check_list.InsertTail(1);
        list = equality_check_list;
        if (list.At(0) != equality_check_list.At(0))
        {
            std::cerr << "Failed Test - `list` element 0 is not the same as `equality_check_list` element 0." << std::endl;
            return;
        }
    }

} // namespace pms

#endif // PMS_LIST_TEST_H