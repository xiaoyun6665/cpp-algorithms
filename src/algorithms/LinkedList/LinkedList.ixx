module;
export module LinkedList;
import std;

export namespace CA{

     template<typename T>
     class LinkedListNode {
     private:
         T value;
         std::unique_ptr<LinkedListNode<T>> next;

     public:
         LinkedListNode() = default;

         explicit LinkedListNode(T&& data) : value(std::move(data)), next(nullptr) {}

         explicit LinkedListNode(const T& data): value(data), next(nullptr){};

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

        // LinkedList& prepend(const T& data);
        // LinkedList& prepend(T&& data);
        //
        // LinkedList& append(const T& data);
        // LinkedList& append(T&& data);
        //
        // LinkedList& insert(const T& data, size_t index);
        // LinkedList& insert(T&& data, size_t index);
        //
        // LinkedList& remove(const T& data);
        //
        // template<typename Condition>
        // LinkedList& find(Condition&&);
        // LinkedList& find(const T& data);
        //
        // decltype(tail) deleteTail();
        // decltype(head) deleteHead();
        //
        // LinkedList& reverse();

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

        // 设置 tail 指针
        tail = currentNew;
        return *this;
    }
 }
