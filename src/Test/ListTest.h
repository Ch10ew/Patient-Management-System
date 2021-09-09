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