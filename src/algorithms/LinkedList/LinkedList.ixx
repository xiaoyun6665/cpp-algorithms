module;
export module LinkedList;
import std;

export namespace CA{
     template<typename T>
     class LinkedListNode {
     private:
         T value;
         std::unique_ptr<LinkedListNode<T>> next = nullptr;

     public:
         LinkedListNode() = default;

         template<typename U>
         requires std::constructible_from<T, U>
         explicit LinkedListNode(U&& data) : value(std::forward<U>(data)), next(nullptr) {}

         LinkedListNode(const LinkedListNode& other);

         LinkedListNode& operator=(const LinkedListNode& other);

         LinkedListNode(LinkedListNode&& other) noexcept = default;

         LinkedListNode& operator=(LinkedListNode&& other) noexcept = default;

         ~LinkedListNode() = default;

         T& getData() { return value; }
         const T& getData() const { return value; }

         void setData(const T& data) { value = data; }
         void setData(T&& data) { value = std::move(data); }

         decltype(next)& getNext() { return next; }
         const decltype(next)& getNext() const { return next; }

         void setNext(std::unique_ptr<LinkedListNode<T>> node) {
             next = std::move(node);
         }

         decltype(next) releaseNext() {
             return std::move(next);
         }
     };


     template<typename T>
     LinkedListNode<T>::LinkedListNode(const LinkedListNode &other) {
         value = other.value;
         next = nullptr;
     }

     template<typename T>
     LinkedListNode<T> & LinkedListNode<T>::operator=(const LinkedListNode &other) {
         if (this != &other) {
             value = other.value;
             next = nullptr;
         }
         return *this;
     }

    template<typename T>
    class LinkedList {
    private:
        std::unique_ptr<LinkedListNode<T>> head = nullptr;
        LinkedListNode<T>* tail = nullptr;
        size_t size = 0;

    public:
        LinkedList() = default;

        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);

        LinkedList(LinkedList&& other) noexcept = default;
        LinkedList& operator=(LinkedList&& other) noexcept = default;

        ~LinkedList() = default;

        template<typename U>
         requires std::constructible_from<T, U>
        LinkedList& prepend(U&& data);

        template<typename U>
         requires std::constructible_from<T, U>
        LinkedList& append(U&& data);

         template<typename U>
         requires std::constructible_from<T, U>
        LinkedList& insert(U&& data, size_t index);

        LinkedList& remove(const T& data);

         template<std::predicate<const T&> Predicate>
         std::optional<std::reference_wrapper<LinkedListNode<T>>> find(Predicate&& pred);

         template<std::predicate<const T&> Predicate>
         std::optional<std::reference_wrapper<const LinkedListNode<T>>> find(Predicate&& pred) const;

         std::optional<std::reference_wrapper<const LinkedListNode<T>>> find(const T& data) const;

         std::optional<std::reference_wrapper<LinkedListNode<T>>> find(const T& data);

        std::unique_ptr<LinkedListNode<T>> deleteTail();
        std::unique_ptr<LinkedListNode<T>> deleteHead();

        LinkedList& reverse();

