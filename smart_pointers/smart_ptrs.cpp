#include <iostream>
#include <memory>

int main()
{
    // unique_ptr

    int n = 50;
    {
        std::unique_ptr<int> val(new int);
        *val = 10;
        std::cout << *val << std::endl;
        std::unique_ptr<int[]> arr(new int[n]);
    }
    {
        std::unique_ptr<int> val = std::make_unique<int>();
        *val = 22;
        std::cout << *val << std::endl;
        std::unique_ptr<int[]> arr = std::make_unique<int[]>(55);
    }
    { // unique_ptr is nullptr after std::move
        std::unique_ptr<int> ptr1{new int{2}};
        std::unique_ptr<int> ptr2{std::move(ptr1)};
        std::cout << "unique_ptr after std::move => ptr2{std::move(ptr1)};" << std::endl;
        std::cout << "(ptr1 == nullptr) : " << (ptr1 == nullptr) << std::endl; // 1
        std::cout << "(ptr2 == nullptr) : " << (ptr2 == nullptr) << std::endl; // 0
    }

    // shared_ptr

    {
        std::shared_ptr<int> foo(new int);
        std::shared_ptr<int> bar = std::make_shared<int>();
    }

    // shared_ptr array

    {
        std::shared_ptr<int[]> arr(new int[99], [](int *i) {
            delete[] i;
        });
    }

    // shared_ptr .use_count()

    {
        std::shared_ptr<int> ptr = std::make_shared<int>(123);
        std::cout << "ptr.use_count() = " << ptr.use_count() << std::endl;
        std::shared_ptr<int> copy = ptr;
        std::cout << "ptr.use_count() = " << ptr.use_count() << std::endl;
        std::cout << "copy.use_count() = " << copy.use_count() << std::endl;
    }

    // weak_ptr

    {
        std::shared_ptr<int> p_shared = std::make_shared<int>(321);
        std::weak_ptr<int> p_weak1(p_shared);
        std::weak_ptr<int> p_weak2(p_weak1);

        std::cout << "*p_shared = " << *p_shared << std::endl;
        std::shared_ptr<int> p_w1_shared = p_weak1.lock();
        std::cout << "*p_w1_shared = " << *p_w1_shared << std::endl;

        std::cout << "p_weak1.expired() = " << p_weak1.expired() << std::endl;
    }
}