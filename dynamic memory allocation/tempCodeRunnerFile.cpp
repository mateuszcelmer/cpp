std::shared_ptr<int> p_shared = std::make_shared<int>(321);
        std::weak_ptr<int> p_weak1(p_shared);
        std::weak_ptr<int> p_weak2(p_weak1);

        std::cout << "*p_shared = " << *p_shared << std::endl;
        std::shared_ptr<int> p_w1_shared = p_weak1.lock();
        std::cout << "*p_w1_shared = " << *p_w1_shared << std::endl;

        std::cout << "p_weak1.expired() = " << p_weak1.expired() << std::endl;