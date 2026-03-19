module;
export module DoublyLinkedList;
import std;

export namespace CA {
    template<typename T>
    class DoublyLinkedListNode {
    private:
        T value;
        std::unique_ptr<DoublyLinkedListNode<T>> next = nullptr;
        std::unique_ptr<DoublyLinkedListNode<T>> previous = nullptr;

    public:
        DoublyLinkedListNode() = default;

        template<typename U>
        requires std::constructible_from<T, U>
        explicit DoublyLinkedListNode(U&& data) : value(std::forward<U>(data)), next(nullptr), previous(nullptr) {}

        DoublyLinkedListNode(const DoublyLinkedListNode& other);

        DoublyLinkedListNode& operator=(const DoublyLinkedListNode& other);

        DoublyLinkedListNode(DoublyLinkedListNode&& other) noexcept = default;

        DoublyLinkedListNode& operator=(DoublyLinkedListNode&& other) noexcept = default;

        ~DoublyLinkedListNode() = default;

        T& getData() { return value; }
        const T& getData() const { return value; }

        template<typename U>
        requires std::assignable_from<T&, U>
        void setData(U&& data) {
            value = std::forward<U>(data);
        }

        decltype(next)& getNext() { return next; }
        const decltype(next)& getNext() const { return next; }

        decltype(previous)& getPrevious() { return previous; }
        const decltype(previous)& getPrevious() const { return previous; }

        void setNext(std::unique_ptr<DoublyLinkedListNode<T>> node) {
            next = std::move(node);
        }

        decltype(next) releaseNext() {
            return std::move(next);
        }

        void setPrevious(std::unique_ptr<DoublyLinkedListNode<T>> node) {
            previous = std::move(node);
        }

        decltype(previous) releasePrevious() {
            return std::move(previous);
        }
    };

    template<typename T>
     DoublyLinkedListNode<T>::DoublyLinkedListNode(const DoublyLinkedListNode &other) {
        value = other.value;
        next = nullptr;
        previous = nullptr;
    }

    template<typename T>
    DoublyLinkedListNode<T> & DoublyLinkedListNode<T>::operator=(const DoublyLinkedListNode &other) {
        if (this != &other) {
            value = other.value;
            next = nullptr;
            previous = nullptr;
        }
        return *this;
    }

    template<typename T>
    class DoublyLinkedList {
    private:
        std::unique_ptr<DoublyLinkedListNode<T>> head = nullptr;
        DoublyLinkedListNode<T>* tail = nullptr;
        size_t size = 0;

    public:
        DoublyLinkedList() = default;

        DoublyLinkedList(const DoublyLinkedList& other);
        DoublyLinkedList& operator=(const DoublyLinkedList& other);

        DoublyLinkedList(DoublyLinkedList&& other) noexcept = default;
        DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept = default;

        ~DoublyLinkedList() = default;

        template<typename U>
         requires std::constructible_from<T, U>
        DoublyLinkedList& prepend(U&& data);

        template<typename U>
         requires std::constructible_from<T, U>
        DoublyLinkedList& append(U&& data);

         template<typename U>
         requires std::constructible_from<T, U>
        DoublyLinkedList& insert(U&& data, size_t index);

        DoublyLinkedList& remove(const T& data);

         template<std::predicate<const T&> Predicate>
         std::optional<std::reference_wrapper<DoublyLinkedListNode<T>>> find(Predicate&& pred);

         template<std::predicate<const T&> Predicate>
         std::optional<std::reference_wrapper<const DoublyLinkedListNode<T>>> find(Predicate&& pred) const;

         std::optional<std::reference_wrapper<const DoublyLinkedListNode<T>>> find(const T& data) const;

         std::optional<std::reference_wrapper<DoublyLinkedListNode<T>>> find(const T& data);

        std::unique_ptr<DoublyLinkedListNode<T>> deleteTail();
        std::unique_ptr<DoublyLinkedListNode<T>> deleteHead();

        DoublyLinkedList& reverse();

        size_t getSize() const { return size; }

        bool isEmpty() const { return size == 0; }

        void clear();
    };