        size_t getSize() const { return size; }
    };

    template<typename T>
    LinkedList<T>::LinkedList(const LinkedList &other) {
        if (other.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }
        head = std::make_unique<LinkedListNode<T>>(other.head->getData());
        auto currentNew = head.get();
        auto currentOther = other.head.get();
        while (currentOther->getNext()) {
            currentOther = currentOther->getNext().get();
            currentNew->setNext(std::make_unique<LinkedListNode<T>>(currentOther->getData()));
            currentNew = currentNew->getNext().get();
        }
        size = other.getSize();
        tail = currentNew;
    }

    template<typename T>
    LinkedList<T> & LinkedList<T>::operator=(const LinkedList &other) {
        if (this == &other) {
            return *this;
        }
        if (other.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            return *this;
        }
        head = std::make_unique<LinkedListNode<T>>(other.head->getData());
        auto currentNew = head.get();
        auto currentOther = other.head.get();
        while (currentOther->getNext()) {
            currentOther = currentOther->getNext().get();
            currentNew->setNext(std::make_unique<LinkedListNode<T>>(currentOther->getData()));
            currentNew = currentNew->getNext().get();
        }
        tail = currentNew;
        size=other.getSize();
        return *this;
    }

    template<typename T>
    template<typename U>
    requires std::constructible_from<T, U>
    LinkedList<T> & LinkedList<T>::prepend(U &&data) {
        auto newNode = std::make_unique<LinkedListNode<T>>(std::forward<U>(data));
        newNode->setNext(std::move(head));
        this->head = std::move(newNode);
        if (tail == nullptr) {
            this->tail = this->head.get();
        }
        size++;
        return *this;
    }

    template<typename T>
    template<typename U>
    requires std::constructible_from<T, U>
    LinkedList<T> & LinkedList<T>::append(U &&data) {
        auto newNode = std::make_unique<LinkedListNode<T>>(std::forward<U>(data));
        if (head == nullptr) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->setNext(std::move(newNode));
            tail = tail->getNext().get();
        }
        size++;
        return *this;
    }

    template<typename T>
    template<typename U> requires std::constructible_from<T, U>
    LinkedList<T> & LinkedList<T>::insert(U &&data, size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            prepend(std::forward<U>(data));
        } else if (index == size) {
            append(std::forward<U>(data));
        } else {
            auto newNode = std::make_unique<LinkedListNode<T>>(std::forward<U>(data));
            auto current = head.get();
            for (size_t i = 0; i < index - 1; i++) {
                current = current->getNext().get();
            }
            newNode->setNext(std::move(current->getNext()));
            current->setNext(std::move(newNode));
            size++;
        }
        return *this;
    }

    template<typename T>
    LinkedList<T> & LinkedList<T>::remove(const T &data) {
        if (head == nullptr) {
            return *this;
        }
        if (head->getData() == data) {
            head = std::move(head->getNext());
            size--;
            if (size == 0) {
                tail = nullptr;
            }
            return *this;
        }
        auto current = head.get();
        while (current->getNext() != nullptr) {
            if (current->getNext()->getData() == data) {
                auto nodeToDelete = std::move(current->getNext());
                current->setNext(std::move(nodeToDelete->getNext()));
                size--;
                if (current->getNext() == nullptr) {
                    tail = current;
                }
                return *this;
            }
            current = current->getNext().get();
        }
        return *this;
    }

    template<typename T>
    template<std::predicate<const T&> Predicate>
    std::optional<std::reference_wrapper<LinkedListNode<T>>> LinkedList<T>::find(Predicate&& pred) {
        auto current = head.get();
        while (current != nullptr) {
            if (pred(current->getData())) {
                return std::ref(*current);
            }
            current = current->getNext().get();
        }
        return std::nullopt;
    }

    template<typename T>
    template<std::predicate<const T&> Predicate>
    std::optional<std::reference_wrapper<const LinkedListNode<T>>> LinkedList<T>::find(Predicate&& pred) const {
        auto current = head.get();
        while (current != nullptr) {
            if (pred(current->getData())) {
                return std::cref(*current);
            }
            current = current->getNext().get();
        }
        return std::nullopt;
    }

    template<typename T>
       std::optional<std::reference_wrapper<LinkedListNode<T>>> LinkedList<T>::find(const T& data) {
        auto current = head.get();
        while (current != nullptr) {
            if (current->getData() == data) {
                return std::ref(*current);
            }
            current = current->getNext().get();
        }
        return std::nullopt;
    }

    template<typename T>
    std::optional<std::reference_wrapper<const LinkedListNode<T>>> LinkedList<T>::find(const T& data) const {
        auto current = head.get();
        while (current != nullptr) {
            if (current->getData() == data) {
                return std::cref(*current);
            }
            current = current->getNext().get();
        }
        return std::nullopt;
    }

    template<typename T>
    std::unique_ptr<LinkedListNode<T>> LinkedList<T>::deleteTail() {
        if (head == nullptr) {
            return nullptr;
        }
        std::unique_ptr<LinkedListNode<T>> oldTail;
        if (head.get() == tail) {
            oldTail = std::move(head);
            head = nullptr;
            tail = nullptr;
            size = 0;
            return oldTail;
        }
        auto current = head.get();
        while (current->getNext().get() != tail) {
            current = current->getNext().get();
        }
        oldTail = std::move(current->getNext());
        current->setNext(nullptr);
        tail = current;
        size--;
        return oldTail;
    }

    template<typename T>
    std::unique_ptr<LinkedListNode<T>> LinkedList<T>::deleteHead() {
        if (head == nullptr) {
            return nullptr;
        }
        auto oldHead = std::move(head);
        if (oldHead->getNext()) {
            head = std::move(oldHead->getNext());
        } else {
            tail = nullptr;
        }
        size--;
        return oldHead;
    }

    template<typename T>
    LinkedList<T> & LinkedList<T>::reverse() {
        if (size <= 1) {
            return *this;
        }
        tail = head.get();
        auto current = std::move(head);
        std::unique_ptr<LinkedListNode<T>> previous = nullptr;
        while (current != nullptr) {
            auto next = std::move(current->getNext());
            current->setNext(std::move(previous));
            previous = std::move(current);
            current = std::move(next);
        }
        head = std::move(previous);
        return *this;
    }
}