    template<typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other) {
        if (other.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }
        head = std::make_unique<DoublyLinkedListNode<T>>(other.head->getData());
        auto currentNew = head.get();
        auto currentOther = other.head.get();
        while (currentOther->getNext()) {
            currentOther = currentOther->getNext().get();
            currentNew->setNext(std::make_unique<DoublyLinkedListNode<T>>(currentOther->getData()));
            currentNew->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*currentNew));
            currentNew = currentNew->getNext().get();
        }
        size = other.getSize();
        tail = currentNew;
    }

    template<typename T>
    DoublyLinkedList<T> & DoublyLinkedList<T>::operator=(const DoublyLinkedList &other) {
        if (this == &other) {
            return *this;
        }
        if (other.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            return *this;
        }
        head = std::make_unique<DoublyLinkedListNode<T>>(other.head->getData());
        auto currentNew = head.get();
        auto currentOther = other.head.get();
        while (currentOther->getNext()) {
            currentOther = currentOther->getNext().get();
            currentNew->setNext(std::make_unique<DoublyLinkedListNode<T>>(currentOther->getData()));
            currentNew->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*currentNew));
            currentNew = currentNew->getNext().get();
        }
        tail = currentNew;
        size = other.getSize();
        return *this;
    }

    template<typename T>
    template<typename U>
    requires std::constructible_from<T, U>
    DoublyLinkedList<T> & DoublyLinkedList<T>::prepend(U &&data) {
        auto newNode = std::make_unique<DoublyLinkedListNode<T>>(std::forward<U>(data));
        if (head == nullptr) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            newNode->setNext(std::move(head));
            newNode->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*newNode));
            head = std::move(newNode);
        }
        size++;
        return *this;
    }

    template<typename T>
    template<typename U>
    requires std::constructible_from<T, U>
    DoublyLinkedList<T> & DoublyLinkedList<T>::append(U &&data) {
        auto newNode = std::make_unique<DoublyLinkedListNode<T>>(std::forward<U>(data));
        if (head == nullptr) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->setNext(std::move(newNode));
            tail->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*tail));
            tail = tail->getNext().get();
        }
        size++;
        return *this;
    }

    template<typename T>
    template<typename U> requires std::constructible_from<T, U>
    DoublyLinkedList<T> & DoublyLinkedList<T>::insert(U &&data, size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            prepend(std::forward<U>(data));
        } else if (index == size) {
            append(std::forward<U>(data));
        } else {
            auto newNode = std::make_unique<DoublyLinkedListNode<T>>(std::forward<U>(data));
            auto current = head.get();
            for (size_t i = 0; i < index - 1; i++) {
                current = current->getNext().get();
            }
            newNode->setNext(std::move(current->getNext()));
            newNode->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*newNode));
            current->setNext(std::move(newNode));
            size++;
        }
        return *this;
    }

    template<typename T>
    DoublyLinkedList<T> & DoublyLinkedList<T>::remove(const T &data) {
        if (head == nullptr) {
            return *this;
        }
        if (head->getData() == data) {
            head = std::move(head->getNext());
            if (head) {
                head->setPrevious(nullptr);
            }
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
                if (current->getNext()) {
                    current->getNext()->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*current));
                } else {
                    tail = current;
                }
                size--;
                return *this;
            }
            current = current->getNext().get();
        }
        return *this;
    }

    template<typename T>
    template<std::predicate<const T&> Predicate>
    std::optional<std::reference_wrapper<DoublyLinkedListNode<T>>> DoublyLinkedList<T>::find(Predicate&& pred) {
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
    std::optional<std::reference_wrapper<const DoublyLinkedListNode<T>>> DoublyLinkedList<T>::find(Predicate&& pred) const {
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
    std::optional<std::reference_wrapper<DoublyLinkedListNode<T>>> DoublyLinkedList<T>::find(const T& data) {
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
    std::optional<std::reference_wrapper<const DoublyLinkedListNode<T>>> DoublyLinkedList<T>::find(const T& data) const {
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
        std::unique_ptr<DoublyLinkedListNode<T>> DoublyLinkedList<T>::deleteTail() {
        if (head == nullptr) {
            return nullptr;
        }
        std::unique_ptr<DoublyLinkedListNode<T>> oldTail;
        if (head.get() == tail) {
            oldTail = std::move(head);
            head = nullptr;
            tail = nullptr;
            size = 0;
            return oldTail;
        }

        auto previousNode = tail->getPrevious().get();
        oldTail = std::move(previousNode->getNext());
        tail = previousNode;
        tail->setNext(nullptr);
        size--;
        return oldTail;
    }

    template<typename T>
    std::unique_ptr<DoublyLinkedListNode<T>> DoublyLinkedList<T>::deleteHead() {
        if (head == nullptr) {
            return nullptr;
        }
        auto oldHead = std::move(head);
        if (oldHead->getNext()) {
            head = std::move(oldHead->getNext());
            head->setPrevious(nullptr);
        } else {
            tail = nullptr;
        }
        size--;
        return oldHead;
    }

    template<typename T>
    DoublyLinkedList<T> & DoublyLinkedList<T>::reverse() {
        if (size <= 1) {
            return *this;
        }
        auto current = std::move(head);
        DoublyLinkedListNode<T>* newTail = nullptr;
        std::unique_ptr<DoublyLinkedListNode<T>> previous = nullptr;
        while (current != nullptr) {
            auto next = std::move(current->getNext());
            current->setNext(std::move(previous));
            previous = std::move(current);
            if (next) {
                next->setPrevious(std::make_unique<DoublyLinkedListNode<T>>(*previous));
            }
            current = std::move(next);
        }
        head = std::move(previous);
        tail = newTail ? newTail : head.get();
        return *this;
    }

    template<typename T>
    void DoublyLinkedList<T>::clear() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

}